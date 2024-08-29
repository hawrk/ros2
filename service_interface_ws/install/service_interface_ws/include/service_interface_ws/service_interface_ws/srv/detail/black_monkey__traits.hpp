// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice

#ifndef SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__TRAITS_HPP_
#define SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "service_interface_ws/srv/detail/black_monkey__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace service_interface_ws
{

namespace srv
{

inline void to_flow_style_yaml(
  const BlackMonkey_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: hit_type
  {
    out << "hit_type: ";
    rosidl_generator_traits::value_to_yaml(msg.hit_type, out);
    out << ", ";
  }

  // member: injury
  {
    out << "injury: ";
    rosidl_generator_traits::value_to_yaml(msg.injury, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BlackMonkey_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hit_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hit_type: ";
    rosidl_generator_traits::value_to_yaml(msg.hit_type, out);
    out << "\n";
  }

  // member: injury
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "injury: ";
    rosidl_generator_traits::value_to_yaml(msg.injury, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BlackMonkey_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace service_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use service_interface_ws::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const service_interface_ws::srv::BlackMonkey_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  service_interface_ws::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use service_interface_ws::srv::to_yaml() instead")]]
inline std::string to_yaml(const service_interface_ws::srv::BlackMonkey_Request & msg)
{
  return service_interface_ws::srv::to_yaml(msg);
}

template<>
inline const char * data_type<service_interface_ws::srv::BlackMonkey_Request>()
{
  return "service_interface_ws::srv::BlackMonkey_Request";
}

template<>
inline const char * name<service_interface_ws::srv::BlackMonkey_Request>()
{
  return "service_interface_ws/srv/BlackMonkey_Request";
}

template<>
struct has_fixed_size<service_interface_ws::srv::BlackMonkey_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<service_interface_ws::srv::BlackMonkey_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<service_interface_ws::srv::BlackMonkey_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace service_interface_ws
{

namespace srv
{

inline void to_flow_style_yaml(
  const BlackMonkey_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: beat
  {
    out << "beat: ";
    rosidl_generator_traits::value_to_yaml(msg.beat, out);
    out << ", ";
  }

  // member: real_injury
  {
    out << "real_injury: ";
    rosidl_generator_traits::value_to_yaml(msg.real_injury, out);
    out << ", ";
  }

  // member: words
  {
    out << "words: ";
    rosidl_generator_traits::value_to_yaml(msg.words, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BlackMonkey_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: beat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "beat: ";
    rosidl_generator_traits::value_to_yaml(msg.beat, out);
    out << "\n";
  }

  // member: real_injury
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "real_injury: ";
    rosidl_generator_traits::value_to_yaml(msg.real_injury, out);
    out << "\n";
  }

  // member: words
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "words: ";
    rosidl_generator_traits::value_to_yaml(msg.words, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BlackMonkey_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace service_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use service_interface_ws::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const service_interface_ws::srv::BlackMonkey_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  service_interface_ws::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use service_interface_ws::srv::to_yaml() instead")]]
inline std::string to_yaml(const service_interface_ws::srv::BlackMonkey_Response & msg)
{
  return service_interface_ws::srv::to_yaml(msg);
}

template<>
inline const char * data_type<service_interface_ws::srv::BlackMonkey_Response>()
{
  return "service_interface_ws::srv::BlackMonkey_Response";
}

template<>
inline const char * name<service_interface_ws::srv::BlackMonkey_Response>()
{
  return "service_interface_ws/srv/BlackMonkey_Response";
}

template<>
struct has_fixed_size<service_interface_ws::srv::BlackMonkey_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<service_interface_ws::srv::BlackMonkey_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<service_interface_ws::srv::BlackMonkey_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<service_interface_ws::srv::BlackMonkey>()
{
  return "service_interface_ws::srv::BlackMonkey";
}

template<>
inline const char * name<service_interface_ws::srv::BlackMonkey>()
{
  return "service_interface_ws/srv/BlackMonkey";
}

template<>
struct has_fixed_size<service_interface_ws::srv::BlackMonkey>
  : std::integral_constant<
    bool,
    has_fixed_size<service_interface_ws::srv::BlackMonkey_Request>::value &&
    has_fixed_size<service_interface_ws::srv::BlackMonkey_Response>::value
  >
{
};

template<>
struct has_bounded_size<service_interface_ws::srv::BlackMonkey>
  : std::integral_constant<
    bool,
    has_bounded_size<service_interface_ws::srv::BlackMonkey_Request>::value &&
    has_bounded_size<service_interface_ws::srv::BlackMonkey_Response>::value
  >
{
};

template<>
struct is_service<service_interface_ws::srv::BlackMonkey>
  : std::true_type
{
};

template<>
struct is_service_request<service_interface_ws::srv::BlackMonkey_Request>
  : std::true_type
{
};

template<>
struct is_service_response<service_interface_ws::srv::BlackMonkey_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__TRAITS_HPP_
