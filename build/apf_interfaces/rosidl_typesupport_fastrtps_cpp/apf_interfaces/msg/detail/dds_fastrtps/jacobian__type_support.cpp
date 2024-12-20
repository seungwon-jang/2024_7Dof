// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice
#include "apf_interfaces/msg/detail/jacobian__rosidl_typesupport_fastrtps_cpp.hpp"
#include "apf_interfaces/msg/detail/jacobian__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace apf_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_apf_interfaces
cdr_serialize(
  const apf_interfaces::msg::Jacobian & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: flat_jacobian
  {
    cdr << ros_message.flat_jacobian;
  }
  // Member: col_num
  cdr << ros_message.col_num;
  // Member: flat_jacobian5
  {
    cdr << ros_message.flat_jacobian5;
  }
  // Member: col_num5
  cdr << ros_message.col_num5;
  // Member: flat_jacobian3
  {
    cdr << ros_message.flat_jacobian3;
  }
  // Member: col_num3
  cdr << ros_message.col_num3;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_apf_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  apf_interfaces::msg::Jacobian & ros_message)
{
  // Member: flat_jacobian
  {
    cdr >> ros_message.flat_jacobian;
  }

  // Member: col_num
  cdr >> ros_message.col_num;

  // Member: flat_jacobian5
  {
    cdr >> ros_message.flat_jacobian5;
  }

  // Member: col_num5
  cdr >> ros_message.col_num5;

  // Member: flat_jacobian3
  {
    cdr >> ros_message.flat_jacobian3;
  }

  // Member: col_num3
  cdr >> ros_message.col_num3;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_apf_interfaces
get_serialized_size(
  const apf_interfaces::msg::Jacobian & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: flat_jacobian
  {
    size_t array_size = ros_message.flat_jacobian.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.flat_jacobian[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: col_num
  {
    size_t item_size = sizeof(ros_message.col_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flat_jacobian5
  {
    size_t array_size = ros_message.flat_jacobian5.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.flat_jacobian5[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: col_num5
  {
    size_t item_size = sizeof(ros_message.col_num5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: flat_jacobian3
  {
    size_t array_size = ros_message.flat_jacobian3.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.flat_jacobian3[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: col_num3
  {
    size_t item_size = sizeof(ros_message.col_num3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_apf_interfaces
max_serialized_size_Jacobian(
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


  // Member: flat_jacobian
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

  // Member: col_num
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: flat_jacobian5
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

  // Member: col_num5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: flat_jacobian3
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

  // Member: col_num3
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
    using DataType = apf_interfaces::msg::Jacobian;
    is_plain =
      (
      offsetof(DataType, col_num3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Jacobian__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const apf_interfaces::msg::Jacobian *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Jacobian__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<apf_interfaces::msg::Jacobian *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Jacobian__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const apf_interfaces::msg::Jacobian *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Jacobian__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Jacobian(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Jacobian__callbacks = {
  "apf_interfaces::msg",
  "Jacobian",
  _Jacobian__cdr_serialize,
  _Jacobian__cdr_deserialize,
  _Jacobian__get_serialized_size,
  _Jacobian__max_serialized_size
};

static rosidl_message_type_support_t _Jacobian__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Jacobian__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace apf_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_apf_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<apf_interfaces::msg::Jacobian>()
{
  return &apf_interfaces::msg::typesupport_fastrtps_cpp::_Jacobian__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, apf_interfaces, msg, Jacobian)() {
  return &apf_interfaces::msg::typesupport_fastrtps_cpp::_Jacobian__handle;
}

#ifdef __cplusplus
}
#endif
