/*
 * @Author: hawrkchen
 * @Date: 2025-04-17 15:07:21
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-08 16:38:15
 * @Description: 
 * @FilePath: /dros_dispatch_service/src/action_main.cpp
 */
#include <rclcpp/rclcpp.hpp>

#include "rclcpp_action/rclcpp_action.hpp"

#include "dros_common_interfaces/action/navigate_to_pose.hpp"
#include "turtlesim/action/rotate_absolute.hpp"
#include "dros_common_interfaces/srv/grasp.hpp"
#include "dros_common_interfaces/action/dexterous_hand.hpp"

using NavigateToPose = dros_common_interfaces::action::NavigateToPose;
using RotateAbsolute = turtlesim::action::RotateAbsolute;
using Grasp = dros_common_interfaces::srv::Grasp;
using DexterousHand = dros_common_interfaces::action::DexterousHand;

class NavigateToPoseServer: public rclcpp::Node {
    public:
        NavigateToPoseServer(const std::string& node_name): Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "NavigateToPoseServer has been started");

            action_server_ = rclcpp_action::create_server<NavigateToPose>(
                this, "navigate_to_pose",
                std::bind(&NavigateToPoseServer::goal_callback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&NavigateToPoseServer::cancel_callback, this, std::placeholders::_1),
                std::bind(&NavigateToPoseServer::accept_callback, this, std::placeholders::_1));
            
        }

    private:
        rclcpp_action::GoalResponse goal_callback(
            const rclcpp_action::GoalUUID& uuid,
            const std::shared_ptr<const NavigateToPose::Goal>& goal)
        {
            (void)uuid;
            RCLCPP_INFO(this->get_logger(), "Received goal request with position (%f, %f, %f)", 
            goal->pose.pose.position.x, goal->pose.pose.position.y, goal->pose.pose.position.z);
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        }

        rclcpp_action::CancelResponse cancel_callback(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<NavigateToPose>>& goal_handle)
        {
            RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
            (void)goal_handle;
            return rclcpp_action::CancelResponse::ACCEPT;
        }

        void accept_callback(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<NavigateToPose>>& goal_handle)
        {
            RCLCPP_INFO(this->get_logger(), "Accepting goal");
            //goal_handle->accpet();
            // 开启新的线程
            auto execute_task = [this, goal_handle]() {
                rclcpp::Rate loop_rate(2);
                const auto& goal = goal_handle->get_goal();
                auto feedback = std::make_shared<NavigateToPose::Feedback>();
                auto result = std::make_shared<NavigateToPose::Result>();

                for(int i = 0; i < 10; i++) {
                    if(goal_handle->is_canceling()) {
                        RCLCPP_INFO(this->get_logger(), "Goal is being canceled");
                        //result->error_code = 304;
                        //result->error_msg = "goal is being canceled";
                        goal_handle->canceled(result);
                        return;
                    }
                    feedback->number_of_recoveries++;
                    goal_handle->publish_feedback(feedback);
                    RCLCPP_INFO(this->get_logger(), "Publishing feedback: %d", feedback->number_of_recoveries);
                    loop_rate.sleep();
                }
                // 完成任务
                //result->error_code = 0;
                //result->error_msg = "success";
                goal_handle->succeed(result);
                RCLCPP_INFO(this->get_logger(), "Goal succeeded");
            };
            std::thread{execute_task}.detach();
        }


    private:
        rclcpp_action::Server<NavigateToPose>::SharedPtr action_server_;
};   


class PickupActionServer: public rclcpp::Node {
    public:
        PickupActionServer(const std::string& node_name): Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "PickupActionServer has been started");

            action_server_ = rclcpp_action::create_server<RotateAbsolute>(
                this, "pickup",
                std::bind(&PickupActionServer::goal_callback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&PickupActionServer::cancel_callback, this, std::placeholders::_1),
                std::bind(&PickupActionServer::accept_callback, this, std::placeholders::_1));
            
        }
    private:
        rclcpp_action::GoalResponse goal_callback(
            const rclcpp_action::GoalUUID& uuid,
            const std::shared_ptr<const RotateAbsolute::Goal>& goal)
        {
            (void)uuid;
            RCLCPP_INFO(this->get_logger(), "Received goal request with angle %f", goal->theta);
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        }

        rclcpp_action::CancelResponse cancel_callback(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<RotateAbsolute>>& theta)
        {
            RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
            (void)theta;
            return rclcpp_action::CancelResponse::ACCEPT;
        }

        void accept_callback(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<RotateAbsolute>>& goal_handle)
        {
            RCLCPP_INFO(this->get_logger(), "Accepting goal");
            //goal_handle->accpet();
            // 开启新的线程
            auto execute_task = [this, goal_handle]() {
                rclcpp::Rate loop_rate(2);
                const auto& goal = goal_handle->get_goal();
                auto feedback = std::make_shared<RotateAbsolute::Feedback>();
                auto result = std::make_shared<RotateAbsolute::Result>();

                for(int i = 0; i < 10; i++) {
                    if(goal_handle->is_canceling()) {
                        RCLCPP_INFO(this->get_logger(), "Goal is being canceled");
                        result->delta = 0.00;
                        goal_handle->canceled(result);
                        return;
                    }
                    feedback->remaining++;
                    goal_handle->publish_feedback(feedback);
                    RCLCPP_INFO(this->get_logger(), "Publishing feedback: %f", feedback->remaining);
                    loop_rate.sleep();
                }
                // 完成任务
                result->delta += 10;
                goal_handle->succeed(result);
                RCLCPP_INFO(this->get_logger(), "Goal succeeded");
            };
            std::thread{execute_task}.detach();
        }


    private:
        rclcpp_action::Server<RotateAbsolute>::SharedPtr action_server_;
};

