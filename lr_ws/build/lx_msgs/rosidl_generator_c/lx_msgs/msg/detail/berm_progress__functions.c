// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:msg/BermProgress.idl
// generated code does not contain a copyright notice
#include "lx_msgs/msg/detail/berm_progress__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `berm_points`
#include "geometry_msgs/msg/detail/point_stamped__functions.h"
// Member `heights`
// Member `timestamps`
// Member `volumes`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
lx_msgs__msg__BermProgress__init(lx_msgs__msg__BermProgress * msg)
{
  if (!msg) {
    return false;
  }
  // berm_points
  if (!geometry_msgs__msg__PointStamped__Sequence__init(&msg->berm_points, 0)) {
    lx_msgs__msg__BermProgress__fini(msg);
    return false;
  }
  // heights
  if (!rosidl_runtime_c__float__Sequence__init(&msg->heights, 0)) {
    lx_msgs__msg__BermProgress__fini(msg);
    return false;
  }
  // average_height
  // length
  // peakline_error
  // timestamps
  if (!rosidl_runtime_c__float__Sequence__init(&msg->timestamps, 0)) {
    lx_msgs__msg__BermProgress__fini(msg);
    return false;
  }
  // volumes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->volumes, 0)) {
    lx_msgs__msg__BermProgress__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__msg__BermProgress__fini(lx_msgs__msg__BermProgress * msg)
{
  if (!msg) {
    return;
  }
  // berm_points
  geometry_msgs__msg__PointStamped__Sequence__fini(&msg->berm_points);
  // heights
  rosidl_runtime_c__float__Sequence__fini(&msg->heights);
  // average_height
  // length
  // peakline_error
  // timestamps
  rosidl_runtime_c__float__Sequence__fini(&msg->timestamps);
  // volumes
  rosidl_runtime_c__float__Sequence__fini(&msg->volumes);
}

bool
lx_msgs__msg__BermProgress__are_equal(const lx_msgs__msg__BermProgress * lhs, const lx_msgs__msg__BermProgress * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // berm_points
  if (!geometry_msgs__msg__PointStamped__Sequence__are_equal(
      &(lhs->berm_points), &(rhs->berm_points)))
  {
    return false;
  }
  // heights
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->heights), &(rhs->heights)))
  {
    return false;
  }
  // average_height
  if (lhs->average_height != rhs->average_height) {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  // peakline_error
  if (lhs->peakline_error != rhs->peakline_error) {
    return false;
  }
  // timestamps
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->timestamps), &(rhs->timestamps)))
  {
    return false;
  }
  // volumes
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->volumes), &(rhs->volumes)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__msg__BermProgress__copy(
  const lx_msgs__msg__BermProgress * input,
  lx_msgs__msg__BermProgress * output)
{
  if (!input || !output) {
    return false;
  }
  // berm_points
  if (!geometry_msgs__msg__PointStamped__Sequence__copy(
      &(input->berm_points), &(output->berm_points)))
  {
    return false;
  }
  // heights
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->heights), &(output->heights)))
  {
    return false;
  }
  // average_height
  output->average_height = input->average_height;
  // length
  output->length = input->length;
  // peakline_error
  output->peakline_error = input->peakline_error;
  // timestamps
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->timestamps), &(output->timestamps)))
  {
    return false;
  }
  // volumes
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->volumes), &(output->volumes)))
  {
    return false;
  }
  return true;
}

lx_msgs__msg__BermProgress *
lx_msgs__msg__BermProgress__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__BermProgress * msg = (lx_msgs__msg__BermProgress *)allocator.allocate(sizeof(lx_msgs__msg__BermProgress), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__msg__BermProgress));
  bool success = lx_msgs__msg__BermProgress__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__msg__BermProgress__destroy(lx_msgs__msg__BermProgress * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__msg__BermProgress__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__msg__BermProgress__Sequence__init(lx_msgs__msg__BermProgress__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__BermProgress * data = NULL;

  if (size) {
    data = (lx_msgs__msg__BermProgress *)allocator.zero_allocate(size, sizeof(lx_msgs__msg__BermProgress), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__msg__BermProgress__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__msg__BermProgress__fini(&data[i - 1]);
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
lx_msgs__msg__BermProgress__Sequence__fini(lx_msgs__msg__BermProgress__Sequence * array)
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
      lx_msgs__msg__BermProgress__fini(&array->data[i]);
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

lx_msgs__msg__BermProgress__Sequence *
lx_msgs__msg__BermProgress__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__BermProgress__Sequence * array = (lx_msgs__msg__BermProgress__Sequence *)allocator.allocate(sizeof(lx_msgs__msg__BermProgress__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__msg__BermProgress__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__msg__BermProgress__Sequence__destroy(lx_msgs__msg__BermProgress__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__msg__BermProgress__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__msg__BermProgress__Sequence__are_equal(const lx_msgs__msg__BermProgress__Sequence * lhs, const lx_msgs__msg__BermProgress__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__msg__BermProgress__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__msg__BermProgress__Sequence__copy(
  const lx_msgs__msg__BermProgress__Sequence * input,
  lx_msgs__msg__BermProgress__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__msg__BermProgress);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__msg__BermProgress * data =
      (lx_msgs__msg__BermProgress *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__msg__BermProgress__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__msg__BermProgress__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__msg__BermProgress__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
