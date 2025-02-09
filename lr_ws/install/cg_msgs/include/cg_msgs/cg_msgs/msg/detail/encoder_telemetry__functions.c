// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:msg/EncoderTelemetry.idl
// generated code does not contain a copyright notice
#include "cg_msgs/msg/detail/encoder_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cg_msgs__msg__EncoderTelemetry__init(cg_msgs__msg__EncoderTelemetry * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cg_msgs__msg__EncoderTelemetry__fini(msg);
    return false;
  }
  // steer_pos_front
  msg->steer_pos_front = 0l;
  // steer_pos_rear
  msg->steer_pos_rear = 0l;
  // tool_pos
  msg->tool_pos = 0l;
  // drive_vel_front
  msg->drive_vel_front = 0l;
  // drive_vel_rear
  msg->drive_vel_rear = 0l;
  // drive_delta_front
  msg->drive_delta_front = 0l;
  // drive_delta_rear
  msg->drive_delta_rear = 0l;
  // term_byte
  msg->term_byte = 0l;
  return true;
}

void
cg_msgs__msg__EncoderTelemetry__fini(cg_msgs__msg__EncoderTelemetry * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // steer_pos_front
  // steer_pos_rear
  // tool_pos
  // drive_vel_front
  // drive_vel_rear
  // drive_delta_front
  // drive_delta_rear
  // term_byte
}

bool
cg_msgs__msg__EncoderTelemetry__are_equal(const cg_msgs__msg__EncoderTelemetry * lhs, const cg_msgs__msg__EncoderTelemetry * rhs)
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
  // steer_pos_front
  if (lhs->steer_pos_front != rhs->steer_pos_front) {
    return false;
  }
  // steer_pos_rear
  if (lhs->steer_pos_rear != rhs->steer_pos_rear) {
    return false;
  }
  // tool_pos
  if (lhs->tool_pos != rhs->tool_pos) {
    return false;
  }
  // drive_vel_front
  if (lhs->drive_vel_front != rhs->drive_vel_front) {
    return false;
  }
  // drive_vel_rear
  if (lhs->drive_vel_rear != rhs->drive_vel_rear) {
    return false;
  }
  // drive_delta_front
  if (lhs->drive_delta_front != rhs->drive_delta_front) {
    return false;
  }
  // drive_delta_rear
  if (lhs->drive_delta_rear != rhs->drive_delta_rear) {
    return false;
  }
  // term_byte
  if (lhs->term_byte != rhs->term_byte) {
    return false;
  }
  return true;
}

bool
cg_msgs__msg__EncoderTelemetry__copy(
  const cg_msgs__msg__EncoderTelemetry * input,
  cg_msgs__msg__EncoderTelemetry * output)
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
  // steer_pos_front
  output->steer_pos_front = input->steer_pos_front;
  // steer_pos_rear
  output->steer_pos_rear = input->steer_pos_rear;
  // tool_pos
  output->tool_pos = input->tool_pos;
  // drive_vel_front
  output->drive_vel_front = input->drive_vel_front;
  // drive_vel_rear
  output->drive_vel_rear = input->drive_vel_rear;
  // drive_delta_front
  output->drive_delta_front = input->drive_delta_front;
  // drive_delta_rear
  output->drive_delta_rear = input->drive_delta_rear;
  // term_byte
  output->term_byte = input->term_byte;
  return true;
}

cg_msgs__msg__EncoderTelemetry *
cg_msgs__msg__EncoderTelemetry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__EncoderTelemetry * msg = (cg_msgs__msg__EncoderTelemetry *)allocator.allocate(sizeof(cg_msgs__msg__EncoderTelemetry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__msg__EncoderTelemetry));
  bool success = cg_msgs__msg__EncoderTelemetry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__msg__EncoderTelemetry__destroy(cg_msgs__msg__EncoderTelemetry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__msg__EncoderTelemetry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__msg__EncoderTelemetry__Sequence__init(cg_msgs__msg__EncoderTelemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__EncoderTelemetry * data = NULL;

  if (size) {
    data = (cg_msgs__msg__EncoderTelemetry *)allocator.zero_allocate(size, sizeof(cg_msgs__msg__EncoderTelemetry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__msg__EncoderTelemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__msg__EncoderTelemetry__fini(&data[i - 1]);
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
cg_msgs__msg__EncoderTelemetry__Sequence__fini(cg_msgs__msg__EncoderTelemetry__Sequence * array)
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
      cg_msgs__msg__EncoderTelemetry__fini(&array->data[i]);
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

cg_msgs__msg__EncoderTelemetry__Sequence *
cg_msgs__msg__EncoderTelemetry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__msg__EncoderTelemetry__Sequence * array = (cg_msgs__msg__EncoderTelemetry__Sequence *)allocator.allocate(sizeof(cg_msgs__msg__EncoderTelemetry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__msg__EncoderTelemetry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__msg__EncoderTelemetry__Sequence__destroy(cg_msgs__msg__EncoderTelemetry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__msg__EncoderTelemetry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__msg__EncoderTelemetry__Sequence__are_equal(const cg_msgs__msg__EncoderTelemetry__Sequence * lhs, const cg_msgs__msg__EncoderTelemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__msg__EncoderTelemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__msg__EncoderTelemetry__Sequence__copy(
  const cg_msgs__msg__EncoderTelemetry__Sequence * input,
  cg_msgs__msg__EncoderTelemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__msg__EncoderTelemetry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__msg__EncoderTelemetry * data =
      (cg_msgs__msg__EncoderTelemetry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__msg__EncoderTelemetry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__msg__EncoderTelemetry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__msg__EncoderTelemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
