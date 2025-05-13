/*
 * @Author: hawrkchen
 * @Date: 2024-12-12 14:13:10
 * @Description: 
 * @FilePath: /sys_server_ros/handler/sys_handler.hpp
 */
#pragma once

#include <rclcpp/rclcpp.hpp>

#include "hv/HttpService.h"
#include "../internal/dsys_base.hpp"
//#include "../internal/omni_factory.hpp"

#include "../internal/ota/ota_mng_query.hpp"
#include "../internal/ota/ota_mng_upgrade.hpp"
#include "../internal/ota/ota_mng_rollback.hpp"

class DHttpHandler  {
    public:

        DHttpHandler() = default;


        static int preprocessor(HttpRequest* req, HttpResponse* res);
        static  int error_handler(const HttpContextPtr& ctx);

        // middleware
        static int auth_middleware(HttpRequest* req, HttpResponse* res);


        // ----------business logic----------------
        // ota upgrade
        static int ota_upgrade_handler(HttpRequest* req, HttpResponse* res);

        // ota query
        static int ota_query_handler(HttpRequest* req, HttpResponse* res);

        // ota rollback
        static int ota_rollback_handler(HttpRequest* req, HttpResponse* res);



    private:
        static  int response_status(const HttpContextPtr& ctx, int code = 200, const char* message =  nullptr);

        static  int response_status(const HttpResponseWriterPtr& writer, int code = 200, const char* message = nullptr);

        static  int response_status(HttpResponse* res, int code = 200, const char* message = nullptr, const char* data = nullptr);

};