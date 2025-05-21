/*
 * @Author: hawrkchen
 * @Date: 2025-05-21 09:31:05
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-21 09:43:03
 * @Description: 
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/voiceplay_node.hpp
 */

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "behaviortree_cpp/bt_factory.h"

using VoiceText = std_msgs::msg::String;

class VoicePlayNode : public rclcpp::Node {
    public:
        VoicePlayNode(const std::string& node_name):Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "VoicePlayNode has been created");

            pub_ = this->create_publisher<VoiceText>("voice_play", 10);
        }

        rclcpp::Publisher<VoiceText>::SharedPtr get_publish_client() {
            return this->pub_;
        }

    private:
        rclcpp::Publisher<VoiceText>::SharedPtr pub_;

};

class VoicePlayPublisher : public BT::SyncActionNode {
    public:
        VoicePlayPublisher(const std::string& name, const BT::NodeConfig& config,
            std::shared_ptr<VoicePlayNode> node):
            BT::SyncActionNode(name, config), node_(node) {
                RCLCPP_INFO(node_->get_logger(), "VoicePlayPublisher has been created");
            }

            static BT::PortsList providedPorts() {
                return {BT::InputPort<std::string>("text")};
            }

            BT::NodeStatus tick() override {
                //auto text = getInput<std::string>("text");
                RCLCPP_INFO(node_->get_logger(), "voice play tick....");

                auto text = "请你喝水呀，你个二百五";
                VoiceText msg;
                msg.data = text;
                node_->get_publish_client()->publish(msg);
                RCLCPP_INFO(node_->get_logger(), "voice play end");

                return BT::NodeStatus::SUCCESS;
            }

    private:
        std::shared_ptr<VoicePlayNode> node_;
};