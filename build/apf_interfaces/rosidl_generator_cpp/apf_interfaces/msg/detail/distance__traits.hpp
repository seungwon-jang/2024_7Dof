// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__DISTANCE__TRAITS_HPP_
#define APF_INTERFACES__MSG__DETAIL__DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "apf_interfaces/msg/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'end_point'
// Member 'direction_vector'
// Member 'target_point'
// Member 'end_angle_distance'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace apf_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Distance & msg,
  std::ostream & out)
{
  out << "{";
  // member: end_point
  {
    out << "end_point: ";
    to_flow_style_yaml(msg.end_point, out);
    out << ", ";
  }

  // member: direction_vector
  {
    out << "direction_vector: ";
    to_flow_style_yaml(msg.direction_vector, out);
    out << ", ";
  }

  // member: target_point
  {
    out << "target_point: ";
    to_flow_style_yaml(msg.target_point, out);
    out << ", ";
  }

  // member: end_distance
  {
    out << "end_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.end_distance, out);
    out << ", ";
  }

  // member: end_angle_distance
  {
    out << "end_angle_distance: ";
    to_flow_style_yaml(msg.end_angle_distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Distance & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: end_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_point:\n";
    to_block_style_yaml(msg.end_point, out, indentation + 2);
  }

  // member: direction_vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction_vector:\n";
    to_block_style_yaml(msg.direction_vector, out, indentation + 2);
  }

  // member: target_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_point:\n";
    to_block_style_yaml(msg.target_point, out, indentation + 2);
  }

  // member: end_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.end_distance, out);
    out << "\n";
  }

  // member: end_angle_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_angle_distance:\n";
    to_block_style_yaml(msg.end_angle_distance, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Distance & msg, bool use_flow_style = false)
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
  const apf_interfaces::msg::Distance & msg,
  std::ostream & out, size_t indentation = 0)
{
  apf_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use apf_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const apf_interfaces::msg::Distance & msg)
{
  return apf_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<apf_interfaces::msg::Distance>()
{
  return "apf_interfaces::msg::Distance";
}

template<>
inline const char * name<apf_interfaces::msg::Distance>()
{
  return "apf_interfaces/msg/Distance";
}

template<>
struct has_fixed_size<apf_interfaces::msg::Distance>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<apf_interfaces::msg::Distance>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<apf_interfaces::msg::Distance>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // APF_INTERFACES__MSG__DETAIL__DISTANCE__TRAITS_HPP_
