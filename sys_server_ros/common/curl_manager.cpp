/*
 * @Author: hawrkchen
 * @Date: 2025-03-05 09:26:29
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-12 09:44:16
 * @Description: 
 * @FilePath: /sys_server_ros/common/curl_manager.cpp
 */

#include "curl_manager.hpp"
#include <iostream>

bool CurlManager::download_file(const std::string& url, const std::string& output_file) {
    // 打开文件，检查是否支持断点续传
    file_ = fopen(output_file.c_str(), "ab");
    if (!file_) {
        LOGE("Failed to open file: %s", output_file.c_str());
        return false;
    }
    //LOGI("Downloading url:[%s]", url.c_str());

    // 获取当前文件大小，用于断点续传
    fseek(file_, 0, SEEK_END);
    offset_ = ftell(file_);

    curl_easy_reset(curl_); //重置curl句柄,防止之前设置的curl_easy_setopt 影响

    // 设置CURL选项
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, file_);
    // 设置用户名和密码
    curl_easy_setopt(curl_, CURLOPT_USERNAME, "anonymous");
    curl_easy_setopt(curl_, CURLOPT_PASSWORD, "");

    // 设置回调函数
    curl_easy_setopt(curl_,CURLOPT_XFERINFOFUNCTION,progressCallback);
    curl_easy_setopt(curl_,CURLOPT_XFERINFODATA,this);
    curl_easy_setopt(curl_, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl_, CURLOPT_RESUME_FROM_LARGE, offset_);

    // 执行下载
    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        LOGE("Failed to download file: %s", curl_easy_strerror(res));
        return false;
    }
    // 这里必须先关闭并且设置为空指针，否则会下载不完整导致解密失败
    fclose(file_);
    file_ = nullptr;   
    LOGI("Download completed: %s", output_file.c_str());
    return true;
}

long long CurlManager::get_upgrade_pkg_size(const std::string& url) {
    //LOGI("in get_upgrade_pkg_size,url:[%s]", url.c_str());
    long long pkg_size = 0;

    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    // 设置只发送HTTP HEAD请求
    curl_easy_setopt(curl_, CURLOPT_NOBODY, 1L);
    // 设置回调函数
    curl_easy_setopt(curl_, CURLOPT_HEADERFUNCTION, header_callback);

    curl_easy_setopt(curl_, CURLOPT_HEADERDATA, &pkg_size);
    // 执行请求
    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        std::cerr << "Failed to get upgrade package size: " << curl_easy_strerror(res) << std::endl;
        return 0;
    }   
    LOGI("Get upgrade package size: %lld bytes", pkg_size);
    return pkg_size;
}

void CurlManager::get_remote_file_list(const std::string& url) {
    CURLcode res;
    std::string fileList;

    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &fileList);
    curl_easy_setopt(curl_, CURLOPT_FTPLISTONLY, 1L); // 只列出文件名
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, fileListCallback); // 设置回调函数

    res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        std::cerr << "Failed to get remote file list: " << curl_easy_strerror(res) << std::endl;
        return;
    }

    // 输出文件列表
    LOGI("Remote file list:\n%s", fileList.c_str());
}

void CurlManager::send_http_request(const std::string& url, const std::string& request_data, std::string& response_data) {
    if(!curl_) {
        curl_ = curl_easy_init();        
    }
    curl_easy_reset(curl_);
    //std::cout <<"get url:" << url << std::endl; 

    // 设置请求URL
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    // 设置请求头
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers);
    // 设置请求数据
    curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, request_data.c_str());  
    // 设置回调响应函数 
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, response_callback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response_data);
    // 执行请求
    curl_easy_setopt(curl_, CURLOPT_POST, 1L);
    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        LOGE("Failed to send http request: %s", curl_easy_strerror(res));
    }
}

int CurlManager::progressCallback(void* clientp, curl_off_t dltotal, 
                                    curl_off_t dlnow, curl_off_t ultotal, 
                                    curl_off_t ulnow) {
    //CurlManager* downloader = static_cast<CurlManager*>(clientp);
    (void)clientp;
    (void)ultotal;
    (void)ulnow;
    static int count = 0;
    static const int printInterval = 100;   //这个是控制频率
    if (dltotal > 0) {
        if(count > 0 && count % printInterval == 0) {  // 设置打印间隔
            double progress = static_cast<double>(dlnow) / dltotal * 100.0;
            LOGI("Download progress: %.2f%%", progress);
        } 
        count++;

    }
    return 0;
}

size_t CurlManager::header_callback(char* buffer, size_t size, size_t nitems, void* userdata) {
    size_t totalSize = size * nitems;
    std::string header(buffer, totalSize);
    if (header.find("Content-Length:") != std::string::npos) {
        size_t pos = header.find(":") + 2;
        std::string lengthStr = header.substr(pos, header.find("\r", pos) - pos);
        long contentLength = std::stol(lengthStr);
        //std::cout << "Content-Length: " << contentLength << " bytes" << std::endl;
        *static_cast<long long*>(userdata) = contentLength;
    }
    //std::cout << "get totalSize: "   << totalSize << std::endl;
    return totalSize;
}



size_t CurlManager::response_callback(void* buffer, size_t size, size_t nitems, void* userdata) {   
    //响应数据写入 response_data
    std::string* response_data = static_cast<std::string*>(userdata);
    size_t totalSize = size * nitems;
    response_data->append(static_cast<char*>(buffer), totalSize);
    //std::cout << "get totalSize: "   << totalSize << std::endl;
    return totalSize;
}

size_t CurlManager::fileListCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t totalSize = size * nmemb;
    std::string* fileList = static_cast<std::string*>(userdata);
    fileList->append(static_cast<char*>(ptr), totalSize);
    return totalSize;
}