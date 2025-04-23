/*
 * @Author: hawrkchen
 * @Date: 2025-04-16 14:46:56
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-04-18 15:11:28
 * @Description: 
 * @FilePath: /dros_dispatch_service/src/main.cpp
 */
#include <rclcpp/rclcpp.hpp>

#include "dros_dispatch_service/dispatch_node.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto dispatch_node = std::make_shared<DispatchNode>("dispatch_node");
  rclcpp::spin(dispatch_node);
  rclcpp::shutdown();
  return 0;
}

/*
＃include "cpp-httplib.h"
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto dispatch_node = std::make_shared<DispatchNode>("dispatch_node");

    // 创建一个 HTTP 服务器
    Server svr;

    // 设置一个 POST 路由来接收任务字符串
    svr.Post("/task", [&](const Request& req, Response& res) {
        std::string task_string = req.body;
        dispatch_node->receive_task(task_string);
        res.set_content("Task received", "text/plain");
    });

    // 启动 HTTP 服务器
    std::thread server_thread([&svr]() {
        svr.listen("0.0.0.0", 8080);
    });

    // 启动 ROS 2 节点的事件循环
    rclcpp::spin(dispatch_node);
    rclcpp::shutdown();

    // 等待 HTTP 服务器线程结束
    server_thread.join();

    return 0;
}
*/