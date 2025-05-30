// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from service_interface_ws:srv/BlackMonkey.idl
// generated code does not contain a copyright notice

#ifndef SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__FUNCTIONS_H_
#define SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "service_interface_ws/msg/rosidl_generator_c__visibility_control.h"

#include "service_interface_ws/srv/detail/black_monkey__struct.h"

/// Initialize srv/BlackMonkey message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * service_interface_ws__srv__BlackMonkey_Request
 * )) before or use
 * service_interface_ws__srv__BlackMonkey_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Request__init(service_interface_ws__srv__BlackMonkey_Request * msg);

/// Finalize srv/BlackMonkey message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Request__fini(service_interface_ws__srv__BlackMonkey_Request * msg);

/// Create srv/BlackMonkey message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * service_interface_ws__srv__BlackMonkey_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
service_interface_ws__srv__BlackMonkey_Request *
service_interface_ws__srv__BlackMonkey_Request__create();

/// Destroy srv/BlackMonkey message.
/**
 * It calls
 * service_interface_ws__srv__BlackMonkey_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Request__destroy(service_interface_ws__srv__BlackMonkey_Request * msg);

/// Check for srv/BlackMonkey message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Request__are_equal(const service_interface_ws__srv__BlackMonkey_Request * lhs, const service_interface_ws__srv__BlackMonkey_Request * rhs);

/// Copy a srv/BlackMonkey message.
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
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Request__copy(
  const service_interface_ws__srv__BlackMonkey_Request * input,
  service_interface_ws__srv__BlackMonkey_Request * output);

/// Initialize array of srv/BlackMonkey messages.
/**
 * It allocates the memory for the number of elements and calls
 * service_interface_ws__srv__BlackMonkey_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Request__Sequence__init(service_interface_ws__srv__BlackMonkey_Request__Sequence * array, size_t size);

/// Finalize array of srv/BlackMonkey messages.
/**
 * It calls
 * service_interface_ws__srv__BlackMonkey_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Request__Sequence__fini(service_interface_ws__srv__BlackMonkey_Request__Sequence * array);

/// Create array of srv/BlackMonkey messages.
/**
 * It allocates the memory for the array and calls
 * service_interface_ws__srv__BlackMonkey_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
service_interface_ws__srv__BlackMonkey_Request__Sequence *
service_interface_ws__srv__BlackMonkey_Request__Sequence__create(size_t size);

/// Destroy array of srv/BlackMonkey messages.
/**
 * It calls
 * service_interface_ws__srv__BlackMonkey_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Request__Sequence__destroy(service_interface_ws__srv__BlackMonkey_Request__Sequence * array);

/// Check for srv/BlackMonkey message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Request__Sequence__are_equal(const service_interface_ws__srv__BlackMonkey_Request__Sequence * lhs, const service_interface_ws__srv__BlackMonkey_Request__Sequence * rhs);

/// Copy an array of srv/BlackMonkey messages.
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
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Request__Sequence__copy(
  const service_interface_ws__srv__BlackMonkey_Request__Sequence * input,
  service_interface_ws__srv__BlackMonkey_Request__Sequence * output);

/// Initialize srv/BlackMonkey message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * service_interface_ws__srv__BlackMonkey_Response
 * )) before or use
 * service_interface_ws__srv__BlackMonkey_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Response__init(service_interface_ws__srv__BlackMonkey_Response * msg);

/// Finalize srv/BlackMonkey message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Response__fini(service_interface_ws__srv__BlackMonkey_Response * msg);

/// Create srv/BlackMonkey message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * service_interface_ws__srv__BlackMonkey_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
service_interface_ws__srv__BlackMonkey_Response *
service_interface_ws__srv__BlackMonkey_Response__create();

/// Destroy srv/BlackMonkey message.
/**
 * It calls
 * service_interface_ws__srv__BlackMonkey_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Response__destroy(service_interface_ws__srv__BlackMonkey_Response * msg);

/// Check for srv/BlackMonkey message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Response__are_equal(const service_interface_ws__srv__BlackMonkey_Response * lhs, const service_interface_ws__srv__BlackMonkey_Response * rhs);

/// Copy a srv/BlackMonkey message.
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
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Response__copy(
  const service_interface_ws__srv__BlackMonkey_Response * input,
  service_interface_ws__srv__BlackMonkey_Response * output);

/// Initialize array of srv/BlackMonkey messages.
/**
 * It allocates the memory for the number of elements and calls
 * service_interface_ws__srv__BlackMonkey_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Response__Sequence__init(service_interface_ws__srv__BlackMonkey_Response__Sequence * array, size_t size);

/// Finalize array of srv/BlackMonkey messages.
/**
 * It calls
 * service_interface_ws__srv__BlackMonkey_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Response__Sequence__fini(service_interface_ws__srv__BlackMonkey_Response__Sequence * array);

/// Create array of srv/BlackMonkey messages.
/**
 * It allocates the memory for the array and calls
 * service_interface_ws__srv__BlackMonkey_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
service_interface_ws__srv__BlackMonkey_Response__Sequence *
service_interface_ws__srv__BlackMonkey_Response__Sequence__create(size_t size);

/// Destroy array of srv/BlackMonkey messages.
/**
 * It calls
 * service_interface_ws__srv__BlackMonkey_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
void
service_interface_ws__srv__BlackMonkey_Response__Sequence__destroy(service_interface_ws__srv__BlackMonkey_Response__Sequence * array);

/// Check for srv/BlackMonkey message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Response__Sequence__are_equal(const service_interface_ws__srv__BlackMonkey_Response__Sequence * lhs, const service_interface_ws__srv__BlackMonkey_Response__Sequence * rhs);

/// Copy an array of srv/BlackMonkey messages.
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
ROSIDL_GENERATOR_C_PUBLIC_service_interface_ws
bool
service_interface_ws__srv__BlackMonkey_Response__Sequence__copy(
  const service_interface_ws__srv__BlackMonkey_Response__Sequence * input,
  service_interface_ws__srv__BlackMonkey_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SERVICE_INTERFACE_WS__SRV__DETAIL__BLACK_MONKEY__FUNCTIONS_H_
