// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice

#ifndef SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__STRUCT_H_
#define SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/BlackMonkey in the package service_interface_ws.
typedef struct service_interface_ws__srv__BlackMonkey_Request
{
  int32_t hit_type;
  /// 伤害数值
  uint32_t injury;
} service_interface_ws__srv__BlackMonkey_Request;

// Struct for a sequence of service_interface_ws__srv__BlackMonkey_Request.
typedef struct service_interface_ws__srv__BlackMonkey_Request__Sequence
{
  service_interface_ws__srv__BlackMonkey_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} service_interface_ws__srv__BlackMonkey_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'words'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BlackMonkey in the package service_interface_ws.
typedef struct service_interface_ws__srv__BlackMonkey_Response
{
  bool beat;
  /// 实际伤害数值
  uint32_t real_injury;
  /// 反馈
  rosidl_runtime_c__String words;
} service_interface_ws__srv__BlackMonkey_Response;

// Struct for a sequence of service_interface_ws__srv__BlackMonkey_Response.
typedef struct service_interface_ws__srv__BlackMonkey_Response__Sequence
{
  service_interface_ws__srv__BlackMonkey_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} service_interface_ws__srv__BlackMonkey_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__STRUCT_H_
