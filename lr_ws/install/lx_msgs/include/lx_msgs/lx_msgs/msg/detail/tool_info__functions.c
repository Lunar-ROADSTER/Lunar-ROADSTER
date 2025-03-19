// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:msg/ToolInfo.idl
// generated code does not contain a copyright notice
#include "lx_msgs/msg/detail/tool_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
lx_msgs__msg__ToolInfo__init(lx_msgs__msg__ToolInfo * msg)
{
  if (!msg) {
    return false;
  }
  // drum_pos
  // drum_current
  return true;
}

void
lx_msgs__msg__ToolInfo__fini(lx_msgs__msg__ToolInfo * msg)
{
  if (!msg) {
    return;
  }
  // drum_pos
  // drum_current
}

bool
lx_msgs__msg__ToolInfo__are_equal(const lx_msgs__msg__ToolInfo * lhs, const lx_msgs__msg__ToolInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // drum_pos
  if (lhs->drum_pos != rhs->drum_pos) {
    return false;
  }
  // drum_current
  if (lhs->drum_current != rhs->drum_current) {
    return false;
  }
  return true;
}

bool
lx_msgs__msg__ToolInfo__copy(
  const lx_msgs__msg__ToolInfo * input,
  lx_msgs__msg__ToolInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // drum_pos
  output->drum_pos = input->drum_pos;
  // drum_current
  output->drum_current = input->drum_current;
  return true;
}

lx_msgs__msg__ToolInfo *
lx_msgs__msg__ToolInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__ToolInfo * msg = (lx_msgs__msg__ToolInfo *)allocator.allocate(sizeof(lx_msgs__msg__ToolInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__msg__ToolInfo));
  bool success = lx_msgs__msg__ToolInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__msg__ToolInfo__destroy(lx_msgs__msg__ToolInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__msg__ToolInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__msg__ToolInfo__Sequence__init(lx_msgs__msg__ToolInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__ToolInfo * data = NULL;

  if (size) {
    data = (lx_msgs__msg__ToolInfo *)allocator.zero_allocate(size, sizeof(lx_msgs__msg__ToolInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__msg__ToolInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__msg__ToolInfo__fini(&data[i - 1]);
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
lx_msgs__msg__ToolInfo__Sequence__fini(lx_msgs__msg__ToolInfo__Sequence * array)
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
      lx_msgs__msg__ToolInfo__fini(&array->data[i]);
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

lx_msgs__msg__ToolInfo__Sequence *
lx_msgs__msg__ToolInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__ToolInfo__Sequence * array = (lx_msgs__msg__ToolInfo__Sequence *)allocator.allocate(sizeof(lx_msgs__msg__ToolInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__msg__ToolInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__msg__ToolInfo__Sequence__destroy(lx_msgs__msg__ToolInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__msg__ToolInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__msg__ToolInfo__Sequence__are_equal(const lx_msgs__msg__ToolInfo__Sequence * lhs, const lx_msgs__msg__ToolInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__msg__ToolInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__msg__ToolInfo__Sequence__copy(
  const lx_msgs__msg__ToolInfo__Sequence * input,
  lx_msgs__msg__ToolInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__msg__ToolInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__msg__ToolInfo * data =
      (lx_msgs__msg__ToolInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__msg__ToolInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__msg__ToolInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__msg__ToolInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
