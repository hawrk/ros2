/*
 * @Author: hawrkchen
 * @Date: 2025-04-16 15:28:43
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-07 13:40:05
 * @Description: 任务分发，初始化BehaviorTreeFactory
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/dispatch_node.hpp
 */
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "dros_dispatch_service/navigation_node.hpp"
#include "dros_dispatch_service/pickup_node.hpp"
#include "dros_dispatch_service/grasp_node.hpp"

#include "behaviortree_cpp/bt_factory.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DispatchNode : public rclcpp::Node
{
    public:
        DispatchNode(const std::string& name):Node(name) {
            RCLCPP_INFO(this->get_logger(), "Initializing DispatchNode");

            module_sub_ = this->create_subscription<std_msgs::msg::String>(
                "/task_planning", 10, std::bind(&DispatchNode::receive_module_callback, this, std::placeholders::_1));
            // 初始化 NavigationNode
            nav_node_ = std::make_shared<NavigationNode>("navigation_node");
            pickup_node_ = std::make_shared<PickupNode>("pickup_node");
            grasp_node_ = std::make_shared<GraspNode>("grasp_node");
            // 初始化BehaviorTreeFactory
            // factory_.registerNodeType<NavigateToPoseAction>("NavigateToPoseAction",
            //     [this](const std::string& name, const BT::NodeConfig& config) {
            //         return std::make_unique<NavigateToPoseAction>(name, config); 
            //     });
            factory_.registerNodeType<NavigateToPoseAction>("NavigateToPoseAction", nav_node_);
            factory_.registerNodeType<PickupAction>("PickupAction", pickup_node_);
            factory_.registerNodeType<GraspAction>("GraspAction", grasp_node_);

            // <PickupAction item_name="{item_name}" />

            // 初始行为树XML字符串
            std::string xml_string = R"(
            <root BTCPP_format="4">
                <BehaviorTree ID="MainTree">
                    <Sequence name="root">
                        <NavigateToPoseAction  goal_pose="{goal_pose}" />
                        <PickupAction item_name="{item_name}" />
                        <GraspAction grasp_name="{grasp_name}" />
                    </Sequence>
                </BehaviorTree>
            </root>
            )";
            BT::Blackboard::Ptr blackboard = BT::Blackboard::create();
            blackboard->set("goal_pose", geometry_msgs::msg::PoseStamped{});
            blackboard->set("item_name", std::string{"pickup_item"});
            blackboard->set("grasp_name", std::string{"grasp_item"});
            // 解析XML字符串
            tree_ = factory_.createTreeFromText(xml_string, blackboard);
        }

        void process_policy(const std::string& task_string) {
            try {
                std::string xml_string = create_bt_xml_from_message(task_string);
                if(xml_string.empty()) {
                    RCLCPP_INFO(this->get_logger(), "Failed to create BT XML from message, skip...");
                    return ;
                }
                
                BT::Blackboard::Ptr blackboard = BT::Blackboard::create();
                // 这里可以设置 多个值，供不同的模块节点
                blackboard->set("goal_pose", create_goal_pose_from_message(task_string));
                blackboard->set("item_name", create_pickup_item_from_message(task_string));
                blackboard->set("grasp_name", create_pickup_item_from_message(task_string));
                tree_ = factory_.createTreeFromText(xml_string, blackboard);

            } catch(const std::exception& e) {
                RCLCPP_ERROR(this->get_logger(), "Failed to create tree from text: %s", e.what());
                return ;
            }

            tree_.tickWhileRunning();
        }

        // 处理来自http的请求
        void receive_http_task(const std::string& body_string) {
            process_policy(body_string);
        }

    private:
        // 处理来自ros2 topic的任务
        void receive_module_callback(const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "Received module task: %s", msg->data.c_str());
            // 解析任务字符串，并设置树的输入参数
            std::string task_string = msg->data;
            process_policy(task_string);
        }

        geometry_msgs::msg::PoseStamped create_goal_pose_from_message(const std::string& message) {
            //std::cout <<"create_goal_pose_from_message"<< message << std::endl;
            geometry_msgs::msg::PoseStamped goal_pose;

            json j = json::parse(message);
            // 设置目标姿态的各个字段
            const auto& plan_seq = j["data"]["plan_seq"];
            for(const auto& item : plan_seq) {
                if(item.contains("go_to")) {
                    const auto& go_to = item["go_to"];
                    goal_pose.header.frame_id = go_to.at("obj_name").get<std::string>();
                    goal_pose.header.stamp = nav_node_->now();

                    goal_pose.pose.position.x = go_to.at("obj_loc").at("x").get<double>();
                    goal_pose.pose.position.y = go_to.at("obj_loc").at("y").get<double>();
                    goal_pose.pose.position.z = go_to.at("obj_loc").at("z").get<double>();
                    goal_pose.pose.orientation.x = go_to.at("obj_loc").at("dx").get<double>();
                    goal_pose.pose.orientation.y = go_to.at("obj_loc").at("dy").get<double>();
                    goal_pose.pose.orientation.z = go_to.at("obj_loc").at("dz").get<double>();
                    //goal_pose.pose.orientation.w = go_to.at("obj_loc").at("w").get<double>();
                    break;
                }
            }

            return goal_pose;
        }

        std::string create_pickup_item_from_message(const std::string& message) {
            json j = json::parse(message);
            const auto& plan_seq = j["data"]["plan_seq"];
            for(const auto& item : plan_seq) {
                if(item.contains("pick_up")) {
                    const auto& pick_up = item["pick_up"];
                    return pick_up.at("obj_name").get<std::string>();
                }
            }
            return "";
        }


        std::string create_bt_xml_from_message(const std::string& message) {
            std::cout <<"create_bt_xml_from_message" << std::endl;
            std::string xml_template = R"(
                <root BTCPP_format="4">
                    <BehaviorTree ID="MainTree">
                        <Sequence name="root">
                            {actions}
                        </Sequence>
                    </BehaviorTree>
                </root>
            )";

            std::string actions = "";
            json j = json::parse(message);
            if(j.contains("data") && j["data"].contains("plan_seq") 
                && j["data"]["plan_seq"].is_array() && !j["data"]["plan_seq"].empty()) {
                const auto& plan_seq = j["data"]["plan_seq"];
                for(const auto& item : plan_seq) {
                    if(item.contains("go_to")) {
                        actions += "    <NavigateToPoseAction  goal_pose=\"{goal_pose}\" />\n";
                    }
                    if(item.contains("pick_up")) {
                        actions += "\t\t\t\t<GraspAction grasp_name=\"{grasp_name}\" />\n";     
                    }
                }
            } else {
                return "";
            }
            std::string xml_string = xml_template;
            xml_string = xml_string.replace(xml_string.find("{actions}"), 9, actions);

            std::cout << "xml_string: " << xml_string << std::endl;
            return xml_string;
        }


    private:
        BT::BehaviorTreeFactory factory_;
        BT::Tree tree_;

        std::shared_ptr<NavigationNode> nav_node_;
        std::shared_ptr<PickupNode> pickup_node_;
        std::shared_ptr<GraspNode> grasp_node_;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr module_sub_;   // 接受思模块任务派发

};