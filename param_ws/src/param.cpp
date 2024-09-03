/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-09-03 10:07:00
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-09-03 11:05:47
 * @FilePath: /param_ws/src/param.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdio>

#include "rclcpp/rclcpp.hpp"

class ParamMonitor:public rclcpp::Node {
  public:
    ParamMonitor(const std::string& name):Node(name) {
      RCLCPP_INFO(this->get_logger(), "node [%s] start...", name.c_str());

      this->declare_parameter("my_rank", "F2");
      this->declare_parameter("salary", 10159);
      this->declare_parameter("venhicle", "BYD");
      param_sub_ = std::make_shared<rclcpp::ParameterEventHandler>(this);

      RCLCPP_INFO(this->get_logger(), "rank:{%s}\t salary[%ld]\t, venhicle:[%s]",
       this->get_parameter("my_rank").as_string().c_str(), 
       this->get_parameter("salary").as_int(),
       this->get_parameter("venhicle").as_string().c_str());

      auto cb = [&](const rclcpp::Parameter& p) {
        RCLCPP_INFO(this->get_logger(), "目前职级 :[%s],",
         p.as_string().c_str());
        // 下面可以做一些你想做的事情,比如通过topic或service把该字段透传给其他节点
        // TODO:
      };
      auto cb2 = [this](const rclcpp::Parameter& p) {
        RCLCPP_INFO(this->get_logger(), "目前薪酬:[%ld]",
        p.as_int());
      };

      auto cb3 = [this](const rclcpp::Parameter& p) {
        RCLCPP_INFO(this->get_logger(), "目前座驾:[%s]",
        p.as_string().c_str());
      };


      cb_handle_ = param_sub_->add_parameter_callback("my_rank", cb);
      cb_handle2_ = param_sub_->add_parameter_callback("salary",cb2);
      cb_handle3_ = param_sub_->add_parameter_callback("venhicle",cb3);
    }
  private:
  std::shared_ptr<rclcpp::ParameterEventHandler> param_sub_;
  std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle_;
  std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle2_;
  std::shared_ptr<rclcpp::ParameterCallbackHandle> cb_handle3_;

};

int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);

  auto param_node = std::make_shared<ParamMonitor>("param");

  rclcpp::spin(param_node);

  rclcpp::shutdown();

  return 0;
}
