// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice
#include "apf_interfaces/srv/detail/rrts_points__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `obstacle_points`
// Member `start_point`
// Member `end_point`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
apf_interfaces__srv__RRTSPoints_Request__init(apf_interfaces__srv__RRTSPoints_Request * msg)
{
  if (!msg) {
    return false;
  }
  // obstacle_points
  if (!rosidl_runtime_c__double__Sequence__init(&msg->obstacle_points, 0)) {
    apf_interfaces__srv__RRTSPoints_Request__fini(msg);
    return false;
  }
  // obstacle_count
  // start_point
  if (!rosidl_runtime_c__double__Sequence__init(&msg->start_point, 0)) {
    apf_interfaces__srv__RRTSPoints_Request__fini(msg);
    return false;
  }
  // end_point
  if (!rosidl_runtime_c__double__Sequence__init(&msg->end_point, 0)) {
    apf_interfaces__srv__RRTSPoints_Request__fini(msg);
    return false;
  }
  return true;
}

void
apf_interfaces__srv__RRTSPoints_Request__fini(apf_interfaces__srv__RRTSPoints_Request * msg)
{
  if (!msg) {
    return;
  }
  // obstacle_points
  rosidl_runtime_c__double__Sequence__fini(&msg->obstacle_points);
  // obstacle_count
  // start_point
  rosidl_runtime_c__double__Sequence__fini(&msg->start_point);
  // end_point
  rosidl_runtime_c__double__Sequence__fini(&msg->end_point);
}

bool
apf_interfaces__srv__RRTSPoints_Request__are_equal(const apf_interfaces__srv__RRTSPoints_Request * lhs, const apf_interfaces__srv__RRTSPoints_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // obstacle_points
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->obstacle_points), &(rhs->obstacle_points)))
  {
    return false;
  }
  // obstacle_count
  if (lhs->obstacle_count != rhs->obstacle_count) {
    return false;
  }
  // start_point
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->start_point), &(rhs->start_point)))
  {
    return false;
  }
  // end_point
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->end_point), &(rhs->end_point)))
  {
    return false;
  }
  return true;
}

bool
apf_interfaces__srv__RRTSPoints_Request__copy(
  const apf_interfaces__srv__RRTSPoints_Request * input,
  apf_interfaces__srv__RRTSPoints_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // obstacle_points
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->obstacle_points), &(output->obstacle_points)))
  {
    return false;
  }
  // obstacle_count
  output->obstacle_count = input->obstacle_count;
  // start_point
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->start_point), &(output->start_point)))
  {
    return false;
  }
  // end_point
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->end_point), &(output->end_point)))
  {
    return false;
  }
  return true;
}

