/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 10:26:40
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 09:06:12
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_rollback_logic.go
 */
package logic

import (
	"context"

	"dcloud/global"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"dcloud/pkg/dhttp"

	"github.com/spf13/cast"
	"github.com/zeromicro/go-zero/core/logx"
)

type OtaRollbackLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 回滚请求
func NewOtaRollbackLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaRollbackLogic {
	return &OtaRollbackLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

// OtaRollback 程序版本回滚
func (l *OtaRollbackLogic) OtaRollback(req *types.RollbackRequest) (resp *types.RollbackResponse, err error) {
	// todo: add your logic here and delete this line
	l.Logger.Infof("rollback request: %+v", req)
	// 目前回滚操作只支持回滚到上一个版本，不支持回滚到指定版本
	// 机器人终端出于容量考虑，只保存上一个版本的备份，历史备份会全部清除，
	// 机器人终端接受指令，直接使用上一个备份版本，不需要重新下载
	// 如果需要回滚到指定版本，调用手动升级接口
	if req.RollbackType == 1 { // 全量回滚
		robots, err := l.svcCtx.RobotInfoRepo.GetNormalRobotInfo(l.ctx)
		if err != nil {
			l.Logger.Error("获取机器人信息失败")
			return &types.RollbackResponse{
				Code:    1,
				Message: "获取机器人信息失败",
				Result:  0,
			}, nil
		}

		for _, rob := range robots {
			if rob.RobotIp == "" || rob.RobotPort == 0 { // 机器人IP或端口为空，不需要回滚
				l.Logger.Error("机器人IP或端口为空,回滚失败")
				continue
			}
			//查询机器人程序版本信息表，校验版本号
			appVersion, err := l.svcCtx.RobotAppVersionRepo.GetRobotAppVersionByAppName(l.ctx, req.RobotSn, req.AppName)
			if err != nil {
				l.Logger.Errorf("获取机器人程序版本信息失败, err: %v", err)
				continue // 继续处理下一个机器人

			}
			if req.RollbackVersion == appVersion.Version { // 回滚版本与当前版本相同，不需要回滚
				l.Logger.Errorf("当前版本%s 与回滚版本%s相同,不需要回滚", appVersion.Version, req.RollbackVersion)
				continue
			}
			// 调用机器人终端接口，回滚到上一个版本
			// 1. 发送回滚指令
			// 2. 等待回滚完成
			// 3. 回滚成功，更新机器人状态
			// 4. 回滚失败，更新机器人状态
			// 5. 返回回滚结果
			// 调用 http api 升级
			bodyVal := map[string]any{
				"version":  req.RollbackVersion,
				"app_name": req.AppName,
			}
			// 拼装下发URL地址
			upgradeUrl := "http://" + rob.RobotIp + ":" + cast.ToString(rob.RobotPort) + global.HTTP_ROLLBACK_URL
			// 发送升级请求
			code, msg, data, err := dhttp.SendHttpRequest(upgradeUrl, global.HTTP_METHOD_POST, nil, bodyVal)
			if err != nil {
				l.Logger.Error(err)
				//return nil, err  //下发失败了不退出，继续下发其他机器人
			}
			l.Logger.Info("下发回滚请求成功, code: %d, msg: %s, data: %s", code, msg, data)
			// 当下发成功时，才更新表状态
			if code == 200 || code == 0 {
				// 更新当前机器人状态
				err = l.svcCtx.RobotAppVersionRepo.UpdateRobotAppStatus(l.ctx, appVersion.RobotSn, appVersion.AppName, 6)
				if err != nil {
					l.Logger.Error(err)
					//return nil, err  //更新失败了不退出，继续下发其他机器人
				}
			} else {
				err = l.svcCtx.RobotAppVersionRepo.UpdateRobotAppStatus(l.ctx, appVersion.RobotSn, appVersion.AppName, 7)
				if err != nil {
					l.Logger.Error(err)
					//return nil, err  //更新失败了不退出，继续下发其他机器人
				}
			}

		}

	} else if req.RollbackType == 2 { // 指定机器回滚
		rob, err := l.svcCtx.RobotInfoRepo.GetRobotInfoBySn(l.ctx, req.RobotSn) // 查询机器人信息
		if err != nil {
			l.Logger.Error("获取机器人信息失败")
			return &types.RollbackResponse{
				Code:    1,
				Message: "获取机器人信息失败",
				Result:  0,
			}, nil
		}
		if rob.RobotIp == "" || rob.RobotPort == 0 ||
			rob.BatteryLevel < 10.0 || rob.RobotStatus != 1 { // 状态异常，不需要回滚
			return &types.RollbackResponse{
				Code:    1,
				Message: "机器人状态异常，回滚失败",
				Result:  0,
			}, nil
		}
		// 查询机器人程序版本信息表，校验版本号
		appVersion, err := l.svcCtx.RobotAppVersionRepo.GetRobotAppVersionByAppName(l.ctx, req.RobotSn, req.AppName)
		if err != nil {
			l.Logger.Error("获取机器人程序版本信息失败")
			return &types.RollbackResponse{
				Code:    1,
				Message: "获取机器人程序版本信息失败",
				Result:  0,
			}, nil
		}
		l.Logger.Infof("当前版本:[%s], 回滚版本:[%s]", appVersion.Version, req.RollbackVersion)
		if req.CurVersion != appVersion.Version { // 当前版本与回滚版本不匹配
			return &types.RollbackResponse{
				Code:    1,
				Message: "当前版本与系统版本不匹配",
				Result:  0,
			}, nil
		}
		if req.RollbackVersion == appVersion.Version { // 回滚版本与当前版本相同，不需要回滚
			return &types.RollbackResponse{
				Code:    1,
				Message: "回滚版本与当前版本相同，不需要回滚",
				Result:  0,
			}, nil
		}
		// 调用机器人终端接口，回滚到指定版本
		// 1. 发送回滚指令
		// 2. 等待回滚完成
		// 3. 回滚成功，更新机器人状态
		// 4. 回滚失败，更新机器人状态
		// 5. 返回回滚结果
		// 调用 http api 升级
		bodyVal := map[string]any{
			"app_name":         req.AppName,
			"cur_version":      appVersion.Version,
			"rollback_version": req.RollbackVersion,
		}
		// 拼装下发URL地址
		upgradeUrl := "http://" + rob.RobotIp + ":" + cast.ToString(rob.RobotPort) + global.HTTP_ROLLBACK_URL
		// 发送升级请求
		code, msg, data, err := dhttp.SendHttpRequest(upgradeUrl, global.HTTP_METHOD_POST, nil, bodyVal)
		if err != nil {
			l.Logger.Error(err)
			return &types.RollbackResponse{
				Code:    1,
				Message: "下发回滚请求失败",
				Result:  0,
			}, nil
		}
		l.Logger.Infof("下发回滚请求成功, code: %d, msg: %s, data: %s", code, msg, data)
		// 当下发成功时，才更新表状态
		if code == 200 || code == 0 {
			// 更新当前机器人状态
			err = l.svcCtx.RobotAppVersionRepo.UpdateRobotAppStatus(l.ctx, appVersion.RobotSn, appVersion.AppName, 6)
			if err != nil {
				l.Logger.Error(err)
				return &types.RollbackResponse{
					Code:    1,
					Message: "回滚成功，更新机器人状态失败",
					Result:  0,
				}, nil
			}
		} else {
			err = l.svcCtx.RobotAppVersionRepo.UpdateRobotAppStatus(l.ctx, appVersion.RobotSn, appVersion.AppName, 7)
			if err != nil {
				l.Logger.Error(err)
				return &types.RollbackResponse{
					Code:    1,
					Message: "更新机器人状态失败",
					Result:  0,
				}, nil
			}
			return &types.RollbackResponse{
				Code:    int(code),
				Message: msg,
				Result:  0,
			}, nil
		}

	} else {
		l.Logger.Error("回滚类型错误")
		return &types.RollbackResponse{
			Code:    1,
			Message: "回滚类型错误",
			Result:  0,
		}, nil
	}

	return &types.RollbackResponse{
		Code:    0,
		Message: "回滚成功",
		Result:  1, // 回滚成功
	}, nil
}
