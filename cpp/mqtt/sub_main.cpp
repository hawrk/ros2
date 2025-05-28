/*
 * @Author: hawrkchen
 * @Date: 2025-05-27 14:19:11
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-27 16:42:59
 * @Description: 
 * @FilePath: /mqtt/sub_main.cpp
 */

#include <iostream>

#include "mqtt/mqtt_subscriber.hpp"

int main(int argc,char* argv[]) {
    MqttSubscriber subscriber("tcp://localhost:1883", "subscribe");

    subscriber.set_message_callback([](const std::string& topic, const std::string& payload)  {
        std::cout << "Received message: " << payload << std::endl;
    });

    if(!subscriber.connect()) {
        std::cerr << "Failed to connect to MQTT server" << std::endl;
        return 1;
    }

    subscriber.subscribe("topic1", 1);

    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}