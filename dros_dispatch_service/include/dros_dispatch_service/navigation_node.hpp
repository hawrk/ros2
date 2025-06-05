/*
 * @Author: hawrkchen
 * @Date: 2025-04-16 17:02:29
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-30 09:18:58
 * @Description: 
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/navigation_node.hpp
 */

#pragma once

#include <rclcpp/rclcpp.hpp>

#include "rclcpp_action/rclcpp_action.hpp"

#include "dros_common_interfaces/action/navigate_to_pose.hpp"

#include "behaviortree_cpp/bt_factory.h"

using NavigateToPose = dros_common_interfaces::action::NavigateToPose;

class NavigationNode : public rclcpp::Node {
    public:
        NavigationNode(const std::string& node_name):Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "NavigationNode start......");

            reentrant_callback_group_ = this->create_callback_group(
                rclcpp::CallbackGroupType::Reentrant);
    
            // 创建客户端
            this->action_client_ = rclcpp_action::create_client<NavigateToPose>(
                this, 
                "navigate_to_pose",
                reentrant_callback_group_); 
            // 等待action服务器
            while(!this->action_client_->wait_for_action_server(std::chrono::seconds(10)))   {
                RCLCPP_INFO(this->get_logger(), "waitting for action server....");
                if(!rclcpp::ok()) {
                    RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for action server to be up");
                    rclcpp::shutdown();
                    return;
                }
            }
            
        }

        rclcpp_action::Client<NavigateToPose>::SharedPtr get_action_client() {
            return this->action_client_;
        }
        
    private:
        rclcpp_action::Client<NavigateToPose>::SharedPtr action_client_;
        rclcpp::CallbackGroup::SharedPtr reentrant_callback_group_;
};



class NavigateToPoseAction :  public BT::SyncActionNode {
    public:
        NavigateToPoseAction(const std::string& name, const BT::NodeConfig& config, 
        std::shared_ptr<NavigationNode> nav_node):
         BT::SyncActionNode(name, config), nav_node_(nav_node) {

            RCLCPP_INFO(nav_node_->get_logger(), "NavigateToPoseAction start......");
            //nav_node_ = std::make_shared<NavigationNode>("NavigationNode");    
        }

        static BT::PortsList providedPorts() {
            //return {BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose")};
            return {
                BT::InputPort<geometry_msgs::msg::PoseStamped>("goal_pose"),
                BT::InputPort<geometry_msgs::msg::PoseStamped>("user_goal")
            };
        }


