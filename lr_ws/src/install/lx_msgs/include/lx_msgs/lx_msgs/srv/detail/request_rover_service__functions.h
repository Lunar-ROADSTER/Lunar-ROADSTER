// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lx_msgs:srv/RequestRoverService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__FUNCTIONS_H_
#define LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lx_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lx_msgs/srv/detail/request_rover_service__struct.h"

/// Initialize srv/RequestRoverService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__srv__RequestRoverService_Request
 * )) before or use
 * lx_msgs__srv__RequestRoverService_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Request__init(lx_msgs__srv__RequestRoverService_Request * msg);

/// Finalize srv/RequestRoverService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Request__fini(lx_msgs__srv__RequestRoverService_Request * msg);

/// Create srv/RequestRoverService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__srv__RequestRoverService_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__srv__RequestRoverService_Request *
lx_msgs__srv__RequestRoverService_Request__create();

/// Destroy srv/RequestRoverService message.
/**
 * It calls
 * lx_msgs__srv__RequestRoverService_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Request__destroy(lx_msgs__srv__RequestRoverService_Request * msg);

/// Check for srv/RequestRoverService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Request__are_equal(const lx_msgs__srv__RequestRoverService_Request * lhs, const lx_msgs__srv__RequestRoverService_Request * rhs);

/// Copy a srv/RequestRoverService message.
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
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Request__copy(
  const lx_msgs__srv__RequestRoverService_Request * input,
  lx_msgs__srv__RequestRoverService_Request * output);

/// Initialize array of srv/RequestRoverService messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__srv__RequestRoverService_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Request__Sequence__init(lx_msgs__srv__RequestRoverService_Request__Sequence * array, size_t size);

/// Finalize array of srv/RequestRoverService messages.
/**
 * It calls
 * lx_msgs__srv__RequestRoverService_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Request__Sequence__fini(lx_msgs__srv__RequestRoverService_Request__Sequence * array);

/// Create array of srv/RequestRoverService messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__srv__RequestRoverService_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__srv__RequestRoverService_Request__Sequence *
lx_msgs__srv__RequestRoverService_Request__Sequence__create(size_t size);

/// Destroy array of srv/RequestRoverService messages.
/**
 * It calls
 * lx_msgs__srv__RequestRoverService_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Request__Sequence__destroy(lx_msgs__srv__RequestRoverService_Request__Sequence * array);

/// Check for srv/RequestRoverService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Request__Sequence__are_equal(const lx_msgs__srv__RequestRoverService_Request__Sequence * lhs, const lx_msgs__srv__RequestRoverService_Request__Sequence * rhs);

/// Copy an array of srv/RequestRoverService messages.
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
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Request__Sequence__copy(
  const lx_msgs__srv__RequestRoverService_Request__Sequence * input,
  lx_msgs__srv__RequestRoverService_Request__Sequence * output);

/// Initialize srv/RequestRoverService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__srv__RequestRoverService_Response
 * )) before or use
 * lx_msgs__srv__RequestRoverService_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Response__init(lx_msgs__srv__RequestRoverService_Response * msg);

/// Finalize srv/RequestRoverService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Response__fini(lx_msgs__srv__RequestRoverService_Response * msg);

/// Create srv/RequestRoverService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__srv__RequestRoverService_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__srv__RequestRoverService_Response *
lx_msgs__srv__RequestRoverService_Response__create();

/// Destroy srv/RequestRoverService message.
/**
 * It calls
 * lx_msgs__srv__RequestRoverService_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Response__destroy(lx_msgs__srv__RequestRoverService_Response * msg);

/// Check for srv/RequestRoverService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Response__are_equal(const lx_msgs__srv__RequestRoverService_Response * lhs, const lx_msgs__srv__RequestRoverService_Response * rhs);

/// Copy a srv/RequestRoverService message.
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
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Response__copy(
  const lx_msgs__srv__RequestRoverService_Response * input,
  lx_msgs__srv__RequestRoverService_Response * output);

/// Initialize array of srv/RequestRoverService messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__srv__RequestRoverService_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Response__Sequence__init(lx_msgs__srv__RequestRoverService_Response__Sequence * array, size_t size);

/// Finalize array of srv/RequestRoverService messages.
/**
 * It calls
 * lx_msgs__srv__RequestRoverService_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Response__Sequence__fini(lx_msgs__srv__RequestRoverService_Response__Sequence * array);

/// Create array of srv/RequestRoverService messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__srv__RequestRoverService_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__srv__RequestRoverService_Response__Sequence *
lx_msgs__srv__RequestRoverService_Response__Sequence__create(size_t size);

/// Destroy array of srv/RequestRoverService messages.
/**
 * It calls
 * lx_msgs__srv__RequestRoverService_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__srv__RequestRoverService_Response__Sequence__destroy(lx_msgs__srv__RequestRoverService_Response__Sequence * array);

/// Check for srv/RequestRoverService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Response__Sequence__are_equal(const lx_msgs__srv__RequestRoverService_Response__Sequence * lhs, const lx_msgs__srv__RequestRoverService_Response__Sequence * rhs);

/// Copy an array of srv/RequestRoverService messages.
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
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__srv__RequestRoverService_Response__Sequence__copy(
  const lx_msgs__srv__RequestRoverService_Response__Sequence * input,
  lx_msgs__srv__RequestRoverService_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__FUNCTIONS_H_
