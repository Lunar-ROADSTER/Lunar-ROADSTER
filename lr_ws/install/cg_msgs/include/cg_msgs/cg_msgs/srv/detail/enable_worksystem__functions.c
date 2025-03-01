// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cg_msgs:srv/EnableWorksystem.idl
// generated code does not contain a copyright notice
#include "cg_msgs/srv/detail/enable_worksystem__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
cg_msgs__srv__EnableWorksystem_Request__init(cg_msgs__srv__EnableWorksystem_Request * msg)
{
  if (!msg) {
    return false;
  }
  // enable_worksystem
  return true;
}

void
cg_msgs__srv__EnableWorksystem_Request__fini(cg_msgs__srv__EnableWorksystem_Request * msg)
{
  if (!msg) {
    return;
  }
  // enable_worksystem
}

bool
cg_msgs__srv__EnableWorksystem_Request__are_equal(const cg_msgs__srv__EnableWorksystem_Request * lhs, const cg_msgs__srv__EnableWorksystem_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enable_worksystem
  if (lhs->enable_worksystem != rhs->enable_worksystem) {
    return false;
  }
  return true;
}

bool
cg_msgs__srv__EnableWorksystem_Request__copy(
  const cg_msgs__srv__EnableWorksystem_Request * input,
  cg_msgs__srv__EnableWorksystem_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // enable_worksystem
  output->enable_worksystem = input->enable_worksystem;
  return true;
}

cg_msgs__srv__EnableWorksystem_Request *
cg_msgs__srv__EnableWorksystem_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__srv__EnableWorksystem_Request * msg = (cg_msgs__srv__EnableWorksystem_Request *)allocator.allocate(sizeof(cg_msgs__srv__EnableWorksystem_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__srv__EnableWorksystem_Request));
  bool success = cg_msgs__srv__EnableWorksystem_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__srv__EnableWorksystem_Request__destroy(cg_msgs__srv__EnableWorksystem_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__srv__EnableWorksystem_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__srv__EnableWorksystem_Request__Sequence__init(cg_msgs__srv__EnableWorksystem_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__srv__EnableWorksystem_Request * data = NULL;

  if (size) {
    data = (cg_msgs__srv__EnableWorksystem_Request *)allocator.zero_allocate(size, sizeof(cg_msgs__srv__EnableWorksystem_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__srv__EnableWorksystem_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__srv__EnableWorksystem_Request__fini(&data[i - 1]);
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
cg_msgs__srv__EnableWorksystem_Request__Sequence__fini(cg_msgs__srv__EnableWorksystem_Request__Sequence * array)
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
      cg_msgs__srv__EnableWorksystem_Request__fini(&array->data[i]);
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

cg_msgs__srv__EnableWorksystem_Request__Sequence *
cg_msgs__srv__EnableWorksystem_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__srv__EnableWorksystem_Request__Sequence * array = (cg_msgs__srv__EnableWorksystem_Request__Sequence *)allocator.allocate(sizeof(cg_msgs__srv__EnableWorksystem_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__srv__EnableWorksystem_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__srv__EnableWorksystem_Request__Sequence__destroy(cg_msgs__srv__EnableWorksystem_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__srv__EnableWorksystem_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__srv__EnableWorksystem_Request__Sequence__are_equal(const cg_msgs__srv__EnableWorksystem_Request__Sequence * lhs, const cg_msgs__srv__EnableWorksystem_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__srv__EnableWorksystem_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__srv__EnableWorksystem_Request__Sequence__copy(
  const cg_msgs__srv__EnableWorksystem_Request__Sequence * input,
  cg_msgs__srv__EnableWorksystem_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__srv__EnableWorksystem_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__srv__EnableWorksystem_Request * data =
      (cg_msgs__srv__EnableWorksystem_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__srv__EnableWorksystem_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__srv__EnableWorksystem_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__srv__EnableWorksystem_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cg_msgs__srv__EnableWorksystem_Response__init(cg_msgs__srv__EnableWorksystem_Response * msg)
{
  if (!msg) {
    return false;
  }
  // worksystem_enabled
  return true;
}

void
cg_msgs__srv__EnableWorksystem_Response__fini(cg_msgs__srv__EnableWorksystem_Response * msg)
{
  if (!msg) {
    return;
  }
  // worksystem_enabled
}

bool
cg_msgs__srv__EnableWorksystem_Response__are_equal(const cg_msgs__srv__EnableWorksystem_Response * lhs, const cg_msgs__srv__EnableWorksystem_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // worksystem_enabled
  if (lhs->worksystem_enabled != rhs->worksystem_enabled) {
    return false;
  }
  return true;
}

bool
cg_msgs__srv__EnableWorksystem_Response__copy(
  const cg_msgs__srv__EnableWorksystem_Response * input,
  cg_msgs__srv__EnableWorksystem_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // worksystem_enabled
  output->worksystem_enabled = input->worksystem_enabled;
  return true;
}

cg_msgs__srv__EnableWorksystem_Response *
cg_msgs__srv__EnableWorksystem_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__srv__EnableWorksystem_Response * msg = (cg_msgs__srv__EnableWorksystem_Response *)allocator.allocate(sizeof(cg_msgs__srv__EnableWorksystem_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cg_msgs__srv__EnableWorksystem_Response));
  bool success = cg_msgs__srv__EnableWorksystem_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cg_msgs__srv__EnableWorksystem_Response__destroy(cg_msgs__srv__EnableWorksystem_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cg_msgs__srv__EnableWorksystem_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cg_msgs__srv__EnableWorksystem_Response__Sequence__init(cg_msgs__srv__EnableWorksystem_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__srv__EnableWorksystem_Response * data = NULL;

  if (size) {
    data = (cg_msgs__srv__EnableWorksystem_Response *)allocator.zero_allocate(size, sizeof(cg_msgs__srv__EnableWorksystem_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cg_msgs__srv__EnableWorksystem_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cg_msgs__srv__EnableWorksystem_Response__fini(&data[i - 1]);
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
cg_msgs__srv__EnableWorksystem_Response__Sequence__fini(cg_msgs__srv__EnableWorksystem_Response__Sequence * array)
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
      cg_msgs__srv__EnableWorksystem_Response__fini(&array->data[i]);
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

cg_msgs__srv__EnableWorksystem_Response__Sequence *
cg_msgs__srv__EnableWorksystem_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cg_msgs__srv__EnableWorksystem_Response__Sequence * array = (cg_msgs__srv__EnableWorksystem_Response__Sequence *)allocator.allocate(sizeof(cg_msgs__srv__EnableWorksystem_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cg_msgs__srv__EnableWorksystem_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cg_msgs__srv__EnableWorksystem_Response__Sequence__destroy(cg_msgs__srv__EnableWorksystem_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cg_msgs__srv__EnableWorksystem_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cg_msgs__srv__EnableWorksystem_Response__Sequence__are_equal(const cg_msgs__srv__EnableWorksystem_Response__Sequence * lhs, const cg_msgs__srv__EnableWorksystem_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cg_msgs__srv__EnableWorksystem_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cg_msgs__srv__EnableWorksystem_Response__Sequence__copy(
  const cg_msgs__srv__EnableWorksystem_Response__Sequence * input,
  cg_msgs__srv__EnableWorksystem_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cg_msgs__srv__EnableWorksystem_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cg_msgs__srv__EnableWorksystem_Response * data =
      (cg_msgs__srv__EnableWorksystem_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cg_msgs__srv__EnableWorksystem_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cg_msgs__srv__EnableWorksystem_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cg_msgs__srv__EnableWorksystem_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
