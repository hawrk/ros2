/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 10:26:40
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-19 13:52:55
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_robot_query_logic.go
 */
package logic

import (
	"context"

	"dcloud/internal/svc"
	"dcloud/internal/types"
	"dcloud/models"

	"github.com/spf13/cast"
	"github.com/zeromicro/go-zero/core/logx"
)

type OtaRobotQueryLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 查询机器人信息
func NewOtaRobotQueryLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaRobotQueryLogic {
	return &OtaRobotQueryLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *OtaRobotQueryLogic) OtaRobotQuery(req *types.RobotQryRequest) (resp *types.RobotQryResponse, err error) {
	// todo: add your logic here and delete this line
	l.Logger.Infof("query robot info, req: %+v", req)

	// 查询机器人信息
	var robotList []*models.TbRobotInfos
	if req.RobotSn == "" {
		robotList, err = l.svcCtx.RobotInfoRepo.GetAllRobotInfo(l.ctx, req.Page, req.Limit)
		if err != nil {
			return nil, err
		}
		// 组装返回数据
		resp = &types.RobotQryResponse{
			Code:    0,
			Message: "success",
			List:    make([]types.RobotInfo, 0), // 机器人信息列表
		}
		for _, robot := range robotList {
			robotInfo := types.RobotInfo{
				RobotSn:         robot.RobotSn,
				RobotName:       robot.RobotName,
				RobotType:       robot.RobotType,
				FirmwareVersion: robot.FirmwareVersion,
				Region:          robot.Region,
				RobotIp:         robot.RobotIp,
				RobotPort:       robot.RobotPort,
				Address:         robot.Address,
				BatteryLevel:    cast.ToString(robot.BatteryLevel),
				CurVersion:      robot.CurVersion,
				RobotStatus:     robot.RobotStatus,
				ErrLogs:         robot.ErrLogs,
				Operator:        robot.Operator,
			}
			resp.List = append(resp.List, robotInfo)
		}
	} else {
		robot, err := l.svcCtx.RobotInfoRepo.GetRobotInfoBySn(l.ctx, req.RobotSn)
		if err != nil {
			return nil, err
		}
		// 组装返回数据
		resp = &types.RobotQryResponse{
			Code:    0,
			Message: "success",
			List:    make([]types.RobotInfo, 0), // 机器人信息列表
		}
		robotInfo := types.RobotInfo{
			RobotSn:         robot.RobotSn,
			RobotName:       robot.RobotName,
			RobotType:       robot.RobotType,
			FirmwareVersion: robot.FirmwareVersion,
			Region:          robot.Region,
			RobotIp:         robot.RobotIp,
			RobotPort:       robot.RobotPort,
			Address:         robot.Address,
			BatteryLevel:    cast.ToString(robot.BatteryLevel),
			CurVersion:      robot.CurVersion,
			RobotStatus:     robot.RobotStatus,
			ErrLogs:         robot.ErrLogs,
			Operator:        robot.Operator,
		}
		resp.List = append(resp.List, robotInfo)
	}

	return
}
