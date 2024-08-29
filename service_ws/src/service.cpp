/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-29 11:04:21
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-29 14:56:25
 * @FilePath: /service_ws/src/service.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdio>

#include "rclcpp/rclcpp.hpp"
#include "service_interface_ws/srv/black_monkey.hpp"

const size_t MAX_HP = 1000000;   // 最大血量

class BlackMonkeySerivce: public rclcpp::Node {
  public:
    BlackMonkeySerivce(const std::string& name): Node(name) {
      RCLCPP_INFO(this->get_logger(), "节点启动:[%s]", name.c_str());

      service_ = this->create_service<service_interface_ws::srv::BlackMonkey>("black_monkey",
      std::bind(&BlackMonkeySerivce::black_monkey_cb, this, std::placeholders::_1,std::placeholders::_2),
      rmw_qos_profile_services_default);
    }

  private:
    rclcpp::Service<service_interface_ws::srv::BlackMonkey>::SharedPtr service_;
    static size_t hp;     // 血量

    void black_monkey_cb(const service_interface_ws::srv::BlackMonkey::Request::SharedPtr req,
    service_interface_ws::srv::BlackMonkey::Response::SharedPtr rsp) {
      RCLCPP_INFO(rclcpp::get_logger("node"),"get hit_type:%d, injury:[%d]", req->hit_type, req->injury);
      if(req->hit_type ==1) {   // 轻棍
         hp -= req->injury*0.8;
      } else if (req->hit_type == 2) { // 重棍
         hp -= req->injury*0.9; 
      } else {   // 风灵月影
         hp =0;
      }
      if (hp <= 0) {
          RCLCPP_INFO(rclcpp::get_logger("node"), "你个老六,居然是个风灵月影教");
          rsp->beat = true;
          rsp->real_injury = 999999999;
          rsp->words = "你个老六,居然是个风灵月影教";
          rclcpp::shutdown();    // 打死了,服务直接结束
      } else {
        RCLCPP_INFO(rclcpp::get_logger("node"),"小菜鸡,没吃饭吗,打人都不疼,剩余血量[%ld]", hp);
          rsp->beat = false;
          rsp->real_injury = hp;
          rsp->words = "小菜鸡,没吃饭吗,打人都不疼";
      }

    }
}; 

size_t BlackMonkeySerivce::hp = MAX_HP;


int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);
  auto ser_node = std::make_shared<BlackMonkeySerivce>("service");
  rclcpp::spin(ser_node);
  rclcpp::shutdown();
  return 0;
}
