// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:srv/Switch.idl
// generated code does not contain a copyright notice
#include "lx_msgs/srv/detail/switch__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `current_berm_segment`
// Member `prev_berm_segment`
#include "lx_msgs/msg/detail/berm_section__functions.h"

bool
lx_msgs__srv__Switch_Request__init(lx_msgs__srv__Switch_Request * msg)
{
  if (!msg) {
    return false;
  }
  // switch_state
  // current_berm_segment
  if (!lx_msgs__msg__BermSection__init(&msg->current_berm_segment)) {
    lx_msgs__srv__Switch_Request__fini(msg);
    return false;
  }
  // prev_berm_segment
  if (!lx_msgs__msg__BermSection__init(&msg->prev_berm_segment)) {
    lx_msgs__srv__Switch_Request__fini(msg);
    return false;
  }
  // first_seg_dump
  return true;
}

void
lx_msgs__srv__Switch_Request__fini(lx_msgs__srv__Switch_Request * msg)
{
  if (!msg) {
    return;
  }
  // switch_state
  // current_berm_segment
  lx_msgs__msg__BermSection__fini(&msg->current_berm_segment);
  // prev_berm_segment
  lx_msgs__msg__BermSection__fini(&msg->prev_berm_segment);
  // first_seg_dump
}

bool
lx_msgs__srv__Switch_Request__are_equal(const lx_msgs__srv__Switch_Request * lhs, const lx_msgs__srv__Switch_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // switch_state
  if (lhs->switch_state != rhs->switch_state) {
    return false;
  }
  // current_berm_segment
  if (!lx_msgs__msg__BermSection__are_equal(
      &(lhs->current_berm_segment), &(rhs->current_berm_segment)))
  {
    return false;
  }
  // prev_berm_segment
  if (!lx_msgs__msg__BermSection__are_equal(
      &(lhs->prev_berm_segment), &(rhs->prev_berm_segment)))
  {
    return false;
  }
  // first_seg_dump
  if (lhs->first_seg_dump != rhs->first_seg_dump) {
    return false;
  }
  return true;
}

bool
lx_msgs__srv__Switch_Request__copy(
  const lx_msgs__srv__Switch_Request * input,
  lx_msgs__srv__Switch_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // switch_state
  output->switch_state = input->switch_state;
  // current_berm_segment
  if (!lx_msgs__msg__BermSection__copy(
      &(input->current_berm_segment), &(output->current_berm_segment)))
  {
    return false;
  }
  // prev_berm_segment
  if (!lx_msgs__msg__BermSection__copy(
      &(input->prev_berm_segment), &(output->prev_berm_segment)))
  {
    return false;
  }
  // first_seg_dump
  output->first_seg_dump = input->first_seg_dump;
  return true;
}

lx_msgs__srv__Switch_Request *
lx_msgs__srv__Switch_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__Switch_Request * msg = (lx_msgs__srv__Switch_Request *)allocator.allocate(sizeof(lx_msgs__srv__Switch_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__srv__Switch_Request));
  bool success = lx_msgs__srv__Switch_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__srv__Switch_Request__destroy(lx_msgs__srv__Switch_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__srv__Switch_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__srv__Switch_Request__Sequence__init(lx_msgs__srv__Switch_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__Switch_Request * data = NULL;

  if (size) {
    data = (lx_msgs__srv__Switch_Request *)allocator.zero_allocate(size, sizeof(lx_msgs__srv__Switch_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__srv__Switch_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__srv__Switch_Request__fini(&data[i - 1]);
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
lx_msgs__srv__Switch_Request__Sequence__fini(lx_msgs__srv__Switch_Request__Sequence * array)
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
      lx_msgs__srv__Switch_Request__fini(&array->data[i]);
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

lx_msgs__srv__Switch_Request__Sequence *
lx_msgs__srv__Switch_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__Switch_Request__Sequence * array = (lx_msgs__srv__Switch_Request__Sequence *)allocator.allocate(sizeof(lx_msgs__srv__Switch_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__srv__Switch_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__srv__Switch_Request__Sequence__destroy(lx_msgs__srv__Switch_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__srv__Switch_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__srv__Switch_Request__Sequence__are_equal(const lx_msgs__srv__Switch_Request__Sequence * lhs, const lx_msgs__srv__Switch_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__srv__Switch_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__srv__Switch_Request__Sequence__copy(
  const lx_msgs__srv__Switch_Request__Sequence * input,
  lx_msgs__srv__Switch_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__srv__Switch_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__srv__Switch_Request * data =
      (lx_msgs__srv__Switch_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__srv__Switch_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__srv__Switch_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__srv__Switch_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
lx_msgs__srv__Switch_Response__init(lx_msgs__srv__Switch_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
lx_msgs__srv__Switch_Response__fini(lx_msgs__srv__Switch_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
lx_msgs__srv__Switch_Response__are_equal(const lx_msgs__srv__Switch_Response * lhs, const lx_msgs__srv__Switch_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
lx_msgs__srv__Switch_Response__copy(
  const lx_msgs__srv__Switch_Response * input,
  lx_msgs__srv__Switch_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

lx_msgs__srv__Switch_Response *
lx_msgs__srv__Switch_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__Switch_Response * msg = (lx_msgs__srv__Switch_Response *)allocator.allocate(sizeof(lx_msgs__srv__Switch_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__srv__Switch_Response));
  bool success = lx_msgs__srv__Switch_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__srv__Switch_Response__destroy(lx_msgs__srv__Switch_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__srv__Switch_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__srv__Switch_Response__Sequence__init(lx_msgs__srv__Switch_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__Switch_Response * data = NULL;

  if (size) {
    data = (lx_msgs__srv__Switch_Response *)allocator.zero_allocate(size, sizeof(lx_msgs__srv__Switch_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__srv__Switch_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__srv__Switch_Response__fini(&data[i - 1]);
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
lx_msgs__srv__Switch_Response__Sequence__fini(lx_msgs__srv__Switch_Response__Sequence * array)
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
      lx_msgs__srv__Switch_Response__fini(&array->data[i]);
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

lx_msgs__srv__Switch_Response__Sequence *
lx_msgs__srv__Switch_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__Switch_Response__Sequence * array = (lx_msgs__srv__Switch_Response__Sequence *)allocator.allocate(sizeof(lx_msgs__srv__Switch_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__srv__Switch_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__srv__Switch_Response__Sequence__destroy(lx_msgs__srv__Switch_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__srv__Switch_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__srv__Switch_Response__Sequence__are_equal(const lx_msgs__srv__Switch_Response__Sequence * lhs, const lx_msgs__srv__Switch_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__srv__Switch_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__srv__Switch_Response__Sequence__copy(
  const lx_msgs__srv__Switch_Response__Sequence * input,
  lx_msgs__srv__Switch_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__srv__Switch_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__srv__Switch_Response * data =
      (lx_msgs__srv__Switch_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__srv__Switch_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__srv__Switch_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__srv__Switch_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
