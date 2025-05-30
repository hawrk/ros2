

#pragma once

#include <rclcpp/rclcpp.hpp>

#include "behaviortree_cpp/bt_factory.h"

#include "dros_common_interfaces/action/dexterous_hand.hpp"


using DexterousHand = dros_common_interfaces::action::DexterousHand;

class DexterousHandNode : public rclcpp::Node
{
    public:
        DexterousHandNode(const std::string& node_name):Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "Initializing Dexterous Hand Node");

            this->action_client_ = rclcpp_action::create_client<DexterousHand>(this, "hand_control_module");

            while(!this->action_client_->wait_for_action_server(std::chrono::seconds(10))) {
                if(!rclcpp::ok()) {
                    RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for action server to be up");
                    rclcpp::shutdown();
                    return;
                }
                RCLCPP_INFO(this->get_logger(), "Waiting for action server to be up...");
            }
        }

        rclcpp_action::Client<DexterousHand>::SharedPtr get_action_client() {
            return this->action_client_;
        }


    private:
        rclcpp_action::Client<DexterousHand>::SharedPtr action_client_;
};
        
class DexterousHandAction : public BT::SyncActionNode {
    public:
        DexterousHandAction(const std::string& name, const BT::NodeConfig& config,
        std::shared_ptr<DexterousHandNode> dexterous_hand_node):
        BT::SyncActionNode(name, config), dexterous_hand_node_(dexterous_hand_node) {
            // set blackboard variables
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Initializing Dexterous Hand Action");
        }

        static BT::PortsList providedPorts() {
            return {
                BT::InputPort<std::string>("target_position"),
                BT::InputPort<dros_common_interfaces::action::DexterousHand::Goal>("pass_to")
            };
        }

        BT::NodeStatus tick() override {
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Executing Dexterous Hand tick...");
            auto target_position = this->getInput<std::string>("target_position");

            auto pass_to = this->getInput<dros_common_interfaces::action::DexterousHand::Goal>("pass_to");

            // 初始化入口参数
            auto goal = DexterousHand::Goal();
            if(target_position) {
                //goal.target_position = std::stoi(target_position.value());
                goal.target_position = 3;
                RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Target position: %s", target_position.value().c_str());
            }
            if(pass_to) {
                goal = pass_to.value();
            }

            //goal.target_position = 3.14;

            auto send_goal_options = rclcpp_action::Client<DexterousHand>::SendGoalOptions();
            send_goal_options.goal_response_callback =
                std::bind(&DexterousHandAction::goal_response_callback, this, std::placeholders::_1);
            send_goal_options.feedback_callback =
                std::bind(&DexterousHandAction::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);     
            send_goal_options.result_callback =
                std::bind(&DexterousHandAction::result_callback, this, std::placeholders::_1);

            // 
            auto dex_hand_client = dexterous_hand_node_->get_action_client();
            auto goal_future = dex_hand_client->async_send_goal(goal, send_goal_options);
            if(rclcpp::spin_until_future_complete(dexterous_hand_node_->get_node_base_interface(), goal_future)!= rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(dexterous_hand_node_->get_logger(), "Failed to send goal");
                return BT::NodeStatus::FAILURE;
            }
            auto future = goal_future.get();
            if(!future) {
                RCLCPP_ERROR(dexterous_hand_node_->get_logger(), "Goal rejected");
                return BT::NodeStatus::FAILURE;
            }
            // 异步获取结果
            auto result_future = dex_hand_client->async_get_result(future);
            // 等待结果返回
            if(rclcpp::spin_until_future_complete(dexterous_hand_node_->get_node_base_interface(), 
                result_future)!= rclcpp::FutureReturnCode::SUCCESS) {
                    RCLCPP_ERROR(dexterous_hand_node_->get_logger(), "Failed to get result");
                    return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "我在等待灵巧手抓取结果");
            // 处理结果
            auto result = result_future.get();
            if(result.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_ERROR(dexterous_hand_node_->get_logger(), "Action failed with result msg: %s", result.result->msg.c_str());
                return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Action succeeded");
            return BT::NodeStatus::SUCCESS;
        }

    private:
        // action 请求回调
        void goal_response_callback(const rclcpp_action::ClientGoalHandle<DexterousHand>::SharedPtr& goal_handle) {
            if (!goal_handle) {
                RCLCPP_ERROR(dexterous_hand_node_->get_logger(), "Goal rejected");
                return;
            }
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Goal accepted");
        }

        // action 反馈回调
        void feedback_callback(const rclcpp_action::ClientGoalHandle<DexterousHand>::SharedPtr, 
                    const std::shared_ptr<const DexterousHand::Feedback>& feedback) {
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Received feedback");
            float current_pose = feedback->progress;
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Current pose: %f", current_pose);
        }

        // action 结果回调
        void result_callback(const rclcpp_action::ClientGoalHandle<DexterousHand>::WrappedResult& result) {
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Received result");
            switch(result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Action succeeded");
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Action aborted");
                    return;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Action canceled");
                    return;
                default:
                    RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Action returned with unknown result code");
                    return;
            }
            RCLCPP_INFO(dexterous_hand_node_->get_logger(), "Result: %d, msg:%s", 
                result.result->success, result.result->msg.c_str());
        }

    private:
        std::shared_ptr<DexterousHandNode> dexterous_hand_node_;
};