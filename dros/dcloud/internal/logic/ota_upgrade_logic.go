/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 14:32:26
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-26 10:03:13
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_upgrade_logic.go
 */
package logic

import (
	"context"
	"dcloud/global"
	"dcloud/models"
	"dcloud/pkg/dcrypto"
	"dcloud/pkg/dfile"
	"dcloud/pkg/dftp"
	"dcloud/pkg/dhttp"
	"dcloud/pkg/dversion"
	"path/filepath"
	"time"

	"dcloud/internal/svc"
	"dcloud/internal/types"

	"github.com/spf13/cast"
	"github.com/zeromicro/go-zero/core/logx"
)

type OtaUpgradeLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

func NewOtaUpgradeLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaUpgradeLogic {
	return &OtaUpgradeLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *OtaUpgradeLogic) OtaUpgrade(req *types.UpgradeRequest) (resp *types.UpgradeResponse, err error) {
	l.Logger.Infof("Ota upgrade called, req: %v", req)

	// 先查表，找到当前版本号
	appVersions, err := l.svcCtx.AppVersionRepo.GetLatestVersion(l.ctx, req.AppName)
	if err != nil {
		l.Logger.Error(err)
		return &types.UpgradeResponse{
			Message: err.Error(),
		}, nil
	}
	// 生成新版本号
	var version string
	if len(appVersions) == 0 {
		version = dversion.GenerateVersion("", 0)
	} else {
		version = dversion.GenerateVersion(appVersions, int32(req.VersionType))
	}

	dstPath := req.FileUrl + "_V" + version + ".tar.gz" // 加上版本号信息
	l.Logger.Info("get dstPath:", dstPath)
	// 版本号信息写入到更新包中
	if err = dfile.WriteToFile(req.FileUrl+"/VERSION", []byte(version)); err != nil {
		l.Logger.Error(err)
		return &types.UpgradeResponse{
			Message: err.Error(),
		}, nil
	}

	// 压缩更新包
	if err = dfile.CompressTarGz(req.FileUrl, dstPath); err != nil {
		l.Logger.Error(err)
		return nil, err
	}
	l.Logger.Info("compress success, begin to crypto")
	// 压缩后加密
	key := []byte(l.svcCtx.Config.Secret.GcmKey) // TODO: key 不应该从配置中读取，应该从数据库中读取
	encFile, err := dcrypto.AesGCMEncrypt(dstPath, key)
	if err != nil {
		l.Logger.Error(err)
		return nil, err
	}

	// 上传到ftp服务器
	dstFilePath := global.FTP_ROOT_PATH + filepath.Base(encFile)
	if err = dftp.UploadFileToFTP(dstFilePath, encFile, global.FTP_URL); err != nil {
		l.Logger.Error(err)
		return nil, err
	}

	// 上传到ftp服务器后，表示已成功生成更新包，更新数据库
	if len(appVersions) == 0 { // 第一次上传，创建新记录
		if err = l.svcCtx.AppVersionRepo.CreateAppVersion(l.ctx, req.AppName, version, req.UpdateContent, dstFilePath, req.Operator); err != nil {
			l.Logger.Error(err)
			return &types.UpgradeResponse{
				Message: err.Error(),
			}, nil
		}
	} else { // 不是第一次上传，更新记录
		if err = l.svcCtx.AppVersionRepo.UpdateAppVersion(l.ctx, req.AppName, version, req.UpdateContent, dstFilePath, req.Operator); err != nil {
			l.Logger.Error(err)
			return &types.UpgradeResponse{
				Message: err.Error(),
			}, nil
		}
	}

	// 调用 http api 升级
	bodyVal := map[string]any{
		"version":  version,
		"address":  "ftp://" + global.FTP_URL + "/" + global.FTP_ROOT_PATH + filepath.Base(encFile),
		"app_name": req.AppName,
	}
	// 查机器人信息表，然后逐一发送升级请求
	robotInfos, err := l.svcCtx.RobotInfoRepo.GetAllRobotInfo(l.ctx, 0, 0)
	if err != nil {
		l.Logger.Error(err)
		return nil, err
	}

	for _, robotInfo := range robotInfos {
		if robotInfo.RobotStatus != 1 { // 非正常状态不更新
			l.Logger.Info("robot status not normal:", robotInfo.RobotStatus)
			continue
		}
		// TODO: 这里如果机器人信息表不维护升级状态，则需要在tb_robot_app_version 中维护、
		// 如果多个App可以独立更新，则不在这里维护升级状态，
		// 否则如果只能有一个app更新，则在这张表中维护升级状态
		// if robotInfo.UpgradeStatus == 2 || robotInfo.UpgradeStatus == 5 { // 升级中或回滚中，不更新
		// 	l.Logger.Info("robot upgrade status not normal:", robotInfo.UpgradeStatus)
		// 	continue
		// }
		if robotInfo.BatteryLevel < 10.0 { // 电量低于10％不更新
			l.Logger.Info("robot battery level not enough:", robotInfo.BatteryLevel)
			continue
		}
		if robotInfo.RobotIp == "" || robotInfo.RobotPort == 0 { // 机器人IP或端口为空不更新
			l.Logger.Info("robot ip or port is empty:", robotInfo.RobotIp, robotInfo.RobotPort)
			continue
		}
		// 拼装下发URL地址
		upgradeUrl := "http://" + robotInfo.RobotIp + ":" + cast.ToString(robotInfo.RobotPort) + global.HTTP_UPGRADE_URL
		// 发送升级请求
		code, msg, _, err := dhttp.SendHttpRequest(upgradeUrl, global.HTTP_METHOD_POST, nil, bodyVal)
		if err != nil {
			l.Logger.Error(err)
			//return nil, err  //下发失败了不退出，继续下发其他机器人
		}
		l.Logger.Info("robot upgrade request sent, code: ", code, ",msg: ", msg)
		// 当下发成功时，才更新表状态
		if code == 200 || code == 0 {
			// 更新当前机器人状态
			u := &models.TbRobotAppVersion{
				Version:         version,
				VersionDesc:     req.UpdateContent,
				FilePath:        dstFilePath,
				UpdateStatus:    2,
				Operator:        req.Operator,
				UpdateStartTime: time.Now(),
			}
			err = l.svcCtx.RobotAppVersionRepo.UpdateRobotAppVersion(l.ctx, robotInfo.RobotSn, req.AppName, u)
			if err != nil {
				l.Logger.Error(err)
				//return nil, err  //更新失败了不退出，继续下发其他机器人
			}
		}
		// 下发失败时，大概率原因是网络问题，不要更新表状态信息

		//l.Logger.Info("code: ", code, ",msg: ", msg, ",data: ", data)
	}
	l.Logger.Info("all robots upgrade request sent")

	return &types.UpgradeResponse{
		Code:    200,
		Message: version,
	}, nil
}
