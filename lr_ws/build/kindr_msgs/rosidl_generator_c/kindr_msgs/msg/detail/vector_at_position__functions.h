// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice

#ifndef KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__FUNCTIONS_H_
#define KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kindr_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "kindr_msgs/msg/detail/vector_at_position__struct.h"

/// Initialize msg/VectorAtPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kindr_msgs__msg__VectorAtPosition
 * )) before or use
 * kindr_msgs__msg__VectorAtPosition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
bool
kindr_msgs__msg__VectorAtPosition__init(kindr_msgs__msg__VectorAtPosition * msg);

/// Finalize msg/VectorAtPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
void
kindr_msgs__msg__VectorAtPosition__fini(kindr_msgs__msg__VectorAtPosition * msg);

/// Create msg/VectorAtPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kindr_msgs__msg__VectorAtPosition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
kindr_msgs__msg__VectorAtPosition *
kindr_msgs__msg__VectorAtPosition__create();

/// Destroy msg/VectorAtPosition message.
/**
 * It calls
 * kindr_msgs__msg__VectorAtPosition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
void
kindr_msgs__msg__VectorAtPosition__destroy(kindr_msgs__msg__VectorAtPosition * msg);

/// Check for msg/VectorAtPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
bool
kindr_msgs__msg__VectorAtPosition__are_equal(const kindr_msgs__msg__VectorAtPosition * lhs, const kindr_msgs__msg__VectorAtPosition * rhs);

/// Copy a msg/VectorAtPosition message.
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
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
bool
kindr_msgs__msg__VectorAtPosition__copy(
  const kindr_msgs__msg__VectorAtPosition * input,
  kindr_msgs__msg__VectorAtPosition * output);

/// Initialize array of msg/VectorAtPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * kindr_msgs__msg__VectorAtPosition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
bool
kindr_msgs__msg__VectorAtPosition__Sequence__init(kindr_msgs__msg__VectorAtPosition__Sequence * array, size_t size);

/// Finalize array of msg/VectorAtPosition messages.
/**
 * It calls
 * kindr_msgs__msg__VectorAtPosition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
void
kindr_msgs__msg__VectorAtPosition__Sequence__fini(kindr_msgs__msg__VectorAtPosition__Sequence * array);

/// Create array of msg/VectorAtPosition messages.
/**
 * It allocates the memory for the array and calls
 * kindr_msgs__msg__VectorAtPosition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
kindr_msgs__msg__VectorAtPosition__Sequence *
kindr_msgs__msg__VectorAtPosition__Sequence__create(size_t size);

/// Destroy array of msg/VectorAtPosition messages.
/**
 * It calls
 * kindr_msgs__msg__VectorAtPosition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
void
kindr_msgs__msg__VectorAtPosition__Sequence__destroy(kindr_msgs__msg__VectorAtPosition__Sequence * array);

/// Check for msg/VectorAtPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
bool
kindr_msgs__msg__VectorAtPosition__Sequence__are_equal(const kindr_msgs__msg__VectorAtPosition__Sequence * lhs, const kindr_msgs__msg__VectorAtPosition__Sequence * rhs);

/// Copy an array of msg/VectorAtPosition messages.
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
ROSIDL_GENERATOR_C_PUBLIC_kindr_msgs
bool
kindr_msgs__msg__VectorAtPosition__Sequence__copy(
  const kindr_msgs__msg__VectorAtPosition__Sequence * input,
  kindr_msgs__msg__VectorAtPosition__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__FUNCTIONS_H_
