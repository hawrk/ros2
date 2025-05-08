// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dros_common_interfaces:action/DexterousHand.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__BUILDER_HPP_
#define DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dros_common_interfaces/action/detail/dexterous_hand__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_Goal_target_position
{
public:
  Init_DexterousHand_Goal_target_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dros_common_interfaces::action::DexterousHand_Goal target_position(::dros_common_interfaces::action::DexterousHand_Goal::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_Goal>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_Goal_target_position();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_Result_msg
{
public:
  explicit Init_DexterousHand_Result_msg(::dros_common_interfaces::action::DexterousHand_Result & msg)
  : msg_(msg)
  {}
  ::dros_common_interfaces::action::DexterousHand_Result msg(::dros_common_interfaces::action::DexterousHand_Result::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_Result msg_;
};

class Init_DexterousHand_Result_success
{
public:
  Init_DexterousHand_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DexterousHand_Result_msg success(::dros_common_interfaces::action::DexterousHand_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DexterousHand_Result_msg(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_Result>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_Result_success();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_Feedback_progress
{
public:
  Init_DexterousHand_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dros_common_interfaces::action::DexterousHand_Feedback progress(::dros_common_interfaces::action::DexterousHand_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_Feedback>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_Feedback_progress();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_SendGoal_Request_goal
{
public:
  explicit Init_DexterousHand_SendGoal_Request_goal(::dros_common_interfaces::action::DexterousHand_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::dros_common_interfaces::action::DexterousHand_SendGoal_Request goal(::dros_common_interfaces::action::DexterousHand_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_SendGoal_Request msg_;
};

class Init_DexterousHand_SendGoal_Request_goal_id
{
public:
  Init_DexterousHand_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DexterousHand_SendGoal_Request_goal goal_id(::dros_common_interfaces::action::DexterousHand_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DexterousHand_SendGoal_Request_goal(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_SendGoal_Request>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_SendGoal_Request_goal_id();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_SendGoal_Response_stamp
{
public:
  explicit Init_DexterousHand_SendGoal_Response_stamp(::dros_common_interfaces::action::DexterousHand_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::dros_common_interfaces::action::DexterousHand_SendGoal_Response stamp(::dros_common_interfaces::action::DexterousHand_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_SendGoal_Response msg_;
};

class Init_DexterousHand_SendGoal_Response_accepted
{
public:
  Init_DexterousHand_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DexterousHand_SendGoal_Response_stamp accepted(::dros_common_interfaces::action::DexterousHand_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_DexterousHand_SendGoal_Response_stamp(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_SendGoal_Response>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_SendGoal_Response_accepted();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_GetResult_Request_goal_id
{
public:
  Init_DexterousHand_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dros_common_interfaces::action::DexterousHand_GetResult_Request goal_id(::dros_common_interfaces::action::DexterousHand_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_GetResult_Request>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_GetResult_Request_goal_id();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_GetResult_Response_result
{
public:
  explicit Init_DexterousHand_GetResult_Response_result(::dros_common_interfaces::action::DexterousHand_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::dros_common_interfaces::action::DexterousHand_GetResult_Response result(::dros_common_interfaces::action::DexterousHand_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_GetResult_Response msg_;
};

class Init_DexterousHand_GetResult_Response_status
{
public:
  Init_DexterousHand_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DexterousHand_GetResult_Response_result status(::dros_common_interfaces::action::DexterousHand_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_DexterousHand_GetResult_Response_result(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_GetResult_Response>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_GetResult_Response_status();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace action
{

namespace builder
{

class Init_DexterousHand_FeedbackMessage_feedback
{
public:
  explicit Init_DexterousHand_FeedbackMessage_feedback(::dros_common_interfaces::action::DexterousHand_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::dros_common_interfaces::action::DexterousHand_FeedbackMessage feedback(::dros_common_interfaces::action::DexterousHand_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_FeedbackMessage msg_;
};

class Init_DexterousHand_FeedbackMessage_goal_id
{
public:
  Init_DexterousHand_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DexterousHand_FeedbackMessage_feedback goal_id(::dros_common_interfaces::action::DexterousHand_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DexterousHand_FeedbackMessage_feedback(msg_);
  }

private:
  ::dros_common_interfaces::action::DexterousHand_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::action::DexterousHand_FeedbackMessage>()
{
  return dros_common_interfaces::action::builder::Init_DexterousHand_FeedbackMessage_goal_id();
}

}  // namespace dros_common_interfaces

#endif  // DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__BUILDER_HPP_