apf_interfaces__srv__RRTSPoints_Request *
apf_interfaces__srv__RRTSPoints_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__srv__RRTSPoints_Request * msg = (apf_interfaces__srv__RRTSPoints_Request *)allocator.allocate(sizeof(apf_interfaces__srv__RRTSPoints_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(apf_interfaces__srv__RRTSPoints_Request));
  bool success = apf_interfaces__srv__RRTSPoints_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
apf_interfaces__srv__RRTSPoints_Request__destroy(apf_interfaces__srv__RRTSPoints_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    apf_interfaces__srv__RRTSPoints_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
apf_interfaces__srv__RRTSPoints_Request__Sequence__init(apf_interfaces__srv__RRTSPoints_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__srv__RRTSPoints_Request * data = NULL;

  if (size) {
    data = (apf_interfaces__srv__RRTSPoints_Request *)allocator.zero_allocate(size, sizeof(apf_interfaces__srv__RRTSPoints_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = apf_interfaces__srv__RRTSPoints_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        apf_interfaces__srv__RRTSPoints_Request__fini(&data[i - 1]);
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
apf_interfaces__srv__RRTSPoints_Request__Sequence__fini(apf_interfaces__srv__RRTSPoints_Request__Sequence * array)
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
      apf_interfaces__srv__RRTSPoints_Request__fini(&array->data[i]);
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

apf_interfaces__srv__RRTSPoints_Request__Sequence *
apf_interfaces__srv__RRTSPoints_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__srv__RRTSPoints_Request__Sequence * array = (apf_interfaces__srv__RRTSPoints_Request__Sequence *)allocator.allocate(sizeof(apf_interfaces__srv__RRTSPoints_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = apf_interfaces__srv__RRTSPoints_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
apf_interfaces__srv__RRTSPoints_Request__Sequence__destroy(apf_interfaces__srv__RRTSPoints_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    apf_interfaces__srv__RRTSPoints_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
apf_interfaces__srv__RRTSPoints_Request__Sequence__are_equal(const apf_interfaces__srv__RRTSPoints_Request__Sequence * lhs, const apf_interfaces__srv__RRTSPoints_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!apf_interfaces__srv__RRTSPoints_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
apf_interfaces__srv__RRTSPoints_Request__Sequence__copy(
  const apf_interfaces__srv__RRTSPoints_Request__Sequence * input,
  apf_interfaces__srv__RRTSPoints_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(apf_interfaces__srv__RRTSPoints_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    apf_interfaces__srv__RRTSPoints_Request * data =
      (apf_interfaces__srv__RRTSPoints_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!apf_interfaces__srv__RRTSPoints_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          apf_interfaces__srv__RRTSPoints_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!apf_interfaces__srv__RRTSPoints_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result_points`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
apf_interfaces__srv__RRTSPoints_Response__init(apf_interfaces__srv__RRTSPoints_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result_points
  if (!rosidl_runtime_c__double__Sequence__init(&msg->result_points, 0)) {
    apf_interfaces__srv__RRTSPoints_Response__fini(msg);
    return false;
  }
  // point_count
  return true;
}

void
apf_interfaces__srv__RRTSPoints_Response__fini(apf_interfaces__srv__RRTSPoints_Response * msg)
{
  if (!msg) {
    return;
  }
  // result_points
  rosidl_runtime_c__double__Sequence__fini(&msg->result_points);
  // point_count
}

bool
apf_interfaces__srv__RRTSPoints_Response__are_equal(const apf_interfaces__srv__RRTSPoints_Response * lhs, const apf_interfaces__srv__RRTSPoints_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result_points
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->result_points), &(rhs->result_points)))
  {
    return false;
  }
  // point_count
  if (lhs->point_count != rhs->point_count) {
    return false;
  }
  return true;
}

bool
apf_interfaces__srv__RRTSPoints_Response__copy(
  const apf_interfaces__srv__RRTSPoints_Response * input,
  apf_interfaces__srv__RRTSPoints_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result_points
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->result_points), &(output->result_points)))
  {
    return false;
  }
  // point_count
  output->point_count = input->point_count;
  return true;
}

apf_interfaces__srv__RRTSPoints_Response *
apf_interfaces__srv__RRTSPoints_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__srv__RRTSPoints_Response * msg = (apf_interfaces__srv__RRTSPoints_Response *)allocator.allocate(sizeof(apf_interfaces__srv__RRTSPoints_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(apf_interfaces__srv__RRTSPoints_Response));
  bool success = apf_interfaces__srv__RRTSPoints_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
apf_interfaces__srv__RRTSPoints_Response__destroy(apf_interfaces__srv__RRTSPoints_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    apf_interfaces__srv__RRTSPoints_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
apf_interfaces__srv__RRTSPoints_Response__Sequence__init(apf_interfaces__srv__RRTSPoints_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__srv__RRTSPoints_Response * data = NULL;

  if (size) {
    data = (apf_interfaces__srv__RRTSPoints_Response *)allocator.zero_allocate(size, sizeof(apf_interfaces__srv__RRTSPoints_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = apf_interfaces__srv__RRTSPoints_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        apf_interfaces__srv__RRTSPoints_Response__fini(&data[i - 1]);
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
apf_interfaces__srv__RRTSPoints_Response__Sequence__fini(apf_interfaces__srv__RRTSPoints_Response__Sequence * array)
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
      apf_interfaces__srv__RRTSPoints_Response__fini(&array->data[i]);
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

apf_interfaces__srv__RRTSPoints_Response__Sequence *
apf_interfaces__srv__RRTSPoints_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__srv__RRTSPoints_Response__Sequence * array = (apf_interfaces__srv__RRTSPoints_Response__Sequence *)allocator.allocate(sizeof(apf_interfaces__srv__RRTSPoints_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = apf_interfaces__srv__RRTSPoints_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
apf_interfaces__srv__RRTSPoints_Response__Sequence__destroy(apf_interfaces__srv__RRTSPoints_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    apf_interfaces__srv__RRTSPoints_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
apf_interfaces__srv__RRTSPoints_Response__Sequence__are_equal(const apf_interfaces__srv__RRTSPoints_Response__Sequence * lhs, const apf_interfaces__srv__RRTSPoints_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!apf_interfaces__srv__RRTSPoints_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
apf_interfaces__srv__RRTSPoints_Response__Sequence__copy(
  const apf_interfaces__srv__RRTSPoints_Response__Sequence * input,
  apf_interfaces__srv__RRTSPoints_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(apf_interfaces__srv__RRTSPoints_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    apf_interfaces__srv__RRTSPoints_Response * data =
      (apf_interfaces__srv__RRTSPoints_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!apf_interfaces__srv__RRTSPoints_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          apf_interfaces__srv__RRTSPoints_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!apf_interfaces__srv__RRTSPoints_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
