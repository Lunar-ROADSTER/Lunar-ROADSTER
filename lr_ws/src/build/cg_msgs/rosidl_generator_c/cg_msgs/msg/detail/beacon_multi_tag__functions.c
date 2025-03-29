// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/beacon_multi_tag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `TagsList`
#include "cg_msgs/msg/detail/beacon_tag__functions.h"

bool
cg_msgs__msg__BeaconMultiTag__init(cg_msgs__msg__BeaconMultiTag * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cg_msgs__msg__BeaconMultiTag__fini(msg);
    return false;
  }
  // TagsList
  for (size_t i = 0; i < 2; ++i) {
    if (!cg_msgs__msg__BeaconTag__init(&msg->TagsList[i])) {
      cg_msgs__msg__BeaconMultiTag__fini(msg);
      return false;
    }
  }
  return true;
}

void
cg_msgs__msg__BeaconMultiTag__fini(cg_msgs__msg__BeaconMultiTag * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // TagsList
  for (size_t i = 0; i < 2; ++i) {
    cg_msgs__msg__BeaconTag__fini(&msg->TagsList[i]);
  }
}

bool
cg_msgs__msg__BeaconMultiTag__are_equal(const cg_msgs__msg__BeaconMultiTag * lhs, const cg_msgs__msg__BeaconMultiTag * rhs)
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
  // TagsList
  for (size_t i = 0; i < 2; ++i) {
    if (!cg_msgs__msg__BeaconTag__are_equal(
        &(lhs->TagsList[i]), &(rhs->TagsList[i])))
    {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__BeaconMultiTag__copy(
  const cg_msgs__msg__BeaconMultiTag * input,
  cg_msgs__msg__BeaconMultiTag * output)
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
  // TagsList
  for (size_t i = 0; i < 2; ++i) {
    if (!cg_msgs__msg__BeaconTag__copy(
        &(input->TagsList[i]), &(output->TagsList[i])))
    {
      return false;
    }
  }
  return true;
}

cg_msgs__msg__BeaconMultiTag *
cg_msgs__msg__BeaconMultiTag__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__BeaconMultiTag * msg = (cg_msgs__msg__BeaconMultiTag *)allocator.allocate(sizeof(cg_msgs__msg__BeaconMultiTag), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__BeaconMultiTag));
  bool success = cg_msgs__msg__BeaconMultiTag__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__BeaconMultiTag__destroy(cg_msgs__msg__BeaconMultiTag * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__BeaconMultiTag__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__BeaconMultiTag__Sequence__init(cg_msgs__msg__BeaconMultiTag__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__BeaconMultiTag * data = NULL;

  if (size) {
    data = (cg_msgs__msg__BeaconMultiTag *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__BeaconMultiTag), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__BeaconMultiTag__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__BeaconMultiTag__fini(&data[i - 1]);
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
cg_msgs__msg__BeaconMultiTag__Sequence__fini(cg_msgs__msg__BeaconMultiTag__Sequence * array)
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
      cg_msgs__msg__BeaconMultiTag__fini(&array->data[i]);
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

cg_msgs__msg__BeaconMultiTag__Sequence *
cg_msgs__msg__BeaconMultiTag__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__BeaconMultiTag__Sequence * array = (cg_msgs__msg__BeaconMultiTag__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__BeaconMultiTag__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__BeaconMultiTag__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__BeaconMultiTag__Sequence__destroy(cg_msgs__msg__BeaconMultiTag__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__BeaconMultiTag__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__BeaconMultiTag__Sequence__are_equal(const cg_msgs__msg__BeaconMultiTag__Sequence * lhs, const cg_msgs__msg__BeaconMultiTag__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__BeaconMultiTag__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__BeaconMultiTag__Sequence__copy(
  const cg_msgs__msg__BeaconMultiTag__Sequence * input,
  cg_msgs__msg__BeaconMultiTag__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__BeaconMultiTag);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__BeaconMultiTag * data =
      (cg_msgs__msg__BeaconMultiTag *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__BeaconMultiTag__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__BeaconMultiTag__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__BeaconMultiTag__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
