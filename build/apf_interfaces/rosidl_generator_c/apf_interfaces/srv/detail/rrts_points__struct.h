// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__STRUCT_H_
#define APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'obstacle_points'
// Member 'start_point'
// Member 'end_point'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/RRTSPoints in the package apf_interfaces.
typedef struct apf_interfaces__srv__RRTSPoints_Request
{
  rosidl_runtime_c__double__Sequence obstacle_points;
  int64_t obstacle_count;
  /// 이거는 RRTs를 수행할 시작지점과 도착지점을 보낸다.
  /// (x,y,z,x,y,z,w)로 보낸다
  rosidl_runtime_c__double__Sequence start_point;
  rosidl_runtime_c__double__Sequence end_point;
} apf_interfaces__srv__RRTSPoints_Request;

// Struct for a sequence of apf_interfaces__srv__RRTSPoints_Request.
typedef struct apf_interfaces__srv__RRTSPoints_Request__Sequence
{
  apf_interfaces__srv__RRTSPoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} apf_interfaces__srv__RRTSPoints_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result_points'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/RRTSPoints in the package apf_interfaces.
typedef struct apf_interfaces__srv__RRTSPoints_Response
{
  /// RRTs를 통해 나온 목표 점들을 보낸다.
  /// 얘도 나중에 보간을 하면 (x,y,z,x,y,z,w)로 보낼 생각이다.
  rosidl_runtime_c__double__Sequence result_points;
  int64_t point_count;
} apf_interfaces__srv__RRTSPoints_Response;

// Struct for a sequence of apf_interfaces__srv__RRTSPoints_Response.
typedef struct apf_interfaces__srv__RRTSPoints_Response__Sequence
{
  apf_interfaces__srv__RRTSPoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} apf_interfaces__srv__RRTSPoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__STRUCT_H_
