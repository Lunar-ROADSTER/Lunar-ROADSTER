// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice
#include "lx_msgs/msg/detail/rover_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `mobility_twist`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
lx_msgs__msg__RoverCommand__init(lx_msgs__msg__RoverCommand * msg)
{
  if (!msg) {
    return false;
  }
  // mobility_twist
  if (!geometry_msgs__msg__Twist__init(&msg->mobility_twist)) {
    lx_msgs__msg__RoverCommand__fini(msg);
    return false;
  }
  // actuator_speed
  // drum_speed
  return true;
}

void
lx_msgs__msg__RoverCommand__fini(lx_msgs__msg__RoverCommand * msg)
{
  if (!msg) {
    return;
  }
  // mobility_twist
  geometry_msgs__msg__Twist__fini(&msg->mobility_twist);
  // actuator_speed
  // drum_speed
}

bool
lx_msgs__msg__RoverCommand__are_equal(const lx_msgs__msg__RoverCommand * lhs, const lx_msgs__msg__RoverCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mobility_twist
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->mobility_twist), &(rhs->mobility_twist)))
  {
    return false;
  }
  // actuator_speed
  if (lhs->actuator_speed != rhs->actuator_speed) {
    return false;
  }
  // drum_speed
  if (lhs->drum_speed != rhs->drum_speed) {
    return false;
  }
  return true;
}

bool
lx_msgs__msg__RoverCommand__copy(
  const lx_msgs__msg__RoverCommand * input,
  lx_msgs__msg__RoverCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // mobility_twist
  if (!geometry_msgs__msg__Twist__copy(
      &(input->mobility_twist), &(output->mobility_twist)))
  {
    return false;
  }
  // actuator_speed
  output->actuator_speed = input->actuator_speed;
  // drum_speed
  output->drum_speed = input->drum_speed;
  return true;
}

lx_msgs__msg__RoverCommand *
lx_msgs__msg__RoverCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__RoverCommand * msg = (lx_msgs__msg__RoverCommand *)allocator.allocate(sizeof(lx_msgs__msg__RoverCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__msg__RoverCommand));
  bool success = lx_msgs__msg__RoverCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__msg__RoverCommand__destroy(lx_msgs__msg__RoverCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__msg__RoverCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__msg__RoverCommand__Sequence__init(lx_msgs__msg__RoverCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__RoverCommand * data = NULL;

  if (size) {
    data = (lx_msgs__msg__RoverCommand *)allocator.zero_allocate(size, sizeof(lx_msgs__msg__RoverCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__msg__RoverCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__msg__RoverCommand__fini(&data[i - 1]);
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
lx_msgs__msg__RoverCommand__Sequence__fini(lx_msgs__msg__RoverCommand__Sequence * array)
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
      lx_msgs__msg__RoverCommand__fini(&array->data[i]);
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

lx_msgs__msg__RoverCommand__Sequence *
lx_msgs__msg__RoverCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__RoverCommand__Sequence * array = (lx_msgs__msg__RoverCommand__Sequence *)allocator.allocate(sizeof(lx_msgs__msg__RoverCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__msg__RoverCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__msg__RoverCommand__Sequence__destroy(lx_msgs__msg__RoverCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__msg__RoverCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__msg__RoverCommand__Sequence__are_equal(const lx_msgs__msg__RoverCommand__Sequence * lhs, const lx_msgs__msg__RoverCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__msg__RoverCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__msg__RoverCommand__Sequence__copy(
  const lx_msgs__msg__RoverCommand__Sequence * input,
  lx_msgs__msg__RoverCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__msg__RoverCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__msg__RoverCommand * data =
      (lx_msgs__msg__RoverCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__msg__RoverCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__msg__RoverCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__msg__RoverCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
