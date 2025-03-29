// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:msg/BermSection.idl
// generated code does not contain a copyright notice
#include "lx_msgs/msg/detail/berm_section__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
lx_msgs__msg__BermSection__init(lx_msgs__msg__BermSection * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // theta
  return true;
}

void
lx_msgs__msg__BermSection__fini(lx_msgs__msg__BermSection * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
}

bool
lx_msgs__msg__BermSection__are_equal(const lx_msgs__msg__BermSection * lhs, const lx_msgs__msg__BermSection * rhs)
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
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  return true;
}

bool
lx_msgs__msg__BermSection__copy(
  const lx_msgs__msg__BermSection * input,
  lx_msgs__msg__BermSection * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  return true;
}

lx_msgs__msg__BermSection *
lx_msgs__msg__BermSection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__BermSection * msg = (lx_msgs__msg__BermSection *)allocator.allocate(sizeof(lx_msgs__msg__BermSection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__msg__BermSection));
  bool success = lx_msgs__msg__BermSection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__msg__BermSection__destroy(lx_msgs__msg__BermSection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__msg__BermSection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__msg__BermSection__Sequence__init(lx_msgs__msg__BermSection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__BermSection * data = NULL;

  if (size) {
    data = (lx_msgs__msg__BermSection *)allocator.zero_allocate(size, sizeof(lx_msgs__msg__BermSection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__msg__BermSection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__msg__BermSection__fini(&data[i - 1]);
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
lx_msgs__msg__BermSection__Sequence__fini(lx_msgs__msg__BermSection__Sequence * array)
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
      lx_msgs__msg__BermSection__fini(&array->data[i]);
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

lx_msgs__msg__BermSection__Sequence *
lx_msgs__msg__BermSection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__BermSection__Sequence * array = (lx_msgs__msg__BermSection__Sequence *)allocator.allocate(sizeof(lx_msgs__msg__BermSection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__msg__BermSection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__msg__BermSection__Sequence__destroy(lx_msgs__msg__BermSection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__msg__BermSection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__msg__BermSection__Sequence__are_equal(const lx_msgs__msg__BermSection__Sequence * lhs, const lx_msgs__msg__BermSection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__msg__BermSection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__msg__BermSection__Sequence__copy(
  const lx_msgs__msg__BermSection__Sequence * input,
  lx_msgs__msg__BermSection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__msg__BermSection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__msg__BermSection * data =
      (lx_msgs__msg__BermSection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__msg__BermSection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__msg__BermSection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__msg__BermSection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
