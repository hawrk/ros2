/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 10:13:49
 * @Description: 
 * @FilePath: /sys_server/internal/ota/ota_mng_rollback.hpp
 */
#pragma once

#include "../dsys_base.hpp"


class OTAManagerRollback :public DsysBase {
    public:
        OTAManagerRollback();
        bool process() override;

        bool parse_param() override;

        

private:
    std::string app_name_;
    std::string cur_version_;      // 当前版本
    std::string rollback_version_;  // 回滚版本
};