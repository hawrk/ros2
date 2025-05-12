/*
 * @Author: hawrkchen
 * @Date: 2025-03-05 09:26:20
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 17:50:14
 * @Description: 
 * @FilePath: /sys_server/common/curl_manager.hpp
 */


#pragma once

#include <fstream>
#include <string>
#include <curl/curl.h>

#include "hv/hlog.h"


class CurlManager {
    public:
        CurlManager() : curl_(curl_easy_init()), file_(nullptr), offset_(0) {
            if (!curl_) {
                throw std::runtime_error("Failed to initialize libcurl.");
            }
        }

        ~CurlManager() {
            if (curl_) {
                curl_easy_cleanup(curl_);
            }
            if (file_) {
                fclose(file_);
            }
        }

        // 下载文件
        bool download_file(const std::string& url, const std::string& output_file);

        // 获取远程文件大小
        long long get_upgrade_pkg_size(const std::string& url);

        void get_remote_file_list(const std::string& url);
    
    // 发送HTTP请求
        void send_http_request(const std::string& url, const std::string& request_data, std::string& response_data);

    private:
        CURL* curl_;
        FILE* file_;
        long offset_;

        static int progressCallback(void* clientp, curl_off_t dltotal, 
                                    curl_off_t dlnow, curl_off_t ultotal, 
                                    curl_off_t ulnow);

        static size_t header_callback(char* buffer, size_t size, size_t nitems, void* userdata);

        static size_t response_callback(void* buffer, size_t size, size_t nitems, void* userdata);

        static size_t fileListCallback(void *ptr, size_t size, size_t nmemb, void *userdata);

};