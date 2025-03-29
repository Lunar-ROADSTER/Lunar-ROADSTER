// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lx_msgs:action/AutoDig.idl
// generated code does not contain a copyright notice
#include "lx_msgs/action/detail/auto_dig__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
lx_msgs__action__AutoDig_Goal__init(lx_msgs__action__AutoDig_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // unused
  return true;
}

void
lx_msgs__action__AutoDig_Goal__fini(lx_msgs__action__AutoDig_Goal * msg)
{
  if (!msg) {
    return;
  }
  // unused
}

bool
lx_msgs__action__AutoDig_Goal__are_equal(const lx_msgs__action__AutoDig_Goal * lhs, const lx_msgs__action__AutoDig_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // unused
  if (lhs->unused != rhs->unused) {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_Goal__copy(
  const lx_msgs__action__AutoDig_Goal * input,
  lx_msgs__action__AutoDig_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // unused
  output->unused = input->unused;
  return true;
}

lx_msgs__action__AutoDig_Goal *
lx_msgs__action__AutoDig_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Goal * msg = (lx_msgs__action__AutoDig_Goal *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_Goal));
  bool success = lx_msgs__action__AutoDig_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_Goal__destroy(lx_msgs__action__AutoDig_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_Goal__Sequence__init(lx_msgs__action__AutoDig_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Goal * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_Goal *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_Goal__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_Goal__Sequence__fini(lx_msgs__action__AutoDig_Goal__Sequence * array)
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
      lx_msgs__action__AutoDig_Goal__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_Goal__Sequence *
lx_msgs__action__AutoDig_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Goal__Sequence * array = (lx_msgs__action__AutoDig_Goal__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_Goal__Sequence__destroy(lx_msgs__action__AutoDig_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_Goal__Sequence__are_equal(const lx_msgs__action__AutoDig_Goal__Sequence * lhs, const lx_msgs__action__AutoDig_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_Goal__Sequence__copy(
  const lx_msgs__action__AutoDig_Goal__Sequence * input,
  lx_msgs__action__AutoDig_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_Goal * data =
      (lx_msgs__action__AutoDig_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
lx_msgs__action__AutoDig_Result__init(lx_msgs__action__AutoDig_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
lx_msgs__action__AutoDig_Result__fini(lx_msgs__action__AutoDig_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
lx_msgs__action__AutoDig_Result__are_equal(const lx_msgs__action__AutoDig_Result * lhs, const lx_msgs__action__AutoDig_Result * rhs)
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
lx_msgs__action__AutoDig_Result__copy(
  const lx_msgs__action__AutoDig_Result * input,
  lx_msgs__action__AutoDig_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

lx_msgs__action__AutoDig_Result *
lx_msgs__action__AutoDig_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Result * msg = (lx_msgs__action__AutoDig_Result *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_Result));
  bool success = lx_msgs__action__AutoDig_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_Result__destroy(lx_msgs__action__AutoDig_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_Result__Sequence__init(lx_msgs__action__AutoDig_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Result * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_Result *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_Result__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_Result__Sequence__fini(lx_msgs__action__AutoDig_Result__Sequence * array)
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
      lx_msgs__action__AutoDig_Result__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_Result__Sequence *
lx_msgs__action__AutoDig_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Result__Sequence * array = (lx_msgs__action__AutoDig_Result__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_Result__Sequence__destroy(lx_msgs__action__AutoDig_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_Result__Sequence__are_equal(const lx_msgs__action__AutoDig_Result__Sequence * lhs, const lx_msgs__action__AutoDig_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_Result__Sequence__copy(
  const lx_msgs__action__AutoDig_Result__Sequence * input,
  lx_msgs__action__AutoDig_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_Result * data =
      (lx_msgs__action__AutoDig_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
lx_msgs__action__AutoDig_Feedback__init(lx_msgs__action__AutoDig_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    lx_msgs__action__AutoDig_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__action__AutoDig_Feedback__fini(lx_msgs__action__AutoDig_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
lx_msgs__action__AutoDig_Feedback__are_equal(const lx_msgs__action__AutoDig_Feedback * lhs, const lx_msgs__action__AutoDig_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_Feedback__copy(
  const lx_msgs__action__AutoDig_Feedback * input,
  lx_msgs__action__AutoDig_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

lx_msgs__action__AutoDig_Feedback *
lx_msgs__action__AutoDig_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Feedback * msg = (lx_msgs__action__AutoDig_Feedback *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_Feedback));
  bool success = lx_msgs__action__AutoDig_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_Feedback__destroy(lx_msgs__action__AutoDig_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_Feedback__Sequence__init(lx_msgs__action__AutoDig_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Feedback * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_Feedback *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_Feedback__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_Feedback__Sequence__fini(lx_msgs__action__AutoDig_Feedback__Sequence * array)
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
      lx_msgs__action__AutoDig_Feedback__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_Feedback__Sequence *
lx_msgs__action__AutoDig_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_Feedback__Sequence * array = (lx_msgs__action__AutoDig_Feedback__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_Feedback__Sequence__destroy(lx_msgs__action__AutoDig_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_Feedback__Sequence__are_equal(const lx_msgs__action__AutoDig_Feedback__Sequence * lhs, const lx_msgs__action__AutoDig_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_Feedback__Sequence__copy(
  const lx_msgs__action__AutoDig_Feedback__Sequence * input,
  lx_msgs__action__AutoDig_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_Feedback * data =
      (lx_msgs__action__AutoDig_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "lx_msgs/action/detail/auto_dig__functions.h"

bool
lx_msgs__action__AutoDig_SendGoal_Request__init(lx_msgs__action__AutoDig_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    lx_msgs__action__AutoDig_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!lx_msgs__action__AutoDig_Goal__init(&msg->goal)) {
    lx_msgs__action__AutoDig_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__action__AutoDig_SendGoal_Request__fini(lx_msgs__action__AutoDig_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  lx_msgs__action__AutoDig_Goal__fini(&msg->goal);
}

bool
lx_msgs__action__AutoDig_SendGoal_Request__are_equal(const lx_msgs__action__AutoDig_SendGoal_Request * lhs, const lx_msgs__action__AutoDig_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!lx_msgs__action__AutoDig_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_SendGoal_Request__copy(
  const lx_msgs__action__AutoDig_SendGoal_Request * input,
  lx_msgs__action__AutoDig_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!lx_msgs__action__AutoDig_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

lx_msgs__action__AutoDig_SendGoal_Request *
lx_msgs__action__AutoDig_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_SendGoal_Request * msg = (lx_msgs__action__AutoDig_SendGoal_Request *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_SendGoal_Request));
  bool success = lx_msgs__action__AutoDig_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_SendGoal_Request__destroy(lx_msgs__action__AutoDig_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_SendGoal_Request__Sequence__init(lx_msgs__action__AutoDig_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_SendGoal_Request * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_SendGoal_Request *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_SendGoal_Request__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_SendGoal_Request__Sequence__fini(lx_msgs__action__AutoDig_SendGoal_Request__Sequence * array)
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
      lx_msgs__action__AutoDig_SendGoal_Request__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_SendGoal_Request__Sequence *
lx_msgs__action__AutoDig_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_SendGoal_Request__Sequence * array = (lx_msgs__action__AutoDig_SendGoal_Request__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_SendGoal_Request__Sequence__destroy(lx_msgs__action__AutoDig_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_SendGoal_Request__Sequence__are_equal(const lx_msgs__action__AutoDig_SendGoal_Request__Sequence * lhs, const lx_msgs__action__AutoDig_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_SendGoal_Request__Sequence__copy(
  const lx_msgs__action__AutoDig_SendGoal_Request__Sequence * input,
  lx_msgs__action__AutoDig_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_SendGoal_Request * data =
      (lx_msgs__action__AutoDig_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
lx_msgs__action__AutoDig_SendGoal_Response__init(lx_msgs__action__AutoDig_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    lx_msgs__action__AutoDig_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__action__AutoDig_SendGoal_Response__fini(lx_msgs__action__AutoDig_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
lx_msgs__action__AutoDig_SendGoal_Response__are_equal(const lx_msgs__action__AutoDig_SendGoal_Response * lhs, const lx_msgs__action__AutoDig_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_SendGoal_Response__copy(
  const lx_msgs__action__AutoDig_SendGoal_Response * input,
  lx_msgs__action__AutoDig_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

lx_msgs__action__AutoDig_SendGoal_Response *
lx_msgs__action__AutoDig_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_SendGoal_Response * msg = (lx_msgs__action__AutoDig_SendGoal_Response *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_SendGoal_Response));
  bool success = lx_msgs__action__AutoDig_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_SendGoal_Response__destroy(lx_msgs__action__AutoDig_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_SendGoal_Response__Sequence__init(lx_msgs__action__AutoDig_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_SendGoal_Response * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_SendGoal_Response *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_SendGoal_Response__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_SendGoal_Response__Sequence__fini(lx_msgs__action__AutoDig_SendGoal_Response__Sequence * array)
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
      lx_msgs__action__AutoDig_SendGoal_Response__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_SendGoal_Response__Sequence *
lx_msgs__action__AutoDig_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_SendGoal_Response__Sequence * array = (lx_msgs__action__AutoDig_SendGoal_Response__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_SendGoal_Response__Sequence__destroy(lx_msgs__action__AutoDig_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_SendGoal_Response__Sequence__are_equal(const lx_msgs__action__AutoDig_SendGoal_Response__Sequence * lhs, const lx_msgs__action__AutoDig_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_SendGoal_Response__Sequence__copy(
  const lx_msgs__action__AutoDig_SendGoal_Response__Sequence * input,
  lx_msgs__action__AutoDig_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_SendGoal_Response * data =
      (lx_msgs__action__AutoDig_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
lx_msgs__action__AutoDig_GetResult_Request__init(lx_msgs__action__AutoDig_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    lx_msgs__action__AutoDig_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__action__AutoDig_GetResult_Request__fini(lx_msgs__action__AutoDig_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
lx_msgs__action__AutoDig_GetResult_Request__are_equal(const lx_msgs__action__AutoDig_GetResult_Request * lhs, const lx_msgs__action__AutoDig_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_GetResult_Request__copy(
  const lx_msgs__action__AutoDig_GetResult_Request * input,
  lx_msgs__action__AutoDig_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

lx_msgs__action__AutoDig_GetResult_Request *
lx_msgs__action__AutoDig_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_GetResult_Request * msg = (lx_msgs__action__AutoDig_GetResult_Request *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_GetResult_Request));
  bool success = lx_msgs__action__AutoDig_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_GetResult_Request__destroy(lx_msgs__action__AutoDig_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_GetResult_Request__Sequence__init(lx_msgs__action__AutoDig_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_GetResult_Request * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_GetResult_Request *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_GetResult_Request__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_GetResult_Request__Sequence__fini(lx_msgs__action__AutoDig_GetResult_Request__Sequence * array)
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
      lx_msgs__action__AutoDig_GetResult_Request__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_GetResult_Request__Sequence *
lx_msgs__action__AutoDig_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_GetResult_Request__Sequence * array = (lx_msgs__action__AutoDig_GetResult_Request__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_GetResult_Request__Sequence__destroy(lx_msgs__action__AutoDig_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_GetResult_Request__Sequence__are_equal(const lx_msgs__action__AutoDig_GetResult_Request__Sequence * lhs, const lx_msgs__action__AutoDig_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_GetResult_Request__Sequence__copy(
  const lx_msgs__action__AutoDig_GetResult_Request__Sequence * input,
  lx_msgs__action__AutoDig_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_GetResult_Request * data =
      (lx_msgs__action__AutoDig_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "lx_msgs/action/detail/auto_dig__functions.h"

bool
lx_msgs__action__AutoDig_GetResult_Response__init(lx_msgs__action__AutoDig_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!lx_msgs__action__AutoDig_Result__init(&msg->result)) {
    lx_msgs__action__AutoDig_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__action__AutoDig_GetResult_Response__fini(lx_msgs__action__AutoDig_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  lx_msgs__action__AutoDig_Result__fini(&msg->result);
}

bool
lx_msgs__action__AutoDig_GetResult_Response__are_equal(const lx_msgs__action__AutoDig_GetResult_Response * lhs, const lx_msgs__action__AutoDig_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!lx_msgs__action__AutoDig_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_GetResult_Response__copy(
  const lx_msgs__action__AutoDig_GetResult_Response * input,
  lx_msgs__action__AutoDig_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!lx_msgs__action__AutoDig_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

lx_msgs__action__AutoDig_GetResult_Response *
lx_msgs__action__AutoDig_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_GetResult_Response * msg = (lx_msgs__action__AutoDig_GetResult_Response *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_GetResult_Response));
  bool success = lx_msgs__action__AutoDig_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_GetResult_Response__destroy(lx_msgs__action__AutoDig_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_GetResult_Response__Sequence__init(lx_msgs__action__AutoDig_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_GetResult_Response * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_GetResult_Response *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_GetResult_Response__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_GetResult_Response__Sequence__fini(lx_msgs__action__AutoDig_GetResult_Response__Sequence * array)
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
      lx_msgs__action__AutoDig_GetResult_Response__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_GetResult_Response__Sequence *
lx_msgs__action__AutoDig_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_GetResult_Response__Sequence * array = (lx_msgs__action__AutoDig_GetResult_Response__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_GetResult_Response__Sequence__destroy(lx_msgs__action__AutoDig_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_GetResult_Response__Sequence__are_equal(const lx_msgs__action__AutoDig_GetResult_Response__Sequence * lhs, const lx_msgs__action__AutoDig_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_GetResult_Response__Sequence__copy(
  const lx_msgs__action__AutoDig_GetResult_Response__Sequence * input,
  lx_msgs__action__AutoDig_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_GetResult_Response * data =
      (lx_msgs__action__AutoDig_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "lx_msgs/action/detail/auto_dig__functions.h"

bool
lx_msgs__action__AutoDig_FeedbackMessage__init(lx_msgs__action__AutoDig_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    lx_msgs__action__AutoDig_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!lx_msgs__action__AutoDig_Feedback__init(&msg->feedback)) {
    lx_msgs__action__AutoDig_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
lx_msgs__action__AutoDig_FeedbackMessage__fini(lx_msgs__action__AutoDig_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  lx_msgs__action__AutoDig_Feedback__fini(&msg->feedback);
}

bool
lx_msgs__action__AutoDig_FeedbackMessage__are_equal(const lx_msgs__action__AutoDig_FeedbackMessage * lhs, const lx_msgs__action__AutoDig_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!lx_msgs__action__AutoDig_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
lx_msgs__action__AutoDig_FeedbackMessage__copy(
  const lx_msgs__action__AutoDig_FeedbackMessage * input,
  lx_msgs__action__AutoDig_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!lx_msgs__action__AutoDig_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

lx_msgs__action__AutoDig_FeedbackMessage *
lx_msgs__action__AutoDig_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_FeedbackMessage * msg = (lx_msgs__action__AutoDig_FeedbackMessage *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lx_msgs__action__AutoDig_FeedbackMessage));
  bool success = lx_msgs__action__AutoDig_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lx_msgs__action__AutoDig_FeedbackMessage__destroy(lx_msgs__action__AutoDig_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lx_msgs__action__AutoDig_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lx_msgs__action__AutoDig_FeedbackMessage__Sequence__init(lx_msgs__action__AutoDig_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_FeedbackMessage * data = NULL;

  if (size) {
    data = (lx_msgs__action__AutoDig_FeedbackMessage *)allocator.zero_allocate(size, sizeof(lx_msgs__action__AutoDig_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lx_msgs__action__AutoDig_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lx_msgs__action__AutoDig_FeedbackMessage__fini(&data[i - 1]);
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
lx_msgs__action__AutoDig_FeedbackMessage__Sequence__fini(lx_msgs__action__AutoDig_FeedbackMessage__Sequence * array)
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
      lx_msgs__action__AutoDig_FeedbackMessage__fini(&array->data[i]);
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

lx_msgs__action__AutoDig_FeedbackMessage__Sequence *
lx_msgs__action__AutoDig_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lx_msgs__action__AutoDig_FeedbackMessage__Sequence * array = (lx_msgs__action__AutoDig_FeedbackMessage__Sequence *)allocator.allocate(sizeof(lx_msgs__action__AutoDig_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lx_msgs__action__AutoDig_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lx_msgs__action__AutoDig_FeedbackMessage__Sequence__destroy(lx_msgs__action__AutoDig_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lx_msgs__action__AutoDig_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lx_msgs__action__AutoDig_FeedbackMessage__Sequence__are_equal(const lx_msgs__action__AutoDig_FeedbackMessage__Sequence * lhs, const lx_msgs__action__AutoDig_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lx_msgs__action__AutoDig_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lx_msgs__action__AutoDig_FeedbackMessage__Sequence__copy(
  const lx_msgs__action__AutoDig_FeedbackMessage__Sequence * input,
  lx_msgs__action__AutoDig_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lx_msgs__action__AutoDig_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lx_msgs__action__AutoDig_FeedbackMessage * data =
      (lx_msgs__action__AutoDig_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lx_msgs__action__AutoDig_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lx_msgs__action__AutoDig_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lx_msgs__action__AutoDig_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
