// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice
#include "apf_interfaces/msg/detail/distance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `end_point`
// Member `direction_vector`
// Member `target_point`
// Member `end_angle_distance`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
apf_interfaces__msg__Distance__init(apf_interfaces__msg__Distance * msg)
{
  if (!msg) {
    return false;
  }
  // end_point
  if (!geometry_msgs__msg__Point__init(&msg->end_point)) {
    apf_interfaces__msg__Distance__fini(msg);
    return false;
  }
  // direction_vector
  if (!geometry_msgs__msg__Point__init(&msg->direction_vector)) {
    apf_interfaces__msg__Distance__fini(msg);
    return false;
  }
  // target_point
  if (!geometry_msgs__msg__Point__init(&msg->target_point)) {
    apf_interfaces__msg__Distance__fini(msg);
    return false;
  }
  // end_distance
  // end_angle_distance
  if (!geometry_msgs__msg__Point__init(&msg->end_angle_distance)) {
    apf_interfaces__msg__Distance__fini(msg);
    return false;
  }
  return true;
}

void
apf_interfaces__msg__Distance__fini(apf_interfaces__msg__Distance * msg)
{
  if (!msg) {
    return;
  }
  // end_point
  geometry_msgs__msg__Point__fini(&msg->end_point);
  // direction_vector
  geometry_msgs__msg__Point__fini(&msg->direction_vector);
  // target_point
  geometry_msgs__msg__Point__fini(&msg->target_point);
  // end_distance
  // end_angle_distance
  geometry_msgs__msg__Point__fini(&msg->end_angle_distance);
}

bool
apf_interfaces__msg__Distance__are_equal(const apf_interfaces__msg__Distance * lhs, const apf_interfaces__msg__Distance * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // end_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->end_point), &(rhs->end_point)))
  {
    return false;
  }
  // direction_vector
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->direction_vector), &(rhs->direction_vector)))
  {
    return false;
  }
  // target_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target_point), &(rhs->target_point)))
  {
    return false;
  }
  // end_distance
  if (lhs->end_distance != rhs->end_distance) {
    return false;
  }
  // end_angle_distance
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->end_angle_distance), &(rhs->end_angle_distance)))
  {
    return false;
  }
  return true;
}

bool
apf_interfaces__msg__Distance__copy(
  const apf_interfaces__msg__Distance * input,
  apf_interfaces__msg__Distance * output)
{
  if (!input || !output) {
    return false;
  }
  // end_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->end_point), &(output->end_point)))
  {
    return false;
  }
  // direction_vector
  if (!geometry_msgs__msg__Point__copy(
      &(input->direction_vector), &(output->direction_vector)))
  {
    return false;
  }
  // target_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->target_point), &(output->target_point)))
  {
    return false;
  }
  // end_distance
  output->end_distance = input->end_distance;
  // end_angle_distance
  if (!geometry_msgs__msg__Point__copy(
      &(input->end_angle_distance), &(output->end_angle_distance)))
  {
    return false;
  }
  return true;
}

apf_interfaces__msg__Distance *
apf_interfaces__msg__Distance__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__msg__Distance * msg = (apf_interfaces__msg__Distance *)allocator.allocate(sizeof(apf_interfaces__msg__Distance), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(apf_interfaces__msg__Distance));
  bool success = apf_interfaces__msg__Distance__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
apf_interfaces__msg__Distance__destroy(apf_interfaces__msg__Distance * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    apf_interfaces__msg__Distance__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
apf_interfaces__msg__Distance__Sequence__init(apf_interfaces__msg__Distance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__msg__Distance * data = NULL;

  if (size) {
    data = (apf_interfaces__msg__Distance *)allocator.zero_allocate(size, sizeof(apf_interfaces__msg__Distance), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = apf_interfaces__msg__Distance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        apf_interfaces__msg__Distance__fini(&data[i - 1]);
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
apf_interfaces__msg__Distance__Sequence__fini(apf_interfaces__msg__Distance__Sequence * array)
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
      apf_interfaces__msg__Distance__fini(&array->data[i]);
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

apf_interfaces__msg__Distance__Sequence *
apf_interfaces__msg__Distance__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  apf_interfaces__msg__Distance__Sequence * array = (apf_interfaces__msg__Distance__Sequence *)allocator.allocate(sizeof(apf_interfaces__msg__Distance__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = apf_interfaces__msg__Distance__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
apf_interfaces__msg__Distance__Sequence__destroy(apf_interfaces__msg__Distance__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    apf_interfaces__msg__Distance__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
apf_interfaces__msg__Distance__Sequence__are_equal(const apf_interfaces__msg__Distance__Sequence * lhs, const apf_interfaces__msg__Distance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!apf_interfaces__msg__Distance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
apf_interfaces__msg__Distance__Sequence__copy(
  const apf_interfaces__msg__Distance__Sequence * input,
  apf_interfaces__msg__Distance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(apf_interfaces__msg__Distance);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    apf_interfaces__msg__Distance * data =
      (apf_interfaces__msg__Distance *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!apf_interfaces__msg__Distance__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          apf_interfaces__msg__Distance__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!apf_interfaces__msg__Distance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
