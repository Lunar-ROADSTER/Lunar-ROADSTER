// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SLIP__FUNCTIONS_H_
#define CG_MSGS__MSG__DETAIL__SLIP__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cg_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cg_msgs/msg/detail/slip__struct.h"

/// Initialize msg/Slip message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cg_msgs__msg__Slip
 * )) before or use
 * cg_msgs__msg__Slip__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__Slip__init(cg_msgs__msg__Slip * msg);

/// Finalize msg/Slip message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__Slip__fini(cg_msgs__msg__Slip * msg);

/// Create msg/Slip message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cg_msgs__msg__Slip__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
cg_msgs__msg__Slip *
cg_msgs__msg__Slip__create();

/// Destroy msg/Slip message.
/**
 * It calls
 * cg_msgs__msg__Slip__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__Slip__destroy(cg_msgs__msg__Slip * msg);

/// Check for msg/Slip message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__Slip__are_equal(const cg_msgs__msg__Slip * lhs, const cg_msgs__msg__Slip * rhs);

/// Copy a msg/Slip message.
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
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__Slip__copy(
  const cg_msgs__msg__Slip * input,
  cg_msgs__msg__Slip * output);

/// Initialize array of msg/Slip messages.
/**
 * It allocates the memory for the number of elements and calls
 * cg_msgs__msg__Slip__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__Slip__Sequence__init(cg_msgs__msg__Slip__Sequence * array, size_t size);

/// Finalize array of msg/Slip messages.
/**
 * It calls
 * cg_msgs__msg__Slip__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__Slip__Sequence__fini(cg_msgs__msg__Slip__Sequence * array);

/// Create array of msg/Slip messages.
/**
 * It allocates the memory for the array and calls
 * cg_msgs__msg__Slip__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
cg_msgs__msg__Slip__Sequence *
cg_msgs__msg__Slip__Sequence__create(size_t size);

/// Destroy array of msg/Slip messages.
/**
 * It calls
 * cg_msgs__msg__Slip__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__Slip__Sequence__destroy(cg_msgs__msg__Slip__Sequence * array);

/// Check for msg/Slip message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__Slip__Sequence__are_equal(const cg_msgs__msg__Slip__Sequence * lhs, const cg_msgs__msg__Slip__Sequence * rhs);

/// Copy an array of msg/Slip messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__Slip__Sequence__copy(
  const cg_msgs__msg__Slip__Sequence * input,
  cg_msgs__msg__Slip__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__SLIP__FUNCTIONS_H_
