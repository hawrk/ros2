/*
 * @Author: hawrkchen
 * @Date: 2025-04-28 14:29:53
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-30 08:56:49
 * @Description: 
 * @FilePath: /dros_dispatch_service/include/dros_dispatch_service/grasp_node.hpp
 */
#include <rclcpp/rclcpp.hpp>
#include <dros_common_interfaces/srv/grasp.hpp>

#include "behaviortree_cpp/bt_factory.h"

using Grasp = dros_common_interfaces::srv::Grasp;

class GraspNode : public rclcpp::Node {
    public:
        GraspNode(const std::string& node_name):Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "Creating grasp node...");
            this->client_ = this->create_client<Grasp>("grasp");
            while(!this->client_->wait_for_service(std::chrono::seconds(10))) {
                RCLCPP_INFO(this->get_logger(), "Waiting for grasp  server to be up...");
                if(!rclcpp::ok()) {
                    RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for action server to be up");
                    rclcpp::shutdown();
                    return;
                }
            }
        }

        rclcpp::Client<Grasp>::SharedPtr get_grasp_client() {
            return this->client_;
        }


    private:
        rclcpp::Client<Grasp>::SharedPtr client_;
};

class GraspAction: public BT::SyncActionNode {
    public:
        GraspAction(const std::string& name, const BT::NodeConfig& config,
        std::shared_ptr<GraspNode> grasp_node): BT::SyncActionNode(name, config), grasp_node_(grasp_node) {
            RCLCPP_INFO(grasp_node_->get_logger(), "Creating grasp action...");
        }

        static BT::PortsList providedPorts() {
            return {BT::InputPort<std::string>("grasp_name")};
        }

        BT::NodeStatus tick() override {
            RCLCPP_INFO(grasp_node_->get_logger(), "Grasp action tick...");
            auto grasp_name = this->getInput<std::string>("grasp_name").value();
            RCLCPP_INFO(grasp_node_->get_logger(), "Grasp action: grasp_name: %s", grasp_name.c_str());

            //turtlesim::srv::Spawn::Request request;
            auto request = std::make_shared<Grasp::Request>();
   
            request->object_name = grasp_name;

            auto result = grasp_node_->get_grasp_client()->async_send_request(request);
            RCLCPP_INFO(grasp_node_->get_logger(), "我在等待抓取结果！");
            if(rclcpp::spin_until_future_complete(this->grasp_node_->get_node_base_interface(), result) 
              != rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(grasp_node_->get_logger(), "Failed to call grasp service");
                return BT::NodeStatus::FAILURE;
            }
            auto response = result.get();
            RCLCPP_INFO(grasp_node_->get_logger(), "Grasp action succeeded, response: %s", response->err_msg.c_str());
            return BT::NodeStatus::SUCCESS;
        }

    private:
        std::shared_ptr<GraspNode> grasp_node_;
};