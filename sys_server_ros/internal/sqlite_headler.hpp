/*
 * @Author: hawrkchen
 * @Date: 2025-03-20 13:55:05
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 13:46:48
 * @Description: 
 * @FilePath: /sys_server/internal/sqlite_headler.hpp
 */

#pragma once

#include <string>

#include "sqlite3.h"
#include "sqlite_orm/sqlite_orm.h"

#include "constant.hpp"

struct User {
    int id;
    std::string name;
    int age;
};

// 机器人应用版本信息
struct AppVersion {
    int id;
    std::string app_name;
    std::string version;
    int status;
    std::string update_logs;   // 更新日志
};

// 机器人状态信息
struct RobotStatus {
    int id;
    std::string robot_sn;
    int robot_type;
    int robot_status;
    std::string robot_ip;
    std::string firmware_version;
    int robot_port;
    float battery_level;
};


using namespace sqlite_orm;


// 创建 Storage 实例的函数
static auto createStorage() {
    return sqlite_orm::make_storage("../robot.db",
        sqlite_orm::make_table("users",
            sqlite_orm::make_column("id", &User::id, sqlite_orm::primary_key().autoincrement()),
            sqlite_orm::make_column("name", &User::name),
            sqlite_orm::make_column("age", &User::age)),

        sqlite_orm::make_table("app_version",
            sqlite_orm::make_column("id", &AppVersion::id, sqlite_orm::primary_key().autoincrement()),
            sqlite_orm::make_column("app_name", &AppVersion::app_name),
            sqlite_orm::make_column("version", &AppVersion::version),
            sqlite_orm::make_column("status", &AppVersion::status),
            sqlite_orm::make_column("update_logs", &AppVersion::update_logs)),

        sqlite_orm::make_table("robot_status",
            sqlite_orm::make_column("id", &RobotStatus::id, sqlite_orm::primary_key().autoincrement()),
            sqlite_orm::make_column("robot_sn", &RobotStatus::robot_sn),
            sqlite_orm::make_column("robot_type", &RobotStatus::robot_type),
            sqlite_orm::make_column("robot_status", &RobotStatus::robot_status),
            sqlite_orm::make_column("robot_ip", &RobotStatus::robot_ip),
            sqlite_orm::make_column("firmware_version", &RobotStatus::firmware_version),
            sqlite_orm::make_column("robot_port", &RobotStatus::robot_port),
            sqlite_orm::make_column("battery_level", &RobotStatus::battery_level))
    );
}

using Storage = decltype(createStorage());


// 单例模式类
class Database {
public:
    // 获取单例实例
    static Storage& getInstance() {
        static Storage instance = createStorage();
        // 同步数据库模式
        instance.sync_schema();
        return instance;
    }

    // 删除拷贝构造函数和赋值操作符以防止拷贝
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

private:
    // 私有构造函数以防止外部实例化
    Database() {}
};