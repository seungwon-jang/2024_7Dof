// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice
#include "apf_interfaces/msg/detail/jacobian__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `flat_jacobian`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
apf_interfaces__msg__Jacobian__init(apf_interfaces__msg__Jacobian * msg)
{
  if (!msg) {
    return false;
  }
  // flat_jacobian
  if (!rosidl_runtime_c__double__Sequence__init(&msg->flat_jacobian, 0)) {
    apf_interfaces__msg__Jacobian__fini(msg);
    return false;
  }
  // col_num
  return true;
}

void
apf_interfaces__msg__Jacobian__fini(apf_interfaces__msg__Jacobian * msg)
{
  if (!msg) {
    return;
  }
  // flat_jacobian
  rosidl_runtime_c__double__Sequence__fini(&msg->flat_jacobian);
  // col_num
}

bool
apf_interfaces__msg__Jacobian__are_equal(const apf_interfaces__msg__Jacobian * lhs, const apf_interfaces__msg__Jacobian * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // flat_jacobian
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->flat_jacobian), &(rhs->flat_jacobian)))
  {
    return false;
  }
  // col_num
  if (lhs->col_num != rhs->col_num) {
    return false;
  }
  return true;
}

bool
apf_interfaces__msg__Jacobian__copy(
  const apf_interfaces__msg__Jacobian * input,
  apf_interfaces__msg__Jacobian * output)
{
  if (!input || !output) {
    return false;
  }
  // flat_jacobian
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->flat_jacobian), &(output->flat_jacobian)))
  {
    return false;
  }
  // col_num
  output->col_num = input->col_num;
  return true;
}

apf_interfaces__msg__Jacobian *
apf_interfaces__msg__Jacobian__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__msg__Jacobian * msg = (apf_interfaces__msg__Jacobian *)allocator.allocate(sizeof(apf_interfaces__msg__Jacobian), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(apf_interfaces__msg__Jacobian));
  bool success = apf_interfaces__msg__Jacobian__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
apf_interfaces__msg__Jacobian__destroy(apf_interfaces__msg__Jacobian * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    apf_interfaces__msg__Jacobian__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
apf_interfaces__msg__Jacobian__Sequence__init(apf_interfaces__msg__Jacobian__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__msg__Jacobian * data = NULL;

  if (size) {
    data = (apf_interfaces__msg__Jacobian *)allocator.zero_allocate(size, sizeof(apf_interfaces__msg__Jacobian), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = apf_interfaces__msg__Jacobian__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        apf_interfaces__msg__Jacobian__fini(&data[i - 1]);
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
apf_interfaces__msg__Jacobian__Sequence__fini(apf_interfaces__msg__Jacobian__Sequence * array)
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
      apf_interfaces__msg__Jacobian__fini(&array->data[i]);
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

apf_interfaces__msg__Jacobian__Sequence *
apf_interfaces__msg__Jacobian__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__msg__Jacobian__Sequence * array = (apf_interfaces__msg__Jacobian__Sequence *)allocator.allocate(sizeof(apf_interfaces__msg__Jacobian__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = apf_interfaces__msg__Jacobian__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
apf_interfaces__msg__Jacobian__Sequence__destroy(apf_interfaces__msg__Jacobian__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    apf_interfaces__msg__Jacobian__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
apf_interfaces__msg__Jacobian__Sequence__are_equal(const apf_interfaces__msg__Jacobian__Sequence * lhs, const apf_interfaces__msg__Jacobian__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!apf_interfaces__msg__Jacobian__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
apf_interfaces__msg__Jacobian__Sequence__copy(
  const apf_interfaces__msg__Jacobian__Sequence * input,
  apf_interfaces__msg__Jacobian__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(apf_interfaces__msg__Jacobian);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    apf_interfaces__msg__Jacobian * data =
      (apf_interfaces__msg__Jacobian *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!apf_interfaces__msg__Jacobian__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          apf_interfaces__msg__Jacobian__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!apf_interfaces__msg__Jacobian__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
