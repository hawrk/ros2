/*
 * @Author: hawrkchen
 * @Date: 2025-05-19 15:46:50
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-05-20 09:23:31
 * @Description: 
 * @FilePath: /ros_log_ws/src/main.cpp
 */
#include <cstdio>
#include <rclcpp/rclcpp.hpp>
#include <rcutils/logging.h>
#include <chrono>
#include <sstream>
#include <fstream>
#include <mutex>  
// 定义全局文件流和互斥锁（确保线程安全）
static std::ofstream log_file;
static std::mutex log_mutex;

void custom_log_outut_handle(const rcutils_log_location_t* log_location, 
  int severity, 
  const char * logger_name, 
  const rcutils_time_point_value_t timestamp, 
  const char* format,
  va_list* args) {
    (void)log_location;
    (void)severity;

    time_t sec = timestamp / 1000000000;
    long nsec = timestamp % 1000000000;

    struct tm tm_time;
    localtime_r(&sec, &tm_time);

    char time_str[64];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", &tm_time);

    std::stringstream ss;
    ss << "[" << time_str << "." << std::setw(9) << std::setfill('0') << nsec << "] ["
       << logger_name << "] ";
    
        // 添加日志级别（可选）
    const char* severity_str = "";
    switch (severity) {
        case RCUTILS_LOG_SEVERITY_DEBUG: severity_str = "DEBUG"; break;
        case RCUTILS_LOG_SEVERITY_INFO: severity_str = "INFO"; break;
        case RCUTILS_LOG_SEVERITY_WARN: severity_str = "WARN"; break;
        case RCUTILS_LOG_SEVERITY_ERROR: severity_str = "ERROR"; break;
        case RCUTILS_LOG_SEVERITY_FATAL: severity_str = "FATAL"; break;
    }
    ss << "[" << severity_str << "] ";

    // 处理日志消息内容
    char msg_buffer[1024];
    vsnprintf(msg_buffer, sizeof(msg_buffer), format, *args);
    ss << msg_buffer << std::endl;

    // 输出到控制台
    printf("%s", ss.str().c_str());

    // 输出到文件
    {
        std::lock_guard<std::mutex> lock(log_mutex);
        if(!log_file.is_open()) {
            log_file.open("~/.ros/log/ros2.log", std::ios::out | std::ios::app);
            if(!log_file) {
              fprintf(stderr, "Failed to open log file\n");
              return;
            }
        }
        log_file << ss.str();
        log_file.flush();
    }
  }


int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rcutils_logging_set_output_handler(custom_log_outut_handle);   // 注册新的日志输出函数后，原有的日志配置将全部失效

    auto node = rclcpp::Node::make_shared("my_node");
    RCLCPP_INFO(node->get_logger(), "Hello, ROS2!");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
