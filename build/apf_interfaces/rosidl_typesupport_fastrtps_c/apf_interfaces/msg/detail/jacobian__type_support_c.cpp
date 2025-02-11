// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice
#include "apf_interfaces/msg/detail/jacobian__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "apf_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "apf_interfaces/msg/detail/jacobian__struct.h"
#include "apf_interfaces/msg/detail/jacobian__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // flat_jacobian, flat_jacobian3, flat_jacobian5
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // flat_jacobian, flat_jacobian3, flat_jacobian5

// forward declare type support functions


using _Jacobian__ros_msg_type = apf_interfaces__msg__Jacobian;

static bool _Jacobian__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Jacobian__ros_msg_type * ros_message = static_cast<const _Jacobian__ros_msg_type *>(untyped_ros_message);
  // Field name: flat_jacobian
  {
    size_t size = ros_message->flat_jacobian.size;
    auto array_ptr = ros_message->flat_jacobian.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: col_num
  {
    cdr << ros_message->col_num;
  }

  // Field name: flat_jacobian5
  {
    size_t size = ros_message->flat_jacobian5.size;
    auto array_ptr = ros_message->flat_jacobian5.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: col_num5
  {
    cdr << ros_message->col_num5;
  }

  // Field name: flat_jacobian3
  {
    size_t size = ros_message->flat_jacobian3.size;
    auto array_ptr = ros_message->flat_jacobian3.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: col_num3
  {
    cdr << ros_message->col_num3;
  }

  return true;
}

static bool _Jacobian__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Jacobian__ros_msg_type * ros_message = static_cast<_Jacobian__ros_msg_type *>(untyped_ros_message);
  // Field name: flat_jacobian
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->flat_jacobian.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->flat_jacobian);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->flat_jacobian, size)) {
      fprintf(stderr, "failed to create array for field 'flat_jacobian'");
      return false;
    }
    auto array_ptr = ros_message->flat_jacobian.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: col_num
  {
    cdr >> ros_message->col_num;
  }

  // Field name: flat_jacobian5
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->flat_jacobian5.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->flat_jacobian5);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->flat_jacobian5, size)) {
      fprintf(stderr, "failed to create array for field 'flat_jacobian5'");
      return false;
    }
    auto array_ptr = ros_message->flat_jacobian5.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: col_num5
  {
    cdr >> ros_message->col_num5;
  }

  // Field name: flat_jacobian3
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->flat_jacobian3.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->flat_jacobian3);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->flat_jacobian3, size)) {
      fprintf(stderr, "failed to create array for field 'flat_jacobian3'");
      return false;
    }
    auto array_ptr = ros_message->flat_jacobian3.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: col_num3
  {
    cdr >> ros_message->col_num3;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_apf_interfaces
size_t get_serialized_size_apf_interfaces__msg__Jacobian(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Jacobian__ros_msg_type * ros_message = static_cast<const _Jacobian__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name flat_jacobian
  {
    size_t array_size = ros_message->flat_jacobian.size;
    auto array_ptr = ros_message->flat_jacobian.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name col_num
  {
    size_t item_size = sizeof(ros_message->col_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flat_jacobian5
  {
    size_t array_size = ros_message->flat_jacobian5.size;
    auto array_ptr = ros_message->flat_jacobian5.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name col_num5
  {
    size_t item_size = sizeof(ros_message->col_num5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flat_jacobian3
  {
    size_t array_size = ros_message->flat_jacobian3.size;
    auto array_ptr = ros_message->flat_jacobian3.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name col_num3
  {
    size_t item_size = sizeof(ros_message->col_num3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Jacobian__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_apf_interfaces__msg__Jacobian(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_apf_interfaces
size_t max_serialized_size_apf_interfaces__msg__Jacobian(
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

  // member: flat_jacobian
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
  // member: col_num
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: flat_jacobian5
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
  // member: col_num5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: flat_jacobian3
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
  // member: col_num3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = apf_interfaces__msg__Jacobian;
    is_plain =
      (
      offsetof(DataType, col_num3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Jacobian__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_apf_interfaces__msg__Jacobian(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Jacobian = {
  "apf_interfaces::msg",
  "Jacobian",
  _Jacobian__cdr_serialize,
  _Jacobian__cdr_deserialize,
  _Jacobian__get_serialized_size,
  _Jacobian__max_serialized_size
};

static rosidl_message_type_support_t _Jacobian__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Jacobian,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, apf_interfaces, msg, Jacobian)() {
  return &_Jacobian__type_support;
}

#if defined(__cplusplus)
}
#endif
