// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice
#include "service_interface_ws/srv/detail/black_monkey__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "service_interface_ws/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "service_interface_ws/srv/detail/black_monkey__struct.h"
#include "service_interface_ws/srv/detail/black_monkey__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _BlackMonkey_Request__ros_msg_type = service_interface_ws__srv__BlackMonkey_Request;

static bool _BlackMonkey_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BlackMonkey_Request__ros_msg_type * ros_message = static_cast<const _BlackMonkey_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: hit_type
  {
    cdr << ros_message->hit_type;
  }

  // Field name: injury
  {
    cdr << ros_message->injury;
  }

  return true;
}

static bool _BlackMonkey_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BlackMonkey_Request__ros_msg_type * ros_message = static_cast<_BlackMonkey_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: hit_type
  {
    cdr >> ros_message->hit_type;
  }

  // Field name: injury
  {
    cdr >> ros_message->injury;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_service_interface_ws
size_t get_serialized_size_service_interface_ws__srv__BlackMonkey_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BlackMonkey_Request__ros_msg_type * ros_message = static_cast<const _BlackMonkey_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name hit_type
  {
    size_t item_size = sizeof(ros_message->hit_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name injury
  {
    size_t item_size = sizeof(ros_message->injury);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BlackMonkey_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_service_interface_ws__srv__BlackMonkey_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_service_interface_ws
size_t max_serialized_size_service_interface_ws__srv__BlackMonkey_Request(
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

  // member: hit_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: injury
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
    using DataType = service_interface_ws__srv__BlackMonkey_Request;
    is_plain =
      (
      offsetof(DataType, injury) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BlackMonkey_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_service_interface_ws__srv__BlackMonkey_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BlackMonkey_Request = {
  "service_interface_ws::srv",
  "BlackMonkey_Request",
  _BlackMonkey_Request__cdr_serialize,
  _BlackMonkey_Request__cdr_deserialize,
  _BlackMonkey_Request__get_serialized_size,
  _BlackMonkey_Request__max_serialized_size
};

static rosidl_message_type_support_t _BlackMonkey_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BlackMonkey_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_interface_ws, srv, BlackMonkey_Request)() {
  return &_BlackMonkey_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "service_interface_ws/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "service_interface_ws/srv/detail/black_monkey__struct.h"
// already included above
// #include "service_interface_ws/srv/detail/black_monkey__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // words
#include "rosidl_runtime_c/string_functions.h"  // words

// forward declare type support functions


using _BlackMonkey_Response__ros_msg_type = service_interface_ws__srv__BlackMonkey_Response;

static bool _BlackMonkey_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BlackMonkey_Response__ros_msg_type * ros_message = static_cast<const _BlackMonkey_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: beat
  {
    cdr << (ros_message->beat ? true : false);
  }

  // Field name: real_injury
  {
    cdr << ros_message->real_injury;
  }

  // Field name: words
  {
    const rosidl_runtime_c__String * str = &ros_message->words;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _BlackMonkey_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BlackMonkey_Response__ros_msg_type * ros_message = static_cast<_BlackMonkey_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: beat
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->beat = tmp ? true : false;
  }

  // Field name: real_injury
  {
    cdr >> ros_message->real_injury;
  }

  // Field name: words
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->words.data) {
      rosidl_runtime_c__String__init(&ros_message->words);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->words,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'words'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_service_interface_ws
size_t get_serialized_size_service_interface_ws__srv__BlackMonkey_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BlackMonkey_Response__ros_msg_type * ros_message = static_cast<const _BlackMonkey_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name beat
  {
    size_t item_size = sizeof(ros_message->beat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name real_injury
  {
    size_t item_size = sizeof(ros_message->real_injury);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name words
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->words.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _BlackMonkey_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_service_interface_ws__srv__BlackMonkey_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_service_interface_ws
size_t max_serialized_size_service_interface_ws__srv__BlackMonkey_Response(
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

  // member: beat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: real_injury
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: words
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
    using DataType = service_interface_ws__srv__BlackMonkey_Response;
    is_plain =
      (
      offsetof(DataType, words) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BlackMonkey_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_service_interface_ws__srv__BlackMonkey_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BlackMonkey_Response = {
  "service_interface_ws::srv",
  "BlackMonkey_Response",
  _BlackMonkey_Response__cdr_serialize,
  _BlackMonkey_Response__cdr_deserialize,
  _BlackMonkey_Response__get_serialized_size,
  _BlackMonkey_Response__max_serialized_size
};

static rosidl_message_type_support_t _BlackMonkey_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BlackMonkey_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_interface_ws, srv, BlackMonkey_Response)() {
  return &_BlackMonkey_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "service_interface_ws/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "service_interface_ws/srv/black_monkey.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t BlackMonkey__callbacks = {
  "service_interface_ws::srv",
  "BlackMonkey",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_interface_ws, srv, BlackMonkey_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_interface_ws, srv, BlackMonkey_Response)(),
};

static rosidl_service_type_support_t BlackMonkey__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &BlackMonkey__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_interface_ws, srv, BlackMonkey)() {
  return &BlackMonkey__handle;
}

#if defined(__cplusplus)
}
#endif
