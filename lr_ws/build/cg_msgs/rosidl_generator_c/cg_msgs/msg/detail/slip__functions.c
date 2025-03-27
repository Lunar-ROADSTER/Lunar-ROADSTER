// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/slip__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cg_msgs__msg__Slip__init(cg_msgs__msg__Slip * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cg_msgs__msg__Slip__fini(msg);
    return false;
  }
  // slip
  msg->slip = 0.0f;
  // slip_avg
  msg->slip_avg = 0.0f;
  // slip_latch
  msg->slip_latch = true;
  // vel
  msg->vel = 0.0f;
  // vel_avg
  msg->vel_avg = 0.0f;
  return true;
}

void
cg_msgs__msg__Slip__fini(cg_msgs__msg__Slip * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // slip
  // slip_avg
  // slip_latch
  // vel
  // vel_avg
}

bool
cg_msgs__msg__Slip__are_equal(const cg_msgs__msg__Slip * lhs, const cg_msgs__msg__Slip * rhs)
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
  // slip
  if (lhs->slip != rhs->slip) {
    return false;
  }
  // slip_avg
  if (lhs->slip_avg != rhs->slip_avg) {
    return false;
  }
  // slip_latch
  if (lhs->slip_latch != rhs->slip_latch) {
    return false;
  }
  // vel
  if (lhs->vel != rhs->vel) {
    return false;
  }
  // vel_avg
  if (lhs->vel_avg != rhs->vel_avg) {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__Slip__copy(
  const cg_msgs__msg__Slip * input,
  cg_msgs__msg__Slip * output)
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
  // slip
  output->slip = input->slip;
  // slip_avg
  output->slip_avg = input->slip_avg;
  // slip_latch
  output->slip_latch = input->slip_latch;
  // vel
  output->vel = input->vel;
  // vel_avg
  output->vel_avg = input->vel_avg;
  return true;
}

cg_msgs__msg__Slip *
cg_msgs__msg__Slip__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Slip * msg = (cg_msgs__msg__Slip *)allocator.allocate(sizeof(cg_msgs__msg__Slip), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__Slip));
  bool success = cg_msgs__msg__Slip__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__Slip__destroy(cg_msgs__msg__Slip * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__Slip__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__Slip__Sequence__init(cg_msgs__msg__Slip__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Slip * data = NULL;

  if (size) {
    data = (cg_msgs__msg__Slip *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__Slip), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__Slip__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__Slip__fini(&data[i - 1]);
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
cg_msgs__msg__Slip__Sequence__fini(cg_msgs__msg__Slip__Sequence * array)
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
      cg_msgs__msg__Slip__fini(&array->data[i]);
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

cg_msgs__msg__Slip__Sequence *
cg_msgs__msg__Slip__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Slip__Sequence * array = (cg_msgs__msg__Slip__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__Slip__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__Slip__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__Slip__Sequence__destroy(cg_msgs__msg__Slip__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__Slip__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__Slip__Sequence__are_equal(const cg_msgs__msg__Slip__Sequence * lhs, const cg_msgs__msg__Slip__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__Slip__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__Slip__Sequence__copy(
  const cg_msgs__msg__Slip__Sequence * input,
  cg_msgs__msg__Slip__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__Slip);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__Slip * data =
      (cg_msgs__msg__Slip *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__Slip__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__Slip__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__Slip__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
