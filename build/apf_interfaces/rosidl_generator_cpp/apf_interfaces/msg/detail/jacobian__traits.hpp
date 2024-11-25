// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__JACOBIAN__TRAITS_HPP_
#define APF_INTERFACES__MSG__DETAIL__JACOBIAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "apf_interfaces/msg/detail/jacobian__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace apf_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Jacobian & msg,
  std::ostream & out)
{
  out << "{";
  // member: flat_jacobian
  {
    if (msg.flat_jacobian.size() == 0) {
      out << "flat_jacobian: []";
    } else {
      out << "flat_jacobian: [";
      size_t pending_items = msg.flat_jacobian.size();
      for (auto item : msg.flat_jacobian) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: col_num
  {
    out << "col_num: ";
    rosidl_generator_traits::value_to_yaml(msg.col_num, out);
    out << ", ";
  }

  // member: flat_jacobian5
  {
    if (msg.flat_jacobian5.size() == 0) {
      out << "flat_jacobian5: []";
    } else {
      out << "flat_jacobian5: [";
      size_t pending_items = msg.flat_jacobian5.size();
      for (auto item : msg.flat_jacobian5) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: col_num5
  {
    out << "col_num5: ";
    rosidl_generator_traits::value_to_yaml(msg.col_num5, out);
    out << ", ";
  }

  // member: flat_jacobian3
  {
    if (msg.flat_jacobian3.size() == 0) {
      out << "flat_jacobian3: []";
    } else {
      out << "flat_jacobian3: [";
      size_t pending_items = msg.flat_jacobian3.size();
      for (auto item : msg.flat_jacobian3) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: col_num3
  {
    out << "col_num3: ";
    rosidl_generator_traits::value_to_yaml(msg.col_num3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Jacobian & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: flat_jacobian
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.flat_jacobian.size() == 0) {
      out << "flat_jacobian: []\n";
    } else {
      out << "flat_jacobian:\n";
      for (auto item : msg.flat_jacobian) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: col_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "col_num: ";
    rosidl_generator_traits::value_to_yaml(msg.col_num, out);
    out << "\n";
  }

  // member: flat_jacobian5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.flat_jacobian5.size() == 0) {
      out << "flat_jacobian5: []\n";
    } else {
      out << "flat_jacobian5:\n";
      for (auto item : msg.flat_jacobian5) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: col_num5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "col_num5: ";
    rosidl_generator_traits::value_to_yaml(msg.col_num5, out);
    out << "\n";
  }

  // member: flat_jacobian3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.flat_jacobian3.size() == 0) {
      out << "flat_jacobian3: []\n";
    } else {
      out << "flat_jacobian3:\n";
      for (auto item : msg.flat_jacobian3) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: col_num3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "col_num3: ";
    rosidl_generator_traits::value_to_yaml(msg.col_num3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Jacobian & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace apf_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use apf_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const apf_interfaces::msg::Jacobian & msg,
  std::ostream & out, size_t indentation = 0)
{
  apf_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use apf_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const apf_interfaces::msg::Jacobian & msg)
{
  return apf_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<apf_interfaces::msg::Jacobian>()
{
  return "apf_interfaces::msg::Jacobian";
}

template<>
inline const char * name<apf_interfaces::msg::Jacobian>()
{
  return "apf_interfaces/msg/Jacobian";
}

template<>
struct has_fixed_size<apf_interfaces::msg::Jacobian>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<apf_interfaces::msg::Jacobian>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<apf_interfaces::msg::Jacobian>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // APF_INTERFACES__MSG__DETAIL__JACOBIAN__TRAITS_HPP_
