/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 10:26:40
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-18 16:11:57
 * @Description:
 * @FilePath: /dcloud/internal/logic/ota_version_query_logic.go
 */
package logic

import (
	"context"

	"dcloud/internal/svc"
	"dcloud/internal/types"

	"github.com/zeromicro/go-zero/core/logx"
)

type OtaVersionQueryLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 查询程序应用的版本信息
func NewOtaVersionQueryLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaVersionQueryLogic {
	return &OtaVersionQueryLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *OtaVersionQueryLogic) OtaVersionQuery(req *types.AppVersionQryRequest) (resp *types.AppVersionQryResponse, err error) {
	// todo: add your logic here and delete this line
	l.Logger.Infof("OtaVersionQuery: %+v", req)

	// 查询程序应用的版本信息
	list, err := l.svcCtx.AppVersionRepo.GetAppVersion(l.ctx, req.AppName, req.Page, req.Limit)
	if err != nil {
		l.Logger.Error("GetAppVersion error: %v", err)
		return nil, err
	}

	// 组装返回数据
	resp = &types.AppVersionQryResponse{
		Code:    0,
		Message: "success",
		List:    make([]types.AppVersionInfo, 0, len(list)),
	}
	for _, item := range list {
		resp.List = append(resp.List, types.AppVersionInfo{
			AppName:     item.AppName,
			Version:     item.AppVersion,
			VersionDesc: item.VersionDesc,
			PkgName:     item.PkgName,
			Operator:    item.OpUser,
			CreateTime:  item.CreateTime.Format("2006-01-02 15:04:05"),
		})
	}

	return resp, nil
}
