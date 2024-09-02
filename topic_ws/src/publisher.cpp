/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-29 09:05:02
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-29 09:44:07
 * @FilePath: /topic_ws/src/publisher.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdio>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class TopicPublisher: public rclcpp::Node {
  public:
    TopicPublisher(const std::string& name):Node(name) {
       RCLCPP_INFO(this->get_logger(), "启动节点:[%s]", name.c_str());
       publisher_ = this->create_publisher<std_msgs::msg::String>("sayhi", 100);

       timer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
       std::bind(&TopicPublisher::time_cb, this));

    }


  private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void time_cb() {
      std_msgs::msg::String msg;
      msg.data = "嘀嗒嘀嗒嘀嗒";

      RCLCPP_INFO(this->get_logger(), "send msg:%s", msg.data.c_str());

      publisher_->publish(msg);
      
    }
    
};

int main(int argc, char ** argv)
{

  rclcpp::init(argc,argv);
  auto pub_node = std::make_shared<TopicPublisher>("publisher");

  rclcpp::spin(pub_node);
  rclcpp::shutdown();

  return 0;
}
