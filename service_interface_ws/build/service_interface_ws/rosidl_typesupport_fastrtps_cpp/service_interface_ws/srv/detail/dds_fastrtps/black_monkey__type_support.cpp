// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice
#include "service_interface_ws/srv/detail/black_monkey__rosidl_typesupport_fastrtps_cpp.hpp"
#include "service_interface_ws/srv/detail/black_monkey__struct.hpp"

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

namespace service_interface_ws
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
cdr_serialize(
  const service_interface_ws::srv::BlackMonkey_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: hit_type
  cdr << ros_message.hit_type;
  // Member: injury
  cdr << ros_message.injury;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  service_interface_ws::srv::BlackMonkey_Request & ros_message)
{
  // Member: hit_type
  cdr >> ros_message.hit_type;

  // Member: injury
  cdr >> ros_message.injury;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
get_serialized_size(
  const service_interface_ws::srv::BlackMonkey_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: hit_type
  {
    size_t item_size = sizeof(ros_message.hit_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: injury
  {
    size_t item_size = sizeof(ros_message.injury);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
max_serialized_size_BlackMonkey_Request(
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


  // Member: hit_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: injury
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = service_interface_ws::srv::BlackMonkey_Request;
    is_plain =
      (
      offsetof(DataType, injury) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BlackMonkey_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const service_interface_ws::srv::BlackMonkey_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BlackMonkey_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<service_interface_ws::srv::BlackMonkey_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BlackMonkey_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const service_interface_ws::srv::BlackMonkey_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BlackMonkey_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BlackMonkey_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BlackMonkey_Request__callbacks = {
  "service_interface_ws::srv",
  "BlackMonkey_Request",
  _BlackMonkey_Request__cdr_serialize,
  _BlackMonkey_Request__cdr_deserialize,
  _BlackMonkey_Request__get_serialized_size,
  _BlackMonkey_Request__max_serialized_size
};

static rosidl_message_type_support_t _BlackMonkey_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BlackMonkey_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace service_interface_ws

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_service_interface_ws
const rosidl_message_type_support_t *
get_message_type_support_handle<service_interface_ws::srv::BlackMonkey_Request>()
{
  return &service_interface_ws::srv::typesupport_fastrtps_cpp::_BlackMonkey_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, service_interface_ws, srv, BlackMonkey_Request)() {
  return &service_interface_ws::srv::typesupport_fastrtps_cpp::_BlackMonkey_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace service_interface_ws
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
cdr_serialize(
  const service_interface_ws::srv::BlackMonkey_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: beat
  cdr << (ros_message.beat ? true : false);
  // Member: real_injury
  cdr << ros_message.real_injury;
  // Member: words
  cdr << ros_message.words;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  service_interface_ws::srv::BlackMonkey_Response & ros_message)
{
  // Member: beat
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.beat = tmp ? true : false;
  }

  // Member: real_injury
  cdr >> ros_message.real_injury;

  // Member: words
  cdr >> ros_message.words;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
get_serialized_size(
  const service_interface_ws::srv::BlackMonkey_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: beat
  {
    size_t item_size = sizeof(ros_message.beat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: real_injury
  {
    size_t item_size = sizeof(ros_message.real_injury);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: words
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.words.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_service_interface_ws
max_serialized_size_BlackMonkey_Response(
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


  // Member: beat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: real_injury
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: words
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = service_interface_ws::srv::BlackMonkey_Response;
    is_plain =
      (
      offsetof(DataType, words) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _BlackMonkey_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const service_interface_ws::srv::BlackMonkey_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BlackMonkey_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<service_interface_ws::srv::BlackMonkey_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BlackMonkey_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const service_interface_ws::srv::BlackMonkey_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BlackMonkey_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BlackMonkey_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BlackMonkey_Response__callbacks = {
  "service_interface_ws::srv",
  "BlackMonkey_Response",
  _BlackMonkey_Response__cdr_serialize,
  _BlackMonkey_Response__cdr_deserialize,
  _BlackMonkey_Response__get_serialized_size,
  _BlackMonkey_Response__max_serialized_size
};

static rosidl_message_type_support_t _BlackMonkey_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BlackMonkey_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace service_interface_ws

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_service_interface_ws
const rosidl_message_type_support_t *
get_message_type_support_handle<service_interface_ws::srv::BlackMonkey_Response>()
{
  return &service_interface_ws::srv::typesupport_fastrtps_cpp::_BlackMonkey_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, service_interface_ws, srv, BlackMonkey_Response)() {
  return &service_interface_ws::srv::typesupport_fastrtps_cpp::_BlackMonkey_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace service_interface_ws
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _BlackMonkey__callbacks = {
  "service_interface_ws::srv",
  "BlackMonkey",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, service_interface_ws, srv, BlackMonkey_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, service_interface_ws, srv, BlackMonkey_Response)(),
};

static rosidl_service_type_support_t _BlackMonkey__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BlackMonkey__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace service_interface_ws

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_service_interface_ws
const rosidl_service_type_support_t *
get_service_type_support_handle<service_interface_ws::srv::BlackMonkey>()
{
  return &service_interface_ws::srv::typesupport_fastrtps_cpp::_BlackMonkey__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, service_interface_ws, srv, BlackMonkey)() {
  return &service_interface_ws::srv::typesupport_fastrtps_cpp::_BlackMonkey__handle;
}

#ifdef __cplusplus
}
#endif
