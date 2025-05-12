/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 11:55:28
 * @Description: 
 * @FilePath: /sys_server/internal/ota/ota_mng_upgrade.cpp
 */

#include "ota_mng_upgrade.hpp"

#include <thread>

#include "../../common/file_sys.hpp"
#include "../../common/crypto_suite.hpp"
#include "../constant.hpp"

OTAManagerUpgrade::OTAManagerUpgrade() {

    //app_manager_ = std::make_shared<OTAAppManager>();
    //curl_lib_ = std::make_shared<CurlLib>();
}

bool OTAManagerUpgrade::parse_param() {
    try {
        nlohmann::json body = nlohmann::json::parse(body_str_);

        if(body.contains("app_name") && body["app_name"].is_string()) {
            app_name_ = body["app_name"].get<std::string>();
        }
        if(body.contains("version") && body["version"].is_string()) {
            version_ = body["version"].get<std::string>();
        }
        if(body.contains("address") && body["address"].is_string()) {
            url_ = body["address"].get<std::string>();
        }
        // check 
        if(app_name_.empty()|| version_.empty()|| 
            url_.empty()) {
            LOGE("in OTAManagerUpgrade, not enough param");
            return false;
        }

    } catch(const std::exception& e) {
        LOGE("in OTAManagerUpgrade, Parse body error: %s", e.what());
        return false;
    }
    return true;
}

bool OTAManagerUpgrade::process() {
    LOGI("OTAManagerUpgrade,process start");

    // 1.检查入参
    if(!parse_param()) {
        LOGE("Check param Error");
        set_http_resp(ErrorCode::ERR_PARAM_INVALID, "");
        return false;
    }

    // 2.检查系统空间
    auto ret_size = app_manager_->get_sys_space();
    avaiable_space_size_ = std::get<1>(ret_size);
    if(avaiable_space_size_ < constant::MIN_AVAILABLE_SPACE) {
        LOGE("OTAManagerUpgrade,Check sys space Error, available_size: %lld", avaiable_space_size_);
        set_http_resp(ErrorCode::ERR_SYS_SPACE_NOT_ENOUGH,  "");
        return false;
    }
    
    auto self = shared_from_this();  // 解决主线程结束后，该类可能提前释放资源，需要用shared_from_this延迟被析构
    auto thread_pro = [self]() {  
        //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        // 在该异步线程内，避免直接使用原生类的成员变量，主线程的类提前析构有可能资源被释放
        // 采用 self-> 方式访问类成员变量
        LOGI("get app_name: %s, version: %s, url: %s", self->app_name_.c_str(), self->version_.c_str(), self->url_.c_str());

        // 先查一下表
        auto& storage = Database::getInstance();
        auto app_version = storage.get_all<AppVersion>(where(c(&AppVersion::app_name) == self->app_name_));
        if(app_version.empty()) {  // 无数据，表示是第一次部署，写入
            AppVersion v{-1, self->app_name_, self->version_, 0, ""};   
            storage.insert(v);
        }
        // 有数据，更新一下本地版本号和状态
        storage.update_all(set(c(&AppVersion::status) = 1,
                    c(&AppVersion::version) = self->version_),
                where(c(&AppVersion::app_name) == self->app_name_));
        // 查机器人本地状态表
        auto robot = storage.get_all<RobotStatus>();
        if(robot.empty()) {
            LOGE("OTAManagerUpgrade,get_robot_version Error");
            // 本地机器人无数据时，发更新回执没用了，因为找不到robot_sn，只能更新本地版本表
            self->update_status(storage, 2, "robot_sn not found");
        }
        for(auto r : robot) {
            self->robot_sn_ = r.robot_sn;
            break;
        }
        LOGI("get robot sn: %s",  self->robot_sn_.c_str());
        // TODO. 这里还是需要检查一下机器人本身的状态，在运行中、故障等状态不能更新
        // 电量过低不能更新，还有在更新状态下是否可以更新等
        
        // 3. 下载升级包
        int pkg_size = self->get_upgrade_pkg(self->url_);    
        if(pkg_size == 0) {
            LOGE("OTAManagerUpgrade,get_upgrade_pkg Error");
            auto err_msg = "download pkg file failed";
            //　更新表状态
            self->update_status(storage, 2, err_msg);
            //　再回包
            self->send_http_upgrade_result(self->robot_sn_, self->app_name_, 2, err_msg);
            return ;
        }
        // 4.1. 解密
        std::string decrypto_file;
        std::string gcm_key = g_config_json["ota"]["gcm_key"].get<std::string>();
        std::vector<unsigned char> keyVec(gcm_key.begin(), gcm_key.end());
        LOGI("get decrypt file: %s, key:[%s]", self->local_file_.c_str(), gcm_key.c_str());
        if(!g_crypto_suite.aes_gcm_decrypt(self->local_file_,decrypto_file, keyVec)) {
            LOGE("OTAManagerUpgrade,gcm_decrypt failed");
            auto err_msg = "gcm_decrypt failed";
            self->update_status(storage, 2, err_msg);
            self->send_http_upgrade_result(self->robot_sn_, self->app_name_, 2, err_msg);
            return;
            
        }

        // 4.2 解压升级包
        if(!FileSys::extract_tar_gz_v2(decrypto_file, g_config_json["ota"]["download_dir"].get<std::string>())) {
            LOGE("OTAManagerUpgrade,extract_tar_gz Error");
            auto err_msg = "extract_tar_gz Error";
            self->update_status(storage, 2, err_msg);
            self->send_http_upgrade_result(self->robot_sn_, self->app_name_, 2, err_msg);
            return ;
        }


        // 4.3. 停止原有程序
        if(!self->app_manager_->stop_app_nodes(self->app_name_)) {
            LOGE("OTAManagerUpgrade,stop_app_nodes Error");
            auto err_msg = "stop_app_nodes Error";
            self->update_status(storage, 2, err_msg);
            self->send_http_upgrade_result(self->robot_sn_, self->app_name_, 2, err_msg);
            return ;
        }

        // 5. 备份原有文件
        std::string app_dir = g_config_json["ota"]["app_dir"].get<std::string>() + "/" + self->app_name_;
        std::string backup_dir = g_config_json["ota"]["backup_dir"].get<std::string>() + "/" + self->app_name_;
        LOGI("OTAManagerUpgrade,process, app_dir: %s, backup_dir: %s", app_dir.c_str(), backup_dir.c_str());
        if(!std::filesystem::exists(app_dir)) {   // 原服务不存在，表示是第一次部署，跳过备份
            LOGI("OTAManagerUpgrade,process, app_dir not exist, skip backup");
        } else {
            if(!self->app_manager_->copy_app_files(app_dir, backup_dir)) {
                LOGE("OTAManagerUpgrade,backup_app_files Error");
                auto err_msg = "backup_app_files Error";
                self->update_status(storage, 2, err_msg);
                self->send_http_upgrade_result(self->robot_sn_, self->app_name_, 2, err_msg);
                return ;
            }
        }

        // 6. 升级文件
        std::string download_app_dir = g_config_json["ota"]["download_dir"].get<std::string>() + "/" + self->app_name_;
        LOGI("OTAManagerUpgrade,process, new_app_dir: %s", download_app_dir.c_str());
        if(!self->app_manager_->copy_app_files(download_app_dir, app_dir)) {
            LOGE("OTAManagerUpgrade, replace_app_files Error");
            auto err_msg = "replace_app_files Error";
            self->update_status(storage, 2, err_msg);
            self->send_http_upgrade_result(self->robot_sn_, self->app_name_, 2, err_msg);
            return;
        }
        

        // 7. 启动新版本程序

        // 8. 验证各项服务是否正常
        
        LOGI("OTAManagerUpgrade,process, verify_services");
        return;

    };
    std::thread {thread_pro}.detach();

    LOGI("OTAManagerUpgrade, ret response");
    // 回包
    set_http_resp(ErrorCode::SUCCESS, "");
    return true;
}

