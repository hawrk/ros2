/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-10-15 18:17:18
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-10-15 19:05:18
 * @FilePath: /point_cloud_sub_cpp/src/pc_sub.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "pcl_conversions/pcl_conversions.h"
#include <pcl/common/common.h>
#include <pcl/io/pcd_io.h>

class PclSub: public rclcpp::Node {
    public:
        PclSub(const std::string& name):Node(name) {
            RCLCPP_INFO(this->get_logger(), "Subscribing to point cloud topic");
            sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
                "point_cloud", 10, std::bind(&PclSub::topic_callback, this, std::placeholders::_1));
        }

    private:
        rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_;

        void topic_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "Received point cloud with %d points", msg->width * msg->height);
            //ROS2 转 PCL
            pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
            pcl::fromROSMsg(*msg, *cloud);
            //PCL 处理
            pcl::io::savePCDFileASCII("test.pcd", *cloud);
            RCLCPP_INFO(this->get_logger(), "Saved point cloud to test.pcd");
        }
};



int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto pcl_sub = std::make_shared<PclSub>("pcl_sub");
    rclcpp::spin(pcl_sub);
    rclcpp::shutdown();
    return 0;
}