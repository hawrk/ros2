/*
 * @Author: hawrkchen
 * @Date: 2025-03-18 10:26:40
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-18 15:10:22
 * @Description:
 * @FilePath: /dcloud/internal/handler/ota_version_query_handler.go
 */
package handler

import (
	"net/http"

	"dcloud/internal/logic"
	"dcloud/internal/svc"
	"dcloud/internal/types"

	"github.com/zeromicro/go-zero/rest/httpx"
)

// 查询单个机器人的版本信息
func OtaVersionQueryHandler(svcCtx *svc.ServiceContext) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		var req types.AppVersionQryRequest
		if err := httpx.Parse(r, &req); err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
			return
		}

		l := logic.NewOtaVersionQueryLogic(r.Context(), svcCtx)
		resp, err := l.OtaVersionQuery(&req)
		if err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
		} else {
			httpx.OkJsonCtx(r.Context(), w, resp)
		}
	}
}
