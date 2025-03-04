// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dros_common_interfaces:msg/IMUInfo.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__MSG__DETAIL__IMU_INFO__TRAITS_HPP_
#define DROS_COMMON_INTERFACES__MSG__DETAIL__IMU_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dros_common_interfaces/msg/detail/imu_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace dros_common_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const IMUInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: noise_variances
  {
    if (msg.noise_variances.size() == 0) {
      out << "noise_variances: []";
    } else {
      out << "noise_variances: [";
      size_t pending_items = msg.noise_variances.size();
      for (auto item : msg.noise_variances) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: bias_variances
  {
    if (msg.bias_variances.size() == 0) {
      out << "bias_variances: []";
    } else {
      out << "bias_variances: [";
      size_t pending_items = msg.bias_variances.size();
      for (auto item : msg.bias_variances) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IMUInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: noise_variances
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.noise_variances.size() == 0) {
      out << "noise_variances: []\n";
    } else {
      out << "noise_variances:\n";
      for (auto item : msg.noise_variances) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: bias_variances
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bias_variances.size() == 0) {
      out << "bias_variances: []\n";
    } else {
      out << "bias_variances:\n";
      for (auto item : msg.bias_variances) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IMUInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dros_common_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dros_common_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dros_common_interfaces::msg::IMUInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  dros_common_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dros_common_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dros_common_interfaces::msg::IMUInfo & msg)
{
  return dros_common_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dros_common_interfaces::msg::IMUInfo>()
{
  return "dros_common_interfaces::msg::IMUInfo";
}

template<>
inline const char * name<dros_common_interfaces::msg::IMUInfo>()
{
  return "dros_common_interfaces/msg/IMUInfo";
}

template<>
struct has_fixed_size<dros_common_interfaces::msg::IMUInfo>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<dros_common_interfaces::msg::IMUInfo>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<dros_common_interfaces::msg::IMUInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DROS_COMMON_INTERFACES__MSG__DETAIL__IMU_INFO__TRAITS_HPP_
