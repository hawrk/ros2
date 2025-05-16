// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dros_common_interfaces:action/DexterousHand.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__STRUCT_H_
#define DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'obj_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_Goal
{
  int32_t target_position;
  rosidl_runtime_c__String obj_name;
} dros_common_interfaces__action__DexterousHand_Goal;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_Goal.
typedef struct dros_common_interfaces__action__DexterousHand_Goal__Sequence
{
  dros_common_interfaces__action__DexterousHand_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_Result
{
  bool success;
  rosidl_runtime_c__String msg;
} dros_common_interfaces__action__DexterousHand_Result;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_Result.
typedef struct dros_common_interfaces__action__DexterousHand_Result__Sequence
{
  dros_common_interfaces__action__DexterousHand_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_Feedback
{
  float progress;
} dros_common_interfaces__action__DexterousHand_Feedback;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_Feedback.
typedef struct dros_common_interfaces__action__DexterousHand_Feedback__Sequence
{
  dros_common_interfaces__action__DexterousHand_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "dros_common_interfaces/action/detail/dexterous_hand__struct.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  dros_common_interfaces__action__DexterousHand_Goal goal;
} dros_common_interfaces__action__DexterousHand_SendGoal_Request;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_SendGoal_Request.
typedef struct dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence
{
  dros_common_interfaces__action__DexterousHand_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} dros_common_interfaces__action__DexterousHand_SendGoal_Response;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_SendGoal_Response.
typedef struct dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence
{
  dros_common_interfaces__action__DexterousHand_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} dros_common_interfaces__action__DexterousHand_GetResult_Request;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_GetResult_Request.
typedef struct dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence
{
  dros_common_interfaces__action__DexterousHand_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "dros_common_interfaces/action/detail/dexterous_hand__struct.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_GetResult_Response
{
  int8_t status;
  dros_common_interfaces__action__DexterousHand_Result result;
} dros_common_interfaces__action__DexterousHand_GetResult_Response;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_GetResult_Response.
typedef struct dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence
{
  dros_common_interfaces__action__DexterousHand_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "dros_common_interfaces/action/detail/dexterous_hand__struct.h"

/// Struct defined in action/DexterousHand in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__DexterousHand_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  dros_common_interfaces__action__DexterousHand_Feedback feedback;
} dros_common_interfaces__action__DexterousHand_FeedbackMessage;

// Struct for a sequence of dros_common_interfaces__action__DexterousHand_FeedbackMessage.
typedef struct dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence
{
  dros_common_interfaces__action__DexterousHand_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__STRUCT_H_
