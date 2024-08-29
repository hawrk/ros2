/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-29 14:22:01
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-29 14:49:01
 * @FilePath: /service_ws/src/client.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "rclcpp/rclcpp.hpp"
#include "service_interface_ws/srv/black_monkey.hpp"

class BlackMonkeyClient:public rclcpp::Node {
    public:
      BlackMonkeyClient(const std::string& name):Node(name) {
        RCLCPP_INFO(this->get_logger(), "节点启动[%s]", name.c_str());
        client_ = this->create_client<service_interface_ws::srv::BlackMonkey>("black_monkey",
        rmw_qos_profile_default);
      }

      int hit_elder_jinchi(int argc,char** argv) {
        RCLCPP_INFO(this->get_logger(), "现在去打金池长老...");
        auto request = std::make_shared<service_interface_ws::srv::BlackMonkey::Request>();
        while(!client_->wait_for_service(std::chrono::microseconds(1))) {
            if(!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "等待被打断,不等了,结束");
                rclcpp::shutdown();
                return 1;
            }
            // 否则一直等 
            RCLCPP_INFO(this->get_logger(), "等待观音禅院开门");
        }

        if(argc != 3) {
            RCLCPP_ERROR(this->get_logger(), "输入错误,格式 为  [1,2,3] 伤害值");
            //rclcpp::shutdown();
            return 1;
        }
        request->hit_type = atoi(argv[1]);
        request->injury = atoi(argv[2]);
        client_->async_send_request(request, std::bind(&BlackMonkeyClient::hit_cb, this, std::placeholders::_1));
        return 0;
      }

    private:
        rclcpp::Client<service_interface_ws::srv::BlackMonkey>::SharedPtr client_;

        void hit_cb(rclcpp::Client<service_interface_ws::srv::BlackMonkey>::SharedFuture fu) {
            auto result = fu.get();
            if(result->beat) {
                RCLCPP_INFO(this->get_logger(), "rsp:[%s]", result->words.c_str());
                RCLCPP_INFO(this->get_logger(), "大获全胜");
                rclcpp::shutdown();
            } else {
                RCLCPP_INFO(this->get_logger(), "rsp:[%s]", result->words.c_str());
                RCLCPP_INFO(this->get_logger(), "待我点支香再来");
                //rclcpp::shutdown();
            }
            
        }
};



int main(int argc,char* argv[]) {
    rclcpp::init(argc,argv);
    auto cli_node = std::make_shared<BlackMonkeyClient>("client");
    cli_node->hit_elder_jinchi(argc,argv);
    rclcpp::spin(cli_node);
    rclcpp::shutdown();

    return 0;
}