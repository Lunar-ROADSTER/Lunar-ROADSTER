// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:msg/PlannedTask.idl
// generated code does not contain a copyright notice
#include "lx_msgs/msg/detail/planned_task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `berm_point`
#include "lx_msgs/msg/detail/berm_section__functions.h"

bool
lx_msgs__msg__PlannedTask__init(lx_msgs__msg__PlannedTask * msg)
{
  if (!msg) {
    return false;
  }
  // task_type
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    lx_msgs__msg__PlannedTask__fini(msg);
    return false;
  }
  // berm_point
  if (!lx_msgs__msg__BermSection__init(&msg->berm_point)) {
    lx_msgs__msg__PlannedTask__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__msg__PlannedTask__fini(lx_msgs__msg__PlannedTask * msg)
{
  if (!msg) {
    return;
  }
  // task_type
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // berm_point
  lx_msgs__msg__BermSection__fini(&msg->berm_point);
}

bool
lx_msgs__msg__PlannedTask__are_equal(const lx_msgs__msg__PlannedTask * lhs, const lx_msgs__msg__PlannedTask * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_type
  if (lhs->task_type != rhs->task_type) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // berm_point
  if (!lx_msgs__msg__BermSection__are_equal(
      &(lhs->berm_point), &(rhs->berm_point)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__msg__PlannedTask__copy(
  const lx_msgs__msg__PlannedTask * input,
  lx_msgs__msg__PlannedTask * output)
{
  if (!input || !output) {
    return false;
  }
  // task_type
  output->task_type = input->task_type;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // berm_point
  if (!lx_msgs__msg__BermSection__copy(
      &(input->berm_point), &(output->berm_point)))
  {
    return false;
  }
  return true;
}

lx_msgs__msg__PlannedTask *
lx_msgs__msg__PlannedTask__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__PlannedTask * msg = (lx_msgs__msg__PlannedTask *)allocator.allocate(sizeof(lx_msgs__msg__PlannedTask), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__msg__PlannedTask));
  bool success = lx_msgs__msg__PlannedTask__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__msg__PlannedTask__destroy(lx_msgs__msg__PlannedTask * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__msg__PlannedTask__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__msg__PlannedTask__Sequence__init(lx_msgs__msg__PlannedTask__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__PlannedTask * data = NULL;

  if (size) {
    data = (lx_msgs__msg__PlannedTask *)allocator.zero_allocate(size, sizeof(lx_msgs__msg__PlannedTask), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__msg__PlannedTask__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__msg__PlannedTask__fini(&data[i - 1]);
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
lx_msgs__msg__PlannedTask__Sequence__fini(lx_msgs__msg__PlannedTask__Sequence * array)
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
      lx_msgs__msg__PlannedTask__fini(&array->data[i]);
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

lx_msgs__msg__PlannedTask__Sequence *
lx_msgs__msg__PlannedTask__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__msg__PlannedTask__Sequence * array = (lx_msgs__msg__PlannedTask__Sequence *)allocator.allocate(sizeof(lx_msgs__msg__PlannedTask__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__msg__PlannedTask__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__msg__PlannedTask__Sequence__destroy(lx_msgs__msg__PlannedTask__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__msg__PlannedTask__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__msg__PlannedTask__Sequence__are_equal(const lx_msgs__msg__PlannedTask__Sequence * lhs, const lx_msgs__msg__PlannedTask__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__msg__PlannedTask__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__msg__PlannedTask__Sequence__copy(
  const lx_msgs__msg__PlannedTask__Sequence * input,
  lx_msgs__msg__PlannedTask__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__msg__PlannedTask);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__msg__PlannedTask * data =
      (lx_msgs__msg__PlannedTask *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__msg__PlannedTask__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__msg__PlannedTask__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__msg__PlannedTask__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
