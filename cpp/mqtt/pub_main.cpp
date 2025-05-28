/*
 * @Author: hawrkchen
 * @Date: 2025-05-27 14:19:06
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-27 16:41:35
 * @Description: 
 * @FilePath: /mqtt/pub_main.cpp
 */

#include <iostream>

#include "mqtt/mqtt_publisher.hpp"

int main(int argc,char* argv[]) {
    MqttPublisher publisher("tcp://localhost:1883", "publisher");

    if(!publisher.connect()) {
        std::cerr << "Failed to connect to MQTT server" << std::endl;
        return 1;
    }
    // 发布单条消息
    publisher.publish("topic1", "Hello, MQTT!");

    // 发布多条消息
    publisher.publish_loop("topic1", "hello, loop mqtt");

    return 0;
    
}