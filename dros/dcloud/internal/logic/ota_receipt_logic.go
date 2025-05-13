/*
 * @Author: hawrkchen
 * @Date: 2025-03-13 16:40:44
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-26 10:05:55
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_receipt_logic.go
 */
package logic

import (
	"context"
	"time"

	"dcloud/internal/svc"
	"dcloud/internal/types"
	"dcloud/models"

	"github.com/zeromicro/go-zero/core/logx"
)

type OtaReceiptLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 上报升级结果
func NewOtaReceiptLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaReceiptLogic {
	return &OtaReceiptLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *OtaReceiptLogic) OtaReceipt(req *types.ReceiptRequest) (resp *types.ReceiptResponse, err error) {
	// todo: add your logic here and delete this line
	l.Logger.Infof("OtaReceipt, get req:%+v", req)
	switch req.Result {
	case 1, 2, 3, 4:
		// 升级成功、失败、回滚成功、回滚失败
	default:
		l.Logger.Errorf("OtaReceipt, req.Result:%d is invalid", req.Result)
		return &types.ReceiptResponse{
			Code:    1,
			Message: "req.Result is invalid",
		}, nil
	}

	// 更新机器人升级状态
	// if err := l.svcCtx.RobotInfoRepo.UpdateStatusBysn(l.ctx, req.RobotSn, l.StatusMapping(req.Result), req.Message, time.Time{}, time.Now(), ""); err != nil {
	// 	l.Logger.Errorf("OtaReceipt, update robot status error:%+v", err)
	// 	return &types.ReceiptResponse{
	// 		Code:    1,
	// 		Message: "update robot status error",
	// 	}, nil
	// }
	//更新tb_robot_app_version表
	// 更新当前机器人状态
	u := &models.TbRobotAppVersion{
		UpdateStatus:  l.StatusMapping(req.Result),
		UpdateLogs:    req.Message,
		Operator:      "sys_server",
		UpdateEndTime: time.Now(),
	}
	if err := l.svcCtx.RobotAppVersionRepo.UpdateRobotAppVersion(l.ctx, req.RobotSn, req.AppName, u); err != nil {
		l.Logger.Errorf("OtaReceipt, update robot app version error:%+v", err)
		return &types.ReceiptResponse{
			Code:    1,
			Message: "update robot app version error",
		}, nil
	}
	return &types.ReceiptResponse{
		Code:    0,
		Message: "success",
	}, nil

}

func (l *OtaReceiptLogic) StatusMapping(result int) int {
	statusMap := map[int]int{
		1: 3, // 升级成功
		2: 4, // 升级失败
		3: 6, // 回滚成功
		4: 7, // 回滚失败
	}
	return statusMap[result]
}
