/*
 * @Author: hawrkchen
 * @Date: 2025-05-09 15:47:36
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-12 12:00:45
 * @Description: 
 * @FilePath: /sys_server_ros/src/main.cpp
 */
#include <rclcpp/rclcpp.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <ament_index_cpp/get_package_prefix.hpp>
#include <fstream>
#include <thread>
#include <libudev.h>

#include "sys_server_ros/subscribe_node.hpp"

#include "hv/HttpServer.h"

#include "../handler/router.hpp"
#include "../internal/constant.hpp"

#define PACKAGE_NAME "sys_server_ros"

hv::HttpServer g_http_server;
hv::HttpService g_http_service;

nlohmann::json g_config_json;

void signalHandler(int signum) {
    RCLCPP_INFO(rclcpp::get_logger("sys_server_ros"), "get signal :%d, exit", signum);
    exit(signum);
}

int parse_confile(const char* confile) {
    std::ifstream ifs(confile);
    if(!ifs) {
        RCLCPP_ERROR(rclcpp::get_logger("sys_server_ros"), "open config file %s failed", confile);
        return -1;
    }
    //nlohmann::json g_config_json;
    ifs >> g_config_json;
    /*   
    // 该日志配置是libhv中自带的，暂时不用
    // logfile
    if(std::string val = g_config_json["log"]["file"].get<std::string>(); !val.empty()) {
        //strncpy(g_main_ctx.logfile, str.c_str(), sizeof(g_main_ctx.logfile) - 1);
        hlog_set_file(val.c_str());
    }
    // loglevel
    if(std::string val = g_config_json["log"]["level"].get<std::string>(); !val.empty()) {
        hlog_set_level_by_str(val.c_str());
    }
    hlog_set_remain_days(7);
    if(g_config_json["log"]["dye"].get<bool>()) {  // 开启染色功能
        logger_enable_color(hlog, 1);
    }
    */
    // port
    if(int port = g_config_json["server"]["port"].get<int>(); port > 0) {
        g_http_server.port = port;
    } else {
        g_http_server.port = 8090;
    }
    return 0;
}

void print_device_attributes(struct udev_device* dev) {
    const char* syspath = udev_device_get_syspath(dev);
    if (syspath) {
        std::cout << "syspath: " << syspath << std::endl;
    }

    struct udev_list_entry* entry;

    // 打印设备属性
    entry = udev_device_get_properties_list_entry(dev);
    if (entry) {
        std::cout << "Properties:" << std::endl;
        while (entry) {
            const char* key = udev_list_entry_get_name(entry);
            const char* value = udev_list_entry_get_value(entry);
            if (key && value) {
                std::cout << key << ": " << value << std::endl;
            }
            entry = udev_list_entry_get_next(entry);
        }
    }
    // TODO: 处理调用http操作

}


void usb_listen_thread() {
    
    struct udev* udev;
    struct udev_monitor* mon;

    // 创建udev对象
    udev = udev_new();
    if (!udev) {
        std::cerr << "Can't create udev object\n";
        return ;
    }

    // 创建udev监视器
    mon = udev_monitor_new_from_netlink(udev, "udev");
    if (!mon) {
        std::cerr << "Can't create udev monitor\n";
        udev_unref(udev);
        return ;
    }

    // 过滤usb设备事件
    udev_monitor_filter_add_match_subsystem_devtype(mon, "usb", "usb_device");

    // 开启udev监视器
    if (udev_monitor_enable_receiving(mon) < 0) {
        std::cerr << "Can't enable udev monitor\n";
        udev_monitor_unref(mon);    
        udev_unref(udev);
        return ;
    }

    // 创建文件描述符
    int fd = udev_monitor_get_fd(mon);

    // 循环等待设备插入
    while (true) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(fd, &fds);

        std::cout << "Waiting for USB device..." << std::endl;
        int ret = select(fd + 1, &fds, NULL, NULL, NULL);
        if(ret >  0 && FD_ISSET(fd, &fds)) {
            // 设备插入事件发生
            struct udev_device* dev = udev_monitor_receive_device(mon);
            if (dev) {
                const char* action = udev_device_get_action(dev);
                if (action) {
                    std::string action_str(action);
                    if (action_str == "add") {
                        const char* syspath = udev_device_get_syspath(dev);
                        if (syspath) {
                            std::cout << "USB device inserted: " << syspath << std::endl;
                        }
                    } else if(action_str == "remove") {
                        const char* syspath = udev_device_get_syspath(dev);
                        if (syspath) {
                            std::cout << "USB device removed: " << syspath << std::endl;
                        }
                    }

                    // 打印设备属性
                    print_device_attributes(dev);
                    
                    udev_device_unref(dev);
                }
            }
        }
    }

    // 释放udev监视器
    udev_monitor_unref(mon);
    // 释放udev对象
    udev_unref(udev);
    std::cout << "Exiting..." << std::endl;
}



int main(int argc, char ** argv)
{
    std::string config_path = ament_index_cpp::get_package_share_directory(PACKAGE_NAME) 
        + "/etc/config.json";
    parse_confile(config_path.c_str());
        // 添加信号
    signal(SIGINT, signalHandler);    // 处理 Ctrl-C
    signal(SIGQUIT, signalHandler);   // 处理 "Ctrl-\"

        // USB插入监听
    std::thread { usb_listen_thread }.detach();

    // 启动HTTP服务
    std::thread hv_thread ([&]() {
        Router::RegisterRoutes(g_http_service);
        g_http_server.registerHttpService(&g_http_service);

        g_http_server.run();
    });
    
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscribeNode>("sub_node");
    
    rclcpp::spin(node);
    rclcpp::shutdown();

    hv_thread.join();

    return 0;
}
