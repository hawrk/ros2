// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice

#ifndef SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__BUILDER_HPP_
#define SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "service_interface_ws/srv/detail/black_monkey__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace service_interface_ws
{

namespace srv
{

namespace builder
{

class Init_BlackMonkey_Request_injury
{
public:
  explicit Init_BlackMonkey_Request_injury(::service_interface_ws::srv::BlackMonkey_Request & msg)
  : msg_(msg)
  {}
  ::service_interface_ws::srv::BlackMonkey_Request injury(::service_interface_ws::srv::BlackMonkey_Request::_injury_type arg)
  {
    msg_.injury = std::move(arg);
    return std::move(msg_);
  }

private:
  ::service_interface_ws::srv::BlackMonkey_Request msg_;
};

class Init_BlackMonkey_Request_hit_type
{
public:
  Init_BlackMonkey_Request_hit_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BlackMonkey_Request_injury hit_type(::service_interface_ws::srv::BlackMonkey_Request::_hit_type_type arg)
  {
    msg_.hit_type = std::move(arg);
    return Init_BlackMonkey_Request_injury(msg_);
  }

private:
  ::service_interface_ws::srv::BlackMonkey_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::service_interface_ws::srv::BlackMonkey_Request>()
{
  return service_interface_ws::srv::builder::Init_BlackMonkey_Request_hit_type();
}

}  // namespace service_interface_ws


namespace service_interface_ws
{

namespace srv
{

namespace builder
{

class Init_BlackMonkey_Response_words
{
public:
  explicit Init_BlackMonkey_Response_words(::service_interface_ws::srv::BlackMonkey_Response & msg)
  : msg_(msg)
  {}
  ::service_interface_ws::srv::BlackMonkey_Response words(::service_interface_ws::srv::BlackMonkey_Response::_words_type arg)
  {
    msg_.words = std::move(arg);
    return std::move(msg_);
  }

private:
  ::service_interface_ws::srv::BlackMonkey_Response msg_;
};

class Init_BlackMonkey_Response_real_injury
{
public:
  explicit Init_BlackMonkey_Response_real_injury(::service_interface_ws::srv::BlackMonkey_Response & msg)
  : msg_(msg)
  {}
  Init_BlackMonkey_Response_words real_injury(::service_interface_ws::srv::BlackMonkey_Response::_real_injury_type arg)
  {
    msg_.real_injury = std::move(arg);
    return Init_BlackMonkey_Response_words(msg_);
  }

private:
  ::service_interface_ws::srv::BlackMonkey_Response msg_;
};

class Init_BlackMonkey_Response_beat
{
public:
  Init_BlackMonkey_Response_beat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BlackMonkey_Response_real_injury beat(::service_interface_ws::srv::BlackMonkey_Response::_beat_type arg)
  {
    msg_.beat = std::move(arg);
    return Init_BlackMonkey_Response_real_injury(msg_);
  }

private:
  ::service_interface_ws::srv::BlackMonkey_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::service_interface_ws::srv::BlackMonkey_Response>()
{
  return service_interface_ws::srv::builder::Init_BlackMonkey_Response_beat();
}

}  // namespace service_interface_ws

#endif  // SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__BUILDER_HPP_
