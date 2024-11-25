// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "apf_interfaces/srv/detail/rrts_points__rosidl_typesupport_introspection_c.h"
#include "apf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "apf_interfaces/srv/detail/rrts_points__functions.h"
#include "apf_interfaces/srv/detail/rrts_points__struct.h"


// Include directives for member types
// Member `obstacle_points`
// Member `start_point`
// Member `end_point`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  apf_interfaces__srv__RRTSPoints_Request__init(message_memory);
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_fini_function(void * message_memory)
{
  apf_interfaces__srv__RRTSPoints_Request__fini(message_memory);
}

size_t apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Request__obstacle_points(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__obstacle_points(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__obstacle_points(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Request__obstacle_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__obstacle_points(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Request__obstacle_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__obstacle_points(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Request__obstacle_points(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Request__start_point(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__start_point(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__start_point(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Request__start_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__start_point(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Request__start_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__start_point(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Request__start_point(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Request__end_point(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__end_point(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__end_point(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Request__end_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__end_point(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Request__end_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__end_point(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Request__end_point(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_member_array[4] = {
  {
    "obstacle_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__srv__RRTSPoints_Request, obstacle_points),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Request__obstacle_points,  // size() function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__obstacle_points,  // get_const(index) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__obstacle_points,  // get(index) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Request__obstacle_points,  // fetch(index, &value) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Request__obstacle_points,  // assign(index, value) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Request__obstacle_points  // resize(index) function pointer
  },
  {
    "obstacle_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__srv__RRTSPoints_Request, obstacle_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__srv__RRTSPoints_Request, start_point),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Request__start_point,  // size() function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__start_point,  // get_const(index) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__start_point,  // get(index) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Request__start_point,  // fetch(index, &value) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Request__start_point,  // assign(index, value) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Request__start_point  // resize(index) function pointer
  },
  {
    "end_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__srv__RRTSPoints_Request, end_point),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Request__end_point,  // size() function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Request__end_point,  // get_const(index) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Request__end_point,  // get(index) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Request__end_point,  // fetch(index, &value) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Request__end_point,  // assign(index, value) function pointer
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Request__end_point  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_members = {
  "apf_interfaces__srv",  // message namespace
  "RRTSPoints_Request",  // message name
  4,  // number of fields
  sizeof(apf_interfaces__srv__RRTSPoints_Request),
  apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_member_array,  // message members
  apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_type_support_handle = {
  0,
  &apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_apf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints_Request)() {
  if (!apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_type_support_handle.typesupport_identifier) {
    apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &apf_interfaces__srv__RRTSPoints_Request__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__rosidl_typesupport_introspection_c.h"
// already included above
// #include "apf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__functions.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__struct.h"


// Include directives for member types
// Member `result_points`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  apf_interfaces__srv__RRTSPoints_Response__init(message_memory);
}

void apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_fini_function(void * message_memory)
{
  apf_interfaces__srv__RRTSPoints_Response__fini(message_memory);
}

size_t apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Response__result_points(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Response__result_points(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Response__result_points(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Response__result_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Response__result_points(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Response__result_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Response__result_points(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Response__result_points(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_member_array[2] = {
  {
    "result_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__srv__RRTSPoints_Response, result_points),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__size_function__RRTSPoints_Response__result_points,  // size() function pointer
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__get_const_function__RRTSPoints_Response__result_points,  // get_const(index) function pointer
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__get_function__RRTSPoints_Response__result_points,  // get(index) function pointer
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__fetch_function__RRTSPoints_Response__result_points,  // fetch(index, &value) function pointer
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__assign_function__RRTSPoints_Response__result_points,  // assign(index, value) function pointer
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__resize_function__RRTSPoints_Response__result_points  // resize(index) function pointer
  },
  {
    "point_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__srv__RRTSPoints_Response, point_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_members = {
  "apf_interfaces__srv",  // message namespace
  "RRTSPoints_Response",  // message name
  2,  // number of fields
  sizeof(apf_interfaces__srv__RRTSPoints_Response),
  apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_member_array,  // message members
  apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_type_support_handle = {
  0,
  &apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_apf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints_Response)() {
  if (!apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_type_support_handle.typesupport_identifier) {
    apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &apf_interfaces__srv__RRTSPoints_Response__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "apf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_members = {
  "apf_interfaces__srv",  // service namespace
  "RRTSPoints",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_Request_message_type_support_handle,
  NULL  // response message
  // apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_Response_message_type_support_handle
};

static rosidl_service_type_support_t apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_type_support_handle = {
  0,
  &apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_apf_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints)() {
  if (!apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_type_support_handle.typesupport_identifier) {
    apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, srv, RRTSPoints_Response)()->data;
  }

  return &apf_interfaces__srv__detail__rrts_points__rosidl_typesupport_introspection_c__RRTSPoints_service_type_support_handle;
}
