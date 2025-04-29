// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dros_common_interfaces:srv/Grasp.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__TRAITS_HPP_
#define DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dros_common_interfaces/srv/detail/grasp__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dros_common_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Grasp_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: object_name
  {
    out << "object_name: ";
    rosidl_generator_traits::value_to_yaml(msg.object_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Grasp_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: object_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_name: ";
    rosidl_generator_traits::value_to_yaml(msg.object_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Grasp_Request & msg, bool use_flow_style = false)
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

}  // namespace dros_common_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dros_common_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dros_common_interfaces::srv::Grasp_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dros_common_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dros_common_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dros_common_interfaces::srv::Grasp_Request & msg)
{
  return dros_common_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dros_common_interfaces::srv::Grasp_Request>()
{
  return "dros_common_interfaces::srv::Grasp_Request";
}

template<>
inline const char * name<dros_common_interfaces::srv::Grasp_Request>()
{
  return "dros_common_interfaces/srv/Grasp_Request";
}

template<>
struct has_fixed_size<dros_common_interfaces::srv::Grasp_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dros_common_interfaces::srv::Grasp_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dros_common_interfaces::srv::Grasp_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dros_common_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Grasp_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: err_code
  {
    out << "err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.err_code, out);
    out << ", ";
  }

  // member: err_msg
  {
    out << "err_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.err_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Grasp_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: err_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.err_code, out);
    out << "\n";
  }

  // member: err_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.err_msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Grasp_Response & msg, bool use_flow_style = false)
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

}  // namespace dros_common_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dros_common_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dros_common_interfaces::srv::Grasp_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dros_common_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dros_common_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dros_common_interfaces::srv::Grasp_Response & msg)
{
  return dros_common_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dros_common_interfaces::srv::Grasp_Response>()
{
  return "dros_common_interfaces::srv::Grasp_Response";
}

template<>
inline const char * name<dros_common_interfaces::srv::Grasp_Response>()
{
  return "dros_common_interfaces/srv/Grasp_Response";
}

template<>
struct has_fixed_size<dros_common_interfaces::srv::Grasp_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dros_common_interfaces::srv::Grasp_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dros_common_interfaces::srv::Grasp_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dros_common_interfaces::srv::Grasp>()
{
  return "dros_common_interfaces::srv::Grasp";
}

template<>
inline const char * name<dros_common_interfaces::srv::Grasp>()
{
  return "dros_common_interfaces/srv/Grasp";
}

template<>
struct has_fixed_size<dros_common_interfaces::srv::Grasp>
  : std::integral_constant<
    bool,
    has_fixed_size<dros_common_interfaces::srv::Grasp_Request>::value &&
    has_fixed_size<dros_common_interfaces::srv::Grasp_Response>::value
  >
{
};

template<>
struct has_bounded_size<dros_common_interfaces::srv::Grasp>
  : std::integral_constant<
    bool,
    has_bounded_size<dros_common_interfaces::srv::Grasp_Request>::value &&
    has_bounded_size<dros_common_interfaces::srv::Grasp_Response>::value
  >
{
};

template<>
struct is_service<dros_common_interfaces::srv::Grasp>
  : std::true_type
{
};

template<>
struct is_service_request<dros_common_interfaces::srv::Grasp_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dros_common_interfaces::srv::Grasp_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__TRAITS_HPP_
