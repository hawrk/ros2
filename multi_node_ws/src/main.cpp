/*
 * @Author: hawrkchen
 * @Date: 2025-05-23 09:44:05
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-23 10:21:49
 * @Description: 
 * @FilePath: /multi_node_ws/src/main.cpp
 */
#include <cstdio>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>

class MultiNode : public rclcpp::Node {
  public:
    MultiNode(const std::string& name) : Node(name) {
      RCLCPP_INFO(this->get_logger(), "MultiNode  start");

      callback_group = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
      callback_group_2 = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

      auto sub1_opt = rclcpp::SubscriptionOptions();
      sub1_opt.callback_group = callback_group;

      auto sub2_opt = rclcpp::SubscriptionOptions();
      sub2_opt.callback_group = callback_group_2;

      sub1_ = this->create_subscription<std_msgs::msg::String>(
        "topic1", 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
          RCLCPP_INFO(this->get_logger(), "topic1: %s", msg->data.c_str());
          RCLCPP_INFO(this->get_logger(), "我收到topic1的消息,但是会等待很长时间");
          std::this_thread::sleep_for(std::chrono::seconds(100));
        },sub1_opt);

      sub2_ = this->create_subscription<std_msgs::msg::String>(
        "topic2", 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
          RCLCPP_INFO(this->get_logger(), "topic2: %s", msg->data.c_str());
        },sub2_opt);
  }

  private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub1_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub2_;

    rclcpp::CallbackGroup::SharedPtr callback_group;
    rclcpp::CallbackGroup::SharedPtr callback_group_2;

};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions options;
  options.use_global_arguments(false);

  auto node = std::make_shared<MultiNode>("multi_node");

  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node->get_node_base_interface());

  executor.spin();

  rclcpp::shutdown();
  return 0;
}
