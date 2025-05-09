/*
 * @Author: hawrkchen
 * @Date: 2025-05-09 15:47:36
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-09 16:01:25
 * @Description: 
 * @FilePath: /sys_server_ros/src/main.cpp
 */
#include <rclcpp/rclcpp.hpp>

#include "sys_server_ros/subscribe_node.hpp"

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscribeNode>("sub_node");
    
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
