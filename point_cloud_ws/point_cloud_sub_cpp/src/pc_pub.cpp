/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-10-16 09:08:32
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-10-16 09:32:16
 * @FilePath: /point_cloud_sub_cpp/src/pc_pub.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "pcl_conversions/pcl_conversions.h"
#include <pcl/common/common.h>
#include <pcl/io/pcd_io.h>

class PointCloudPublisher : public rclcpp::Node {
    public:
        PointCloudPublisher(const std::string& node_name) : Node(node_name) {
            RCLCPP_INFO(this->get_logger(), "PointCloudPublisher node has been created[%s]", node_name.c_str());

            pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("point_cloud", 10);

            timer_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&PointCloudPublisher::timer_callback, this));
        }

    

    private:
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_;
        rclcpp::TimerBase::SharedPtr timer_;

        void timer_callback() {
            RCLCPP_INFO(this->get_logger(), "Publishing point cloud");

            sensor_msgs::msg::PointCloud2 msg;
            msg.height = 480;
            msg.width = 640;

            sensor_msgs::PointCloud2Modifier modifier(msg);
            modifier.setPointCloud2FieldsByString(2, "xyz", "rgb");
            modifier.resize(msg.width * msg.height);

            auto iter_x = sensor_msgs::PointCloud2Iterator<float>(msg, "x");
            auto iter_y = sensor_msgs::PointCloud2Iterator<float>(msg, "y");    
            auto iter_z = sensor_msgs::PointCloud2Iterator<float>(msg, "z");
            auto iter_r = sensor_msgs::PointCloud2Iterator<uint8_t>(msg, "r");
            auto iter_g = sensor_msgs::PointCloud2Iterator<uint8_t>(msg, "g");
            auto iter_b = sensor_msgs::PointCloud2Iterator<uint8_t>(msg, "b");

            for (uint32_t i = 0; i < msg.width * msg.height; ++i, ++iter_x, ++iter_y, ++iter_z, ++iter_r, ++iter_g, ++iter_b) {
                *iter_x = i % msg.width;
                *iter_y = i / msg.width;
                *iter_z = 0;
                *iter_r = 255;
                *iter_g = 0;
                *iter_b = 0;
            }
            // PCL转换 ROS2  msg
            /*
            // PCL 点云数据转换成ROS2 msg
             pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcl_cloud;
             pcl::toROSMsg(*pcl_cloud, msg);
             pub_->publish(msg);
             */

            pub_->publish(msg);
        }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto pcl_sub = std::make_shared<PointCloudPublisher>("pcl_sub");
    rclcpp::spin(pcl_sub);
    rclcpp::shutdown();
    return 0;
}
