// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/BeaconTag.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/beacon_tag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `tag_id`
#include "rosidl_runtime_c/string_functions.h"

bool
cg_msgs__msg__BeaconTag__init(cg_msgs__msg__BeaconTag * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cg_msgs__msg__BeaconTag__fini(msg);
    return false;
  }
  // tag_id
  if (!rosidl_runtime_c__String__init(&msg->tag_id)) {
    cg_msgs__msg__BeaconTag__fini(msg);
    return false;
  }
  // pose_x
  // pose_y
  // pose_z
  // orientation_x
  // orientation_y
  // orientation_z
  // orientation_w
  return true;
}

void
cg_msgs__msg__BeaconTag__fini(cg_msgs__msg__BeaconTag * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // tag_id
  rosidl_runtime_c__String__fini(&msg->tag_id);
  // pose_x
  // pose_y
  // pose_z
  // orientation_x
  // orientation_y
  // orientation_z
  // orientation_w
}

bool
cg_msgs__msg__BeaconTag__are_equal(const cg_msgs__msg__BeaconTag * lhs, const cg_msgs__msg__BeaconTag * rhs)
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
  // tag_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tag_id), &(rhs->tag_id)))
  {
    return false;
  }
  // pose_x
  if (lhs->pose_x != rhs->pose_x) {
    return false;
  }
  // pose_y
  if (lhs->pose_y != rhs->pose_y) {
    return false;
  }
  // pose_z
  if (lhs->pose_z != rhs->pose_z) {
    return false;
  }
  // orientation_x
  if (lhs->orientation_x != rhs->orientation_x) {
    return false;
  }
  // orientation_y
  if (lhs->orientation_y != rhs->orientation_y) {
    return false;
  }
  // orientation_z
  if (lhs->orientation_z != rhs->orientation_z) {
    return false;
  }
  // orientation_w
  if (lhs->orientation_w != rhs->orientation_w) {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__BeaconTag__copy(
  const cg_msgs__msg__BeaconTag * input,
  cg_msgs__msg__BeaconTag * output)
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
  // tag_id
  if (!rosidl_runtime_c__String__copy(
      &(input->tag_id), &(output->tag_id)))
  {
    return false;
  }
  // pose_x
  output->pose_x = input->pose_x;
  // pose_y
  output->pose_y = input->pose_y;
  // pose_z
  output->pose_z = input->pose_z;
  // orientation_x
  output->orientation_x = input->orientation_x;
  // orientation_y
  output->orientation_y = input->orientation_y;
  // orientation_z
  output->orientation_z = input->orientation_z;
  // orientation_w
  output->orientation_w = input->orientation_w;
  return true;
}

cg_msgs__msg__BeaconTag *
cg_msgs__msg__BeaconTag__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__BeaconTag * msg = (cg_msgs__msg__BeaconTag *)allocator.allocate(sizeof(cg_msgs__msg__BeaconTag), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__BeaconTag));
  bool success = cg_msgs__msg__BeaconTag__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__BeaconTag__destroy(cg_msgs__msg__BeaconTag * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__BeaconTag__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__BeaconTag__Sequence__init(cg_msgs__msg__BeaconTag__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__BeaconTag * data = NULL;

  if (size) {
    data = (cg_msgs__msg__BeaconTag *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__BeaconTag), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__BeaconTag__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__BeaconTag__fini(&data[i - 1]);
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
cg_msgs__msg__BeaconTag__Sequence__fini(cg_msgs__msg__BeaconTag__Sequence * array)
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
      cg_msgs__msg__BeaconTag__fini(&array->data[i]);
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

cg_msgs__msg__BeaconTag__Sequence *
cg_msgs__msg__BeaconTag__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__BeaconTag__Sequence * array = (cg_msgs__msg__BeaconTag__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__BeaconTag__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__BeaconTag__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__BeaconTag__Sequence__destroy(cg_msgs__msg__BeaconTag__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__BeaconTag__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__BeaconTag__Sequence__are_equal(const cg_msgs__msg__BeaconTag__Sequence * lhs, const cg_msgs__msg__BeaconTag__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__BeaconTag__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__BeaconTag__Sequence__copy(
  const cg_msgs__msg__BeaconTag__Sequence * input,
  cg_msgs__msg__BeaconTag__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__BeaconTag);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__BeaconTag * data =
      (cg_msgs__msg__BeaconTag *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__BeaconTag__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__BeaconTag__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__BeaconTag__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
