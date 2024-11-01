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
#include "geometry_msgs/msg/point.h"
// Member `end_point`
// Member `direction_vector`
// Member `target_point`
// Member `end_angle_distance`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

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

static rosidl_typesupport_introspection_c__MessageMember apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_member_array[5] = {
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
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_members = {
  "apf_interfaces__msg",  // message namespace
  "Distance",  // message name
  5,  // number of fields
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
  if (!apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle.typesupport_identifier) {
    apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &apf_interfaces__msg__Distance__rosidl_typesupport_introspection_c__Distance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
