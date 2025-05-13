/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 13:50:10
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 19:30:34
 * @Description:
 * @FilePath: /dcloud/global/constant.go
 */
// package global

package global

const (
	HTTP_METHOD_GET     = "GET"
	HTTP_METHOD_POST    = "POST"
	HTTP_METHOD_PUT     = "PUT"
	HTTP_METHOD_DELETE  = "DELETE"
	HTTP_METHOD_PATCH   = "PATCH"
	HTTP_METHOD_OPTIONS = "OPTIONS"

	// 机器人终端服务器URL地址
	HTTP_UPGRADE_URL  = "/api/v1/ota/upgrade"
	HTTP_ROLLBACK_URL = "/api/v1/ota/rollback"
	HTTP_QUERY_URL    = "/api/v1/ota/query"

	// 加密升级文件服务器地址
	FTP_URL       = "127.0.0.1:21"
	FTP_ROOT_PATH = "app_dir/"
	FTP_USER      = "anonymous"
	FTP_PASSWD    = ""

	AES_GCM_bufferSize = 8 * 1024 * 1024 // 8MB缓冲块 AES-GCM加密时使用
)
