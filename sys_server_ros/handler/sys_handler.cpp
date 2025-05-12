/*
 * @Author: hawrkchen
 * @Date: 2024-12-12 14:13:16
 * @Description: 
 * @FilePath: /sys_server/handler/sys_handler.cpp
 */

#include "sys_handler.hpp"


int DHttpHandler::preprocessor(HttpRequest* req, HttpResponse* res) 
{
    req->ParseBody();

    res->content_type = APPLICATION_JSON;

    return HTTP_STATUS_NEXT;
}

int DHttpHandler::error_handler(const HttpContextPtr& ctx)
{
    int err_code = ctx->response->status_code;
    return response_status(ctx, err_code);
}

// middleware
int DHttpHandler::auth_middleware(HttpRequest* req, HttpResponse* res)
{
    // TODO: implement authentication middleware
    // 公共接口前置校验
    if(req->content_type != APPLICATION_JSON) {
        return response_status(res, HTTP_STATUS_BAD_REQUEST, "Unsupported protocol Type");
    }
    return HTTP_STATUS_NEXT;
}


int DHttpHandler::ota_upgrade_handler(HttpRequest* req, HttpResponse* res)
{
    // print the request body
    hv::Json body_json = req->GetJson();
    LOGI("OTA request body:%s", body_json.dump().c_str());
    //
    
    //std::unique_ptr<DsysBase> task = std::make_unique<OTAManagerUpgrade>();
    std::shared_ptr<DsysBase> task = std::make_shared<OTAManagerUpgrade>();
    task->set_body_str(body_json.dump());

    // 应用主控
    task->process();

    auto [code, message, data] = task->get_http_resp();
    LOGI("OTA response:%d, %s, %s", code, message.c_str(), data.c_str());
    response_status(res, code, message.c_str(), data.c_str());

    return HTTP_STATUS_OK;
}

int DHttpHandler::ota_query_handler(HttpRequest* req, HttpResponse* res) {
    // print the request body
    hv::Json body_json = req->GetJson();
    LOGI("OTA request body:%s", body_json.dump().c_str());
    //
    
    std::unique_ptr<DsysBase> task = std::make_unique<OTAManagerQuery>();
    task->set_body_str(body_json.dump());

    // 应用主控
    task->process();

    auto [code, message, data] = task->get_http_resp();
    LOGI("OTA response:%d, %s, %s", code, message.c_str(), data.c_str());
    response_status(res, code, message.c_str(), data.c_str());

    return HTTP_STATUS_OK;
}

 int DHttpHandler::ota_rollback_handler(HttpRequest* req, HttpResponse* res) {
    // print the request body
    hv::Json body_json = req->GetJson();
    LOGI("OTA request body:%s", body_json.dump().c_str());
    //
    
    std::unique_ptr<DsysBase> task = std::make_unique<OTAManagerRollback>();
    task->set_body_str(body_json.dump());

    // 应用主控
    task->process();

    auto [code, message, data] = task->get_http_resp();
    LOGI("OTA response:%d, %s, %s", code, message.c_str(), data.c_str());
    response_status(res, code, message.c_str(), data.c_str());

    return HTTP_STATUS_OK;
 }

///=====================================
int DHttpHandler::response_status(const HttpContextPtr& ctx, int code, const char* message)
{
    response_status(ctx->response.get(), code, message);
    ctx->send();
    return code;
}

int DHttpHandler::response_status(const HttpResponseWriterPtr& writer, int code, const char* message)
{
    response_status(writer->response.get(), code, message);
    writer->End();
    return code;
}


int DHttpHandler::response_status(HttpResponse* res, int code, const char* message, const char* data)
{
    if(message == nullptr) {
        message = http_status_str((enum http_status)code);
    }
    res->content_type = APPLICATION_JSON;

    hv::Json response_json;
    response_json["code"] = code;
    response_json["message"] = message;
    response_json["data"] = data == nullptr ? "" : data;
    res->body = response_json.dump();

    return code;

}

