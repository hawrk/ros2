package logic

import (
	"context"

	"dcloud/internal/svc"
	"dcloud/internal/types"

	"github.com/zeromicro/go-zero/core/logx"
)

type OtaHistoryQueryLogic struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

// 程序升级历史查询
func NewOtaHistoryQueryLogic(ctx context.Context, svcCtx *svc.ServiceContext) *OtaHistoryQueryLogic {
	return &OtaHistoryQueryLogic{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *OtaHistoryQueryLogic) OtaHistoryQuery(req *types.UpgradeHistoryQryRequest) (resp *types.UpgradeHistoryQryResponse, err error) {
	// todo: add your logic here and delete this line

	return
}
