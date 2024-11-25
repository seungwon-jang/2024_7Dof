// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "apf_interfaces/srv/detail/rrts_points__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace apf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RRTSPoints_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) apf_interfaces::srv::RRTSPoints_Request(_init);
}

void RRTSPoints_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<apf_interfaces::srv::RRTSPoints_Request *>(message_memory);
  typed_message->~RRTSPoints_Request();
}

size_t size_function__RRTSPoints_Request__obstacle_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RRTSPoints_Request__obstacle_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RRTSPoints_Request__obstacle_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RRTSPoints_Request__obstacle_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RRTSPoints_Request__obstacle_points(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RRTSPoints_Request__obstacle_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RRTSPoints_Request__obstacle_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RRTSPoints_Request__obstacle_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RRTSPoints_Request__start_point(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RRTSPoints_Request__start_point(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RRTSPoints_Request__start_point(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RRTSPoints_Request__start_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RRTSPoints_Request__start_point(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RRTSPoints_Request__start_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RRTSPoints_Request__start_point(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RRTSPoints_Request__start_point(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RRTSPoints_Request__end_point(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RRTSPoints_Request__end_point(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RRTSPoints_Request__end_point(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RRTSPoints_Request__end_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RRTSPoints_Request__end_point(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RRTSPoints_Request__end_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RRTSPoints_Request__end_point(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RRTSPoints_Request__end_point(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RRTSPoints_Request_message_member_array[4] = {
  {
    "obstacle_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::srv::RRTSPoints_Request, obstacle_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__RRTSPoints_Request__obstacle_points,  // size() function pointer
    get_const_function__RRTSPoints_Request__obstacle_points,  // get_const(index) function pointer
    get_function__RRTSPoints_Request__obstacle_points,  // get(index) function pointer
    fetch_function__RRTSPoints_Request__obstacle_points,  // fetch(index, &value) function pointer
    assign_function__RRTSPoints_Request__obstacle_points,  // assign(index, value) function pointer
    resize_function__RRTSPoints_Request__obstacle_points  // resize(index) function pointer
  },
  {
    "obstacle_count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::srv::RRTSPoints_Request, obstacle_count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "start_point",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::srv::RRTSPoints_Request, start_point),  // bytes offset in struct
    nullptr,  // default value
    size_function__RRTSPoints_Request__start_point,  // size() function pointer
    get_const_function__RRTSPoints_Request__start_point,  // get_const(index) function pointer
    get_function__RRTSPoints_Request__start_point,  // get(index) function pointer
    fetch_function__RRTSPoints_Request__start_point,  // fetch(index, &value) function pointer
    assign_function__RRTSPoints_Request__start_point,  // assign(index, value) function pointer
    resize_function__RRTSPoints_Request__start_point  // resize(index) function pointer
  },
  {
    "end_point",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::srv::RRTSPoints_Request, end_point),  // bytes offset in struct
    nullptr,  // default value
    size_function__RRTSPoints_Request__end_point,  // size() function pointer
    get_const_function__RRTSPoints_Request__end_point,  // get_const(index) function pointer
    get_function__RRTSPoints_Request__end_point,  // get(index) function pointer
    fetch_function__RRTSPoints_Request__end_point,  // fetch(index, &value) function pointer
    assign_function__RRTSPoints_Request__end_point,  // assign(index, value) function pointer
    resize_function__RRTSPoints_Request__end_point  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RRTSPoints_Request_message_members = {
  "apf_interfaces::srv",  // message namespace
  "RRTSPoints_Request",  // message name
  4,  // number of fields
  sizeof(apf_interfaces::srv::RRTSPoints_Request),
  RRTSPoints_Request_message_member_array,  // message members
  RRTSPoints_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  RRTSPoints_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RRTSPoints_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RRTSPoints_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace apf_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<apf_interfaces::srv::RRTSPoints_Request>()
{
  return &::apf_interfaces::srv::rosidl_typesupport_introspection_cpp::RRTSPoints_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, apf_interfaces, srv, RRTSPoints_Request)() {
  return &::apf_interfaces::srv::rosidl_typesupport_introspection_cpp::RRTSPoints_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace apf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RRTSPoints_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) apf_interfaces::srv::RRTSPoints_Response(_init);
}

void RRTSPoints_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<apf_interfaces::srv::RRTSPoints_Response *>(message_memory);
  typed_message->~RRTSPoints_Response();
}

size_t size_function__RRTSPoints_Response__result_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RRTSPoints_Response__result_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RRTSPoints_Response__result_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RRTSPoints_Response__result_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RRTSPoints_Response__result_points(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RRTSPoints_Response__result_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RRTSPoints_Response__result_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RRTSPoints_Response__result_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RRTSPoints_Response_message_member_array[2] = {
  {
    "result_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::srv::RRTSPoints_Response, result_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__RRTSPoints_Response__result_points,  // size() function pointer
    get_const_function__RRTSPoints_Response__result_points,  // get_const(index) function pointer
    get_function__RRTSPoints_Response__result_points,  // get(index) function pointer
    fetch_function__RRTSPoints_Response__result_points,  // fetch(index, &value) function pointer
    assign_function__RRTSPoints_Response__result_points,  // assign(index, value) function pointer
    resize_function__RRTSPoints_Response__result_points  // resize(index) function pointer
  },
  {
    "point_count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(apf_interfaces::srv::RRTSPoints_Response, point_count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RRTSPoints_Response_message_members = {
  "apf_interfaces::srv",  // message namespace
  "RRTSPoints_Response",  // message name
  2,  // number of fields
  sizeof(apf_interfaces::srv::RRTSPoints_Response),
  RRTSPoints_Response_message_member_array,  // message members
  RRTSPoints_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  RRTSPoints_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RRTSPoints_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RRTSPoints_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace apf_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<apf_interfaces::srv::RRTSPoints_Response>()
{
  return &::apf_interfaces::srv::rosidl_typesupport_introspection_cpp::RRTSPoints_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, apf_interfaces, srv, RRTSPoints_Response)() {
  return &::apf_interfaces::srv::rosidl_typesupport_introspection_cpp::RRTSPoints_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace apf_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers RRTSPoints_service_members = {
  "apf_interfaces::srv",  // service namespace
  "RRTSPoints",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<apf_interfaces::srv::RRTSPoints>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t RRTSPoints_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RRTSPoints_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace apf_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<apf_interfaces::srv::RRTSPoints>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::apf_interfaces::srv::rosidl_typesupport_introspection_cpp::RRTSPoints_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::apf_interfaces::srv::RRTSPoints_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::apf_interfaces::srv::RRTSPoints_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, apf_interfaces, srv, RRTSPoints)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<apf_interfaces::srv::RRTSPoints>();
}

#ifdef __cplusplus
}
#endif
