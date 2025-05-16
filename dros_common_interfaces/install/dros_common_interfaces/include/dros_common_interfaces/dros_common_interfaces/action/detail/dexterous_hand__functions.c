// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dros_common_interfaces:action/DexterousHand.idl
// generated code does not contain a copyright notice
#include "dros_common_interfaces/action/detail/dexterous_hand__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `obj_name`
#include "rosidl_runtime_c/string_functions.h"

bool
dros_common_interfaces__action__DexterousHand_Goal__init(dros_common_interfaces__action__DexterousHand_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target_position
  // obj_name
  if (!rosidl_runtime_c__String__init(&msg->obj_name)) {
    dros_common_interfaces__action__DexterousHand_Goal__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_Goal__fini(dros_common_interfaces__action__DexterousHand_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target_position
  // obj_name
  rosidl_runtime_c__String__fini(&msg->obj_name);
}

bool
dros_common_interfaces__action__DexterousHand_Goal__are_equal(const dros_common_interfaces__action__DexterousHand_Goal * lhs, const dros_common_interfaces__action__DexterousHand_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_position
  if (lhs->target_position != rhs->target_position) {
    return false;
  }
  // obj_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->obj_name), &(rhs->obj_name)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_Goal__copy(
  const dros_common_interfaces__action__DexterousHand_Goal * input,
  dros_common_interfaces__action__DexterousHand_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target_position
  output->target_position = input->target_position;
  // obj_name
  if (!rosidl_runtime_c__String__copy(
      &(input->obj_name), &(output->obj_name)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__action__DexterousHand_Goal *
dros_common_interfaces__action__DexterousHand_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Goal * msg = (dros_common_interfaces__action__DexterousHand_Goal *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_Goal));
  bool success = dros_common_interfaces__action__DexterousHand_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_Goal__destroy(dros_common_interfaces__action__DexterousHand_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_Goal__Sequence__init(dros_common_interfaces__action__DexterousHand_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Goal * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_Goal *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_Goal__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_Goal__Sequence__fini(dros_common_interfaces__action__DexterousHand_Goal__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_Goal__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_Goal__Sequence *
dros_common_interfaces__action__DexterousHand_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Goal__Sequence * array = (dros_common_interfaces__action__DexterousHand_Goal__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_Goal__Sequence__destroy(dros_common_interfaces__action__DexterousHand_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_Goal__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_Goal__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_Goal__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_Goal__Sequence * input,
  dros_common_interfaces__action__DexterousHand_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_Goal * data =
      (dros_common_interfaces__action__DexterousHand_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `msg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
dros_common_interfaces__action__DexterousHand_Result__init(dros_common_interfaces__action__DexterousHand_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // msg
  if (!rosidl_runtime_c__String__init(&msg->msg)) {
    dros_common_interfaces__action__DexterousHand_Result__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_Result__fini(dros_common_interfaces__action__DexterousHand_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // msg
  rosidl_runtime_c__String__fini(&msg->msg);
}

bool
dros_common_interfaces__action__DexterousHand_Result__are_equal(const dros_common_interfaces__action__DexterousHand_Result * lhs, const dros_common_interfaces__action__DexterousHand_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg), &(rhs->msg)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_Result__copy(
  const dros_common_interfaces__action__DexterousHand_Result * input,
  dros_common_interfaces__action__DexterousHand_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // msg
  if (!rosidl_runtime_c__String__copy(
      &(input->msg), &(output->msg)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__action__DexterousHand_Result *
dros_common_interfaces__action__DexterousHand_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Result * msg = (dros_common_interfaces__action__DexterousHand_Result *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_Result));
  bool success = dros_common_interfaces__action__DexterousHand_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_Result__destroy(dros_common_interfaces__action__DexterousHand_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_Result__Sequence__init(dros_common_interfaces__action__DexterousHand_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Result * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_Result *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_Result__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_Result__Sequence__fini(dros_common_interfaces__action__DexterousHand_Result__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_Result__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_Result__Sequence *
dros_common_interfaces__action__DexterousHand_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Result__Sequence * array = (dros_common_interfaces__action__DexterousHand_Result__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_Result__Sequence__destroy(dros_common_interfaces__action__DexterousHand_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_Result__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_Result__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_Result__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_Result__Sequence * input,
  dros_common_interfaces__action__DexterousHand_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_Result * data =
      (dros_common_interfaces__action__DexterousHand_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
dros_common_interfaces__action__DexterousHand_Feedback__init(dros_common_interfaces__action__DexterousHand_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  return true;
}

void
dros_common_interfaces__action__DexterousHand_Feedback__fini(dros_common_interfaces__action__DexterousHand_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // progress
}

bool
dros_common_interfaces__action__DexterousHand_Feedback__are_equal(const dros_common_interfaces__action__DexterousHand_Feedback * lhs, const dros_common_interfaces__action__DexterousHand_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_Feedback__copy(
  const dros_common_interfaces__action__DexterousHand_Feedback * input,
  dros_common_interfaces__action__DexterousHand_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  output->progress = input->progress;
  return true;
}

dros_common_interfaces__action__DexterousHand_Feedback *
dros_common_interfaces__action__DexterousHand_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Feedback * msg = (dros_common_interfaces__action__DexterousHand_Feedback *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_Feedback));
  bool success = dros_common_interfaces__action__DexterousHand_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_Feedback__destroy(dros_common_interfaces__action__DexterousHand_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__init(dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Feedback * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_Feedback *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_Feedback__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__fini(dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_Feedback__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_Feedback__Sequence *
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array = (dros_common_interfaces__action__DexterousHand_Feedback__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__destroy(dros_common_interfaces__action__DexterousHand_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_Feedback__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_Feedback__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_Feedback__Sequence * input,
  dros_common_interfaces__action__DexterousHand_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_Feedback * data =
      (dros_common_interfaces__action__DexterousHand_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_Feedback__copy(
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
// #include "dros_common_interfaces/action/detail/dexterous_hand__functions.h"

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__init(dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!dros_common_interfaces__action__DexterousHand_Goal__init(&msg->goal)) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  dros_common_interfaces__action__DexterousHand_Goal__fini(&msg->goal);
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Request * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Request * rhs)
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
  if (!dros_common_interfaces__action__DexterousHand_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Request * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Request * output)
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
  if (!dros_common_interfaces__action__DexterousHand_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__action__DexterousHand_SendGoal_Request *
dros_common_interfaces__action__DexterousHand_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg = (dros_common_interfaces__action__DexterousHand_SendGoal_Request *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Request));
  bool success = dros_common_interfaces__action__DexterousHand_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__init(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_SendGoal_Request * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_SendGoal_Request *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence *
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array = (dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_SendGoal_Request * data =
      (dros_common_interfaces__action__DexterousHand_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_SendGoal_Request__copy(
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
dros_common_interfaces__action__DexterousHand_SendGoal_Response__init(dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Response * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Response * rhs)
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
dros_common_interfaces__action__DexterousHand_SendGoal_Response__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Response * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Response * output)
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

dros_common_interfaces__action__DexterousHand_SendGoal_Response *
dros_common_interfaces__action__DexterousHand_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg = (dros_common_interfaces__action__DexterousHand_SendGoal_Response *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Response));
  bool success = dros_common_interfaces__action__DexterousHand_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__init(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_SendGoal_Response * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_SendGoal_Response *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__fini(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence *
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array = (dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__destroy(dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * input,
  dros_common_interfaces__action__DexterousHand_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_SendGoal_Response * data =
      (dros_common_interfaces__action__DexterousHand_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_SendGoal_Response__copy(
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
dros_common_interfaces__action__DexterousHand_GetResult_Request__init(dros_common_interfaces__action__DexterousHand_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(dros_common_interfaces__action__DexterousHand_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Request * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Request * rhs)
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
dros_common_interfaces__action__DexterousHand_GetResult_Request__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Request * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Request * output)
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

dros_common_interfaces__action__DexterousHand_GetResult_Request *
dros_common_interfaces__action__DexterousHand_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_GetResult_Request * msg = (dros_common_interfaces__action__DexterousHand_GetResult_Request *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Request));
  bool success = dros_common_interfaces__action__DexterousHand_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_GetResult_Request__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__init(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_GetResult_Request * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_GetResult_Request *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__fini(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence *
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array = (dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_GetResult_Request * data =
      (dros_common_interfaces__action__DexterousHand_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_GetResult_Request__copy(
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
// #include "dros_common_interfaces/action/detail/dexterous_hand__functions.h"

bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__init(dros_common_interfaces__action__DexterousHand_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!dros_common_interfaces__action__DexterousHand_Result__init(&msg->result)) {
    dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(dros_common_interfaces__action__DexterousHand_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  dros_common_interfaces__action__DexterousHand_Result__fini(&msg->result);
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Response * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!dros_common_interfaces__action__DexterousHand_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Response * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!dros_common_interfaces__action__DexterousHand_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__action__DexterousHand_GetResult_Response *
dros_common_interfaces__action__DexterousHand_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_GetResult_Response * msg = (dros_common_interfaces__action__DexterousHand_GetResult_Response *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Response));
  bool success = dros_common_interfaces__action__DexterousHand_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_GetResult_Response__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__init(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_GetResult_Response * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_GetResult_Response *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__fini(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence *
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array = (dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__destroy(dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * input,
  dros_common_interfaces__action__DexterousHand_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_GetResult_Response * data =
      (dros_common_interfaces__action__DexterousHand_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_GetResult_Response__copy(
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
// #include "dros_common_interfaces/action/detail/dexterous_hand__functions.h"

bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__init(dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!dros_common_interfaces__action__DexterousHand_Feedback__init(&msg->feedback)) {
    dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  dros_common_interfaces__action__DexterousHand_Feedback__fini(&msg->feedback);
}

bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__are_equal(const dros_common_interfaces__action__DexterousHand_FeedbackMessage * lhs, const dros_common_interfaces__action__DexterousHand_FeedbackMessage * rhs)
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
  if (!dros_common_interfaces__action__DexterousHand_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__copy(
  const dros_common_interfaces__action__DexterousHand_FeedbackMessage * input,
  dros_common_interfaces__action__DexterousHand_FeedbackMessage * output)
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
  if (!dros_common_interfaces__action__DexterousHand_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

dros_common_interfaces__action__DexterousHand_FeedbackMessage *
dros_common_interfaces__action__DexterousHand_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg = (dros_common_interfaces__action__DexterousHand_FeedbackMessage *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dros_common_interfaces__action__DexterousHand_FeedbackMessage));
  bool success = dros_common_interfaces__action__DexterousHand_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__destroy(dros_common_interfaces__action__DexterousHand_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__init(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_FeedbackMessage * data = NULL;

  if (size) {
    data = (dros_common_interfaces__action__DexterousHand_FeedbackMessage *)allocator.zero_allocate(size, sizeof(dros_common_interfaces__action__DexterousHand_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dros_common_interfaces__action__DexterousHand_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(&data[i - 1]);
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
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__fini(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array)
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
      dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(&array->data[i]);
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

dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence *
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array = (dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence *)allocator.allocate(sizeof(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__destroy(dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__are_equal(const dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * lhs, const dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence__copy(
  const dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * input,
  dros_common_interfaces__action__DexterousHand_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dros_common_interfaces__action__DexterousHand_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dros_common_interfaces__action__DexterousHand_FeedbackMessage * data =
      (dros_common_interfaces__action__DexterousHand_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dros_common_interfaces__action__DexterousHand_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dros_common_interfaces__action__DexterousHand_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dros_common_interfaces__action__DexterousHand_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
