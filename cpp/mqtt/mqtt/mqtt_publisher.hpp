/*
 * @Author: hawrkchen
 * @Date: 2025-05-27 10:16:50
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-27 16:33:23
 * @Description: 
 * @FilePath: /mqtt/mqtt/mqtt_publisher.hpp
 */
#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include <mqtt/async_client.h>

class MqttPublisher {
    public:

        MqttPublisher(const std::string& address, const std::string& client_id,
                      const std::string& username = "", const std::string& password = "");

        ~MqttPublisher();

        bool connect(int keep_alive = 20, bool clean_session = true);

        void disconnect();

        bool publish(const std::string& topic, const std::string& message);

        void publish_loop(const std::string& topic, const std::string& message, int interval_ms = 1000);


    private:
        std::string address_;      // 客户端地址
        std::string client_id_;    // 客户端ID
        std::string username_;     // 用户名
        std::string password_;     // 密码
        mqtt::async_client client_;   // 异步客户端
        bool is_connected_ = false;    // 是否已连接
};