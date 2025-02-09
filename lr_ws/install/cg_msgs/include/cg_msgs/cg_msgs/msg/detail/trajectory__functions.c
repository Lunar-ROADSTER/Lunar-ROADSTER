// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `path`
#include "cg_msgs/msg/detail/pose2_d__functions.h"
// Member `velocity_targets`
// Member `tool_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cg_msgs__msg__Trajectory__init(cg_msgs__msg__Trajectory * msg)
{
  if (!msg) {
    return false;
  }
  // path
  if (!cg_msgs__msg__Pose2D__Sequence__init(&msg->path, 0)) {
    cg_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  // velocity_targets
  if (!rosidl_runtime_c__float__Sequence__init(&msg->velocity_targets, 0)) {
    cg_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  // tool_positions
  if (!rosidl_runtime_c__float__Sequence__init(&msg->tool_positions, 0)) {
    cg_msgs__msg__Trajectory__fini(msg);
    return false;
  }
  return true;
}

void
cg_msgs__msg__Trajectory__fini(cg_msgs__msg__Trajectory * msg)
{
  if (!msg) {
    return;
  }
  // path
  cg_msgs__msg__Pose2D__Sequence__fini(&msg->path);
  // velocity_targets
  rosidl_runtime_c__float__Sequence__fini(&msg->velocity_targets);
  // tool_positions
  rosidl_runtime_c__float__Sequence__fini(&msg->tool_positions);
}

bool
cg_msgs__msg__Trajectory__are_equal(const cg_msgs__msg__Trajectory * lhs, const cg_msgs__msg__Trajectory * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // path
  if (!cg_msgs__msg__Pose2D__Sequence__are_equal(
      &(lhs->path), &(rhs->path)))
  {
    return false;
  }
  // velocity_targets
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->velocity_targets), &(rhs->velocity_targets)))
  {
    return false;
  }
  // tool_positions
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->tool_positions), &(rhs->tool_positions)))
  {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__Trajectory__copy(
  const cg_msgs__msg__Trajectory * input,
  cg_msgs__msg__Trajectory * output)
{
  if (!input || !output) {
    return false;
  }
  // path
  if (!cg_msgs__msg__Pose2D__Sequence__copy(
      &(input->path), &(output->path)))
  {
    return false;
  }
  // velocity_targets
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->velocity_targets), &(output->velocity_targets)))
  {
    return false;
  }
  // tool_positions
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->tool_positions), &(output->tool_positions)))
  {
    return false;
  }
  return true;
}

cg_msgs__msg__Trajectory *
cg_msgs__msg__Trajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Trajectory * msg = (cg_msgs__msg__Trajectory *)allocator.allocate(sizeof(cg_msgs__msg__Trajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__Trajectory));
  bool success = cg_msgs__msg__Trajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__Trajectory__destroy(cg_msgs__msg__Trajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__Trajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__Trajectory__Sequence__init(cg_msgs__msg__Trajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Trajectory * data = NULL;

  if (size) {
    data = (cg_msgs__msg__Trajectory *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__Trajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__Trajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__Trajectory__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cg_msgs__msg__Trajectory__Sequence__fini(cg_msgs__msg__Trajectory__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cg_msgs__msg__Trajectory__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cg_msgs__msg__Trajectory__Sequence *
cg_msgs__msg__Trajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Trajectory__Sequence * array = (cg_msgs__msg__Trajectory__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__Trajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__Trajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__Trajectory__Sequence__destroy(cg_msgs__msg__Trajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__Trajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__Trajectory__Sequence__are_equal(const cg_msgs__msg__Trajectory__Sequence * lhs, const cg_msgs__msg__Trajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__Trajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__Trajectory__Sequence__copy(
  const cg_msgs__msg__Trajectory__Sequence * input,
  cg_msgs__msg__Trajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__Trajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__Trajectory * data =
      (cg_msgs__msg__Trajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__Trajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__Trajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__Trajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
