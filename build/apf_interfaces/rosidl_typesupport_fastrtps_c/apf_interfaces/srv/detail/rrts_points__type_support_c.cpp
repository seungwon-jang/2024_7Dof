// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice
#include "apf_interfaces/srv/detail/rrts_points__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "apf_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "apf_interfaces/srv/detail/rrts_points__struct.h"
#include "apf_interfaces/srv/detail/rrts_points__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // end_point, obstacle_points, start_point
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // end_point, obstacle_points, start_point

// forward declare type support functions


using _RRTSPoints_Request__ros_msg_type = apf_interfaces__srv__RRTSPoints_Request;

static bool _RRTSPoints_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RRTSPoints_Request__ros_msg_type * ros_message = static_cast<const _RRTSPoints_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: obstacle_points
  {
    size_t size = ros_message->obstacle_points.size;
    auto array_ptr = ros_message->obstacle_points.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: obstacle_count
  {
    cdr << ros_message->obstacle_count;
  }

  // Field name: start_point
  {
    size_t size = ros_message->start_point.size;
    auto array_ptr = ros_message->start_point.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: end_point
  {
    size_t size = ros_message->end_point.size;
    auto array_ptr = ros_message->end_point.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _RRTSPoints_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RRTSPoints_Request__ros_msg_type * ros_message = static_cast<_RRTSPoints_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: obstacle_points
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->obstacle_points.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->obstacle_points);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->obstacle_points, size)) {
      fprintf(stderr, "failed to create array for field 'obstacle_points'");
      return false;
    }
    auto array_ptr = ros_message->obstacle_points.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: obstacle_count
  {
    cdr >> ros_message->obstacle_count;
  }

  // Field name: start_point
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->start_point.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->start_point);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->start_point, size)) {
      fprintf(stderr, "failed to create array for field 'start_point'");
      return false;
    }
    auto array_ptr = ros_message->start_point.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: end_point
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->end_point.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->end_point);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->end_point, size)) {
      fprintf(stderr, "failed to create array for field 'end_point'");
      return false;
    }
    auto array_ptr = ros_message->end_point.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_apf_interfaces
size_t get_serialized_size_apf_interfaces__srv__RRTSPoints_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RRTSPoints_Request__ros_msg_type * ros_message = static_cast<const _RRTSPoints_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name obstacle_points
  {
    size_t array_size = ros_message->obstacle_points.size;
    auto array_ptr = ros_message->obstacle_points.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name obstacle_count
  {
    size_t item_size = sizeof(ros_message->obstacle_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name start_point
  {
    size_t array_size = ros_message->start_point.size;
    auto array_ptr = ros_message->start_point.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name end_point
  {
    size_t array_size = ros_message->end_point.size;
    auto array_ptr = ros_message->end_point.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RRTSPoints_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_apf_interfaces__srv__RRTSPoints_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_apf_interfaces
size_t max_serialized_size_apf_interfaces__srv__RRTSPoints_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: obstacle_points
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: obstacle_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: start_point
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: end_point
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = apf_interfaces__srv__RRTSPoints_Request;
    is_plain =
      (
      offsetof(DataType, end_point) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RRTSPoints_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_apf_interfaces__srv__RRTSPoints_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RRTSPoints_Request = {
  "apf_interfaces::srv",
  "RRTSPoints_Request",
  _RRTSPoints_Request__cdr_serialize,
  _RRTSPoints_Request__cdr_deserialize,
  _RRTSPoints_Request__get_serialized_size,
  _RRTSPoints_Request__max_serialized_size
};

static rosidl_message_type_support_t _RRTSPoints_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RRTSPoints_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, apf_interfaces, srv, RRTSPoints_Request)() {
  return &_RRTSPoints_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "apf_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__struct.h"
// already included above
// #include "apf_interfaces/srv/detail/rrts_points__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // result_points
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // result_points

// forward declare type support functions


using _RRTSPoints_Response__ros_msg_type = apf_interfaces__srv__RRTSPoints_Response;

static bool _RRTSPoints_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RRTSPoints_Response__ros_msg_type * ros_message = static_cast<const _RRTSPoints_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result_points
  {
    size_t size = ros_message->result_points.size;
    auto array_ptr = ros_message->result_points.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: point_count
  {
    cdr << ros_message->point_count;
  }

  return true;
}

static bool _RRTSPoints_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RRTSPoints_Response__ros_msg_type * ros_message = static_cast<_RRTSPoints_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result_points
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->result_points.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->result_points);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->result_points, size)) {
      fprintf(stderr, "failed to create array for field 'result_points'");
      return false;
    }
    auto array_ptr = ros_message->result_points.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: point_count
  {
    cdr >> ros_message->point_count;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_apf_interfaces
size_t get_serialized_size_apf_interfaces__srv__RRTSPoints_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RRTSPoints_Response__ros_msg_type * ros_message = static_cast<const _RRTSPoints_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result_points
  {
    size_t array_size = ros_message->result_points.size;
    auto array_ptr = ros_message->result_points.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name point_count
  {
    size_t item_size = sizeof(ros_message->point_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RRTSPoints_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_apf_interfaces__srv__RRTSPoints_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_apf_interfaces
size_t max_serialized_size_apf_interfaces__srv__RRTSPoints_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: result_points
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: point_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = apf_interfaces__srv__RRTSPoints_Response;
    is_plain =
      (
      offsetof(DataType, point_count) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RRTSPoints_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_apf_interfaces__srv__RRTSPoints_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RRTSPoints_Response = {
  "apf_interfaces::srv",
  "RRTSPoints_Response",
  _RRTSPoints_Response__cdr_serialize,
  _RRTSPoints_Response__cdr_deserialize,
  _RRTSPoints_Response__get_serialized_size,
  _RRTSPoints_Response__max_serialized_size
};

static rosidl_message_type_support_t _RRTSPoints_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RRTSPoints_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, apf_interfaces, srv, RRTSPoints_Response)() {
  return &_RRTSPoints_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "apf_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "apf_interfaces/srv/rrts_points.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t RRTSPoints__callbacks = {
  "apf_interfaces::srv",
  "RRTSPoints",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, apf_interfaces, srv, RRTSPoints_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, apf_interfaces, srv, RRTSPoints_Response)(),
};

static rosidl_service_type_support_t RRTSPoints__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &RRTSPoints__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, apf_interfaces, srv, RRTSPoints)() {
  return &RRTSPoints__handle;
}

#if defined(__cplusplus)
}
#endif
