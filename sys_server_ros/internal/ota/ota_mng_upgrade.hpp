/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 10:13:20
 * @Description: 
 * @FilePath: /sys_server/internal/ota/ota_mng_upgrade.hpp
 */
#pragma once

#include "../dsys_base.hpp"
#include "../../common/curl_manager.hpp"

#include <memory>

class OTAManagerUpgrade :public DsysBase, public std::enable_shared_from_this<OTAManagerUpgrade> {
    public:
        OTAManagerUpgrade();
        bool process() override;

        bool parse_param() override;

        // 返回下载的包大小
        int32_t get_upgrade_pkg(const std::string& url);
    
    private:
        // 更新本地版本状态信息
        void update_status(Storage &storage,int status, const std::string& msg);

        // http 发送更新结果
        void send_http_upgrade_result(const std::string& robot_sn, const std::string& app_name, 
            int ret_code, const std::string& msg);


    private:
        //std::shared_ptr<CurlLib> curl_lib_;
        CurlManager curl_mngr_;

        std::string app_name_;
        std::string version_;
        std::string url_;
        std::string robot_sn_;

        std::string local_file_;
        long long avaiable_space_size_;
    
   
};