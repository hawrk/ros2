/*
 * @Author: hawrkchen
 * @Date: 2025-05-27 10:17:21
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-27 16:54:36
 * @Description: 
 * @FilePath: /mqtt/mqtt/mqtt_subscriber.cpp
 */

#include "mqtt_subscriber.hpp"

MqttSubscriber::MqttSubscriber(const std::string& address, const std::string& client_id, const std::string& username, const std::string& password)
    : address_(address), 
    client_id_(client_id), 
    username_(username), 
    password_(password),
    client_(address,client_id),
    callback_handler_(*this) {

    client_.set_callback(callback_handler_);
}

MqttSubscriber::~MqttSubscriber() {
    if(is_connected_) {
        disconnect();
    }
}

bool MqttSubscriber::connect(int keep_alive, bool clean_session) {
    try {
        mqtt::connect_options conn_opts;
        conn_opts.set_keep_alive_interval(keep_alive);
        conn_opts.set_clean_session(clean_session);
        if(!username_.empty()) {
            conn_opts.set_user_name(username_);
        }
        if (!password_.empty())
        {
            conn_opts.set_password(password_);
        }
        

        std::cout << "Connecting to " << address_ << " with client ID " << client_id_ << std::endl;
        client_.connect(conn_opts)->wait();
        is_connected_ = true;
        std::cout << "Connected successfully" << std::endl;
        return true;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error connecting to " << address_ << ": " << exc.what() << std::endl;
        return false;
    }
}

void MqttSubscriber::disconnect() {
    try {
        client_.disconnect()->wait();
        is_connected_ = false;
        std::cout << "Disconnected successfully" << std::endl;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error disconnecting from " << address_ << ": " << exc.what() << std::endl;
    }
}

bool MqttSubscriber::subscribe(const std::string& topic, int qos) {
    try {
        if(!is_connected_) {
            std::cerr << "Error: not connected to " << address_ << std::endl;
            return false;
        }
        client_.subscribe(topic, qos)->wait();
        std::cout << "Subscribed to topic " << topic << " with QoS " << qos << std::endl;
        return true;    
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error subscribing to topic " << topic << ": " << exc.what() << std::endl;
        return false;
    }
}

bool MqttSubscriber::unsubscribe(const std::string& topic) {
    try {
        if(!is_connected_) {
            std::cerr << "Error: not connected to " << address_ << std::endl;
            return false;
        }
        client_.unsubscribe(topic)->wait();
        std::cout << "Unsubscribed from topic " << topic << std::endl;
        return true;
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error unsubscribing from topic " << topic << ": " << exc.what() << std::endl;
        return false;
    }
}

void MqttSubscriber::set_message_callback(const MessageCallback& callback) {
    message_callback_ = callback;
}