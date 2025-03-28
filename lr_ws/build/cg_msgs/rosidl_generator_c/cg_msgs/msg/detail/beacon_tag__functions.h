// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cg_msgs:msg/BeaconTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_TAG__FUNCTIONS_H_
#define CG_MSGS__MSG__DETAIL__BEACON_TAG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cg_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cg_msgs/msg/detail/beacon_tag__struct.h"

/// Initialize msg/BeaconTag message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cg_msgs__msg__BeaconTag
 * )) before or use
 * cg_msgs__msg__BeaconTag__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__BeaconTag__init(cg_msgs__msg__BeaconTag * msg);

/// Finalize msg/BeaconTag message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__BeaconTag__fini(cg_msgs__msg__BeaconTag * msg);

/// Create msg/BeaconTag message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cg_msgs__msg__BeaconTag__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
cg_msgs__msg__BeaconTag *
cg_msgs__msg__BeaconTag__create();

/// Destroy msg/BeaconTag message.
/**
 * It calls
 * cg_msgs__msg__BeaconTag__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__BeaconTag__destroy(cg_msgs__msg__BeaconTag * msg);

/// Check for msg/BeaconTag message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__BeaconTag__are_equal(const cg_msgs__msg__BeaconTag * lhs, const cg_msgs__msg__BeaconTag * rhs);

/// Copy a msg/BeaconTag message.
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
cg_msgs__msg__BeaconTag__copy(
  const cg_msgs__msg__BeaconTag * input,
  cg_msgs__msg__BeaconTag * output);

/// Initialize array of msg/BeaconTag messages.
/**
 * It allocates the memory for the number of elements and calls
 * cg_msgs__msg__BeaconTag__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__BeaconTag__Sequence__init(cg_msgs__msg__BeaconTag__Sequence * array, size_t size);

/// Finalize array of msg/BeaconTag messages.
/**
 * It calls
 * cg_msgs__msg__BeaconTag__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__BeaconTag__Sequence__fini(cg_msgs__msg__BeaconTag__Sequence * array);

/// Create array of msg/BeaconTag messages.
/**
 * It allocates the memory for the array and calls
 * cg_msgs__msg__BeaconTag__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
cg_msgs__msg__BeaconTag__Sequence *
cg_msgs__msg__BeaconTag__Sequence__create(size_t size);

/// Destroy array of msg/BeaconTag messages.
/**
 * It calls
 * cg_msgs__msg__BeaconTag__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
void
cg_msgs__msg__BeaconTag__Sequence__destroy(cg_msgs__msg__BeaconTag__Sequence * array);

/// Check for msg/BeaconTag message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cg_msgs
bool
cg_msgs__msg__BeaconTag__Sequence__are_equal(const cg_msgs__msg__BeaconTag__Sequence * lhs, const cg_msgs__msg__BeaconTag__Sequence * rhs);

/// Copy an array of msg/BeaconTag messages.
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
cg_msgs__msg__BeaconTag__Sequence__copy(
  const cg_msgs__msg__BeaconTag__Sequence * input,
  cg_msgs__msg__BeaconTag__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__BEACON_TAG__FUNCTIONS_H_
