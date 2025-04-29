// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dros_common_interfaces:action/NavigateToPose.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_
#define DROS_COMMON_INTERFACES__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'behavior_tree'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_Goal
{
  geometry_msgs__msg__PoseStamped pose;
  rosidl_runtime_c__String behavior_tree;
} dros_common_interfaces__action__NavigateToPose_Goal;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_Goal.
typedef struct dros_common_interfaces__action__NavigateToPose_Goal__Sequence
{
  dros_common_interfaces__action__NavigateToPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_Goal__Sequence;


// Constants defined in the message

/// Constant 'NONE'.
/**
  * Error codes
  * Note: The expected priority order of the errors should match the message order
 */
enum
{
  dros_common_interfaces__action__NavigateToPose_Result__NONE = 0
};

/// Constant 'UNKNOWN'.
enum
{
  dros_common_interfaces__action__NavigateToPose_Result__UNKNOWN = 9000
};

/// Constant 'FAILED_TO_LOAD_BEHAVIOR_TREE'.
enum
{
  dros_common_interfaces__action__NavigateToPose_Result__FAILED_TO_LOAD_BEHAVIOR_TREE = 9001
};

/// Constant 'TF_ERROR'.
enum
{
  dros_common_interfaces__action__NavigateToPose_Result__TF_ERROR = 9002
};

// Include directives for member types
// Member 'error_msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_Result
{
  uint16_t error_code;
  rosidl_runtime_c__String error_msg;
} dros_common_interfaces__action__NavigateToPose_Result;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_Result.
typedef struct dros_common_interfaces__action__NavigateToPose_Result__Sequence
{
  dros_common_interfaces__action__NavigateToPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'navigation_time'
// Member 'estimated_time_remaining'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_Feedback
{
  geometry_msgs__msg__PoseStamped current_pose;
  builtin_interfaces__msg__Duration navigation_time;
  builtin_interfaces__msg__Duration estimated_time_remaining;
  int16_t number_of_recoveries;
  float distance_remaining;
} dros_common_interfaces__action__NavigateToPose_Feedback;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_Feedback.
typedef struct dros_common_interfaces__action__NavigateToPose_Feedback__Sequence
{
  dros_common_interfaces__action__NavigateToPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "dros_common_interfaces/action/detail/navigate_to_pose__struct.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  dros_common_interfaces__action__NavigateToPose_Goal goal;
} dros_common_interfaces__action__NavigateToPose_SendGoal_Request;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_SendGoal_Request.
typedef struct dros_common_interfaces__action__NavigateToPose_SendGoal_Request__Sequence
{
  dros_common_interfaces__action__NavigateToPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} dros_common_interfaces__action__NavigateToPose_SendGoal_Response;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_SendGoal_Response.
typedef struct dros_common_interfaces__action__NavigateToPose_SendGoal_Response__Sequence
{
  dros_common_interfaces__action__NavigateToPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} dros_common_interfaces__action__NavigateToPose_GetResult_Request;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_GetResult_Request.
typedef struct dros_common_interfaces__action__NavigateToPose_GetResult_Request__Sequence
{
  dros_common_interfaces__action__NavigateToPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "dros_common_interfaces/action/detail/navigate_to_pose__struct.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_GetResult_Response
{
  int8_t status;
  dros_common_interfaces__action__NavigateToPose_Result result;
} dros_common_interfaces__action__NavigateToPose_GetResult_Response;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_GetResult_Response.
typedef struct dros_common_interfaces__action__NavigateToPose_GetResult_Response__Sequence
{
  dros_common_interfaces__action__NavigateToPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "dros_common_interfaces/action/detail/navigate_to_pose__struct.h"

/// Struct defined in action/NavigateToPose in the package dros_common_interfaces.
typedef struct dros_common_interfaces__action__NavigateToPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  dros_common_interfaces__action__NavigateToPose_Feedback feedback;
} dros_common_interfaces__action__NavigateToPose_FeedbackMessage;

// Struct for a sequence of dros_common_interfaces__action__NavigateToPose_FeedbackMessage.
typedef struct dros_common_interfaces__action__NavigateToPose_FeedbackMessage__Sequence
{
  dros_common_interfaces__action__NavigateToPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dros_common_interfaces__action__NavigateToPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DROS_COMMON_INTERFACES__ACTION__DETAIL__NAVIGATE_TO_POSE__STRUCT_H_
