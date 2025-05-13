package handler

import (
	"net/http"

	"dcloud/internal/logic"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"github.com/zeromicro/go-zero/rest/httpx"
)

func OtaUpgradeHandler(svcCtx *svc.ServiceContext) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		var req types.UpgradeRequest
		if err := httpx.Parse(r, &req); err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
			return
		}

		l := logic.NewOtaUpgradeLogic(r.Context(), svcCtx)
		resp, err := l.OtaUpgrade(&req)
		if err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
		} else {
			httpx.OkJsonCtx(r.Context(), w, resp)
		}
	}
}