// 灵巧手 动作action
class DexterousHandActionServer: public rclcpp::Node {
    public:
        DexterousHandActionServer(const std::string& node_name): Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "DexterousHandActionServer has been started");
            action_server_ = rclcpp_action::create_server<DexterousHand>(
                this, "hand_control_module",
                std::bind(&DexterousHandActionServer::goal_callback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&DexterousHandActionServer::cancel_callback, this, std::placeholders::_1),
                std::bind(&DexterousHandActionServer::accept_callback, this, std::placeholders::_1));
            
        }
    
    private:
        rclcpp_action::GoalResponse goal_callback(
            const rclcpp_action::GoalUUID& uuid,
            const std::shared_ptr<const DexterousHand::Goal>& goal)
        {
            (void)uuid;
            RCLCPP_INFO(this->get_logger(), "Received goal request with angle %d", goal->target_position);
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        }

        rclcpp_action::CancelResponse cancel_callback(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<DexterousHand>>& theta)
        {
            RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
            (void)theta;
            return rclcpp_action::CancelResponse::ACCEPT;
        }

        void accept_callback(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle<DexterousHand>>& goal_handle)
        {
            RCLCPP_INFO(this->get_logger(), "Accepting goal");
            //goal_handle->accpet();
            // 开启新的线程
            auto execute_task = [this, goal_handle]() {
                rclcpp::Rate loop_rate(2);
                const auto& goal = goal_handle->get_goal();
                auto feedback = std::make_shared<DexterousHand::Feedback>();
                auto result = std::make_shared<DexterousHand::Result>();

                for(int i = 0; i < 10; i++) {
                    if(goal_handle->is_canceling()) {
                        RCLCPP_INFO(this->get_logger(), "Goal is being canceled");
                        result->msg = "success";
                        goal_handle->canceled(result);
                        return;
                    }
                    feedback->progress++;
                    goal_handle->publish_feedback(feedback);
                    RCLCPP_INFO(this->get_logger(), "Publishing feedback: %f", feedback->progress);
                    loop_rate.sleep();
                }
                // 完成任务
                result->success = true;
                result->msg = "success";
                goal_handle->succeed(result);
                RCLCPP_INFO(this->get_logger(), "Goal succeeded");
            };
            std::thread{execute_task}.detach();
        }


    private:
        rclcpp_action::Server<DexterousHand>::SharedPtr action_server_;
};

class GraspServer: public rclcpp::Node {
    public:
        GraspServer(const std::string& node_name): Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "GraspServer has been started");
            grasp_service_ = this->create_service<Grasp>("grasp", std::bind(&GraspServer::grasp_callback, 
                this, std::placeholders::_1, std::placeholders::_2));
        }

    private:
        rclcpp::Service<Grasp>::SharedPtr grasp_service_;
        
        void grasp_callback(const std::shared_ptr<Grasp::Request>& request, const std::shared_ptr<Grasp::Response>& response) {
            RCLCPP_INFO(this->get_logger(), "Received request to grasp object");
            RCLCPP_INFO(this->get_logger(), "Grasping object:%s", request->object_name.c_str());

            response->err_code = 0;
            response->err_msg = "success";
        }
    
};


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    
    auto navigate_to_pose_server = std::make_shared<NavigateToPoseServer>("navigate_to_pose_server");
    auto pickup_action_server = std::make_shared<PickupActionServer>("pickup_action_server");
    auto grasp_server = std::make_shared<GraspServer>("grasp_server");
    auto dex_server = std::make_shared<DexterousHandActionServer>("dex_server");

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(pickup_action_server);
    executor.add_node(navigate_to_pose_server);
    executor.add_node(grasp_server);
    executor.add_node(dex_server);

    executor.spin();
    rclcpp::shutdown();
    /*
    auto pickup_action_server = std::make_shared<PickupActionServer>("pickup_action_server");
    rclcpp::spin(pickup_action_server); // 阻塞
    rclcpp::shutdown();
    */
    return 0;   
}