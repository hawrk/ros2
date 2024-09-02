// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interface_ws:action/Book.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__STRUCT_H_
#define ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'book_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_Goal
{
  rosidl_runtime_c__String book_name;
} action_interface_ws__action__Book_Goal;

// Struct for a sequence of action_interface_ws__action__Book_Goal.
typedef struct action_interface_ws__action__Book_Goal__Sequence
{
  action_interface_ws__action__Book_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_Result
{
  int32_t line_num;
} action_interface_ws__action__Book_Result;

// Struct for a sequence of action_interface_ws__action__Book_Result.
typedef struct action_interface_ws__action__Book_Result__Sequence
{
  action_interface_ws__action__Book_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'line_words'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_Feedback
{
  int32_t cur_line;
  rosidl_runtime_c__String line_words;
} action_interface_ws__action__Book_Feedback;

// Struct for a sequence of action_interface_ws__action__Book_Feedback.
typedef struct action_interface_ws__action__Book_Feedback__Sequence
{
  action_interface_ws__action__Book_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "action_interface_ws/action/detail/book__struct.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interface_ws__action__Book_Goal goal;
} action_interface_ws__action__Book_SendGoal_Request;

// Struct for a sequence of action_interface_ws__action__Book_SendGoal_Request.
typedef struct action_interface_ws__action__Book_SendGoal_Request__Sequence
{
  action_interface_ws__action__Book_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} action_interface_ws__action__Book_SendGoal_Response;

// Struct for a sequence of action_interface_ws__action__Book_SendGoal_Response.
typedef struct action_interface_ws__action__Book_SendGoal_Response__Sequence
{
  action_interface_ws__action__Book_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} action_interface_ws__action__Book_GetResult_Request;

// Struct for a sequence of action_interface_ws__action__Book_GetResult_Request.
typedef struct action_interface_ws__action__Book_GetResult_Request__Sequence
{
  action_interface_ws__action__Book_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interface_ws/action/detail/book__struct.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_GetResult_Response
{
  int8_t status;
  action_interface_ws__action__Book_Result result;
} action_interface_ws__action__Book_GetResult_Response;

// Struct for a sequence of action_interface_ws__action__Book_GetResult_Response.
typedef struct action_interface_ws__action__Book_GetResult_Response__Sequence
{
  action_interface_ws__action__Book_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "action_interface_ws/action/detail/book__struct.h"

/// Struct defined in action/Book in the package action_interface_ws.
typedef struct action_interface_ws__action__Book_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interface_ws__action__Book_Feedback feedback;
} action_interface_ws__action__Book_FeedbackMessage;

// Struct for a sequence of action_interface_ws__action__Book_FeedbackMessage.
typedef struct action_interface_ws__action__Book_FeedbackMessage__Sequence
{
  action_interface_ws__action__Book_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface_ws__action__Book_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACE_WS__ACTION__DETAIL__BOOK__STRUCT_H_
