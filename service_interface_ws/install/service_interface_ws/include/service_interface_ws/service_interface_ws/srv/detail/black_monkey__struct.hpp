// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice

#ifndef SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__STRUCT_HPP_
#define SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__service_interface_ws__srv__BlackMonkey_Request __attribute__((deprecated))
#else
# define DEPRECATED__service_interface_ws__srv__BlackMonkey_Request __declspec(deprecated)
#endif

namespace service_interface_ws
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BlackMonkey_Request_
{
  using Type = BlackMonkey_Request_<ContainerAllocator>;

  explicit BlackMonkey_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hit_type = 0l;
      this->injury = 0ul;
    }
  }

  explicit BlackMonkey_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hit_type = 0l;
      this->injury = 0ul;
    }
  }

  // field types and members
  using _hit_type_type =
    int32_t;
  _hit_type_type hit_type;
  using _injury_type =
    uint32_t;
  _injury_type injury;

  // setters for named parameter idiom
  Type & set__hit_type(
    const int32_t & _arg)
  {
    this->hit_type = _arg;
    return *this;
  }
  Type & set__injury(
    const uint32_t & _arg)
  {
    this->injury = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__service_interface_ws__srv__BlackMonkey_Request
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__service_interface_ws__srv__BlackMonkey_Request
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BlackMonkey_Request_ & other) const
  {
    if (this->hit_type != other.hit_type) {
      return false;
    }
    if (this->injury != other.injury) {
      return false;
    }
    return true;
  }
  bool operator!=(const BlackMonkey_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BlackMonkey_Request_

// alias to use template instance with default allocator
using BlackMonkey_Request =
  service_interface_ws::srv::BlackMonkey_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace service_interface_ws


#ifndef _WIN32
# define DEPRECATED__service_interface_ws__srv__BlackMonkey_Response __attribute__((deprecated))
#else
# define DEPRECATED__service_interface_ws__srv__BlackMonkey_Response __declspec(deprecated)
#endif

namespace service_interface_ws
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BlackMonkey_Response_
{
  using Type = BlackMonkey_Response_<ContainerAllocator>;

  explicit BlackMonkey_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->beat = false;
      this->real_injury = 0ul;
      this->words = "";
    }
  }

  explicit BlackMonkey_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : words(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->beat = false;
      this->real_injury = 0ul;
      this->words = "";
    }
  }

  // field types and members
  using _beat_type =
    bool;
  _beat_type beat;
  using _real_injury_type =
    uint32_t;
  _real_injury_type real_injury;
  using _words_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _words_type words;

  // setters for named parameter idiom
  Type & set__beat(
    const bool & _arg)
  {
    this->beat = _arg;
    return *this;
  }
  Type & set__real_injury(
    const uint32_t & _arg)
  {
    this->real_injury = _arg;
    return *this;
  }
  Type & set__words(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->words = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__service_interface_ws__srv__BlackMonkey_Response
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__service_interface_ws__srv__BlackMonkey_Response
    std::shared_ptr<service_interface_ws::srv::BlackMonkey_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BlackMonkey_Response_ & other) const
  {
    if (this->beat != other.beat) {
      return false;
    }
    if (this->real_injury != other.real_injury) {
      return false;
    }
    if (this->words != other.words) {
      return false;
    }
    return true;
  }
  bool operator!=(const BlackMonkey_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BlackMonkey_Response_

// alias to use template instance with default allocator
using BlackMonkey_Response =
  service_interface_ws::srv::BlackMonkey_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace service_interface_ws

namespace service_interface_ws
{

namespace srv
{

struct BlackMonkey
{
  using Request = service_interface_ws::srv::BlackMonkey_Request;
  using Response = service_interface_ws::srv::BlackMonkey_Response;
};

}  // namespace srv

}  // namespace service_interface_ws

#endif  // SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__STRUCT_HPP_
