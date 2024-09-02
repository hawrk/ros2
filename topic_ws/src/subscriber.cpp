/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-29 09:45:39
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-29 09:55:30
 * @FilePath: /topic_ws/src/subscriber.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class TopicSubscriber: public rclcpp::Node {
    public:
      TopicSubscriber(const std::string& name):Node(name) {
        RCLCPP_INFO(this->get_logger(), "启动节点:[%s]", name.c_str());

        sub_ = this->create_subscription<std_msgs::msg::String>("sayhi", 100, 
        std::bind(&TopicSubscriber::subscribe_cb, this, std::placeholders::_1));
      }

    private:
      rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

      void subscribe_cb(const std_msgs::msg::String::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "收到节点:[%s]", msg->data.c_str());
      }
      
};


int main(int argc,char* argv[]) {
    rclcpp::init(argc,argv);
    auto sub_node = std::make_shared<TopicSubscriber>("subscriber");
    rclcpp::spin(sub_node);

    rclcpp::shutdown();

    return 0;
}