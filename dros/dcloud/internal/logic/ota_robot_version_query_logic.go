/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 15:09:39
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-26 10:03:34
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_robot_version_query_logic.go
 */
package logic

import (
	"context"
	"encoding/json"
	"errors"
	"time"

	"dcloud/global"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"dcloud/models"
	"dcloud/pkg/dhttp"

	"github.com/spf13/cast"
	"github.com/zeromicro/go-zero/core/logx"
)

type OtaRobotVersionQueryLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 查询机器人程序版本信息
func NewOtaRobotVersionQueryLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaRobotVersionQueryLogic {
	return &OtaRobotVersionQueryLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

// 查询机器人程序版本信息，同步机器人终端版本
func (l *OtaRobotVersionQueryLogic) OtaRobotVersionQuery(req *types.RobotVersionQryRequest) (resp *types.RobotVersionQryResponse, err error) {
	// todo: add your logic here and delete this line
	l.Logger.Infof("OtaRobotVersionQuery: %+v", req)

	// 这里查询分两种，一种是直接查询本地机器人程序版本信息，从表中获取即可
	// 另一种是查询远程机器人程序版本信息，需要通过网络请求获取，然后同步到本地数据库中
	if req.QueryType == 1 {
		// 先根据 robot_sn 查询机器人IP信息
		list, err := l.svcCtx.RobotAppVersionRepo.GetRobotAppVersion(l.ctx, req.RobotSn, req.AppName)
		if err != nil {
			l.Logger.Errorf("OtaRobotVersionQuery: get robot app version failed: %s", err.Error())
			return nil, err
		}
		resp = &types.RobotVersionQryResponse{
			Code:    0,
			Message: "success",
			List:    make([]types.RobotVersionInfo, 0),
		}

		for _, item := range list {
			// 根据 app_name 查询 app 版本信息
			// appVersion, err := l.svcCtx.AppVersionRepo.GetLatestVersion(l.ctx, item.AppName)
			// if err != nil {
			// 	l.Logger.Errorf("OtaRobotVersionQuery: get app version failed: %s", err.Error())
			// 	return nil, err
			// }
			// 组装返回数据
			resp.List = append(resp.List, types.RobotVersionInfo{
				Id:              cast.ToInt64(item.Id),
				RobotSn:         item.RobotSn,
				AppType:         item.AppType,
				Version:         item.Version,
				VersionDesc:     item.VersionDesc,
				FilePath:        item.FilePath,
				AppName:         item.AppName,
				UpdateStatus:    item.UpdateStatus,
				UpdateLogs:      item.UpdateLogs,
				UpdateStartTime: item.UpdateStartTime.Format("2006-01-02 15:04:05"),
				UpdateEndTime:   item.UpdateEndTime.Format("2006-01-02 15:04:05"),
				Operator:        item.Operator,
			})
		}

		return resp, nil

	} else if req.QueryType == 2 {
		// 先根据 robot_sn 查询机器人IP信息
		robot, err := l.svcCtx.RobotInfoRepo.GetRobotInfoBySn(l.ctx, req.RobotSn)
		if err != nil {
			l.Logger.Errorf("OtaRobotVersionQuery: get robot info failed: %s", err.Error())
			return nil, err
		}
		if robot.RobotIp == "" || robot.RobotPort == 0 {
			l.Logger.Errorf("OtaRobotVersionQuery: robot ip or port is empty: %s", req.RobotSn)
			return nil, errors.New("robot ip or port is empty")
		}
		// 拼BODY
		var bodyVal = make(map[string]any)
		if req.AppName == "" {
			bodyVal["query_type"] = 1
		} else {
			bodyVal["app_name"] = req.AppName
			bodyVal["query_type"] = 2
		}

		// 拼装下发URL地址
		queryUrl := "http://" + robot.RobotIp + ":" + cast.ToString(robot.RobotPort) + global.HTTP_QUERY_URL
		// 发送升级请求
		code, msg, data, err := dhttp.SendHttpRequest(queryUrl, global.HTTP_METHOD_POST, nil, bodyVal)
		if err != nil {
			l.Logger.Error(err)
			return nil, err
		}
		if code != 0 {
			l.Logger.Errorf("OtaRobotVersionQuery: query robot version failed: %s", msg)
			return nil, errors.New(msg)
		}
		// 解析返回数据
		// TODO: 不是这种返回类型，待后端定义
		var infos []types.RobotVersionInfo
		err = json.Unmarshal([]byte(data), &infos)
		if err != nil {
			l.Logger.Error(err)
			return nil, err
		}
		// 遍历返回数据，更新本地数据库
		layout := "2006-01-02 15:04:05"
		for _, item := range infos {
			// 更新本地数据库
			st, _ := time.Parse(layout, item.UpdateStartTime)
			et, _ := time.Parse(layout, item.UpdateEndTime)
			u := &models.TbRobotAppVersion{
				AppType:         item.AppType,
				Version:         item.Version,
				VersionDesc:     item.VersionDesc,
				FilePath:        item.FilePath,
				UpdateStatus:    item.UpdateStatus,
				UpdateLogs:      item.UpdateLogs,
				UpdateStartTime: st,
				UpdateEndTime:   et,
				Operator:        item.Operator,
			}
			err = l.svcCtx.RobotAppVersionRepo.UpdateRobotAppVersion(l.ctx, robot.RobotSn, item.AppName, u)
			if err != nil {
				l.Logger.Error(err)
				return nil, err
			}
		}
		// 统一返回
		list, err := l.svcCtx.RobotAppVersionRepo.GetRobotAppVersion(l.ctx, req.RobotSn, req.AppName)
		if err != nil {
			l.Logger.Errorf("OtaRobotVersionQuery: get robot app version failed: %s", err.Error())
			return nil, err
		}
		resp = &types.RobotVersionQryResponse{
			Code:    0,
			Message: "success",
			List:    make([]types.RobotVersionInfo, 0),
		}

		for _, item := range list {
			resp.List = append(resp.List, types.RobotVersionInfo{
				Id:              cast.ToInt64(item.Id),
				RobotSn:         item.RobotSn,
				AppType:         item.AppType,
				Version:         item.Version,
				VersionDesc:     item.VersionDesc,
				FilePath:        item.FilePath,
				AppName:         item.AppName,
				UpdateStatus:    item.UpdateStatus,
				UpdateLogs:      item.UpdateLogs,
				UpdateStartTime: item.UpdateStartTime.Format("2006-01-02 15:04:05"),
				UpdateEndTime:   item.UpdateEndTime.Format("2006-01-02 15:04:05"),
				Operator:        item.Operator,
			})
		}
		return resp, nil

	} else {
		l.Logger.Errorf("OtaRobotVersionQuery: unsupported query type: %d", req.QueryType)
		return nil, errors.New("unsupported query type")
	}

}
