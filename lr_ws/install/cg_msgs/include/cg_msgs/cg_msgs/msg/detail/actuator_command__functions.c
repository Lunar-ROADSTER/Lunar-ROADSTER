// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/ActuatorCommand.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/actuator_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cg_msgs__msg__ActuatorCommand__init(cg_msgs__msg__ActuatorCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cg_msgs__msg__ActuatorCommand__fini(msg);
    return false;
  }
  // wheel_velocity
  msg->wheel_velocity = 0.0l;
  // steer_position
  msg->steer_position = 0.0l;
  // tool_position
  msg->tool_position = 0.0l;
  return true;
}

void
cg_msgs__msg__ActuatorCommand__fini(cg_msgs__msg__ActuatorCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // wheel_velocity
  // steer_position
  // tool_position
}

bool
cg_msgs__msg__ActuatorCommand__are_equal(const cg_msgs__msg__ActuatorCommand * lhs, const cg_msgs__msg__ActuatorCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // wheel_velocity
  if (lhs->wheel_velocity != rhs->wheel_velocity) {
    return false;
  }
  // steer_position
  if (lhs->steer_position != rhs->steer_position) {
    return false;
  }
  // tool_position
  if (lhs->tool_position != rhs->tool_position) {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__ActuatorCommand__copy(
  const cg_msgs__msg__ActuatorCommand * input,
  cg_msgs__msg__ActuatorCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // wheel_velocity
  output->wheel_velocity = input->wheel_velocity;
  // steer_position
  output->steer_position = input->steer_position;
  // tool_position
  output->tool_position = input->tool_position;
  return true;
}

cg_msgs__msg__ActuatorCommand *
cg_msgs__msg__ActuatorCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__ActuatorCommand * msg = (cg_msgs__msg__ActuatorCommand *)allocator.allocate(sizeof(cg_msgs__msg__ActuatorCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__ActuatorCommand));
  bool success = cg_msgs__msg__ActuatorCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__ActuatorCommand__destroy(cg_msgs__msg__ActuatorCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__ActuatorCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__ActuatorCommand__Sequence__init(cg_msgs__msg__ActuatorCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__ActuatorCommand * data = NULL;

  if (size) {
    data = (cg_msgs__msg__ActuatorCommand *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__ActuatorCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__ActuatorCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__ActuatorCommand__fini(&data[i - 1]);
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
cg_msgs__msg__ActuatorCommand__Sequence__fini(cg_msgs__msg__ActuatorCommand__Sequence * array)
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
      cg_msgs__msg__ActuatorCommand__fini(&array->data[i]);
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

cg_msgs__msg__ActuatorCommand__Sequence *
cg_msgs__msg__ActuatorCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__ActuatorCommand__Sequence * array = (cg_msgs__msg__ActuatorCommand__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__ActuatorCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__ActuatorCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__ActuatorCommand__Sequence__destroy(cg_msgs__msg__ActuatorCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__ActuatorCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__ActuatorCommand__Sequence__are_equal(const cg_msgs__msg__ActuatorCommand__Sequence * lhs, const cg_msgs__msg__ActuatorCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__ActuatorCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__ActuatorCommand__Sequence__copy(
  const cg_msgs__msg__ActuatorCommand__Sequence * input,
  cg_msgs__msg__ActuatorCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__ActuatorCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__ActuatorCommand * data =
      (cg_msgs__msg__ActuatorCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__ActuatorCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__ActuatorCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__ActuatorCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
