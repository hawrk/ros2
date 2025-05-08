// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dros_common_interfaces:action/DexterousHand.idl
// generated code does not contain a copyright notice

#ifndef DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__FUNCTIONS_H_
#define DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dros_common_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dros_common_interfaces/action/detail/dexterous_hand__struct.h"

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_Goal
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Goal__init(dros_common_interfaces__action__DexterousHand_Goal * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Goal__fini(dros_common_interfaces__action__DexterousHand_Goal * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_Goal *
dros_common_interfaces__action__DexterousHand_Goal__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Goal__destroy(dros_common_interfaces__action__DexterousHand_Goal * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Goal__are_equal(const dros_common_interfaces__action__DexterousHand_Goal * lhs, const dros_common_interfaces__action__DexterousHand_Goal * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Goal__copy(
  const dros_common_interfaces__action__DexterousHand_Goal * input,
  dros_common_interfaces__action__DexterousHand_Goal * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Goal__Sequence__init(dros_common_interfaces__action__DexterousHand_Goal__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Goal__Sequence__fini(dros_common_interfaces__action__DexterousHand_Goal__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_Goal__Sequence *
dros_common_interfaces__action__DexterousHand_Goal__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Goal__Sequence__destroy(dros_common_interfaces__action__DexterousHand_Goal__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Goal__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_Goal__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_Goal__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Goal__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_Goal__Sequence * input,
  dros_common_interfaces__action__DexterousHand_Goal__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_Result
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Result__init(dros_common_interfaces__action__DexterousHand_Result * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Result__fini(dros_common_interfaces__action__DexterousHand_Result * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_Result *
dros_common_interfaces__action__DexterousHand_Result__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Result__destroy(dros_common_interfaces__action__DexterousHand_Result * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Result__are_equal(const dros_common_interfaces__action__DexterousHand_Result * lhs, const dros_common_interfaces__action__DexterousHand_Result * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Result__copy(
  const dros_common_interfaces__action__DexterousHand_Result * input,
  dros_common_interfaces__action__DexterousHand_Result * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Result__Sequence__init(dros_common_interfaces__action__DexterousHand_Result__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Result__Sequence__fini(dros_common_interfaces__action__DexterousHand_Result__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_Result__Sequence *
dros_common_interfaces__action__DexterousHand_Result__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Result__Sequence__destroy(dros_common_interfaces__action__DexterousHand_Result__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Result__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_Result__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_Result__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Result__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_Result__Sequence * input,
  dros_common_interfaces__action__DexterousHand_Result__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_Feedback
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Feedback__init(dros_common_interfaces__action__DexterousHand_Feedback * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Feedback__fini(dros_common_interfaces__action__DexterousHand_Feedback * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_Feedback *
dros_common_interfaces__action__DexterousHand_Feedback__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Feedback__destroy(dros_common_interfaces__action__DexterousHand_Feedback * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Feedback__are_equal(const dros_common_interfaces__action__DexterousHand_Feedback * lhs, const dros_common_interfaces__action__DexterousHand_Feedback * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Feedback__copy(
  const dros_common_interfaces__action__DexterousHand_Feedback * input,
  dros_common_interfaces__action__DexterousHand_Feedback * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__init(dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__fini(dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_Feedback__Sequence *
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__destroy(dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_Feedback__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_Feedback__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_Feedback__Sequence * input,
  dros_common_interfaces__action__DexterousHand_Feedback__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__init(dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_SendGoal_Request *
dros_common_interfaces__action__DexterousHand_SendGoal_Request__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Request * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Request * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Request * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Request * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__init(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence *
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__init(dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_SendGoal_Response *
dros_common_interfaces__action__DexterousHand_SendGoal_Response__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Response * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Response * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Response * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Response * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__init(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence *
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_GetResult_Request
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__init(dros_common_interfaces__action__DexterousHand_GetResult_Request * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(dros_common_interfaces__action__DexterousHand_GetResult_Request * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_GetResult_Request *
dros_common_interfaces__action__DexterousHand_GetResult_Request__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Request__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Request * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Request * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Request * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Request * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Request * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__init(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__fini(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence *
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_GetResult_Response
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__init(dros_common_interfaces__action__DexterousHand_GetResult_Response * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(dros_common_interfaces__action__DexterousHand_GetResult_Response * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_GetResult_Response *
dros_common_interfaces__action__DexterousHand_GetResult_Response__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Response__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Response * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Response * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Response * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Response * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Response * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__init(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__fini(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence *
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * output);

/// Initialize action/DexterousHand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage
 * )) before or use
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__init(dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg);

/// Finalize action/DexterousHand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg);

/// Create action/DexterousHand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_FeedbackMessage *
dros_common_interfaces__action__DexterousHand_FeedbackMessage__create();

/// Destroy action/DexterousHand message.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__destroy(dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg);

/// Check for action/DexterousHand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__are_equal(const dros_common_interfaces__action__DexterousHand_FeedbackMessage * lhs, const dros_common_interfaces__action__DexterousHand_FeedbackMessage * rhs);

/// Copy a action/DexterousHand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__copy(
  const dros_common_interfaces__action__DexterousHand_FeedbackMessage * input,
  dros_common_interfaces__action__DexterousHand_FeedbackMessage * output);

/// Initialize array of action/DexterousHand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__init(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__fini(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array);

/// Create array of action/DexterousHand messages.
/**
 * It allocates the memory for the array and calls
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence *
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/DexterousHand messages.
/**
 * It calls
 * dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__destroy(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array);

/// Check for action/DexterousHand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/DexterousHand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dros_common_interfaces
bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * input,
  dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DROS_COMMON_INTERFACES__ACTION__DETAIL__DEXTEROUS_HAND__FUNCTIONS_H_
