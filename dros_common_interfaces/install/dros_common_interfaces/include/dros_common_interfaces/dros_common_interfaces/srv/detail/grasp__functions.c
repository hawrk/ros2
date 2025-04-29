// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dros_common_interfaces:srv/Grasp.idl
// generated code does not contain a copyright notice
#include "dros_common_interfaces/srv/detail/grasp__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `object_name`
#include "rosidl_runtime_c/string_functions.h"

bool
dros_common_interfaces__srv__Grasp_Request__init(dros_common_interfaces__srv__Grasp_Request * msg)
{
  if (!msg) {
    return false;
  }
  // object_name
  if (!rosidl_runtime_c__String__init(&msg->object_name)) {
    dros_common_interfaces__srv__Grasp_Request__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__srv__Grasp_Request__fini(dros_common_interfaces__srv__Grasp_Request * msg)
{
  if (!msg) {
    return;
  }
  // object_name
  rosidl_runtime_c__String__fini(&msg->object_name);
}

bool
dros_common_interfaces__srv__Grasp_Request__are_equal(const dros_common_interfaces__srv__Grasp_Request * lhs, const dros_common_interfaces__srv__Grasp_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // object_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object_name), &(rhs->object_name)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__srv__Grasp_Request__copy(
  const dros_common_interfaces__srv__Grasp_Request * input,
  dros_common_interfaces__srv__Grasp_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // object_name
  if (!rosidl_runtime_c__String__copy(
      &(input->object_name), &(output->object_name)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__srv__Grasp_Request *
dros_common_interfaces__srv__Grasp_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__srv__Grasp_Request * msg = (dros_common_interfaces__srv__Grasp_Request *)allocator.allocate(sizeof(dros_common_interfaces__srv__Grasp_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__srv__Grasp_Request));
  bool success = dros_common_interfaces__srv__Grasp_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__srv__Grasp_Request__destroy(dros_common_interfaces__srv__Grasp_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__srv__Grasp_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__srv__Grasp_Request__Sequence__init(dros_common_interfaces__srv__Grasp_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__srv__Grasp_Request * data = NULL;

  if (size) {
    data = (dros_common_interfaces__srv__Grasp_Request *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__srv__Grasp_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__srv__Grasp_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__srv__Grasp_Request__fini(&data[i - 1]);
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
dros_common_interfaces__srv__Grasp_Request__Sequence__fini(dros_common_interfaces__srv__Grasp_Request__Sequence * array)
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
      dros_common_interfaces__srv__Grasp_Request__fini(&array->data[i]);
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

dros_common_interfaces__srv__Grasp_Request__Sequence *
dros_common_interfaces__srv__Grasp_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__srv__Grasp_Request__Sequence * array = (dros_common_interfaces__srv__Grasp_Request__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__srv__Grasp_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__srv__Grasp_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__srv__Grasp_Request__Sequence__destroy(dros_common_interfaces__srv__Grasp_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__srv__Grasp_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__srv__Grasp_Request__Sequence__are_equal(const dros_common_interfaces__srv__Grasp_Request__Sequence * lhs, const dros_common_interfaces__srv__Grasp_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__srv__Grasp_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__srv__Grasp_Request__Sequence__copy(
  const dros_common_interfaces__srv__Grasp_Request__Sequence * input,
  dros_common_interfaces__srv__Grasp_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__srv__Grasp_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__srv__Grasp_Request * data =
      (dros_common_interfaces__srv__Grasp_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__srv__Grasp_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__srv__Grasp_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__srv__Grasp_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `err_msg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
dros_common_interfaces__srv__Grasp_Response__init(dros_common_interfaces__srv__Grasp_Response * msg)
{
  if (!msg) {
    return false;
  }
  // err_code
  // err_msg
  if (!rosidl_runtime_c__String__init(&msg->err_msg)) {
    dros_common_interfaces__srv__Grasp_Response__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__srv__Grasp_Response__fini(dros_common_interfaces__srv__Grasp_Response * msg)
{
  if (!msg) {
    return;
  }
  // err_code
  // err_msg
  rosidl_runtime_c__String__fini(&msg->err_msg);
}

bool
dros_common_interfaces__srv__Grasp_Response__are_equal(const dros_common_interfaces__srv__Grasp_Response * lhs, const dros_common_interfaces__srv__Grasp_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // err_code
  if (lhs->err_code != rhs->err_code) {
    return false;
  }
  // err_msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->err_msg), &(rhs->err_msg)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__srv__Grasp_Response__copy(
  const dros_common_interfaces__srv__Grasp_Response * input,
  dros_common_interfaces__srv__Grasp_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // err_code
  output->err_code = input->err_code;
  // err_msg
  if (!rosidl_runtime_c__String__copy(
      &(input->err_msg), &(output->err_msg)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__srv__Grasp_Response *
dros_common_interfaces__srv__Grasp_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__srv__Grasp_Response * msg = (dros_common_interfaces__srv__Grasp_Response *)allocator.allocate(sizeof(dros_common_interfaces__srv__Grasp_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__srv__Grasp_Response));
  bool success = dros_common_interfaces__srv__Grasp_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__srv__Grasp_Response__destroy(dros_common_interfaces__srv__Grasp_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__srv__Grasp_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__srv__Grasp_Response__Sequence__init(dros_common_interfaces__srv__Grasp_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__srv__Grasp_Response * data = NULL;

  if (size) {
    data = (dros_common_interfaces__srv__Grasp_Response *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__srv__Grasp_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__srv__Grasp_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__srv__Grasp_Response__fini(&data[i - 1]);
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
dros_common_interfaces__srv__Grasp_Response__Sequence__fini(dros_common_interfaces__srv__Grasp_Response__Sequence * array)
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
      dros_common_interfaces__srv__Grasp_Response__fini(&array->data[i]);
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

dros_common_interfaces__srv__Grasp_Response__Sequence *
dros_common_interfaces__srv__Grasp_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__srv__Grasp_Response__Sequence * array = (dros_common_interfaces__srv__Grasp_Response__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__srv__Grasp_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__srv__Grasp_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__srv__Grasp_Response__Sequence__destroy(dros_common_interfaces__srv__Grasp_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__srv__Grasp_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__srv__Grasp_Response__Sequence__are_equal(const dros_common_interfaces__srv__Grasp_Response__Sequence * lhs, const dros_common_interfaces__srv__Grasp_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__srv__Grasp_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__srv__Grasp_Response__Sequence__copy(
  const dros_common_interfaces__srv__Grasp_Response__Sequence * input,
  dros_common_interfaces__srv__Grasp_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__srv__Grasp_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__srv__Grasp_Response * data =
      (dros_common_interfaces__srv__Grasp_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__srv__Grasp_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__srv__Grasp_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__srv__Grasp_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