        BT::NodeStatus tick() override {
            RCLCPP_INFO(nav_node_->get_logger(), "NavigateToPoseAction tick......");
            auto origoal_pose = this->getInput<geometry_msgs::msg::PoseStamped>("goal_pose");
            auto user_pose = this->getInput<geometry_msgs::msg::PoseStamped>("user_goal");
            
            NavigateToPose::Goal goal_msg;
            if(origoal_pose) {
                goal_msg.pose = origoal_pose.value();
                RCLCPP_INFO(nav_node_->get_logger(), "test ::get goal_pose:%lf, %lf, %lf", 
                    origoal_pose->pose.position.x, 
                    origoal_pose->pose.position.y,  
                    origoal_pose->pose.position.z);
            } else if(user_pose) {
                goal_msg.pose = user_pose.value();
                RCLCPP_INFO(nav_node_->get_logger(), "test ::get user_pose:%lf, %lf, %lf", 
                    user_pose->pose.position.x, 
                    user_pose->pose.position.y,  
                    user_pose->pose.position.z);
            }

            auto send_goal_options = rclcpp_action::Client<NavigateToPose>::SendGoalOptions();
            send_goal_options.goal_response_callback = std::bind(&NavigateToPoseAction::goal_response_callback,this,std::placeholders::_1);
            send_goal_options.feedback_callback = std::bind(&NavigateToPoseAction::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
            send_goal_options.result_callback = std::bind(&NavigateToPoseAction::result_callback, this, std::placeholders::_1);

            auto nav_client = nav_node_->get_action_client();

            auto goal_future = nav_client->async_send_goal(goal_msg, send_goal_options);
            if(rclcpp::spin_until_future_complete(nav_node_->get_node_base_interface(), 
            goal_future) != rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(nav_node_->get_logger(), "Send goal_msg failed");
                return BT::NodeStatus::FAILURE;
            }
            // 获取 目标 句柄 goal_future只是表明 发送了goal，并没有得到结果
            auto future = goal_future.get();
            if(!future) {
                RCLCPP_ERROR(nav_node_->get_logger(), "goal_msg rejected");
                return BT::NodeStatus::FAILURE;
            }
            // 异步获取结果
            auto reult_future = nav_client->async_get_result(future);
            // 等待结果返回
            if(rclcpp::spin_until_future_complete(nav_node_->get_node_base_interface(), 
                reult_future) != rclcpp::FutureReturnCode::SUCCESS) {
                    RCLCPP_ERROR(nav_node_->get_logger(), "Get result failed");
                    return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(nav_node_->get_logger(), "我在等待导航结果");
            // 处理结果
            auto result = reult_future.get();
            if(result.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_ERROR(nav_node_->get_logger(), "Navigation failed");
                return BT::NodeStatus::FAILURE;
            }
            RCLCPP_INFO(nav_node_->get_logger(), "Navigation succeeded");
            return BT::NodeStatus::SUCCESS;
        }

    private:
        // action 请求回调
        void goal_response_callback(const rclcpp_action::ClientGoalHandle<NavigateToPose>::SharedPtr& goal_handle) {
            if (!goal_handle) {
                RCLCPP_ERROR(nav_node_->get_logger(), "Goal handle is null");
                return;
            }
            RCLCPP_INFO(nav_node_->get_logger(), "Goal accepted");
        }

        // action 反馈回调
        void feedback_callback(const rclcpp_action::ClientGoalHandle<NavigateToPose>::SharedPtr, 
                    const std::shared_ptr<const NavigateToPose::Feedback>& feedback) {
            RCLCPP_INFO(nav_node_->get_logger(), "Received feedback");
            const geometry_msgs::msg::PoseStamped &current_pose = feedback->current_pose;
            RCLCPP_INFO(nav_node_->get_logger(), "get pos:%lf, %lf, %lf", current_pose.pose.position.x, 
            current_pose.pose.position.y, 
            current_pose.pose.position.z);
        }

        // action 结果回调
        void result_callback(const rclcpp_action::ClientGoalHandle<NavigateToPose>::WrappedResult& result) {
            RCLCPP_INFO(nav_node_->get_logger(), "Received result");
            switch(result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(nav_node_->get_logger(), "goal process successful");
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_ERROR(nav_node_->get_logger(), "goal was aborted");
                    return;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_ERROR(nav_node_->get_logger(), "goal was cancel");
                    return;
                default:
                    RCLCPP_ERROR(nav_node_->get_logger(), "unknown result code");
                    return;
                /*
                case nav2_msgs::action::NavigateToPose::Result::SUCCEEDED:
                    RCLCPP_INFO(this->get_logger(), "Succeeded");
                    break;
                case nav2_msgs::action::NavigateToPose::Result::CANCELED:
                    RCLCPP_INFO(this->get_logger(), "Canceled");
                    break;
                case nav2_msgs::action::NavigateToPose::Result::ABORTED:
                    RCLCPP_INFO(this->get_logger(), "Aborted");
                    break;
                case nav2_msgs::action::NavigateToPose::Result::REJECTED:
                    RCLCPP_INFO(this->get_logger(), "Rejected");
                    break;
                case nav2_msgs::action::NavigateToPose::Result::PREEMPTED:
                    RCLCPP_INFO(this->get_logger(), "Preempted");
                    break;
                default:
                    RCLCPP_INFO(this->get_logger(), "Unknown status");
                    break;
                */
            }
            // 打印最终结果
            RCLCPP_INFO(nav_node_->get_logger(), "get result end");
            //RCLCPP_INFO(nav_node_->get_logger(), "get result:code:%d, msg:%s", 
            //result.result->error_code, result.result->error_msg.c_str());
        }

    private:    
        std::shared_ptr<NavigationNode> nav_node_;
};