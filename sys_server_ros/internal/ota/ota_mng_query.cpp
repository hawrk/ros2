/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 11:25:56
 * @Description: 
 * @FilePath: /sys_server/internal/ota/ota_mng_query.cpp
 */

#include "ota_mng_query.hpp"

using json = nlohmann::json;

OTAManagerQuery::OTAManagerQuery() {
    //app_manager_ = std::make_shared<OTAAppManager>();
}


bool OTAManagerQuery::parse_param() {
    try {
        nlohmann::json body = nlohmann::json::parse(body_str_);
        query_type_ = body["query_type"].get<int>();
        if(body.contains("app_name") && body["app_name"].is_string()) {
            app_name_ = body["app_name"].get<std::string>();
        }

        if(query_type_ == 2 && app_name_.empty()) {
            LOGE("in OTAManagerQuery, query_type 2 but app_name is empty");
            return false;
        }

    } catch(const std::exception& e) {
        LOGE("in OTAManagerQuery, Parse body error: %s", e.what());
        return false;
    }

    return true;
}

bool OTAManagerQuery::process() {
    LOGI("OTAManagerQuery,process start");

    // 1.检查入参
    if(!parse_param()) {
        LOGE("Check param Error");
        set_http_resp(ErrorCode::ERR_PARAM_INVALID, "");
        return false;
    }
    // 从sqlite3中获取数据
    auto& storage = Database::getInstance();
    json j = json::array();

    if(query_type_ == 1) {
        // 查询全部应用版本
        auto versions = storage.get_all<AppVersion>();
        LOGI("OTAManagerQuery, get all app version size:%d", versions.size());
        if (versions.empty()) {
            LOGE("in OTAManagerQuery, no app version data");
            set_http_resp(ErrorCode::ERR_APP_VERSION_NO_DATA, "");
            return false;
        }
        // 拼接所有数据返回json格式
        for(const auto& version : versions) {
            j.push_back({{"app_name", version.app_name}, {"version", version.version}});
        }

    } else if(query_type_ == 2) {
        // 查询指定应用版本
        // select * from app_version where app_name = app_name_;
        auto version = storage.get_all<AppVersion>(where(c(&AppVersion::app_name) == app_name_));
        if(version.empty()) {
            LOGE("in OTAManagerQuery, no app version data");
            set_http_resp(ErrorCode::ERR_APP_VERSION_NO_DATA, "");
            return false;
        }
        // 拼接所有数据返回json格式
        for(const auto& v : version) {
            j.push_back({{"app_name", v.app_name}, {"version", v.version}});
        }
    } else {
        LOGE("in OTAManagerQuery, query_type not support");
        set_http_resp(ErrorCode::ERR_PARAM_INVALID, "");
        return false;
    }

    set_http_resp(ErrorCode::SUCCESS, j.dump());
    return true;
}

