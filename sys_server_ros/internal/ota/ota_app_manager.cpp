/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 14:17:45
 * @Description: 
 * @FilePath: /sys_server_ros/internal/ota/ota_app_manager.cpp
 */


#include "ota_app_manager.hpp"

#include <sys/statvfs.h>
#include <signal.h>
#include <unistd.h>
#include <zlib.h>
#include <thread>

#include "../../common/file_sys.hpp"
#include "../constant.hpp"

void OTAAppManager::start() 
{
    // TODO: start OTA app
    // TODO: check if OTA app is already running

    std::string app_path = "/home/hawrk/src/cpp/hv_demo/ota_app";
    std::string app_args = "";
    std::string app_name_ = "ota_app";

    std::vector<std::string> args = {app_path, app_args};
    std::vector<std::string> env = {};

    std::cout << "Starting OTA app..." << std::endl;
    RCLCPP_INFO(rclcpp::get_logger("sys_server_ros"), "app path: %s", app_path.c_str());
    //LOGI("App path: %s", app_path.c_str());

}

// 获取系统空间信息
std::tuple<long long, long long, long long> OTAAppManager::get_sys_space()
{
    // 默认检查根目录，可根据需要修改
    struct statvfs st;
    if (statvfs("/", &st) != 0) {
        //LOGE("statvfs failed");
        RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "statvfs failed");
        return std::make_tuple(0, 0, 0);
    }
    long long free_size = st.f_bfree * st.f_frsize;
    long long total_size = st.f_blocks * st.f_frsize;
    long long available = st.f_frsize * st.f_bavail;

    RCLCPP_INFO(rclcpp::get_logger("sys_server_ros"), 
        "总空间: %lld MB, 可用空间: %lld MB, 剩余空间: %lld MB", total_size/(1024*1024), available/(1024*1024), free_size/(1024*1024));

    //LOGI("总空间: %lld MB, 可用空间: %lld MB, 剩余空间: %lld MB", total_size/(1024*1024), available/(1024*1024), free_size/(1024*1024));

    //std::cout << "总空间: " << total_size/(1024*1024) << " MB" << std::endl;
    //std::cout << "可用空间:" << available/(1024*1024) << " MB" << std::endl;
    //std::cout << "剩余空间:" << free_size/(1024*1024) << " MB" << std::endl;
    return std::make_tuple(total_size, available, free_size);
}

// 复制节点服务程序文件
bool OTAAppManager::copy_app_files(const std::filesystem::path& source_dir, 
    const std::filesystem::path& backup_dir)
{
    namespace fs = std::filesystem;
    // 检查源目录是否存在
    if (!fs::exists(source_dir) || !fs::is_directory(source_dir)) {
        RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "Source directory does not exist or is not a directory:, \
            source_dir: %s", source_dir.c_str());
        //std::cerr << "Source directory does not exist or is not a directory: " << source_dir << std::endl;
        return false;
    }

    // 检查并创建备份目录
    if (!fs::exists(backup_dir)) {
        fs::create_directories(backup_dir);
    } else {
        remove(backup_dir.c_str());
        fs::create_directories(backup_dir);
    }

    // 遍历源目录中的所有条目
    for (const auto& entry : fs::directory_iterator(source_dir)) {
        // 检查是否是log目录
        if (entry.path().filename() == "log"
            || entry.path().filename() == "logs") {
            continue; 
        }

        // 构建目标路径
        fs::path destination = backup_dir / entry.path().filename();

        // 如果是目录，递归备份
        if (entry.is_directory()) {
            if (!copy_app_files(entry.path(), destination)) {
                //std::cerr << "Failed to backup directory: " << entry.path() << std::endl;
                return false;
            }
        } else if (entry.is_regular_file()) {
            // 如果是文件，复制文件
            if (!std::filesystem::copy_file(entry.path(), destination, fs::copy_options::overwrite_existing)) {
                //std::cerr << "Failed to backup file: " << entry.path() << std::endl;
                return false;
            }
        }
    }
    
    return true;
}

//　粗暴地停止节点服务不是一个好方法，可考虑调用脚本进行终止
bool OTAAppManager::stop_app_nodes(const std::string& app_name) 
{   
    if(app_name.empty()) {
        std::cerr << "App name is empty" << std::endl;
        return false;
    }

    std::string command = "pgrep " + app_name;
    FILE* pipe = popen(command.c_str(), "r");  // 当进程不存在时，依然会打开
    if(!pipe) {
        std::cerr << "popen() failed" << std::endl;
        return false;
    }

    char buffer[128] = {0};
    int pid = -1;
    if(fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        pid = atoi(buffer);
    }
    pclose(pipe);

    if(pid == -1) {  // 进程不存在, 直接返回
        std::cout << "No app node found" << std::endl;
        return true;
    }
    std::cout << "pid: " << pid << std::endl;  
    // 发送终止信号
    if(kill(pid, SIGKILL) != 0) {
        std::cerr << "kill() failed" << std::endl;
        return false;
    }
    // kill(pid, SIGTERM) 温和终止，可能有延迟
    // kill -9 pid
    // kil (pid, SIGKILL)

    // 这里需要注意，如果kill -9 pid，则pid可能已经被杀掉了，需要再次检查一下pid是否存在
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // 等待100ms,进程可能还没完全退出
    if(kill(pid, 0) == 0) {   // 进程依然存在
        std::cerr << "kill() failed" << std::endl;
        return false;
    }

    std::cout << "stop app node success...." << std::endl;

    return true;
    
}

// 更新节点服务程序
bool OTAAppManager::update_app_nodes()
{
    // 1. 替换当前程序节点文件
    // 2. 启动当前程序节点
    return true;
}

// 重启节点服务并验证
bool OTAAppManager::restart_app_nodes()
{
    // 1. 重启当前程序节点
    // 2. 验证当前程序节点是否正常运行
    return true;
}

// 回滚节点服务程序
void OTAAppManager::rollback_app_files()
{
    // TODO: 停止当前程序节点
    // 2. 找到之前备份的程序节点文件
    // 3. 替换当前程序节点文件
    // 4. 重新当前程序节点
}


