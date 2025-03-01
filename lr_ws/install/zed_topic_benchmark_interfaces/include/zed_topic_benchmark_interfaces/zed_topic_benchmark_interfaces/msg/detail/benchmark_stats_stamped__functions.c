// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__init(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(msg);
    return false;
  }
  // topic_freq
  // topic_avg_freq
  // topic_bw
  // topic_avg_bw
  return true;
}

void
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // topic_freq
  // topic_avg_freq
  // topic_bw
  // topic_avg_bw
}

bool
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__are_equal(const zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * lhs, const zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * rhs)
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
  // topic_freq
  if (lhs->topic_freq != rhs->topic_freq) {
    return false;
  }
  // topic_avg_freq
  if (lhs->topic_avg_freq != rhs->topic_avg_freq) {
    return false;
  }
  // topic_bw
  if (lhs->topic_bw != rhs->topic_bw) {
    return false;
  }
  // topic_avg_bw
  if (lhs->topic_avg_bw != rhs->topic_avg_bw) {
    return false;
  }
  return true;
}

bool
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__copy(
  const zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * input,
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * output)
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
  // topic_freq
  output->topic_freq = input->topic_freq;
  // topic_avg_freq
  output->topic_avg_freq = input->topic_avg_freq;
  // topic_bw
  output->topic_bw = input->topic_bw;
  // topic_avg_bw
  output->topic_avg_bw = input->topic_avg_bw;
  return true;
}

zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped *
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * msg = (zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped *)allocator.allocate(sizeof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped));
  bool success = zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__destroy(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__init(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * data = NULL;

  if (size) {
    data = (zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped *)allocator.zero_allocate(size, sizeof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(&data[i - 1]);
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
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__fini(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * array)
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
      zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(&array->data[i]);
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

zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence *
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * array = (zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence *)allocator.allocate(sizeof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__destroy(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__are_equal(const zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * lhs, const zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence__copy(
  const zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * input,
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * data =
      (zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
