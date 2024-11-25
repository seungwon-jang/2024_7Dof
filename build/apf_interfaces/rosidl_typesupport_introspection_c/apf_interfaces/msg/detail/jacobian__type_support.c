// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "apf_interfaces/msg/detail/jacobian__rosidl_typesupport_introspection_c.h"
#include "apf_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "apf_interfaces/msg/detail/jacobian__functions.h"
#include "apf_interfaces/msg/detail/jacobian__struct.h"


// Include directives for member types
// Member `flat_jacobian`
// Member `flat_jacobian5`
// Member `flat_jacobian3`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  apf_interfaces__msg__Jacobian__init(message_memory);
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_fini_function(void * message_memory)
{
  apf_interfaces__msg__Jacobian__fini(message_memory);
}

size_t apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__size_function__Jacobian__flat_jacobian(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__fetch_function__Jacobian__flat_jacobian(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__assign_function__Jacobian__flat_jacobian(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__resize_function__Jacobian__flat_jacobian(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__size_function__Jacobian__flat_jacobian5(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian5(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian5(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__fetch_function__Jacobian__flat_jacobian5(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian5(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__assign_function__Jacobian__flat_jacobian5(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian5(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__resize_function__Jacobian__flat_jacobian5(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__size_function__Jacobian__flat_jacobian3(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian3(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian3(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__fetch_function__Jacobian__flat_jacobian3(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian3(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__assign_function__Jacobian__flat_jacobian3(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian3(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__resize_function__Jacobian__flat_jacobian3(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_member_array[6] = {
  {
    "flat_jacobian",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Jacobian, flat_jacobian),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__size_function__Jacobian__flat_jacobian,  // size() function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian,  // get_const(index) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian,  // get(index) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__fetch_function__Jacobian__flat_jacobian,  // fetch(index, &value) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__assign_function__Jacobian__flat_jacobian,  // assign(index, value) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__resize_function__Jacobian__flat_jacobian  // resize(index) function pointer
  },
  {
    "col_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Jacobian, col_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flat_jacobian5",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Jacobian, flat_jacobian5),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__size_function__Jacobian__flat_jacobian5,  // size() function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian5,  // get_const(index) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian5,  // get(index) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__fetch_function__Jacobian__flat_jacobian5,  // fetch(index, &value) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__assign_function__Jacobian__flat_jacobian5,  // assign(index, value) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__resize_function__Jacobian__flat_jacobian5  // resize(index) function pointer
  },
  {
    "col_num5",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Jacobian, col_num5),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flat_jacobian3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Jacobian, flat_jacobian3),  // bytes offset in struct
    NULL,  // default value
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__size_function__Jacobian__flat_jacobian3,  // size() function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_const_function__Jacobian__flat_jacobian3,  // get_const(index) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__get_function__Jacobian__flat_jacobian3,  // get(index) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__fetch_function__Jacobian__flat_jacobian3,  // fetch(index, &value) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__assign_function__Jacobian__flat_jacobian3,  // assign(index, value) function pointer
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__resize_function__Jacobian__flat_jacobian3  // resize(index) function pointer
  },
  {
    "col_num3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces__msg__Jacobian, col_num3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_members = {
  "apf_interfaces__msg",  // message namespace
  "Jacobian",  // message name
  6,  // number of fields
  sizeof(apf_interfaces__msg__Jacobian),
  apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_member_array,  // message members
  apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_init_function,  // function to initialize message memory (memory has to be allocated)
  apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_type_support_handle = {
  0,
  &apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_apf_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, apf_interfaces, msg, Jacobian)() {
  if (!apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_type_support_handle.typesupport_identifier) {
    apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &apf_interfaces__msg__Jacobian__rosidl_typesupport_introspection_c__Jacobian_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
