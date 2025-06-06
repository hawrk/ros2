// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dros_common_interfaces:msg/RGBD.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dros_common_interfaces/msg/detail/rgbd__rosidl_typesupport_introspection_c.h"
#include "dros_common_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dros_common_interfaces/msg/detail/rgbd__functions.h"
#include "dros_common_interfaces/msg/detail/rgbd__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `rgb_camera_info`
// Member `depth_camera_info`
#include "sensor_msgs/msg/camera_info.h"
// Member `rgb_camera_info`
// Member `depth_camera_info`
#include "sensor_msgs/msg/detail/camera_info__rosidl_typesupport_introspection_c.h"
// Member `rgb`
// Member `depth`
#include "sensor_msgs/msg/image.h"
// Member `rgb`
// Member `depth`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dros_common_interfaces__msg__RGBD__init(message_memory);
}

void dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_fini_function(void * message_memory)
{
  dros_common_interfaces__msg__RGBD__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces__msg__RGBD, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rgb_camera_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces__msg__RGBD, rgb_camera_info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "depth_camera_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces__msg__RGBD, depth_camera_info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rgb",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces__msg__RGBD, rgb),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "depth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces__msg__RGBD, depth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_members = {
  "dros_common_interfaces__msg",  // message namespace
  "RGBD",  // message name
  5,  // number of fields
  sizeof(dros_common_interfaces__msg__RGBD),
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array,  // message members
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_init_function,  // function to initialize message memory (memory has to be allocated)
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_type_support_handle = {
  0,
  &dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dros_common_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dros_common_interfaces, msg, RGBD)() {
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, CameraInfo)();
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, CameraInfo)();
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_type_support_handle.typesupport_identifier) {
    dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dros_common_interfaces__msg__RGBD__rosidl_typesupport_introspection_c__RGBD_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
