/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 10:13:49
 * @Description: 
 * @FilePath: /sys_server/internal/ota/ota_mng_query.hpp
 */
#pragma once

#include "../dsys_base.hpp"

class OTAManagerQuery : public DsysBase {
    public:
        OTAManagerQuery();

        bool process() override;

        bool parse_param() override;

private:
    int query_type_;    // 查询类型
    std::string app_name_;   // 应用名称
   
};