// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lx_msgs:action/Operation.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__ACTION__DETAIL__OPERATION__FUNCTIONS_H_
#define LX_MSGS__ACTION__DETAIL__OPERATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lx_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lx_msgs/action/detail/operation__struct.h"

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_Goal
 * )) before or use
 * lx_msgs__action__Operation_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Goal__init(lx_msgs__action__Operation_Goal * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Goal__fini(lx_msgs__action__Operation_Goal * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_Goal *
lx_msgs__action__Operation_Goal__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Goal__destroy(lx_msgs__action__Operation_Goal * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Goal__are_equal(const lx_msgs__action__Operation_Goal * lhs, const lx_msgs__action__Operation_Goal * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_Goal__copy(
  const lx_msgs__action__Operation_Goal * input,
  lx_msgs__action__Operation_Goal * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Goal__Sequence__init(lx_msgs__action__Operation_Goal__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Goal__Sequence__fini(lx_msgs__action__Operation_Goal__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_Goal__Sequence *
lx_msgs__action__Operation_Goal__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Goal__Sequence__destroy(lx_msgs__action__Operation_Goal__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Goal__Sequence__are_equal(const lx_msgs__action__Operation_Goal__Sequence * lhs, const lx_msgs__action__Operation_Goal__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_Goal__Sequence__copy(
  const lx_msgs__action__Operation_Goal__Sequence * input,
  lx_msgs__action__Operation_Goal__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_Result
 * )) before or use
 * lx_msgs__action__Operation_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Result__init(lx_msgs__action__Operation_Result * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Result__fini(lx_msgs__action__Operation_Result * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_Result *
lx_msgs__action__Operation_Result__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Result__destroy(lx_msgs__action__Operation_Result * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Result__are_equal(const lx_msgs__action__Operation_Result * lhs, const lx_msgs__action__Operation_Result * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_Result__copy(
  const lx_msgs__action__Operation_Result * input,
  lx_msgs__action__Operation_Result * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Result__Sequence__init(lx_msgs__action__Operation_Result__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Result__Sequence__fini(lx_msgs__action__Operation_Result__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_Result__Sequence *
lx_msgs__action__Operation_Result__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Result__Sequence__destroy(lx_msgs__action__Operation_Result__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Result__Sequence__are_equal(const lx_msgs__action__Operation_Result__Sequence * lhs, const lx_msgs__action__Operation_Result__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_Result__Sequence__copy(
  const lx_msgs__action__Operation_Result__Sequence * input,
  lx_msgs__action__Operation_Result__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_Feedback
 * )) before or use
 * lx_msgs__action__Operation_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Feedback__init(lx_msgs__action__Operation_Feedback * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Feedback__fini(lx_msgs__action__Operation_Feedback * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_Feedback *
lx_msgs__action__Operation_Feedback__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Feedback__destroy(lx_msgs__action__Operation_Feedback * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Feedback__are_equal(const lx_msgs__action__Operation_Feedback * lhs, const lx_msgs__action__Operation_Feedback * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_Feedback__copy(
  const lx_msgs__action__Operation_Feedback * input,
  lx_msgs__action__Operation_Feedback * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Feedback__Sequence__init(lx_msgs__action__Operation_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Feedback__Sequence__fini(lx_msgs__action__Operation_Feedback__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_Feedback__Sequence *
lx_msgs__action__Operation_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_Feedback__Sequence__destroy(lx_msgs__action__Operation_Feedback__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_Feedback__Sequence__are_equal(const lx_msgs__action__Operation_Feedback__Sequence * lhs, const lx_msgs__action__Operation_Feedback__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_Feedback__Sequence__copy(
  const lx_msgs__action__Operation_Feedback__Sequence * input,
  lx_msgs__action__Operation_Feedback__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_SendGoal_Request
 * )) before or use
 * lx_msgs__action__Operation_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Request__init(lx_msgs__action__Operation_SendGoal_Request * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Request__fini(lx_msgs__action__Operation_SendGoal_Request * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_SendGoal_Request *
lx_msgs__action__Operation_SendGoal_Request__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Request__destroy(lx_msgs__action__Operation_SendGoal_Request * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Request__are_equal(const lx_msgs__action__Operation_SendGoal_Request * lhs, const lx_msgs__action__Operation_SendGoal_Request * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_SendGoal_Request__copy(
  const lx_msgs__action__Operation_SendGoal_Request * input,
  lx_msgs__action__Operation_SendGoal_Request * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Request__Sequence__init(lx_msgs__action__Operation_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Request__Sequence__fini(lx_msgs__action__Operation_SendGoal_Request__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_SendGoal_Request__Sequence *
lx_msgs__action__Operation_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Request__Sequence__destroy(lx_msgs__action__Operation_SendGoal_Request__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Request__Sequence__are_equal(const lx_msgs__action__Operation_SendGoal_Request__Sequence * lhs, const lx_msgs__action__Operation_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_SendGoal_Request__Sequence__copy(
  const lx_msgs__action__Operation_SendGoal_Request__Sequence * input,
  lx_msgs__action__Operation_SendGoal_Request__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_SendGoal_Response
 * )) before or use
 * lx_msgs__action__Operation_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Response__init(lx_msgs__action__Operation_SendGoal_Response * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Response__fini(lx_msgs__action__Operation_SendGoal_Response * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_SendGoal_Response *
lx_msgs__action__Operation_SendGoal_Response__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Response__destroy(lx_msgs__action__Operation_SendGoal_Response * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Response__are_equal(const lx_msgs__action__Operation_SendGoal_Response * lhs, const lx_msgs__action__Operation_SendGoal_Response * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_SendGoal_Response__copy(
  const lx_msgs__action__Operation_SendGoal_Response * input,
  lx_msgs__action__Operation_SendGoal_Response * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Response__Sequence__init(lx_msgs__action__Operation_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Response__Sequence__fini(lx_msgs__action__Operation_SendGoal_Response__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_SendGoal_Response__Sequence *
lx_msgs__action__Operation_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_SendGoal_Response__Sequence__destroy(lx_msgs__action__Operation_SendGoal_Response__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_SendGoal_Response__Sequence__are_equal(const lx_msgs__action__Operation_SendGoal_Response__Sequence * lhs, const lx_msgs__action__Operation_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_SendGoal_Response__Sequence__copy(
  const lx_msgs__action__Operation_SendGoal_Response__Sequence * input,
  lx_msgs__action__Operation_SendGoal_Response__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_GetResult_Request
 * )) before or use
 * lx_msgs__action__Operation_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Request__init(lx_msgs__action__Operation_GetResult_Request * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Request__fini(lx_msgs__action__Operation_GetResult_Request * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_GetResult_Request *
lx_msgs__action__Operation_GetResult_Request__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Request__destroy(lx_msgs__action__Operation_GetResult_Request * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Request__are_equal(const lx_msgs__action__Operation_GetResult_Request * lhs, const lx_msgs__action__Operation_GetResult_Request * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_GetResult_Request__copy(
  const lx_msgs__action__Operation_GetResult_Request * input,
  lx_msgs__action__Operation_GetResult_Request * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Request__Sequence__init(lx_msgs__action__Operation_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Request__Sequence__fini(lx_msgs__action__Operation_GetResult_Request__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_GetResult_Request__Sequence *
lx_msgs__action__Operation_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Request__Sequence__destroy(lx_msgs__action__Operation_GetResult_Request__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Request__Sequence__are_equal(const lx_msgs__action__Operation_GetResult_Request__Sequence * lhs, const lx_msgs__action__Operation_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_GetResult_Request__Sequence__copy(
  const lx_msgs__action__Operation_GetResult_Request__Sequence * input,
  lx_msgs__action__Operation_GetResult_Request__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_GetResult_Response
 * )) before or use
 * lx_msgs__action__Operation_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Response__init(lx_msgs__action__Operation_GetResult_Response * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Response__fini(lx_msgs__action__Operation_GetResult_Response * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_GetResult_Response *
lx_msgs__action__Operation_GetResult_Response__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Response__destroy(lx_msgs__action__Operation_GetResult_Response * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Response__are_equal(const lx_msgs__action__Operation_GetResult_Response * lhs, const lx_msgs__action__Operation_GetResult_Response * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_GetResult_Response__copy(
  const lx_msgs__action__Operation_GetResult_Response * input,
  lx_msgs__action__Operation_GetResult_Response * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Response__Sequence__init(lx_msgs__action__Operation_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Response__Sequence__fini(lx_msgs__action__Operation_GetResult_Response__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_GetResult_Response__Sequence *
lx_msgs__action__Operation_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_GetResult_Response__Sequence__destroy(lx_msgs__action__Operation_GetResult_Response__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_GetResult_Response__Sequence__are_equal(const lx_msgs__action__Operation_GetResult_Response__Sequence * lhs, const lx_msgs__action__Operation_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_GetResult_Response__Sequence__copy(
  const lx_msgs__action__Operation_GetResult_Response__Sequence * input,
  lx_msgs__action__Operation_GetResult_Response__Sequence * output);

/// Initialize action/Operation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lx_msgs__action__Operation_FeedbackMessage
 * )) before or use
 * lx_msgs__action__Operation_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_FeedbackMessage__init(lx_msgs__action__Operation_FeedbackMessage * msg);

/// Finalize action/Operation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_FeedbackMessage__fini(lx_msgs__action__Operation_FeedbackMessage * msg);

/// Create action/Operation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lx_msgs__action__Operation_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_FeedbackMessage *
lx_msgs__action__Operation_FeedbackMessage__create();

/// Destroy action/Operation message.
/**
 * It calls
 * lx_msgs__action__Operation_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_FeedbackMessage__destroy(lx_msgs__action__Operation_FeedbackMessage * msg);

/// Check for action/Operation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_FeedbackMessage__are_equal(const lx_msgs__action__Operation_FeedbackMessage * lhs, const lx_msgs__action__Operation_FeedbackMessage * rhs);

/// Copy a action/Operation message.
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
lx_msgs__action__Operation_FeedbackMessage__copy(
  const lx_msgs__action__Operation_FeedbackMessage * input,
  lx_msgs__action__Operation_FeedbackMessage * output);

/// Initialize array of action/Operation messages.
/**
 * It allocates the memory for the number of elements and calls
 * lx_msgs__action__Operation_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_FeedbackMessage__Sequence__init(lx_msgs__action__Operation_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_FeedbackMessage__Sequence__fini(lx_msgs__action__Operation_FeedbackMessage__Sequence * array);

/// Create array of action/Operation messages.
/**
 * It allocates the memory for the array and calls
 * lx_msgs__action__Operation_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
lx_msgs__action__Operation_FeedbackMessage__Sequence *
lx_msgs__action__Operation_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Operation messages.
/**
 * It calls
 * lx_msgs__action__Operation_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
void
lx_msgs__action__Operation_FeedbackMessage__Sequence__destroy(lx_msgs__action__Operation_FeedbackMessage__Sequence * array);

/// Check for action/Operation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lx_msgs
bool
lx_msgs__action__Operation_FeedbackMessage__Sequence__are_equal(const lx_msgs__action__Operation_FeedbackMessage__Sequence * lhs, const lx_msgs__action__Operation_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Operation messages.
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
lx_msgs__action__Operation_FeedbackMessage__Sequence__copy(
  const lx_msgs__action__Operation_FeedbackMessage__Sequence * input,
  lx_msgs__action__Operation_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__ACTION__DETAIL__OPERATION__FUNCTIONS_H_
