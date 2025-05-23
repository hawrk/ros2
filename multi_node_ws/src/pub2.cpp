/*
 * @Author: hawrkchen
 * @Date: 2025-05-23 09:56:30
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-23 09:59:12
 * @Description: 
 * @FilePath: /multi_node_ws/src/pub2.cpp
 */
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class PubNode2 : public rclcpp::Node {
    public:
        PubNode2() : Node("pub_node2") {
            RCLCPP_INFO(this->get_logger(), "pub2 node has been created");
            pub_ = this->create_publisher<std_msgs::msg::String>("topic2", 10);
        }

        void publish() {
            RCLCPP_INFO(this->get_logger(), "Publishing message2");
            auto msg = std_msgs::msg::String();
            msg.data = "Hello, pub2 node!";
            pub_->publish(msg);
        }

    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
        
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PubNode2>();
    node->publish();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
