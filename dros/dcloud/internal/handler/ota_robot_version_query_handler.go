package handler

import (
	"net/http"

	"dcloud/internal/logic"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"github.com/zeromicro/go-zero/rest/httpx"
)

// 查询机器人程序版本信息
func OtaRobotVersionQueryHandler(svcCtx *svc.ServiceContext) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		var req types.RobotVersionQryRequest
		if err := httpx.Parse(r, &req); err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
			return
		}

		l := logic.NewOtaRobotVersionQueryLogic(r.Context(), svcCtx)
		resp, err := l.OtaRobotVersionQuery(&req)
		if err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
		} else {
			httpx.OkJsonCtx(r.Context(), w, resp)
		}
	}
}
