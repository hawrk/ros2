// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dros_common_interfaces:srv/Grasp.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__STRUCT_H_
#define DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'object_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Grasp in the package dros_common_interfaces.
typedef struct dros_common_interfaces__srv__Grasp_Request
{
  rosidl_runtime_c__String object_name;
} dros_common_interfaces__srv__Grasp_Request;

// Struct for a sequence of dros_common_interfaces__srv__Grasp_Request.
typedef struct dros_common_interfaces__srv__Grasp_Request__Sequence
{
  dros_common_interfaces__srv__Grasp_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__srv__Grasp_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'err_msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Grasp in the package dros_common_interfaces.
typedef struct dros_common_interfaces__srv__Grasp_Response
{
  int32_t err_code;
  rosidl_runtime_c__String err_msg;
} dros_common_interfaces__srv__Grasp_Response;

// Struct for a sequence of dros_common_interfaces__srv__Grasp_Response.
typedef struct dros_common_interfaces__srv__Grasp_Response__Sequence
{
  dros_common_interfaces__srv__Grasp_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__srv__Grasp_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__STRUCT_H_
