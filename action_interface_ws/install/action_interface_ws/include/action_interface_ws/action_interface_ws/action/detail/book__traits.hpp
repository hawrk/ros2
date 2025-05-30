// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interface_ws:action/Book.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__TRAITS_HPP_
#define ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interface_ws/action/detail/book__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: book_name
  {
    out << "book_name: ";
    rosidl_generator_traits::value_to_yaml(msg.book_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: book_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "book_name: ";
    rosidl_generator_traits::value_to_yaml(msg.book_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_Goal & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_Goal>()
{
  return "action_interface_ws::action::Book_Goal";
}

template<>
inline const char * name<action_interface_ws::action::Book_Goal>()
{
  return "action_interface_ws/action/Book_Goal";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interface_ws::action::Book_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: line_num
  {
    out << "line_num: ";
    rosidl_generator_traits::value_to_yaml(msg.line_num, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: line_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line_num: ";
    rosidl_generator_traits::value_to_yaml(msg.line_num, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_Result & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_Result>()
{
  return "action_interface_ws::action::Book_Result";
}

template<>
inline const char * name<action_interface_ws::action::Book_Result>()
{
  return "action_interface_ws/action/Book_Result";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interface_ws::action::Book_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: cur_line
  {
    out << "cur_line: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_line, out);
    out << ", ";
  }

  // member: line_words
  {
    out << "line_words: ";
    rosidl_generator_traits::value_to_yaml(msg.line_words, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cur_line
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cur_line: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_line, out);
    out << "\n";
  }

  // member: line_words
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line_words: ";
    rosidl_generator_traits::value_to_yaml(msg.line_words, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_Feedback & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_Feedback>()
{
  return "action_interface_ws::action::Book_Feedback";
}

template<>
inline const char * name<action_interface_ws::action::Book_Feedback>()
{
  return "action_interface_ws/action/Book_Feedback";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interface_ws::action::Book_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "action_interface_ws/action/detail/book__traits.hpp"

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_SendGoal_Request & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_SendGoal_Request>()
{
  return "action_interface_ws::action::Book_SendGoal_Request";
}

template<>
inline const char * name<action_interface_ws::action::Book_SendGoal_Request>()
{
  return "action_interface_ws/action/Book_SendGoal_Request";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<action_interface_ws::action::Book_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<action_interface_ws::action::Book_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface_ws::action::Book_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_SendGoal_Response & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_SendGoal_Response>()
{
  return "action_interface_ws::action::Book_SendGoal_Response";
}

template<>
inline const char * name<action_interface_ws::action::Book_SendGoal_Response>()
{
  return "action_interface_ws/action/Book_SendGoal_Response";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<action_interface_ws::action::Book_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface_ws::action::Book_SendGoal>()
{
  return "action_interface_ws::action::Book_SendGoal";
}

template<>
inline const char * name<action_interface_ws::action::Book_SendGoal>()
{
  return "action_interface_ws/action/Book_SendGoal";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface_ws::action::Book_SendGoal_Request>::value &&
    has_fixed_size<action_interface_ws::action::Book_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface_ws::action::Book_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface_ws::action::Book_SendGoal_Request>::value &&
    has_bounded_size<action_interface_ws::action::Book_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<action_interface_ws::action::Book_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface_ws::action::Book_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface_ws::action::Book_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_GetResult_Request & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_GetResult_Request>()
{
  return "action_interface_ws::action::Book_GetResult_Request";
}

template<>
inline const char * name<action_interface_ws::action::Book_GetResult_Request>()
{
  return "action_interface_ws/action/Book_GetResult_Request";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface_ws::action::Book_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interface_ws/action/detail/book__traits.hpp"

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_GetResult_Response & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_GetResult_Response>()
{
  return "action_interface_ws::action::Book_GetResult_Response";
}

template<>
inline const char * name<action_interface_ws::action::Book_GetResult_Response>()
{
  return "action_interface_ws/action/Book_GetResult_Response";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<action_interface_ws::action::Book_Result>::value> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<action_interface_ws::action::Book_Result>::value> {};

template<>
struct is_message<action_interface_ws::action::Book_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface_ws::action::Book_GetResult>()
{
  return "action_interface_ws::action::Book_GetResult";
}

template<>
inline const char * name<action_interface_ws::action::Book_GetResult>()
{
  return "action_interface_ws/action/Book_GetResult";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface_ws::action::Book_GetResult_Request>::value &&
    has_fixed_size<action_interface_ws::action::Book_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface_ws::action::Book_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface_ws::action::Book_GetResult_Request>::value &&
    has_bounded_size<action_interface_ws::action::Book_GetResult_Response>::value
  >
{
};

template<>
struct is_service<action_interface_ws::action::Book_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface_ws::action::Book_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface_ws::action::Book_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "action_interface_ws/action/detail/book__traits.hpp"

namespace action_interface_ws
{

namespace action
{

inline void to_flow_style_yaml(
  const Book_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Book_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Book_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface_ws

namespace rosidl_generator_traits
{

[[deprecated("use action_interface_ws::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface_ws::action::Book_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface_ws::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface_ws::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface_ws::action::Book_FeedbackMessage & msg)
{
  return action_interface_ws::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface_ws::action::Book_FeedbackMessage>()
{
  return "action_interface_ws::action::Book_FeedbackMessage";
}

template<>
inline const char * name<action_interface_ws::action::Book_FeedbackMessage>()
{
  return "action_interface_ws/action/Book_FeedbackMessage";
}

template<>
struct has_fixed_size<action_interface_ws::action::Book_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<action_interface_ws::action::Book_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface_ws::action::Book_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<action_interface_ws::action::Book_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface_ws::action::Book_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<action_interface_ws::action::Book>
  : std::true_type
{
};

template<>
struct is_action_goal<action_interface_ws::action::Book_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<action_interface_ws::action::Book_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<action_interface_ws::action::Book_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__TRAITS_HPP_
