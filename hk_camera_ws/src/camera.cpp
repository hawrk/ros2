/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-09-06 09:21:12
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-09-10 09:27:11
 * @FilePath: /hk_camera_ws/src/camera.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdio>

#include "rclcpp/rclcpp.hpp"


#include "hk_camera_ws/hk_camera.hpp"

class CameraNode: public rclcpp::Node {
  public:
    CameraNode(const std::string& name):Node(name) {
        RCLCPP_INFO(this->get_logger(), "start node:[%s]", name.c_str());
    }


  private:


};

int main(int argc, char ** argv)
{
  HKCamera ca;

  int ret = ca.initial_camera();
  if(ret != 0) {
    RCLCPP_ERROR(rclcpp::get_logger("camera"), "initial_camera error");
    return -1;
  }
  ca.start_camera();

  ca.stop_camera();

  (void)argc;
  (void)argv;

  // rclcpp::init(argc,argv);
  // printf("hello world hk_camera_ws package\n");
  // auto node = std::make_shared<rclcpp::Node>("node");
  // rclcpp::spin(node);
  pause();
  return 0;
}
