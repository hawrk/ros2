/*
 * @Author: hawrkchen
 * @Date: 2025-04-16 15:28:43
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-06-05 11:26:32
 * @Description: 任务分发，初始化BehaviorTreeFactory
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/dispatch_node.hpp
 */
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "dros_dispatch_service/navigation_node.hpp"
#include "dros_dispatch_service/pickup_node.hpp"
#include "dros_dispatch_service/grasp_node.hpp"
#include "dros_dispatch_service/dexterous_hand_node.hpp"
#include "dros_dispatch_service/voiceplay_node.hpp"

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
            nav_node_ = std::make_unique<NavigationNode>("navigation_node");
            pickup_node_ = std::make_shared<PickupNode>("pickup_node");
            grasp_node_ = std::make_shared<GraspNode>("grasp_node");
            dexterous_hand_node_ = std::make_shared<DexterousHandNode>("dexterous_hand_node");
            voice_play_node_ = std::make_shared<VoicePlayNode>("voice_play_node");

            // 初始化BehaviorTreeFactory
            // factory_.registerNodeType<NavigateToPoseAction>("NavigateToPoseAction",
            //     [this](const std::string& name, const BT::NodeConfig& config) {
            //         return std::make_unique<NavigateToPoseAction>(name, config, nav_node_); 
            //     });
            factory_.registerNodeType<NavigateToPoseAction>("NavigateToPoseAction", nav_node_);
            factory_.registerNodeType<PickupAction>("PickupAction", pickup_node_);
            factory_.registerNodeType<GraspAction>("GraspAction", grasp_node_);
            factory_.registerNodeType<DexterousHandAction>("DexterousHandAction", dexterous_hand_node_);
            factory_.registerNodeType<VoicePlayPublisher>("VoicePlayPublisher", voice_play_node_);

            // <PickupAction item_name="{item_name}" />

            // 初始行为树XML字符串
            std::string xml_string = R"(
            <root BTCPP_format="4">
                <BehaviorTree ID="MainTree">
                    <Sequence name="root">
                        <NavigateToPoseAction  goal_pose="{goal_pose}" />
                        <PickupAction item_name="{item_name}" />
                        <GraspAction grasp_name="{grasp_name}" />
                        <DexterousHandAction target_position="{target_position}" />
                    </Sequence>
                </BehaviorTree>
            </root>
            )";
            BT::Blackboard::Ptr blackboard = BT::Blackboard::create();
            blackboard->set("goal_pose", geometry_msgs::msg::PoseStamped{});
            blackboard->set("item_name", std::string{"pickup_item"});
            blackboard->set("grasp_name", std::string{"grasp_item"});
            blackboard->set("target_position", std::string{"target_position"});
            // 解析XML字符串
            tree_ = factory_.createTreeFromText(xml_string, blackboard);
        }

        std::string process_policy(const std::string& task_string) {
            try {
                if(running_) {
                    RCLCPP_ERROR(this->get_logger(), "BehaviorTree is still running, skip...");
                    return {"当前行为树正在执行,当前任务执行失败!"};
                }
                std::string xml_string = create_bt_xml_from_message(task_string);
                if(xml_string.empty()) {
                    RCLCPP_INFO(this->get_logger(), "Failed to create BT XML from message, skip...");
                    return {"xml字符串解析错误,行为树构建失败!"};
                }
                // RCLCPP_INFO(this->get_logger(), "cur bt node status: %d", int(bt_status_));
                // if(this->bt_status_ == BT::NodeStatus::RUNNING) {
                //     RCLCPP_ERROR(this->get_logger(), "BehaviorTree is still running, skip...");
                //     return {"当前行为树正在执行,当前任务执行失败!"};
                // }
                
                BT::Blackboard::Ptr blackboard = BT::Blackboard::create();
                // 这里可以设置 多个值，供不同的模块节点
                blackboard->set("goal_pose", create_goal_pose_from_message(task_string));  // 该参数为导航物品的目标坐标
                blackboard->set("user_goal", create_user_goal_from_message(task_string));   // 目标用户的坐标
                blackboard->set("item_name", create_pickup_item_from_message(task_string));  // 暂时不用
                blackboard->set("grasp_name", create_pickup_item_from_message(task_string));  // 智能小车抓取
                blackboard->set("target_position", create_pickup_item_from_message(task_string));  // 拿水操作
                blackboard->set("pass_to", create_passto_item_from_message(task_string));  // 传递物品操作

                tree_ = factory_.createTreeFromText(xml_string, blackboard);

            } catch(const std::exception& e) {
                RCLCPP_ERROR(this->get_logger(), "Failed to create tree from text: %s", e.what());
                return {"xml字符串解析错误,行为树构建失败!"};
            }
            running_ = true;
            bt_status_ = tree_.tickWhileRunning();
            // 检查行为树的状态
            switch(bt_status_) {
                case BT::NodeStatus::SUCCESS:
                    RCLCPP_INFO(this->get_logger(), "Task completed successfully");
                    break;
                case BT::NodeStatus::FAILURE:
                    RCLCPP_INFO(this->get_logger(), "Task failed");
                    break;
                case BT::NodeStatus::RUNNING:
                    RCLCPP_INFO(this->get_logger(), "Task is running");
                    break;
                default:
                    RCLCPP_INFO(this->get_logger(), "Task status unknown");
            }
            running_ = false;
            return {"任务执行成功!"};
        }

        // 处理来自http的请求
        std::string receive_http_task(const std::string& body_string) {
            return process_policy(body_string);
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
                    if(go_to.at("obj_name").get<std::string>() == "table") {
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
            }

            return goal_pose;
        }
        // 用户坐标，目前还拿不到
        geometry_msgs::msg::PoseStamped create_user_goal_from_message(const std::string& message) {
            //std::cout <<"create_user_goal_from_message"<< message << std::endl;
            geometry_msgs::msg::PoseStamped goal_pose;

            json j = json::parse(message);
            // 设置目标姿态的各个字段
            const auto& plan_seq = j["data"]["plan_seq"];
            for(const auto& item : plan_seq) {
                if(item.contains("go_to")) {
                    const auto& go_to = item["go_to"];
                    if(go_to.at("obj_name").get<std::string>() == "user") {
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

        dros_common_interfaces::action::DexterousHand::Goal create_passto_item_from_message(const std::string& message) {
            auto dexterous_hand = dros_common_interfaces::action::DexterousHand::Goal();
            json j = json::parse(message);
            const auto& plan_seq = j["data"]["plan_seq"];
            for(const auto& item : plan_seq) {
                if(item.contains("pass_to")) {
                    const auto& pick_up = item["pass_to"];
                    dexterous_hand.obj_name = pick_up.at("obj_name").get<std::string>();
                    dexterous_hand.target_position = 11;
                    break;
                }
            }
            return dexterous_hand;
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
                        // 再判断一下go_to 到水杯还是用户
                        const auto& go_to = item["go_to"];
                        if(go_to.at("obj_name").get<std::string>() == "table") {  // 到水杯坐标
                            actions += "    <NavigateToPoseAction  goal_pose=\"{goal_pose}\" />\n";
                        } else {   // 其他的先默认为用户
                            actions += "    <NavigateToPoseAction  user_goal=\"{user_goal}\" />\n";
                        }

                    }
                    if(item.contains("pick_up")) {
                        //actions += "\t\t\t\t<GraspAction grasp_name=\"{grasp_name}\" />\n";  
                        actions += "\t\t\t\t<DexterousHandAction target_position=\"{target_position}\" />\n";     
                    }
                    if(item.contains("pass_to")) {   // 传递物品操作时增加一个语音播放指令
                       actions += "\t\t\t\t<VoicePlayPublisher />\n";  
                       actions += "\t\t\t\t<DexterousHandAction pass_to=\"{pass_to}\" />\n";

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
        BT::NodeStatus bt_status_;
        bool running_ = false;

        std::shared_ptr<NavigationNode> nav_node_;
        std::shared_ptr<PickupNode> pickup_node_;
        std::shared_ptr<GraspNode> grasp_node_;
        std::shared_ptr<DexterousHandNode> dexterous_hand_node_;
        std::shared_ptr<VoicePlayNode> voice_play_node_;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr module_sub_;   // 接受思模块任务派发

};