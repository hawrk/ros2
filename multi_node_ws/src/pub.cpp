/*
 * @Author: hawrkchen
 * @Date: 2025-05-23 09:50:14
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-23 09:59:05
 * @Description: 
 * @FilePath: /multi_node_ws/src/pub.cpp
 */
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class PubNode : public rclcpp::Node {
    public:
        PubNode() : Node("pub_node") {
            RCLCPP_INFO(this->get_logger(), "pub1 node has been created");
            pub_ = this->create_publisher<std_msgs::msg::String>("topic1", 10);
        }

        void publish() {
            RCLCPP_INFO(this->get_logger(), "Publishing message1");
            auto msg = std_msgs::msg::String();
            msg.data = "Hello, pub1 node!";
            pub_->publish(msg);
        }

    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
        
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PubNode>();
    node->publish();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

