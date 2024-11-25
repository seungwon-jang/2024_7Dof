// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__JACOBIAN__STRUCT_H_
#define APF_INTERFACES__MSG__DETAIL__JACOBIAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'flat_jacobian'
// Member 'flat_jacobian5'
// Member 'flat_jacobian3'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Jacobian in the package apf_interfaces.
typedef struct apf_interfaces__msg__Jacobian
{
  rosidl_runtime_c__double__Sequence flat_jacobian;
  int32_t col_num;
  rosidl_runtime_c__double__Sequence flat_jacobian5;
  int32_t col_num5;
  rosidl_runtime_c__double__Sequence flat_jacobian3;
  int32_t col_num3;
} apf_interfaces__msg__Jacobian;

// Struct for a sequence of apf_interfaces__msg__Jacobian.
typedef struct apf_interfaces__msg__Jacobian__Sequence
{
  apf_interfaces__msg__Jacobian * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} apf_interfaces__msg__Jacobian__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // APF_INTERFACES__MSG__DETAIL__JACOBIAN__STRUCT_H_
