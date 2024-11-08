// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "apf_interfaces/msg/detail/distance__rosidl_typesupport_introspection_c.h"
#include "apf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "apf_interfaces/msg/detail/distance__functions.h"
#include "apf_interfaces/msg/detail/distance__struct.h"


// Include directives for member types
// Member `end_point`
// Member `direction_vector`
// Member `target_point`
// Member `end_angle_distance`
// Member `obstacle_direction_vector`
#include "geometry_msgs/msg/point.h"
// Member `end_point`
// Member `direction_vector`
// Member `target_point`
// Member `end_angle_distance`
// Member `obstacle_direction_vector`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `obstacle_distance`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  apf_interfaces__msg__Distance__init(message_memory);
}

void apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_fini_function(void * message_memory)
{
  apf_interfaces__msg__Distance__fini(message_memory);
}

size_t apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__size_function__Distance__obstacle_distance(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_const_function__Distance__obstacle_distance(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_function__Distance__obstacle_distance(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__fetch_function__Distance__obstacle_distance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_const_function__Distance__obstacle_distance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__assign_function__Distance__obstacle_distance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_function__Distance__obstacle_distance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__resize_function__Distance__obstacle_distance(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__size_function__Distance__obstacle_direction_vector(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_const_function__Distance__obstacle_direction_vector(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_function__Distance__obstacle_direction_vector(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__fetch_function__Distance__obstacle_direction_vector(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_const_function__Distance__obstacle_direction_vector(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__assign_function__Distance__obstacle_direction_vector(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_function__Distance__obstacle_direction_vector(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__resize_function__Distance__obstacle_direction_vector(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[8] = {
  {
    "end_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, end_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "direction_vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, direction_vector),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, target_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "end_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, end_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "end_angle_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, end_angle_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "obstacle_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, obstacle_distance),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__size_function__Distance__obstacle_distance,  // size() function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_const_function__Distance__obstacle_distance,  // get_const(index) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_function__Distance__obstacle_distance,  // get(index) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__fetch_function__Distance__obstacle_distance,  // fetch(index, &value) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__assign_function__Distance__obstacle_distance,  // assign(index, value) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__resize_function__Distance__obstacle_distance  // resize(index) function pointer
  },
  {
    "obstacle_direction_vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, obstacle_direction_vector),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__size_function__Distance__obstacle_direction_vector,  // size() function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_const_function__Distance__obstacle_direction_vector,  // get_const(index) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__get_function__Distance__obstacle_direction_vector,  // get(index) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__fetch_function__Distance__obstacle_direction_vector,  // fetch(index, &value) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__assign_function__Distance__obstacle_direction_vector,  // assign(index, value) function pointer
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__resize_function__Distance__obstacle_direction_vector  // resize(index) function pointer
  },
  {
    "obstacle_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Distance, obstacle_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_members = {
  "apf_interfaces__msg",  // message namespace
  "Distance",  // message name
  8,  // number of fields
  sizeof(apf_interfaces__msg__Distance),
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array,  // message members
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_init_function,  // function to initialize message memory (memory has to be allocated)
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle = {
  0,
  &apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_apf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, msg, Distance)() {
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle.typesupport_identifier) {
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
