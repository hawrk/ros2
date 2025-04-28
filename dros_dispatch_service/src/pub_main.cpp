/*
 * @Author: hawrkchen
 * @Date: 2025-04-17 14:53:58
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-04-28 11:07:41
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
        timer_ = this->create_wall_timer(std::chrono::milliseconds(30000), std::bind(&PubNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto msg = std_msgs::msg::String();
        // 生成以下格式的json字符串

    json j = {
        {"reply", "好的，我明白了，请停留在原地等待"},
        {"data", {
            {"task", "给我一杯水"},
            {"task_match", "帮我拿一杯水"},
            {"pan_seq", {
                {{"go_to", {
                    {"obj_name", "table"},
                    {"obj_loc", {
                        {"x", -2.030788847054092},
                        {"y", 0.29037407362934836},
                        {"z", -2.071408365922247},
                        {"dx", 0.3525196761313054},
                        {"dy", 0.20804312762697724},
                        {"dz", 0.1693834213114835}
                    }}
                }}},
                {{"pick_up", {
                    {"obj_name", "bottle"},
                    {"obj_loc", {
                        {"x", -2.030788847054092},
                        {"y", 0.29037407362934836},
                        {"z", -2.071408365922247},
                        {"dx", 0.3525196761313054},
                        {"dy", 0.20804312762697724},
                        {"dz", 0.1693834213114835}
                    }}
                }}},
                {{"pass_to", {
                    {"obj_name", "user"},
                    {"obj_loc", {
                        {"x", 0.0},
                        {"y", 0.0},
                        {"z", 0.0},
                        {"dx", 0.0},
                        {"dy", 0.0},
                        {"dz", 0.0}
                    }}
                }}}
            }}
        }}};

        std::string json_str = j.dump();
        msg.data = json_str;
        RCLCPP_INFO(this->get_logger(), "publish message:...");
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




