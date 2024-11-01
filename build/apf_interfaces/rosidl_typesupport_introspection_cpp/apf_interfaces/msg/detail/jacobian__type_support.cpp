// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "apf_interfaces/msg/detail/jacobian__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace apf_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Jacobian_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) apf_interfaces::msg::Jacobian(_init);
}

void Jacobian_fini_function(void * message_memory)
{
  auto typed_message = static_cast<apf_interfaces::msg::Jacobian *>(message_memory);
  typed_message->~Jacobian();
}

size_t size_function__Jacobian__flat_jacobian(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Jacobian__flat_jacobian(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Jacobian__flat_jacobian(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Jacobian__flat_jacobian(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Jacobian__flat_jacobian(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Jacobian__flat_jacobian(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Jacobian__flat_jacobian(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Jacobian__flat_jacobian(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Jacobian_message_member_array[2] = {
  {
    "flat_jacobian",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::msg::Jacobian, flat_jacobian),  // bytes offset in struct
    nullptr,  // default value
    size_function__Jacobian__flat_jacobian,  // size() function pointer
    get_const_function__Jacobian__flat_jacobian,  // get_const(index) function pointer
    get_function__Jacobian__flat_jacobian,  // get(index) function pointer
    fetch_function__Jacobian__flat_jacobian,  // fetch(index, &value) function pointer
    assign_function__Jacobian__flat_jacobian,  // assign(index, value) function pointer
    resize_function__Jacobian__flat_jacobian  // resize(index) function pointer
  },
  {
    "col_num",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::msg::Jacobian, col_num),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Jacobian_message_members = {
  "apf_interfaces::msg",  // message namespace
  "Jacobian",  // message name
  2,  // number of fields
  sizeof(apf_interfaces::msg::Jacobian),
  Jacobian_message_member_array,  // message members
  Jacobian_init_function,  // function to initialize message memory (memory has to be allocated)
  Jacobian_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Jacobian_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Jacobian_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace apf_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<apf_interfaces::msg::Jacobian>()
{
  return &::apf_interfaces::msg::rosidl_typesupport_introspection_cpp::Jacobian_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, apf_interfaces, msg, Jacobian)() {
  return &::apf_interfaces::msg::rosidl_typesupport_introspection_cpp::Jacobian_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
