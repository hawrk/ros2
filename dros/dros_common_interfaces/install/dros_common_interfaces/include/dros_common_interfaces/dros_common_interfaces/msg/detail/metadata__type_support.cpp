// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dros_common_interfaces:msg/Metadata.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dros_common_interfaces/msg/detail/metadata__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dros_common_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Metadata_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dros_common_interfaces::msg::Metadata(_init);
}

void Metadata_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dros_common_interfaces::msg::Metadata *>(message_memory);
  typed_message->~Metadata();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Metadata_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces::msg::Metadata, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "json_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dros_common_interfaces::msg::Metadata, json_data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Metadata_message_members = {
  "dros_common_interfaces::msg",  // message namespace
  "Metadata",  // message name
  2,  // number of fields
  sizeof(dros_common_interfaces::msg::Metadata),
  Metadata_message_member_array,  // message members
  Metadata_init_function,  // function to initialize message memory (memory has to be allocated)
  Metadata_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Metadata_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Metadata_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dros_common_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dros_common_interfaces::msg::Metadata>()
{
  return &::dros_common_interfaces::msg::rosidl_typesupport_introspection_cpp::Metadata_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dros_common_interfaces, msg, Metadata)() {
  return &::dros_common_interfaces::msg::rosidl_typesupport_introspection_cpp::Metadata_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
