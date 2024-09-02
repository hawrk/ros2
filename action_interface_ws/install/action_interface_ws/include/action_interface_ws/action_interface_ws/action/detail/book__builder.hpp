// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interface_ws:action/Book.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__BUILDER_HPP_
#define ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interface_ws/action/detail/book__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_Goal_book_name
{
public:
  Init_Book_Goal_book_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface_ws::action::Book_Goal book_name(::action_interface_ws::action::Book_Goal::_book_name_type arg)
  {
    msg_.book_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_Goal>()
{
  return action_interface_ws::action::builder::Init_Book_Goal_book_name();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_Result_line_num
{
public:
  Init_Book_Result_line_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface_ws::action::Book_Result line_num(::action_interface_ws::action::Book_Result::_line_num_type arg)
  {
    msg_.line_num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_Result>()
{
  return action_interface_ws::action::builder::Init_Book_Result_line_num();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_Feedback_line_words
{
public:
  explicit Init_Book_Feedback_line_words(::action_interface_ws::action::Book_Feedback & msg)
  : msg_(msg)
  {}
  ::action_interface_ws::action::Book_Feedback line_words(::action_interface_ws::action::Book_Feedback::_line_words_type arg)
  {
    msg_.line_words = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_Feedback msg_;
};

class Init_Book_Feedback_cur_line
{
public:
  Init_Book_Feedback_cur_line()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Book_Feedback_line_words cur_line(::action_interface_ws::action::Book_Feedback::_cur_line_type arg)
  {
    msg_.cur_line = std::move(arg);
    return Init_Book_Feedback_line_words(msg_);
  }

private:
  ::action_interface_ws::action::Book_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_Feedback>()
{
  return action_interface_ws::action::builder::Init_Book_Feedback_cur_line();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_SendGoal_Request_goal
{
public:
  explicit Init_Book_SendGoal_Request_goal(::action_interface_ws::action::Book_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interface_ws::action::Book_SendGoal_Request goal(::action_interface_ws::action::Book_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_SendGoal_Request msg_;
};

class Init_Book_SendGoal_Request_goal_id
{
public:
  Init_Book_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Book_SendGoal_Request_goal goal_id(::action_interface_ws::action::Book_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Book_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interface_ws::action::Book_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_SendGoal_Request>()
{
  return action_interface_ws::action::builder::Init_Book_SendGoal_Request_goal_id();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_SendGoal_Response_stamp
{
public:
  explicit Init_Book_SendGoal_Response_stamp(::action_interface_ws::action::Book_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interface_ws::action::Book_SendGoal_Response stamp(::action_interface_ws::action::Book_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_SendGoal_Response msg_;
};

class Init_Book_SendGoal_Response_accepted
{
public:
  Init_Book_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Book_SendGoal_Response_stamp accepted(::action_interface_ws::action::Book_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Book_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interface_ws::action::Book_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_SendGoal_Response>()
{
  return action_interface_ws::action::builder::Init_Book_SendGoal_Response_accepted();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_GetResult_Request_goal_id
{
public:
  Init_Book_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface_ws::action::Book_GetResult_Request goal_id(::action_interface_ws::action::Book_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_GetResult_Request>()
{
  return action_interface_ws::action::builder::Init_Book_GetResult_Request_goal_id();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_GetResult_Response_result
{
public:
  explicit Init_Book_GetResult_Response_result(::action_interface_ws::action::Book_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interface_ws::action::Book_GetResult_Response result(::action_interface_ws::action::Book_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_GetResult_Response msg_;
};

class Init_Book_GetResult_Response_status
{
public:
  Init_Book_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Book_GetResult_Response_result status(::action_interface_ws::action::Book_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Book_GetResult_Response_result(msg_);
  }

private:
  ::action_interface_ws::action::Book_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_GetResult_Response>()
{
  return action_interface_ws::action::builder::Init_Book_GetResult_Response_status();
}

}  // namespace action_interface_ws


namespace action_interface_ws
{

namespace action
{

namespace builder
{

class Init_Book_FeedbackMessage_feedback
{
public:
  explicit Init_Book_FeedbackMessage_feedback(::action_interface_ws::action::Book_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interface_ws::action::Book_FeedbackMessage feedback(::action_interface_ws::action::Book_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface_ws::action::Book_FeedbackMessage msg_;
};

class Init_Book_FeedbackMessage_goal_id
{
public:
  Init_Book_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Book_FeedbackMessage_feedback goal_id(::action_interface_ws::action::Book_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Book_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interface_ws::action::Book_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface_ws::action::Book_FeedbackMessage>()
{
  return action_interface_ws::action::builder::Init_Book_FeedbackMessage_goal_id();
}

}  // namespace action_interface_ws

#endif  // ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__BUILDER_HPP_
