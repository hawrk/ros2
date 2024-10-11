/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-09-06 09:21:12
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-09-18 15:48:04
 * @FilePath: /hk_camera/src/camera.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdio>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"


#include "hk_camera_ws/hk_camera.hpp"

class CameraNode: public rclcpp::Node {
  public:
    explicit CameraNode(const std::string& name):Node(name) {
        RCLCPP_INFO(this->get_logger(), "start node:[%s]", name.c_str());

        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image_raw", 10);

        int iRet = hk_camera_.initial_camera();
        if(iRet != MV_OK) {
          RCLCPP_ERROR(this->get_logger(), "initial_camera fail, code:[%d]", iRet);
          return;
        }

    }

    void image_publishing() {
      if(hk_camera_.get_handle() == nullptr) {
          return;
      }
      hk_camera_.start_camera(std::bind(&CameraNode::publishing,this, std::placeholders::_1,std::placeholders::_2));

    }

    ~CameraNode() {
      hk_camera_.stop_camera();

    }


  private:
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;  // 发布器
    HKCamera hk_camera_ ;

    void publishing(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo) {
      RCLCPP_INFO(this->get_logger(), "into publishing open cv");
      
      cv::Mat frame = cv::Mat(pFrameInfo->nHeight,pFrameInfo->nWidth,CV_8UC3,pData).clone();
      //原图太大了,按比例缩小一点
      cv::Mat dst;
      cv::resize(frame, dst,cv::Size(pFrameInfo->nHeight/3,pFrameInfo->nWidth/3));

      //调试输出
      cv::imshow("hk_version", dst);
      cv::waitKey(0);


    }


};


// 信号处理函数
void signalHandler(int signum) {
    std::cout << "Caught signal " << signum << ", terminating gracefully..." << std::endl;
    // 这里可以做一些清理工作
    exit(signum); // 退出程序
}

int main(int argc, char ** argv)
{
  
  // HKCamera ca;

  // int ret = ca.initial_camera();
  // if(ret != 0) {
  //   RCLCPP_ERROR(rclcpp::get_logger("camera"), "initial_camera error");
  //   return -1;
  // }
  // ca.start_camera();

  // ca.stop_camera();

  // (void)argc;
  // (void)argv;
  signal(SIGINT, signalHandler);

  
  rclcpp::init(argc,argv);
  auto node = std::make_shared<CameraNode>("camera");
  node->image_publishing();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
