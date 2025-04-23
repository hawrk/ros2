/*
 * @Author: hawrkchen
 * @Date: 2025-04-17 14:53:58
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-04-23 10:34:21
 * @Description: 
 * @FilePath: /dros_dispatch_service/src/pub_main.cpp
 */
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class PubNode : public rclcpp::Node
{
public:
    PubNode() : Node("pub_node")
    {
        RCLCPP_INFO(this->get_logger(), " publisher node start...");
        pub_ = this->create_publisher<std_msgs::msg::String>("module_task", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(50000), std::bind(&PubNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto msg = std_msgs::msg::String();
        // 生成以下格式的json字符串
        // {
        //     "frame_id": "navigation",
        //     "position": {
        //         "x": 1.0,
        //         "y": 2.0,
        //         "z": 0.0
        //     },
        //     "orientation": {
        //         "x": 0.0,
        //         "y": 0.0,
        //         "z": 0.0,
        //         "w": 1.0
        //     }
        // }
        json j = {
            {"frame_id", "navigation"},
            {"position", {{"x", 1.0}, {"y", 2.0}, {"z", 3.0}}},
            {"orientation", {{"x", 0.0}, {"y", 0.0}, {"z", 0.0}, {"w", 1.0}}}
        };
        std::string json_str = j.dump();
        msg.data = json_str;
        pub_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PubNode>());
    rclcpp::shutdown();
    return 0;
}