int32_t OTAManagerUpgrade::get_upgrade_pkg(const std::string& url) {
    // 获取当前文件路径
    std::cout << "get url:" << url << std::endl;
    std::string path = FileSys::get_absolute_path();
    size_t last_slash_pos = url.find_last_of("/");
    if(last_slash_pos == std::string::npos) {
        return 0;
    }
    local_file_ = g_config_json["ota"]["download_dir"].get<std::string>() + "/" + url.substr(last_slash_pos+1);
    LOGI("get download local file: %s", local_file_.c_str());
    // 先获取远程文件的大小 
    
    
    long long remote_file_size =  curl_mngr_.get_upgrade_pkg_size(url);
    if(remote_file_size == 0) {
        LOGE("OTAManagerUpgrade,get_upgrade_pkg, get remote file size failed");
        return 0;
    }
    // check 本地空间是否足够远程文件大小
    LOGI("OTAManagerUpgrade,get_upgrade_pkg, avaiable_size: %lld, remote_size: %lld", 
        avaiable_space_size_, remote_file_size);
    if(avaiable_space_size_ < remote_file_size*3) {  //本地空间要大于3倍远程文件大小
        LOGE("OTAManagerUpgrade,get_upgrade_pkg, not enough space, avaiable_size: %lld, remote_size: %lld", 
            avaiable_space_size_, remote_file_size);
        return 0;
    }
    
    //curl_mngr_.get_remote_file_list(url);
    if (curl_mngr_.download_file(url, local_file_)) {  
        std::cout << "File downloaded successfully." << std::endl;
    } else {
        std::cerr << "File download failed." << std::endl;
    }

    // 计算下载的升级包大小
    if(!std::filesystem::exists(local_file_)) {
        LOGE("OTAManagerUpgrade,get_upgrade_pkg, pkg_file: %s not exist", local_file_.c_str());
        return 0;
    }

    int64_t size = std::filesystem::file_size(local_file_);
    LOGI("OTAManagerUpgrade,get_upgrade_pkg, pkg_file: %s, size: %lld ", local_file_.c_str(), size);
    return size;  
}


void OTAManagerUpgrade::update_status(Storage &storage, int status, const std::string& msg) {
    storage.update_all(set(c(&AppVersion::status) = status,
                        c(&AppVersion::update_logs) = msg),
                    where(c(&AppVersion::app_name) == app_name_));
}

void OTAManagerUpgrade::send_http_upgrade_result(const std::string& robot_sn, const std::string& app_name,
    int ret_code, const std::string& msg) {
    // 组HTTP请求
    std::string req_url = constant::DCLOUD_URL;
    // 拼装json数据 
    nlohmann::json body;
    body["robot_sn"] = robot_sn;
    body["app_name"] = app_name;
    body["result"] = ret_code;
    body["message"] = msg;
    std::string req_body = body.dump();
    LOGI("send_http_upgrade_result, req_body: %s", req_body.c_str());
    std::string response;
    curl_mngr_.send_http_request(req_url, req_body, response);

    LOGI("send_http_upgrade_result, response: %s", response.c_str());
}
