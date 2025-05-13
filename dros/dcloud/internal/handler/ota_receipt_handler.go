package handler

import (
	"net/http"

	"dcloud/internal/logic"
	"dcloud/internal/svc"
	"dcloud/internal/types"
	"github.com/zeromicro/go-zero/rest/httpx"
)

// 上报升级结果
func OtaReceiptHandler(svcCtx *svc.ServiceContext) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		var req types.ReceiptRequest
		if err := httpx.Parse(r, &req); err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
			return
		}

		l := logic.NewOtaReceiptLogic(r.Context(), svcCtx)
		resp, err := l.OtaReceipt(&req)
		if err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
		} else {
			httpx.OkJsonCtx(r.Context(), w, resp)
		}
	}
}
