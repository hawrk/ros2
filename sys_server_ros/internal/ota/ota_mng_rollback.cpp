/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 11:55:40
 * @Description: 
 * @FilePath: /sys_server_ros/internal/ota/ota_mng_rollback.cpp
 */

#include "ota_mng_rollback.hpp"

OTAManagerRollback::OTAManagerRollback() {
    //app_manager_ = std::make_shared<OTAAppManager>();
}

bool OTAManagerRollback::parse_param() {
    try {
        nlohmann::json body = nlohmann::json::parse(body_str_);
        if(body.contains("app_name") && body["app_name"].is_string()) {
            app_name_ = body["app_name"].get<std::string>();
        }
        if(body.contains("cur_version") && body["cur_version"].is_string()) {
            cur_version_ = body["cur_version"].get<std::string>();
        }
        if(body.contains("rollback_version") && body["rollback_version"].is_string()) {
            rollback_version_ = body["rollback_version"].get<std::string>();
        }
        if(app_name_.empty() || cur_version_.empty() || rollback_version_.empty()) {
            RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, app_name or cur_version or rollback_version is empty");
            //LOGE("in OTAManagerRollback, app_name or cur_version or rollback_version is empty");
            return false;
        }

    } catch(const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, Parse body error: %s", e.what());
        //LOGE("in OTAManagerRollback, Parse body error: %s", e.what());
        return false;
    }

    return true;
}

bool OTAManagerRollback::process() {
    RCLCPP_INFO(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, process start...");
    //LOGI("in OTAManagerRollback, process start...");
    // 1. 校验参数
    if(!parse_param()) {
        RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, parse_param error");
        //LOGE("in OTAManagerRollback, parse_param error");
        set_http_resp(ErrorCode::ERR_PARAM_INVALID, "");
        return false;
    }
    // 2. check确认一下当前版本号
    auto& storage = Database::getInstance();
    // select * from app_version where app_name = app_name_;
    auto version = storage.get_all<AppVersion>(where(c(&AppVersion::app_name) == app_name_));
    if(version.empty()) {
        RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, no app version data");
        //LOGE("in OTAManagerRollback, no app version data");
        set_http_resp(ErrorCode::ERR_APP_VERSION_NO_DATA, "");
        return false;
    }
    for(auto& v : version) {  // 原则上只有一条数据
        if(v.version != cur_version_) {  // 当前版本是否匹配
            RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, cur_version is not equal to current version");
            //LOGE("cur_version is not equal to current version");
            set_http_resp(ErrorCode::ERR_PARAM_INVALID, "");
            return false;
        }
        // 检查回滚版本是否存在
        // 回滚版本命名规则：{app_name}_v{version}
        std::string rollback_file = g_config_json["ota"]["backup_dir"].get<std::string>() + "/" 
            + app_name_ + "_v" + rollback_version_;
        RCLCPP_INFO(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, rollback_file: %s", rollback_file.c_str());
        //LOGI("rollback_file: %s", rollback_file.c_str());
        if(!std::filesystem::exists(rollback_file)) {
            RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "in OTAManagerRollback, rollback_file not exists");
            //LOGE("rollback_file not exists");
            set_http_resp(ErrorCode::ERR_ROLLBACK_FILE_NOT_EXIST, "");
            return false;
        }
        // 回滚版本存在，开始回滚
        // TODO:

    }

    set_http_resp(ErrorCode::SUCCESS, "success");
    return true;

}