// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_H_
#define APF_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'end_point'
// Member 'direction_vector'
// Member 'target_point'
// Member 'end_angle_distance'
// Member 'obstacle_direction_vector'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'obstacle_distance'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Distance in the package apf_interfaces.
typedef struct apf_interfaces__msg__Distance
{
  geometry_msgs__msg__Point end_point;
  geometry_msgs__msg__Point direction_vector;
  geometry_msgs__msg__Point target_point;
  double end_distance;
  geometry_msgs__msg__Point end_angle_distance;
  rosidl_runtime_c__double__Sequence obstacle_distance;
  geometry_msgs__msg__Point__Sequence obstacle_direction_vector;
  int32_t obstacle_count;
  int32_t link_count;
} apf_interfaces__msg__Distance;

// Struct for a sequence of apf_interfaces__msg__Distance.
typedef struct apf_interfaces__msg__Distance__Sequence
{
  apf_interfaces__msg__Distance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} apf_interfaces__msg__Distance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // APF_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_H_
