/*
 * @Author: hawrkchen
 * @Date: 2024-12-12 13:55:59
 * @Description: 
 * @FilePath: /sys_server/handler/router.cpp
 */


#include "router.hpp"
#include "sys_handler.hpp"

void Router::RegisterRoutes(hv::HttpService& router) 
{
    router.preprocessor = DHttpHandler::preprocessor;

    router.Use(DHttpHandler::auth_middleware);

    // ---------------OTA---------------
    // ota upgrade
    router.POST("/api/v1/ota/upgrade", DHttpHandler::ota_upgrade_handler);

    // ota query
    router.POST("/api/v1/ota/query", DHttpHandler::ota_query_handler);

    // ota rollback
    router.POST("/api/v1/ota/rollback", DHttpHandler::ota_rollback_handler);

    // ---------------Others-
}