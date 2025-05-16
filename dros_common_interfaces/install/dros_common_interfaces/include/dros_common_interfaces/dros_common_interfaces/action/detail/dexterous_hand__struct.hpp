// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dros_common_interfaces:action/DexterousHand.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__STRUCT_HPP_
#define DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_Goal __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_Goal __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_Goal_
{
  using Type = DexterousHand_Goal_<ContainerAllocator>;

  explicit DexterousHand_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_position = 0l;
      this->obj_name = "";
    }
  }

  explicit DexterousHand_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obj_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_position = 0l;
      this->obj_name = "";
    }
  }

  // field types and members
  using _target_position_type =
    int32_t;
  _target_position_type target_position;
  using _obj_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _obj_name_type obj_name;

  // setters for named parameter idiom
  Type & set__target_position(
    const int32_t & _arg)
  {
    this->target_position = _arg;
    return *this;
  }
  Type & set__obj_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->obj_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_Goal
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_Goal
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_Goal_ & other) const
  {
    if (this->target_position != other.target_position) {
      return false;
    }
    if (this->obj_name != other.obj_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_Goal_

// alias to use template instance with default allocator
using DexterousHand_Goal =
  dros_common_interfaces::action::DexterousHand_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces


#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_Result __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_Result __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_Result_
{
  using Type = DexterousHand_Result_<ContainerAllocator>;

  explicit DexterousHand_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->msg = "";
    }
  }

  explicit DexterousHand_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->msg = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_Result
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_Result
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_Result_

// alias to use template instance with default allocator
using DexterousHand_Result =
  dros_common_interfaces::action::DexterousHand_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces


#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_Feedback __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_Feedback_
{
  using Type = DexterousHand_Feedback_<ContainerAllocator>;

  explicit DexterousHand_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->progress = 0.0f;
    }
  }

  explicit DexterousHand_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->progress = 0.0f;
    }
  }

  // field types and members
  using _progress_type =
    float;
  _progress_type progress;

  // setters for named parameter idiom
  Type & set__progress(
    const float & _arg)
  {
    this->progress = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_Feedback
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_Feedback
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_Feedback_ & other) const
  {
    if (this->progress != other.progress) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_Feedback_

// alias to use template instance with default allocator
using DexterousHand_Feedback =
  dros_common_interfaces::action::DexterousHand_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "dros_common_interfaces/action/detail/dexterous_hand__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Request __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_SendGoal_Request_
{
  using Type = DexterousHand_SendGoal_Request_<ContainerAllocator>;

  explicit DexterousHand_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit DexterousHand_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const dros_common_interfaces::action::DexterousHand_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Request
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Request
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_SendGoal_Request_

// alias to use template instance with default allocator
using DexterousHand_SendGoal_Request =
  dros_common_interfaces::action::DexterousHand_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Response __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_SendGoal_Response_
{
  using Type = DexterousHand_SendGoal_Response_<ContainerAllocator>;

  explicit DexterousHand_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit DexterousHand_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Response
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_SendGoal_Response
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_SendGoal_Response_

// alias to use template instance with default allocator
using DexterousHand_SendGoal_Response =
  dros_common_interfaces::action::DexterousHand_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces

namespace dros_common_interfaces
{

namespace action
{

struct DexterousHand_SendGoal
{
  using Request = dros_common_interfaces::action::DexterousHand_SendGoal_Request;
  using Response = dros_common_interfaces::action::DexterousHand_SendGoal_Response;
};

}  // namespace action

}  // namespace dros_common_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Request __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_GetResult_Request_
{
  using Type = DexterousHand_GetResult_Request_<ContainerAllocator>;

  explicit DexterousHand_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit DexterousHand_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Request
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Request
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_GetResult_Request_

// alias to use template instance with default allocator
using DexterousHand_GetResult_Request =
  dros_common_interfaces::action::DexterousHand_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "dros_common_interfaces/action/detail/dexterous_hand__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Response __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_GetResult_Response_
{
  using Type = DexterousHand_GetResult_Response_<ContainerAllocator>;

  explicit DexterousHand_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit DexterousHand_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const dros_common_interfaces::action::DexterousHand_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Response
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_GetResult_Response
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_GetResult_Response_

// alias to use template instance with default allocator
using DexterousHand_GetResult_Response =
  dros_common_interfaces::action::DexterousHand_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces

namespace dros_common_interfaces
{

namespace action
{

struct DexterousHand_GetResult
{
  using Request = dros_common_interfaces::action::DexterousHand_GetResult_Request;
  using Response = dros_common_interfaces::action::DexterousHand_GetResult_Response;
};

}  // namespace action

}  // namespace dros_common_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "dros_common_interfaces/action/detail/dexterous_hand__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__dros_common_interfaces__action__DexterousHand_FeedbackMessage __declspec(deprecated)
#endif

namespace dros_common_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct DexterousHand_FeedbackMessage_
{
  using Type = DexterousHand_FeedbackMessage_<ContainerAllocator>;

  explicit DexterousHand_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit DexterousHand_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const dros_common_interfaces::action::DexterousHand_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_FeedbackMessage
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dros_common_interfaces__action__DexterousHand_FeedbackMessage
    std::shared_ptr<dros_common_interfaces::action::DexterousHand_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DexterousHand_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const DexterousHand_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DexterousHand_FeedbackMessage_

// alias to use template instance with default allocator
using DexterousHand_FeedbackMessage =
  dros_common_interfaces::action::DexterousHand_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace dros_common_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace dros_common_interfaces
{

namespace action
{

struct DexterousHand
{
  /// The goal message defined in the action definition.
  using Goal = dros_common_interfaces::action::DexterousHand_Goal;
  /// The result message defined in the action definition.
  using Result = dros_common_interfaces::action::DexterousHand_Result;
  /// The feedback message defined in the action definition.
  using Feedback = dros_common_interfaces::action::DexterousHand_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = dros_common_interfaces::action::DexterousHand_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = dros_common_interfaces::action::DexterousHand_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = dros_common_interfaces::action::DexterousHand_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct DexterousHand DexterousHand;

}  // namespace action

}  // namespace dros_common_interfaces

#endif  // DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__STRUCT_HPP_
