/*
 * @Author: hawrkchen
 * @Date: 2025-04-16 15:28:43
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-04-23 10:34:02
 * @Description: 任务分发，初始化BehaviorTreeFactory
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/dispatch_node.hpp
 */
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "dros_dispatch_service/navigation_node.hpp"
#include "dros_dispatch_service/pickup_node.hpp"

#include "behaviortree_cpp/bt_factory.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DispatchNode : public rclcpp::Node
{
    public:
        DispatchNode(const std::string& name):Node(name) {
            RCLCPP_INFO(this->get_logger(), "Initializing DispatchNode");

            module_sub_ = this->create_subscription<std_msgs::msg::String>(
                "module_task", 10, std::bind(&DispatchNode::module_callback, this, std::placeholders::_1));
            // 初始化 NavigationNode
            nav_node_ = std::make_shared<NavigationNode>("navigation_node");
            pickup_node_ = std::make_shared<PickupNode>("pickup_node");
            // 初始化BehaviorTreeFactory
            // factory_.registerNodeType<NavigateToPoseAction>("NavigateToPoseAction",
            //     [this](const std::string& name, const BT::NodeConfig& config) {
            //         return std::make_unique<NavigateToPoseAction>(name, config); 
            //     });
            factory_.registerNodeType<NavigateToPoseAction>("NavigateToPoseAction", nav_node_);
            factory_.registerNodeType<PickupAction>("PickupAction", pickup_node_);

            // 初始行为树XML字符串
            std::string xml_string = R"(
            <root BTCPP_format="4">
                <BehaviorTree ID="MainTree">
                    <Sequence name="root">
                        <NavigateToPoseAction  goal_pose="{goal_pose}" />
                        <PickupAction item_name="{item_name}" />
                    </Sequence>
                </BehaviorTree>
            </root>
            )";
            BT::Blackboard::Ptr blackboard = BT::Blackboard::create();
            blackboard->set("goal_pose", geometry_msgs::msg::PoseStamped{});
            blackboard->set("item_name", std::string{"pickup_item"});
            // 解析XML字符串
            tree_ = factory_.createTreeFromText(xml_string, blackboard);
        }

    private:

        void module_callback(const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "Received module task: %s", msg->data.c_str());
            // 解析任务字符串，并设置树的输入参数
            std::string task_string = msg->data;
            try {
                // json 串转化为 bt xml 串
                // std::string xml_string = R"(
                // <root BTCPP_format="4">
                //     <BehaviorTree ID="MainTree">
                //         <Sequence name="root">
                //             <NavigateToPoseAction goal_pose="{goal_pose}" />
                //             <PickupAction item_name="{item_name}" />
                //         </Sequence>
                //     </BehaviorTree>
                // </root>
                // )";

                std::string xml_string = R"(
                <root BTCPP_format="4">
                    <BehaviorTree ID="MainTree">
                        <Sequence name="root">
                            <NavigateToPoseAction goal_pose="{goal_pose}" />
                            <PickupAction item_name="{item_name}" />
                        </Sequence>
                    </BehaviorTree>
                </root>
                )";
                
                BT::Blackboard::Ptr blackboard = BT::Blackboard::create();
                // 这里可以设置 多个值，供不同的模块节点
                blackboard->set("goal_pose", create_goal_pose_from_message(task_string));
                blackboard->set("item_name", std::string{"pickup_item"});
                tree_ = factory_.createTreeFromText(xml_string, blackboard);

            } catch(const std::exception& e) {
                RCLCPP_ERROR(this->get_logger(), "Failed to create tree from text: %s", e.what());
            }

            tree_.tickWhileRunning();
        }

        geometry_msgs::msg::PoseStamped create_goal_pose_from_message(const std::string& message) {
            std::cout <<"create_goal_pose_from_message"<< message << std::endl;
            geometry_msgs::msg::PoseStamped goal_pose;

            json j = json::parse(message);
            // 设置目标姿态的各个字段
            goal_pose.header.frame_id = j.at("frame_id").get<std::string>();
            goal_pose.header.stamp = nav_node_->now();

            goal_pose.pose.position.x = j.at("position").at("x").get<double>();
            goal_pose.pose.position.y = j.at("position").at("y").get<double>();
            goal_pose.pose.position.z = j.at("position").at("z").get<double>();
            goal_pose.pose.orientation.x = j.at("orientation").at("x").get<double>();
            goal_pose.pose.orientation.y = j.at("orientation").at("y").get<double>();
            goal_pose.pose.orientation.z = j.at("orientation").at("z").get<double>();
            goal_pose.pose.orientation.w = j.at("orientation").at("w").get<double>();

            return goal_pose;
        }


    private:
        BT::BehaviorTreeFactory factory_;
        BT::Tree tree_;

        std::shared_ptr<NavigationNode> nav_node_;
        std::shared_ptr<PickupNode> pickup_node_;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr module_sub_;   // 接受思模块任务派发

};