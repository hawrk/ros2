/*
 * @Author: hawrkchen
 * @Date: 2025-05-09 15:52:34
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-09 15:56:49
 * @Description:
 * @FilePath: /sys_server_ros/include/sys_server_ros/subscribe_node.hpp
 */
#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>

class SubscribeNode : public rclcpp::Node {
    public:
        SubscribeNode(const std::string& node_name) : Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "SubscribeNode is created");
            this->sub_ = this->create_subscription<std_msgs::msg::String>(
                "chatter", 10, std::bind(&SubscribeNode::sub_callback, this, std::placeholders::_1));
        }

    private:
        void sub_callback(const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "Received message: %s", msg->data.c_str());
        }


    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

};