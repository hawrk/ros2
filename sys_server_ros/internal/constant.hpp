/*
 * @Author: hawrkchen
 * @Date: 2025-03-04 15:54:26
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-26 10:44:51
 * @Description: 
 * @FilePath: /sys_server/internal/constant.hpp
 */

#pragma once

#include <cstdint>
#include <nlohmann/json.hpp>

extern nlohmann::json g_config_json;

//extern sqlite_orm::internal::storage_t<decltype(app_version_table), decltype(robot_status_table)>  g_storage;

namespace constant {
    constexpr long long MIN_AVAILABLE_SPACE = 500 * 1024 * 1024; // 500MB minimum available space

    constexpr const size_t CHUNK_SIZE = 8*1024*1024; // 8MB chunks for aes GCM encryption

    constexpr const char* SQLITE3_DB_PATH = "/home/hawrk/sqlite3/robot.db";

    constexpr const char* DCLOUD_URL = "http://127.0.0.1:8866/api/v1/ota/receipt";


} // namespace constant

