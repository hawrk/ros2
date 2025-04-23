/*
 * @Author: hawrkchen
 * @Date: 2025-04-22 09:51:29
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-04-23 10:32:50
 * @Description:   操模块
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/pickup_node.hpp
 */

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "rclcpp_action/rclcpp_action.hpp"

#include "turtlesim/action/rotate_absolute.hpp"

#include "behaviortree_cpp/bt_factory.h"


class PickupNode : public rclcpp::Node {
    public:
        PickupNode(const std::string& node_name):Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "PickupNode started ......");
            // 创建 客户端
            rotate_client_ = rclcpp_action::create_client<turtlesim::action::RotateAbsolute>(this, "pickup");
            while(!rotate_client_->wait_for_action_server(std::chrono::seconds(1))) {
                RCLCPP_INFO(this->get_logger(), "Waiting for pickup action server to be up...");
            }
        }

        rclcpp_action::Client<turtlesim::action::RotateAbsolute>::SharedPtr get_rotate_client() {
            return rotate_client_;
        }

    private:
        rclcpp_action::Client<turtlesim::action::RotateAbsolute>::SharedPtr rotate_client_;
};


class PickupAction: public BT::SyncActionNode {
    public:
        PickupAction(const std::string& name, const BT::NodeConfig& config,
        std::shared_ptr<PickupNode> pickup_node): BT::SyncActionNode(name, config),pickup_node_(pickup_node) {
            RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction started ......");
        }

        static BT::PortsList providedPorts() {
            return {BT::InputPort<std::string>("item_name")};
        }

        BT::NodeStatus tick() override {
            RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction tick......");
            // 读取输入参数  test
            std::string target_name = getInput<std::string>("item_name").value();
            RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction: item_name: %s", target_name.c_str());
            
            turtlesim::action::RotateAbsolute::Goal goal;
            goal.theta = 3.14159265359;

            auto send_goal_options = rclcpp_action::Client<turtlesim::action::RotateAbsolute>::SendGoalOptions();
            send_goal_options.goal_response_callback = std::bind(&PickupAction::goal_response_callback,this,std::placeholders::_1);
            send_goal_options.feedback_callback = std::bind(&PickupAction::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
            send_goal_options.result_callback = std::bind(&PickupAction::result_callback, this, std::placeholders::_1);

            auto rotate_client = pickup_node_->get_rotate_client();

            auto goal_future = rotate_client->async_send_goal(goal, send_goal_options);
            if(rclcpp::spin_until_future_complete(pickup_node_->get_node_base_interface(), 
            goal_future) != rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(pickup_node_->get_logger(), "Send goal failed");
                return BT::NodeStatus::FAILURE;
            }
            // 获取 目标 句柄 goal_future只是表明 发送了goal，并没有得到结果
            auto future = goal_future.get();
            if(!future) {
                RCLCPP_ERROR(pickup_node_->get_logger(), "Goal rejected");
                return BT::NodeStatus::FAILURE;
            }
            // 异步获取结果
            auto reult_future = rotate_client->async_get_result(future);
            // 等待结果返回
            if(rclcpp::spin_until_future_complete(pickup_node_->get_node_base_interface(), 
                reult_future) != rclcpp::FutureReturnCode::SUCCESS) {
                    RCLCPP_ERROR(pickup_node_->get_logger(), "Get result failed");
                    return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(pickup_node_->get_logger(), "我在等待抓取物品结果");
            // 处理结果
            auto result = reult_future.get();
            if(result.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_ERROR(pickup_node_->get_logger(), "PickupAction failed");
                return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction succeeded");
            return BT::NodeStatus::SUCCESS;
        }

    private:
        void goal_response_callback(const rclcpp_action::ClientGoalHandle<turtlesim::action::RotateAbsolute>::SharedPtr& goal_handle) {
            if (!goal_handle) {
                RCLCPP_INFO(pickup_node_->get_logger(), "Goal rejected");
                return;
            }
            RCLCPP_INFO(pickup_node_->get_logger(), "Goal accepted");
        }

        void feedback_callback(const rclcpp_action::ClientGoalHandle<turtlesim::action::RotateAbsolute>::SharedPtr, 
                    const std::shared_ptr<const turtlesim::action::RotateAbsolute::Feedback>& feedback) {
            RCLCPP_INFO(pickup_node_->get_logger(), "Received feedback: %lf", feedback->remaining);
        }

        void result_callback(const rclcpp_action::ClientGoalHandle<turtlesim::action::RotateAbsolute>::WrappedResult& result) {
            RCLCPP_INFO(pickup_node_->get_logger(), "Received result");
            switch(result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction succeeded");
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction aborted");
                    break;
                case rclcpp_action::ResultCode::CANCELED:           
                    RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction canceled");
                    break;
                default:
                    RCLCPP_INFO(pickup_node_->get_logger(), "PickupAction unknown result code");
                    break;
            }
            // 打印最终结果
            RCLCPP_INFO(pickup_node_->get_logger(), "Result: %f", result.result->delta);
        }


    private:
        std::shared_ptr<PickupNode> pickup_node_;
};