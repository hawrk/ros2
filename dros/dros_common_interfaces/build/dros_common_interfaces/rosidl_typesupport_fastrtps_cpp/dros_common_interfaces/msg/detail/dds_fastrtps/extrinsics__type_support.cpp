// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dros_common_interfaces:msg/Extrinsics.idl
// generated code does not contain a copyright notice
#include "dros_common_interfaces/msg/detail/extrinsics__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dros_common_interfaces/msg/detail/extrinsics__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace dros_common_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dros_common_interfaces
cdr_serialize(
  const dros_common_interfaces::msg::Extrinsics & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: rotation
  {
    cdr << ros_message.rotation;
  }
  // Member: translation
  {
    cdr << ros_message.translation;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dros_common_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dros_common_interfaces::msg::Extrinsics & ros_message)
{
  // Member: rotation
  {
    cdr >> ros_message.rotation;
  }

  // Member: translation
  {
    cdr >> ros_message.translation;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dros_common_interfaces
get_serialized_size(
  const dros_common_interfaces::msg::Extrinsics & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: rotation
  {
    size_t array_size = 9;
    size_t item_size = sizeof(ros_message.rotation[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: translation
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.translation[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dros_common_interfaces
max_serialized_size_Extrinsics(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: rotation
  {
    size_t array_size = 9;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: translation
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dros_common_interfaces::msg::Extrinsics;
    is_plain =
      (
      offsetof(DataType, translation) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Extrinsics__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dros_common_interfaces::msg::Extrinsics *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Extrinsics__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dros_common_interfaces::msg::Extrinsics *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Extrinsics__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dros_common_interfaces::msg::Extrinsics *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Extrinsics__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Extrinsics(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Extrinsics__callbacks = {
  "dros_common_interfaces::msg",
  "Extrinsics",
  _Extrinsics__cdr_serialize,
  _Extrinsics__cdr_deserialize,
  _Extrinsics__get_serialized_size,
  _Extrinsics__max_serialized_size
};

static rosidl_message_type_support_t _Extrinsics__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Extrinsics__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dros_common_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dros_common_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<dros_common_interfaces::msg::Extrinsics>()
{
  return &dros_common_interfaces::msg::typesupport_fastrtps_cpp::_Extrinsics__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dros_common_interfaces, msg, Extrinsics)() {
  return &dros_common_interfaces::msg::typesupport_fastrtps_cpp::_Extrinsics__handle;
}

#ifdef __cplusplus
}
#endif
