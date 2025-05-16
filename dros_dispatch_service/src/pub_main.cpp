/*
 * @Author: hawrkchen
 * @Date: 2025-04-17 14:53:58
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-14 11:50:38
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
        pub_ = this->create_publisher<std_msgs::msg::String>("/task_planning", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(30000), std::bind(&PubNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto msg = std_msgs::msg::String();
        // 生成以下格式的json字符串
        /*
        {
            "task": "可以拿一瓶矿泉水",
            "task_match": "帮我拿一瓶矿泉水",
            "plan_seq": [
                {
                    "go_to": {
                        "obj_name": "table",
                        "obj_loc": [-0.33492699127621883, 1.478091804774341, 0.4489604095975871, 2.122405428560488, 1.3050825008208473, 1.209124033360488]
                    }
                },
                {
                    "pick_up": {
                        "obj_name": "bottled_water",
                        "obj_loc": [-0.46921061549165693, 1.1897216102865804, 0.770143183885984, 0.37353558778055906, 0.1606382618571653, 0.12213871952411254]
                    }
                },
                {
                    "go_to": {
                        "obj_name": "user",
                        "obj_loc": [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
                    }
                },
                {
                    "pass_to": {
                        "obj_name": "user",
                        "obj_loc": [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
                    }
                }
            ]
        }
        */

    json j = {
        {"reply", "好的，我明白了，请停留在原地等待"},
        {"data", {
            {"task", "给我一杯水"},
            {"task_match", "帮我拿一杯水"},
            {"plan_seq", {
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
                {{"go_to", {
                    {"obj_name", "user"},
                    {"obj_loc", {
                        {"x", -3.030788847054092},
                        {"y", 0.38037407362934836},
                        {"z", -3.071408365922247},
                        {"dx", 0.3525196761313054},
                        {"dy", 0.20804312762697724},
                        {"dz", 0.1693834213114835}
                    }}
                }}},
                {{"pass_to", {
                    {"obj_name", "user"},
                    {"obj_loc", {
                        {"x", 3.14},
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




