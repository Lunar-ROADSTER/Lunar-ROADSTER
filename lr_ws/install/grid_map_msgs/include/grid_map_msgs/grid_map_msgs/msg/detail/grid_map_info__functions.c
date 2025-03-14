// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from grid_map_msgs:msg/GridMapInfo.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/msg/detail/grid_map_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
grid_map_msgs__msg__GridMapInfo__init(grid_map_msgs__msg__GridMapInfo * msg)
{
  if (!msg) {
    return false;
  }
  // resolution
  // length_x
  // length_y
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    grid_map_msgs__msg__GridMapInfo__fini(msg);
    return false;
  }
  return true;
}

void
grid_map_msgs__msg__GridMapInfo__fini(grid_map_msgs__msg__GridMapInfo * msg)
{
  if (!msg) {
    return;
  }
  // resolution
  // length_x
  // length_y
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
grid_map_msgs__msg__GridMapInfo__are_equal(const grid_map_msgs__msg__GridMapInfo * lhs, const grid_map_msgs__msg__GridMapInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // resolution
  if (lhs->resolution != rhs->resolution) {
    return false;
  }
  // length_x
  if (lhs->length_x != rhs->length_x) {
    return false;
  }
  // length_y
  if (lhs->length_y != rhs->length_y) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
grid_map_msgs__msg__GridMapInfo__copy(
  const grid_map_msgs__msg__GridMapInfo * input,
  grid_map_msgs__msg__GridMapInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // resolution
  output->resolution = input->resolution;
  // length_x
  output->length_x = input->length_x;
  // length_y
  output->length_y = input->length_y;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

grid_map_msgs__msg__GridMapInfo *
grid_map_msgs__msg__GridMapInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grid_map_msgs__msg__GridMapInfo * msg = (grid_map_msgs__msg__GridMapInfo *)allocator.allocate(sizeof(grid_map_msgs__msg__GridMapInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grid_map_msgs__msg__GridMapInfo));
  bool success = grid_map_msgs__msg__GridMapInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grid_map_msgs__msg__GridMapInfo__destroy(grid_map_msgs__msg__GridMapInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grid_map_msgs__msg__GridMapInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grid_map_msgs__msg__GridMapInfo__Sequence__init(grid_map_msgs__msg__GridMapInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grid_map_msgs__msg__GridMapInfo * data = NULL;

  if (size) {
    data = (grid_map_msgs__msg__GridMapInfo *)allocator.zero_allocate(size, sizeof(grid_map_msgs__msg__GridMapInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grid_map_msgs__msg__GridMapInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grid_map_msgs__msg__GridMapInfo__fini(&data[i - 1]);
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
grid_map_msgs__msg__GridMapInfo__Sequence__fini(grid_map_msgs__msg__GridMapInfo__Sequence * array)
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
      grid_map_msgs__msg__GridMapInfo__fini(&array->data[i]);
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

grid_map_msgs__msg__GridMapInfo__Sequence *
grid_map_msgs__msg__GridMapInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grid_map_msgs__msg__GridMapInfo__Sequence * array = (grid_map_msgs__msg__GridMapInfo__Sequence *)allocator.allocate(sizeof(grid_map_msgs__msg__GridMapInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grid_map_msgs__msg__GridMapInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grid_map_msgs__msg__GridMapInfo__Sequence__destroy(grid_map_msgs__msg__GridMapInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grid_map_msgs__msg__GridMapInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grid_map_msgs__msg__GridMapInfo__Sequence__are_equal(const grid_map_msgs__msg__GridMapInfo__Sequence * lhs, const grid_map_msgs__msg__GridMapInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grid_map_msgs__msg__GridMapInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grid_map_msgs__msg__GridMapInfo__Sequence__copy(
  const grid_map_msgs__msg__GridMapInfo__Sequence * input,
  grid_map_msgs__msg__GridMapInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grid_map_msgs__msg__GridMapInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grid_map_msgs__msg__GridMapInfo * data =
      (grid_map_msgs__msg__GridMapInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grid_map_msgs__msg__GridMapInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grid_map_msgs__msg__GridMapInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grid_map_msgs__msg__GridMapInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
