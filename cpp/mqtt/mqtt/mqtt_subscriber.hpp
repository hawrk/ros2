/*
 * @Author: hawrkchen
 * @Date: 2025-05-27 10:17:12
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-27 16:38:40
 * @Description: 
 * @FilePath: /mqtt/mqtt/mqtt_subscriber.hpp
 */
#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include <mqtt/async_client.h>

class MqttSubscriber {
    public:
        using MessageCallback = std::function<void(const std::string& topic , const std::string& payload)>;

        MqttSubscriber(const std::string& address, const std::string& client_id, 
            const std::string& username = "", const std::string& password = "");


        ~MqttSubscriber();

        bool connect(int keep_alive = 20, bool clean_session = true);

        void disconnect();

        bool subscribe(const std::string& topic, int qos = 1);

        bool unsubscribe(const std::string& topic);

        void set_message_callback(const MessageCallback& callback);
        
    
    private:
        class MqttCallback: public mqtt::callback {
            public:
                MqttCallback(MqttSubscriber& subscriber) : subscriber_(subscriber) {}

                // 收到消息时调用
                void message_arrived(mqtt::const_message_ptr message) override {
                    if(subscriber_.message_callback_) {
                        subscriber_.message_callback_(message->get_topic(), message->get_payload_str());
                    }
                }

                // 连接丢失时调用
                void connection_lost(const std::string& cause) override {
                    std::cout << "Connection lost: " << cause << std::endl;
                    subscriber_.is_connected_ = false;
                }

            private:
                MqttSubscriber& subscriber_;
        };
    
    private:
        std::string address_;
        std::string client_id_;
        std::string username_;
        std::string password_;
        mqtt::async_client client_;
        bool is_connected_ = false;
        MessageCallback message_callback_;

        MqttCallback callback_handler_;
};