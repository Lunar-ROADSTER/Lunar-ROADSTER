// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/Point2D.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/point2_d__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cg_msgs__msg__Point2D__init(cg_msgs__msg__Point2D * msg)
{
  if (!msg) {
    return false;
  }
  // x
  msg->x = 0.0l;
  // y
  msg->y = 0.0l;
  return true;
}

void
cg_msgs__msg__Point2D__fini(cg_msgs__msg__Point2D * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
cg_msgs__msg__Point2D__are_equal(const cg_msgs__msg__Point2D * lhs, const cg_msgs__msg__Point2D * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__Point2D__copy(
  const cg_msgs__msg__Point2D * input,
  cg_msgs__msg__Point2D * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

cg_msgs__msg__Point2D *
cg_msgs__msg__Point2D__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Point2D * msg = (cg_msgs__msg__Point2D *)allocator.allocate(sizeof(cg_msgs__msg__Point2D), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__Point2D));
  bool success = cg_msgs__msg__Point2D__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__Point2D__destroy(cg_msgs__msg__Point2D * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__Point2D__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__Point2D__Sequence__init(cg_msgs__msg__Point2D__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Point2D * data = NULL;

  if (size) {
    data = (cg_msgs__msg__Point2D *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__Point2D), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__Point2D__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__Point2D__fini(&data[i - 1]);
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
cg_msgs__msg__Point2D__Sequence__fini(cg_msgs__msg__Point2D__Sequence * array)
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
      cg_msgs__msg__Point2D__fini(&array->data[i]);
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

cg_msgs__msg__Point2D__Sequence *
cg_msgs__msg__Point2D__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__Point2D__Sequence * array = (cg_msgs__msg__Point2D__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__Point2D__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__Point2D__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__Point2D__Sequence__destroy(cg_msgs__msg__Point2D__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__Point2D__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__Point2D__Sequence__are_equal(const cg_msgs__msg__Point2D__Sequence * lhs, const cg_msgs__msg__Point2D__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__Point2D__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__Point2D__Sequence__copy(
  const cg_msgs__msg__Point2D__Sequence * input,
  cg_msgs__msg__Point2D__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__Point2D);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__Point2D * data =
      (cg_msgs__msg__Point2D *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__Point2D__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__Point2D__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__Point2D__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
