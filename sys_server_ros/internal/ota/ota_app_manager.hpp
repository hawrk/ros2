/*
 * @Author: hawrkchen
 * @Date: 2024-12-09 14:17:11
 * @Description: app 升级类管理
 * @FilePath: /sys_server_ros/internal/ota/ota_app_manager.hpp
 */
#pragma once

#include <iostream>
#include <vector>
#include <filesystem>

#include <rclcpp/rclcpp.hpp>

#include "hv/hlog.h"

class OTAAppManager {
    public:
        OTAAppManager() = default;

        ~OTAAppManager() = default;

        // test
        void start();

        // 获取系统空间大小
        std::tuple<long long, long long, long long> get_sys_space();

        // 备份节点服务
        bool copy_app_files(const std::filesystem::path& source_dir, const std::filesystem::path& backup_dir);

        bool stop_app_nodes(const std::string& app_name);

        // 更新节点服务程序
        bool update_app_nodes();

        // 重启节点服务并验证
        bool restart_app_nodes();

        // 回滚节点服务程序
        void rollback_app_files();

    private:
        //std::string app_name_;   // 应用名称  --定义在此处有点别扭，先注释

};