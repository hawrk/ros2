// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dros_common_interfaces:srv/Grasp.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__BUILDER_HPP_
#define DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dros_common_interfaces/srv/detail/grasp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dros_common_interfaces
{

namespace srv
{

namespace builder
{

class Init_Grasp_Request_object_name
{
public:
  Init_Grasp_Request_object_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dros_common_interfaces::srv::Grasp_Request object_name(::dros_common_interfaces::srv::Grasp_Request::_object_name_type arg)
  {
    msg_.object_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::srv::Grasp_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::srv::Grasp_Request>()
{
  return dros_common_interfaces::srv::builder::Init_Grasp_Request_object_name();
}

}  // namespace dros_common_interfaces


namespace dros_common_interfaces
{

namespace srv
{

namespace builder
{

class Init_Grasp_Response_err_msg
{
public:
  explicit Init_Grasp_Response_err_msg(::dros_common_interfaces::srv::Grasp_Response & msg)
  : msg_(msg)
  {}
  ::dros_common_interfaces::srv::Grasp_Response err_msg(::dros_common_interfaces::srv::Grasp_Response::_err_msg_type arg)
  {
    msg_.err_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dros_common_interfaces::srv::Grasp_Response msg_;
};

class Init_Grasp_Response_err_code
{
public:
  Init_Grasp_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Grasp_Response_err_msg err_code(::dros_common_interfaces::srv::Grasp_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_Grasp_Response_err_msg(msg_);
  }

private:
  ::dros_common_interfaces::srv::Grasp_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dros_common_interfaces::srv::Grasp_Response>()
{
  return dros_common_interfaces::srv::builder::Init_Grasp_Response_err_code();
}

}  // namespace dros_common_interfaces

#endif  // DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__BUILDER_HPP_
