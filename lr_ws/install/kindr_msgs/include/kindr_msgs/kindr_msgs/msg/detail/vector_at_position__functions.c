// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice
#include "kindr_msgs/msg/detail/vector_at_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `name`
// Member `position_frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `vector`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
kindr_msgs__msg__VectorAtPosition__init(kindr_msgs__msg__VectorAtPosition * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    kindr_msgs__msg__VectorAtPosition__fini(msg);
    return false;
  }
  // type
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    kindr_msgs__msg__VectorAtPosition__fini(msg);
    return false;
  }
  // vector
  if (!geometry_msgs__msg__Vector3__init(&msg->vector)) {
    kindr_msgs__msg__VectorAtPosition__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    kindr_msgs__msg__VectorAtPosition__fini(msg);
    return false;
  }
  // position_frame_id
  if (!rosidl_runtime_c__String__init(&msg->position_frame_id)) {
    kindr_msgs__msg__VectorAtPosition__fini(msg);
    return false;
  }
  return true;
}

void
kindr_msgs__msg__VectorAtPosition__fini(kindr_msgs__msg__VectorAtPosition * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // type
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // vector
  geometry_msgs__msg__Vector3__fini(&msg->vector);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // position_frame_id
  rosidl_runtime_c__String__fini(&msg->position_frame_id);
}

bool
kindr_msgs__msg__VectorAtPosition__are_equal(const kindr_msgs__msg__VectorAtPosition * lhs, const kindr_msgs__msg__VectorAtPosition * rhs)
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
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // vector
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->vector), &(rhs->vector)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // position_frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->position_frame_id), &(rhs->position_frame_id)))
  {
    return false;
  }
  return true;
}

bool
kindr_msgs__msg__VectorAtPosition__copy(
  const kindr_msgs__msg__VectorAtPosition * input,
  kindr_msgs__msg__VectorAtPosition * output)
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
  // type
  output->type = input->type;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // vector
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->vector), &(output->vector)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // position_frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->position_frame_id), &(output->position_frame_id)))
  {
    return false;
  }
  return true;
}

kindr_msgs__msg__VectorAtPosition *
kindr_msgs__msg__VectorAtPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kindr_msgs__msg__VectorAtPosition * msg = (kindr_msgs__msg__VectorAtPosition *)allocator.allocate(sizeof(kindr_msgs__msg__VectorAtPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kindr_msgs__msg__VectorAtPosition));
  bool success = kindr_msgs__msg__VectorAtPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kindr_msgs__msg__VectorAtPosition__destroy(kindr_msgs__msg__VectorAtPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kindr_msgs__msg__VectorAtPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kindr_msgs__msg__VectorAtPosition__Sequence__init(kindr_msgs__msg__VectorAtPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kindr_msgs__msg__VectorAtPosition * data = NULL;

  if (size) {
    data = (kindr_msgs__msg__VectorAtPosition *)allocator.zero_allocate(size, sizeof(kindr_msgs__msg__VectorAtPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kindr_msgs__msg__VectorAtPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kindr_msgs__msg__VectorAtPosition__fini(&data[i - 1]);
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
kindr_msgs__msg__VectorAtPosition__Sequence__fini(kindr_msgs__msg__VectorAtPosition__Sequence * array)
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
      kindr_msgs__msg__VectorAtPosition__fini(&array->data[i]);
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

kindr_msgs__msg__VectorAtPosition__Sequence *
kindr_msgs__msg__VectorAtPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kindr_msgs__msg__VectorAtPosition__Sequence * array = (kindr_msgs__msg__VectorAtPosition__Sequence *)allocator.allocate(sizeof(kindr_msgs__msg__VectorAtPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kindr_msgs__msg__VectorAtPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kindr_msgs__msg__VectorAtPosition__Sequence__destroy(kindr_msgs__msg__VectorAtPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kindr_msgs__msg__VectorAtPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kindr_msgs__msg__VectorAtPosition__Sequence__are_equal(const kindr_msgs__msg__VectorAtPosition__Sequence * lhs, const kindr_msgs__msg__VectorAtPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kindr_msgs__msg__VectorAtPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kindr_msgs__msg__VectorAtPosition__Sequence__copy(
  const kindr_msgs__msg__VectorAtPosition__Sequence * input,
  kindr_msgs__msg__VectorAtPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kindr_msgs__msg__VectorAtPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kindr_msgs__msg__VectorAtPosition * data =
      (kindr_msgs__msg__VectorAtPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kindr_msgs__msg__VectorAtPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kindr_msgs__msg__VectorAtPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kindr_msgs__msg__VectorAtPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
