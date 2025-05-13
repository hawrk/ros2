package handler

import (
	"net/http"

	"dcloud/internal/logic"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"github.com/zeromicro/go-zero/rest/httpx"
)

// 手动触发升级
func OtaManualUpgradeHandler(svcCtx *svc.ServiceContext) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		var req types.ManualUpgradeRequest
		if err := httpx.Parse(r, &req); err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
			return
		}

		l := logic.NewOtaManualUpgradeLogic(r.Context(), svcCtx)
		resp, err := l.OtaManualUpgrade(&req)
		if err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
		} else {
			httpx.OkJsonCtx(r.Context(), w, resp)
		}
	}
}
