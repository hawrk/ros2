// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dros_common_interfaces:srv/Grasp.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__STRUCT_HPP_
#define DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__srv__Grasp_Request __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__srv__Grasp_Request __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Grasp_Request_
{
  using Type = Grasp_Request_<ContainerAllocator>;

  explicit Grasp_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_name = "";
    }
  }

  explicit Grasp_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_name = "";
    }
  }

  // field types and members
  using _object_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_name_type object_name;

  // setters for named parameter idiom
  Type & set__object_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__srv__Grasp_Request
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__srv__Grasp_Request
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Grasp_Request_ & other) const
  {
    if (this->object_name != other.object_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const Grasp_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Grasp_Request_

// alias to use template instance with default allocator
using Grasp_Request =
  dros_common_interfaces::srv::Grasp_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dros_common_interfaces


#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__srv__Grasp_Response __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__srv__Grasp_Response __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Grasp_Response_
{
  using Type = Grasp_Response_<ContainerAllocator>;

  explicit Grasp_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->err_msg = "";
    }
  }

  explicit Grasp_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : err_msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->err_msg = "";
    }
  }

  // field types and members
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _err_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _err_msg_type err_msg;

  // setters for named parameter idiom
  Type & set__err_code(
    const int32_t & _arg)
  {
    this->err_code = _arg;
    return *this;
  }
  Type & set__err_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->err_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__srv__Grasp_Response
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__srv__Grasp_Response
    std::shared_ptr<dros_common_interfaces::srv::Grasp_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Grasp_Response_ & other) const
  {
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->err_msg != other.err_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Grasp_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Grasp_Response_

// alias to use template instance with default allocator
using Grasp_Response =
  dros_common_interfaces::srv::Grasp_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dros_common_interfaces

namespace dros_common_interfaces
{

namespace srv
{

struct Grasp
{
  using Request = dros_common_interfaces::srv::Grasp_Request;
  using Response = dros_common_interfaces::srv::Grasp_Response;
};

}  // namespace srv

}  // namespace dros_common_interfaces

#endif  // DROS_COMMON_INTERFACES__SRV__DETAIL__GRASP__STRUCT_HPP_
