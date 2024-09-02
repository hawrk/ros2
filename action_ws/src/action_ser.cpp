/*
 * @Author: hawr4kchen hawrk2012@163.com
 * @Date: 2024-09-02 09:10:53
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-09-02 15:30:45
 * @FilePath: /action_ws/src/action_ser.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdio>

#include "rclcpp/rclcpp.hpp"
#include "action_interface_ws/action/book.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "action_ws/books.hpp"

class SanTzuChingServer: public rclcpp::Node {
  public:
    SanTzuChingServer(const std::string& name):Node(name) {
      RCLCPP_INFO(this->get_logger(), "动作节点 [%s] 启动......", name.c_str());

      this->action_ser_ = rclcpp_action::create_server<action_interface_ws::action::Book>(
        this, "santzuching",
      std::bind(&SanTzuChingServer::goal_cb,this,std::placeholders::_1, std::placeholders::_2),
      std::bind(&SanTzuChingServer::cancel_cb,this,std::placeholders::_1),
      std::bind(&SanTzuChingServer::accepted_cb,this,std::placeholders::_1));
    }


  private:
    rclcpp_action::Server<action_interface_ws::action::Book>::SharedPtr action_ser_;

    // 请求处理
    rclcpp_action::GoalResponse goal_cb(const rclcpp_action::GoalUUID& uuid,
    std::shared_ptr<const action_interface_ws::action::Book::Goal> goal) {
      RCLCPP_INFO(this->get_logger(), "received goal:[%s]", goal->book_name.c_str());
      (void)uuid;
      if(goal->book_name != "humen") {
        RCLCPP_WARN(this->get_logger(), "本书库不存在该书,请查询 再试...");
        return rclcpp_action::GoalResponse::REJECT;
      }
      RCLCPP_INFO(this->get_logger(), "本书库存在该书,后台接受!");
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    // 取消接收 (如有)
    rclcpp_action::CancelResponse cancel_cb(
      const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface_ws::action::Book>> cancel_handle) {
        (void)cancel_handle;
        //TODO:
        return rclcpp_action::CancelResponse::ACCEPT;
      }

          // 接受处理
    void accepted_cb(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface_ws::action::Book>> accept_handle) {
      std::thread{std::bind(&SanTzuChingServer::execute_cb,this,std::placeholders::_1),accept_handle}.detach();
    }

    // 开始执行了
    void execute_cb(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface_ws::action::Book>> exe_handle) {
      const auto goal = exe_handle->get_goal();
      RCLCPP_INFO(this->get_logger(), "开始朗读 [%s]", goal->book_name.c_str());

      // 设置结果回包
      auto result = std::make_shared<action_interface_ws::action::Book::Result>();

      // 开始读文件内容 
      int cur_line = 1;
      rclcpp::Rate rate = rclcpp::Rate(2);
      Books rb(goal->book_name);

      while(rclcpp::ok() && cur_line <= rb.get_total_line()) {
        std::string words = rb.get_line_words(cur_line);
        // 设置反馈回包
        auto feedback = std::make_shared<action_interface_ws::action::Book::Feedback>();
        feedback->cur_line = cur_line;
        feedback->line_words = words;
        exe_handle->publish_feedback(feedback);
        //  随时检测任务是否被取消
        if(exe_handle->is_canceling()) {
          result->line_num = cur_line;
          exe_handle->canceled(result);
          RCLCPP_INFO(this->get_logger(), "结束");
          return;
        }

        RCLCPP_INFO(this->get_logger(), "目前是第[%d]行:[%s]",feedback->cur_line,feedback->line_words.c_str());
        cur_line++;
        rate.sleep();

      }
      // 全部读取完成后,返回最终结果
      result->line_num = cur_line -1; 
      exe_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "read over");
    }
  

};


int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);

  auto action_ser = std::make_shared<SanTzuChingServer>("action_ser");

  rclcpp::spin(action_ser);
  rclcpp::shutdown();
  return 0;
} 