// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lx_msgs:msg/PlannedTask.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__PLANNED_TASK__FUNCTIONS_H_
#define LX_MSGS__MSG__DETAIL__PLANNED_TASK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lx_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lx_msgs/msg/detail/planned_task__struct.h"

/// Initialize msg/PlannedTask message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__msg__PlannedTask
 * )) before or use
 * lx_msgs__msg__PlannedTask__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__msg__PlannedTask__init(lx_msgs__msg__PlannedTask * msg);

/// Finalize msg/PlannedTask message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__msg__PlannedTask__fini(lx_msgs__msg__PlannedTask * msg);

/// Create msg/PlannedTask message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__msg__PlannedTask__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__msg__PlannedTask *
lx_msgs__msg__PlannedTask__create();

/// Destroy msg/PlannedTask message.
/**
 * It calls
 * lx_msgs__msg__PlannedTask__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__msg__PlannedTask__destroy(lx_msgs__msg__PlannedTask * msg);

/// Check for msg/PlannedTask message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__msg__PlannedTask__are_equal(const lx_msgs__msg__PlannedTask * lhs, const lx_msgs__msg__PlannedTask * rhs);

/// Copy a msg/PlannedTask message.
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
lx_msgs__msg__PlannedTask__copy(
  const lx_msgs__msg__PlannedTask * input,
  lx_msgs__msg__PlannedTask * output);

/// Initialize array of msg/PlannedTask messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__msg__PlannedTask__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__msg__PlannedTask__Sequence__init(lx_msgs__msg__PlannedTask__Sequence * array, size_t size);

/// Finalize array of msg/PlannedTask messages.
/**
 * It calls
 * lx_msgs__msg__PlannedTask__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__msg__PlannedTask__Sequence__fini(lx_msgs__msg__PlannedTask__Sequence * array);

/// Create array of msg/PlannedTask messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__msg__PlannedTask__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__msg__PlannedTask__Sequence *
lx_msgs__msg__PlannedTask__Sequence__create(size_t size);

/// Destroy array of msg/PlannedTask messages.
/**
 * It calls
 * lx_msgs__msg__PlannedTask__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__msg__PlannedTask__Sequence__destroy(lx_msgs__msg__PlannedTask__Sequence * array);

/// Check for msg/PlannedTask message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__msg__PlannedTask__Sequence__are_equal(const lx_msgs__msg__PlannedTask__Sequence * lhs, const lx_msgs__msg__PlannedTask__Sequence * rhs);

/// Copy an array of msg/PlannedTask messages.
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
lx_msgs__msg__PlannedTask__Sequence__copy(
  const lx_msgs__msg__PlannedTask__Sequence * input,
  lx_msgs__msg__PlannedTask__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__PLANNED_TASK__FUNCTIONS_H_
