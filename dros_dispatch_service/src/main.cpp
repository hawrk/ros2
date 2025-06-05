/*
 * @Author: hawrkchen
 * @Date: 2025-04-16 14:46:56
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-06-04 11:42:03
 * @Description: 
 * @FilePath: /dros_dispatch_service/src/main.cpp
 */
#include <rclcpp/rclcpp.hpp>
#include "httplib.h"
#include "dros_dispatch_service/dispatch_node.hpp"

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto dispatch_node = std::make_shared<DispatchNode>("dispatch_node");

    // 创建一个 HTTP 服务器
    httplib::Server svr;

    // 设置一个 POST 路由来接收任务字符串
    svr.Post("/task", [&](const httplib::Request& req, httplib::Response& res) {
        std::cout << "Received task: " << req.body << std::endl;
        std::string task_string = req.body;

        // std::thread task_thread([&dispatch_node, task_string]() {
        //     dispatch_node->receive_http_task(task_string);
        // });
        // task_thread.detach();
        auto ret_msg = dispatch_node->receive_http_task(task_string);

        // 创建JSON 响应
        json j = {{"msg", ret_msg}};
        res.set_content(j.dump(), "application/json");
        res.status = 200;

    });

    // 启动 HTTP 服务器
    std::thread server_thread([&svr]() {
        svr.listen("127.0.0.1", 8080);
    });

    // 启动 ROS 2 节点的事件循环
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(dispatch_node->get_node_base_interface());
    executor.spin();

    rclcpp::shutdown();
    // rclcpp::spin(dispatch_node);
    // rclcpp::shutdown();

    // 等待 HTTP 服务器线程结束
    server_thread.join();

    return 0;
}
