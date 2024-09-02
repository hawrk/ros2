/*
 * @Author: hawrkchen hawrk2012@163.com
 * @Date: 2024-09-02 09:11:58
 * @LastEditors: hawrkchen hawrk2012@163.com
 * @LastEditTime: 2024-09-02 15:55:52
 * @FilePath: /action_ws/src/action_cli.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "rclcpp/rclcpp.hpp"
#include "action_interface_ws/action/book.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

class SanTzuChingClient:public rclcpp::Node {
    public:
        SanTzuChingClient(const std::string& name):Node(name) {
            RCLCPP_INFO(this->get_logger(), "节点启动:'[%s]", name.c_str());

            this->action_cli_ = rclcpp_action::create_client<action_interface_ws::action::Book>(this,
            "santzuching");
        }

        void send_goal(int argc,char* argv[]) {
            if(!this->action_cli_->wait_for_action_server()) {
                RCLCPP_ERROR(this->get_logger(), "Action Server not available...");
                rclcpp::shutdown();
                return;
            }
           
            if(argc < 2) {
                RCLCPP_ERROR(this->get_logger(), "请输入书名...");
                rclcpp::shutdown();
            }
             //构造请求
             auto goal_msg = action_interface_ws::action::Book::Goal();
             goal_msg.book_name = argv[1];
             RCLCPP_INFO(this->get_logger(), "请求:[%s]", goal_msg.book_name.c_str());
             //构造异步处理
             auto send_goal_options = rclcpp_action::Client<action_interface_ws::action::Book>::SendGoalOptions();

             send_goal_options.goal_response_callback = std::bind(&SanTzuChingClient::goal_res_cb,this,std::placeholders::_1);
             
             send_goal_options.feedback_callback = std::bind(&SanTzuChingClient::feed_back_cb,this,std::placeholders::_1,std::placeholders::_2);

             send_goal_options.result_callback = std::bind(&SanTzuChingClient::result_cb,this,std::placeholders::_1);

             this->action_cli_->async_send_goal(goal_msg,send_goal_options);
        } 
    private:
        rclcpp_action::Client<action_interface_ws::action::Book>::SharedPtr action_cli_;
        // 请求回调
        void goal_res_cb(const rclcpp_action::ClientGoalHandle<action_interface_ws::action::Book>::SharedPtr& goal_handle) {
            if(!goal_handle) {
                RCLCPP_ERROR(this->get_logger(), "goal reject by server");
            }else {
                RCLCPP_INFO(this->get_logger(), "goal accept by server ,waitting...");
            }
        }
        // 反馈回调接收
        void feed_back_cb(rclcpp_action::ClientGoalHandle<action_interface_ws::action::Book>::SharedPtr,
        const std::shared_ptr<const action_interface_ws::action::Book::Feedback> feedback) {
            RCLCPP_INFO(this->get_logger(), "当前第[%d]行, 内容:[%s]", feedback->cur_line, feedback->line_words.c_str());
        }
        // 结果回调
        void result_cb(const rclcpp_action::ClientGoalHandle<action_interface_ws::action::Book>::WrappedResult& result) {
            switch(result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(this->get_logger(), "goal process successful");
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_ERROR(this->get_logger(), "goal was aborted");
                    return;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_ERROR(this->get_logger(), "goal was cancel");
                    return;
                default:
                    RCLCPP_ERROR(this->get_logger(), "unknown result code");
                    return;

            }
            // 打印最终结果
            RCLCPP_INFO(this->get_logger(), "已处理:[%d] 行内容", result.result->line_num);
            rclcpp::shutdown();
        }
    
};



int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);

  auto action_cli = std::make_shared<SanTzuChingClient>("action_cli");

  auto lamb = [&]() {
    action_cli->send_goal(argc,argv);
  };

  std::thread{lamb}.detach();

  rclcpp::spin(action_cli);

  rclcpp::shutdown();
  return 0;
} 