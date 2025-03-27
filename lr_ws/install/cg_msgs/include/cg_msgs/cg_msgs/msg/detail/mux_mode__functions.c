// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/MuxMode.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/mux_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cg_msgs__msg__MuxMode__init(cg_msgs__msg__MuxMode * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  msg->mode = 3;
  return true;
}

void
cg_msgs__msg__MuxMode__fini(cg_msgs__msg__MuxMode * msg)
{
  if (!msg) {
    return;
  }
  // mode
}

bool
cg_msgs__msg__MuxMode__are_equal(const cg_msgs__msg__MuxMode * lhs, const cg_msgs__msg__MuxMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__MuxMode__copy(
  const cg_msgs__msg__MuxMode * input,
  cg_msgs__msg__MuxMode * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

cg_msgs__msg__MuxMode *
cg_msgs__msg__MuxMode__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__MuxMode * msg = (cg_msgs__msg__MuxMode *)allocator.allocate(sizeof(cg_msgs__msg__MuxMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__MuxMode));
  bool success = cg_msgs__msg__MuxMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__MuxMode__destroy(cg_msgs__msg__MuxMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__MuxMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__MuxMode__Sequence__init(cg_msgs__msg__MuxMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__MuxMode * data = NULL;

  if (size) {
    data = (cg_msgs__msg__MuxMode *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__MuxMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__MuxMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__MuxMode__fini(&data[i - 1]);
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
cg_msgs__msg__MuxMode__Sequence__fini(cg_msgs__msg__MuxMode__Sequence * array)
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
      cg_msgs__msg__MuxMode__fini(&array->data[i]);
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

cg_msgs__msg__MuxMode__Sequence *
cg_msgs__msg__MuxMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__MuxMode__Sequence * array = (cg_msgs__msg__MuxMode__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__MuxMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__MuxMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__MuxMode__Sequence__destroy(cg_msgs__msg__MuxMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__MuxMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__MuxMode__Sequence__are_equal(const cg_msgs__msg__MuxMode__Sequence * lhs, const cg_msgs__msg__MuxMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__MuxMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__MuxMode__Sequence__copy(
  const cg_msgs__msg__MuxMode__Sequence * input,
  cg_msgs__msg__MuxMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__MuxMode);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__MuxMode * data =
      (cg_msgs__msg__MuxMode *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__MuxMode__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__MuxMode__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__MuxMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
