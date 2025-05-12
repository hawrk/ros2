/*
 * @Author: hawrkchen
 * @Date: 2025-03-03 16:21:50
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 11:05:26
 * @Description: 
 * @FilePath: /sys_server/internal/err_code.hpp
 */
#pragma once

#include <iostream>
#include <unordered_map>

// 10000-19999 公共错误码
// 20000-29999 OTA服务错误码
// 30000-39999 诊断服务错误码
// 40000-49999 others...
#define ERROR_CODE_MAP(EX) \
    EX(200, SUCCESS, "success") \
    EX(10001, ERR_PARAM_INVALID, "parameter invalid") \
    EX(10002, ERR_FILE_NOT_EXIST, "file not exist") \
    EX(10003, ERR_FILE_OPEN_FAILED, "file open failed") \
    EX(10004, ERR_FILE_WRITE_FAILED, "file write failed") \
    EX(10005, ERR_FILE_READ_FAILED, "file read failed") \
    EX(10006, ERR_SYS_SPACE_NOT_ENOUGH, "system space not enough") \
    EX(10007, ERR_DOWNLOAD_PKG_FAILED, "download package failed") \
    EX(10008, ERR_EXTRACT_PKG_FAILED, "extract package failed") \
    EX(10009, ERR_STOP_APP_FAILED, "stop app failed") \
    EX(10010, ERR_BACKUP_APP_FAILED, "backup appfailed") \
    EX(10011, ERR_REPLACE_APP_FAILED, "replace app failed") \
    EX(10012, ERR_APP_VERSION_NO_DATA, "app version no data") \
    EX(10013, ERR_ROLLBACK_FILE_NOT_EXIST, "rollback file not exist") \
    EX(20001, ERR_OTA_INIT_FAILED, "OTA init failed") \
    EX(20002, ERR_OTA_DOWNLOAD_FAILED, "OTA download failed") \
    EX(30001, ERR_DIAG_INIT_FAILED, "diag init failed")


enum class ErrorCode {
#define EX(num, name, string) name = num,
     ERROR_CODE_MAP(EX)
#undef EX
};

static inline const std::string& get_err_msg(ErrorCode code) {
    static std::unordered_map<ErrorCode, std::string> error_message_map = {
#define EX(num, name, string) {ErrorCode::name, string},
         ERROR_CODE_MAP(EX)
#undef EX
    };
    return error_message_map[code];
}