// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:srv/BermProgressEval.idl
// generated code does not contain a copyright notice
#include "lx_msgs/srv/detail/berm_progress_eval__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
lx_msgs__srv__BermProgressEval_Request__init(lx_msgs__srv__BermProgressEval_Request * msg)
{
  if (!msg) {
    return false;
  }
  // need_metrics
  return true;
}

void
lx_msgs__srv__BermProgressEval_Request__fini(lx_msgs__srv__BermProgressEval_Request * msg)
{
  if (!msg) {
    return;
  }
  // need_metrics
}

bool
lx_msgs__srv__BermProgressEval_Request__are_equal(const lx_msgs__srv__BermProgressEval_Request * lhs, const lx_msgs__srv__BermProgressEval_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // need_metrics
  if (lhs->need_metrics != rhs->need_metrics) {
    return false;
  }
  return true;
}

bool
lx_msgs__srv__BermProgressEval_Request__copy(
  const lx_msgs__srv__BermProgressEval_Request * input,
  lx_msgs__srv__BermProgressEval_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // need_metrics
  output->need_metrics = input->need_metrics;
  return true;
}

lx_msgs__srv__BermProgressEval_Request *
lx_msgs__srv__BermProgressEval_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__BermProgressEval_Request * msg = (lx_msgs__srv__BermProgressEval_Request *)allocator.allocate(sizeof(lx_msgs__srv__BermProgressEval_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__srv__BermProgressEval_Request));
  bool success = lx_msgs__srv__BermProgressEval_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__srv__BermProgressEval_Request__destroy(lx_msgs__srv__BermProgressEval_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__srv__BermProgressEval_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__srv__BermProgressEval_Request__Sequence__init(lx_msgs__srv__BermProgressEval_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__BermProgressEval_Request * data = NULL;

  if (size) {
    data = (lx_msgs__srv__BermProgressEval_Request *)allocator.zero_allocate(size, sizeof(lx_msgs__srv__BermProgressEval_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__srv__BermProgressEval_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__srv__BermProgressEval_Request__fini(&data[i - 1]);
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
lx_msgs__srv__BermProgressEval_Request__Sequence__fini(lx_msgs__srv__BermProgressEval_Request__Sequence * array)
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
      lx_msgs__srv__BermProgressEval_Request__fini(&array->data[i]);
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

lx_msgs__srv__BermProgressEval_Request__Sequence *
lx_msgs__srv__BermProgressEval_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__BermProgressEval_Request__Sequence * array = (lx_msgs__srv__BermProgressEval_Request__Sequence *)allocator.allocate(sizeof(lx_msgs__srv__BermProgressEval_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__srv__BermProgressEval_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__srv__BermProgressEval_Request__Sequence__destroy(lx_msgs__srv__BermProgressEval_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__srv__BermProgressEval_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__srv__BermProgressEval_Request__Sequence__are_equal(const lx_msgs__srv__BermProgressEval_Request__Sequence * lhs, const lx_msgs__srv__BermProgressEval_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__srv__BermProgressEval_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__srv__BermProgressEval_Request__Sequence__copy(
  const lx_msgs__srv__BermProgressEval_Request__Sequence * input,
  lx_msgs__srv__BermProgressEval_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__srv__BermProgressEval_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__srv__BermProgressEval_Request * data =
      (lx_msgs__srv__BermProgressEval_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__srv__BermProgressEval_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__srv__BermProgressEval_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__srv__BermProgressEval_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `progress`
#include "lx_msgs/msg/detail/berm_progress__functions.h"

bool
lx_msgs__srv__BermProgressEval_Response__init(lx_msgs__srv__BermProgressEval_Response * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  if (!lx_msgs__msg__BermProgress__init(&msg->progress)) {
    lx_msgs__srv__BermProgressEval_Response__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__srv__BermProgressEval_Response__fini(lx_msgs__srv__BermProgressEval_Response * msg)
{
  if (!msg) {
    return;
  }
  // progress
  lx_msgs__msg__BermProgress__fini(&msg->progress);
}

bool
lx_msgs__srv__BermProgressEval_Response__are_equal(const lx_msgs__srv__BermProgressEval_Response * lhs, const lx_msgs__srv__BermProgressEval_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (!lx_msgs__msg__BermProgress__are_equal(
      &(lhs->progress), &(rhs->progress)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__srv__BermProgressEval_Response__copy(
  const lx_msgs__srv__BermProgressEval_Response * input,
  lx_msgs__srv__BermProgressEval_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  if (!lx_msgs__msg__BermProgress__copy(
      &(input->progress), &(output->progress)))
  {
    return false;
  }
  return true;
}

lx_msgs__srv__BermProgressEval_Response *
lx_msgs__srv__BermProgressEval_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__BermProgressEval_Response * msg = (lx_msgs__srv__BermProgressEval_Response *)allocator.allocate(sizeof(lx_msgs__srv__BermProgressEval_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__srv__BermProgressEval_Response));
  bool success = lx_msgs__srv__BermProgressEval_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__srv__BermProgressEval_Response__destroy(lx_msgs__srv__BermProgressEval_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__srv__BermProgressEval_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__srv__BermProgressEval_Response__Sequence__init(lx_msgs__srv__BermProgressEval_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__BermProgressEval_Response * data = NULL;

  if (size) {
    data = (lx_msgs__srv__BermProgressEval_Response *)allocator.zero_allocate(size, sizeof(lx_msgs__srv__BermProgressEval_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__srv__BermProgressEval_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__srv__BermProgressEval_Response__fini(&data[i - 1]);
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
lx_msgs__srv__BermProgressEval_Response__Sequence__fini(lx_msgs__srv__BermProgressEval_Response__Sequence * array)
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
      lx_msgs__srv__BermProgressEval_Response__fini(&array->data[i]);
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

lx_msgs__srv__BermProgressEval_Response__Sequence *
lx_msgs__srv__BermProgressEval_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__srv__BermProgressEval_Response__Sequence * array = (lx_msgs__srv__BermProgressEval_Response__Sequence *)allocator.allocate(sizeof(lx_msgs__srv__BermProgressEval_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__srv__BermProgressEval_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__srv__BermProgressEval_Response__Sequence__destroy(lx_msgs__srv__BermProgressEval_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__srv__BermProgressEval_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__srv__BermProgressEval_Response__Sequence__are_equal(const lx_msgs__srv__BermProgressEval_Response__Sequence * lhs, const lx_msgs__srv__BermProgressEval_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__srv__BermProgressEval_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__srv__BermProgressEval_Response__Sequence__copy(
  const lx_msgs__srv__BermProgressEval_Response__Sequence * input,
  lx_msgs__srv__BermProgressEval_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__srv__BermProgressEval_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__srv__BermProgressEval_Response * data =
      (lx_msgs__srv__BermProgressEval_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__srv__BermProgressEval_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__srv__BermProgressEval_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__srv__BermProgressEval_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
