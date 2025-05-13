/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 10:26:40
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-24 15:28:36
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_manual_upgrade_logic.go
 */
package logic

import (
	"context"
	"time"

	"dcloud/global"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"dcloud/pkg/dftp"
	"dcloud/pkg/dhttp"

	"github.com/spf13/cast"
	"github.com/zeromicro/go-zero/core/logx"
)

type OtaManualUpgradeLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 手动触发升级
func NewOtaManualUpgradeLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaManualUpgradeLogic {
	return &OtaManualUpgradeLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

// OtaManualUpgrade 手动触发升级
func (l *OtaManualUpgradeLogic) OtaManualUpgrade(req *types.ManualUpgradeRequest) (resp *types.ManualUpgradeResponse, err error) {
	// todo: add your logic here and delete this line
	l.Logger.Infof("OtaManualUpgrade, req:%+v", req)
	// 查询机器人程序版本信息表,判断是否有该程序版本
	robotAppVersion, err := l.svcCtx.RobotAppVersionRepo.GetRobotAppVersionByAppName(l.ctx, req.RobotSn, req.AppName)
	if err != nil {
		l.Logger.Error("GetRobotAppVersionByAppName error:%+v", err)
		return
	}
	if robotAppVersion.FilePath == "" {
		l.Logger.Error("robotAppVersion is nil or FilePath is empty")
		return
	}
	// 根据 file_url 查询ftp服务器是否有该文件
	exist, err := dftp.CheckFileExist(robotAppVersion.FilePath, global.FTP_URL)
	if err != nil {
		l.Logger.Error("CheckFileExist error:%+v", err)
		return &types.ManualUpgradeResponse{
			Code:    -1,
			Message: "CheckFileExist error",
			Result:  0,
		}, nil
	}
	if !exist {
		l.Logger.Error("file not exist in ftp server")
		return &types.ManualUpgradeResponse{
			Code:    -1,
			Message: "file not exist in ftp server",
			Result:  0,
		}, nil
	}
	// 存在，检查目标机器人是否正常
	robotInfo, err := l.svcCtx.RobotInfoRepo.GetRobotInfoBySn(l.ctx, req.RobotSn)
	if err != nil {
		l.Logger.Error(err)
		return nil, err
	}

	if robotInfo.RobotStatus != 1 || robotInfo.UpgradeStatus == 2 || robotInfo.UpgradeStatus == 5 ||
		robotInfo.BatteryLevel < 10.0 || robotInfo.RobotIp == "" || robotInfo.RobotPort == 0 {
		l.Logger.Info("robot status not normal:", robotInfo.RobotStatus, robotInfo.UpgradeStatus,
			robotInfo.BatteryLevel, robotInfo.RobotIp, robotInfo.RobotPort)

		return &types.ManualUpgradeResponse{
			Code:    -1,
			Message: "robot status not normal",
			Result:  0,
		}, nil
	}

	bodyVal := map[string]any{
		"version":  robotAppVersion.Version,
		"address":  robotAppVersion.FilePath,
		"md5":      "1234567890",
		"app_name": req.AppName,
	}
	// 拼装下发URL地址
	upgradeUrl := "http://" + robotInfo.RobotIp + ":" + cast.ToString(robotInfo.RobotPort) + global.HTTP_UPGRADE_URL
	// 发送升级请求
	code, msg, _, err := dhttp.SendHttpRequest(upgradeUrl, global.HTTP_METHOD_POST, nil, bodyVal)
	if err != nil {
		l.Logger.Error(err)
		return nil, err
	}
	// 当下发成功时，才更新表状态
	if code == 200 || code == 0 {
		// 更新当前机器人状态
		err = l.svcCtx.RobotInfoRepo.UpdateStatusBysn(l.ctx, robotInfo.RobotSn, 2, msg, time.Now(), time.Time{}, req.Operator)
		if err != nil {
			l.Logger.Error(err)
			return nil, err
		}
	}
	return &types.ManualUpgradeResponse{
		Code:    0,
		Message: msg,
		Result:  1,
	}, nil
}
