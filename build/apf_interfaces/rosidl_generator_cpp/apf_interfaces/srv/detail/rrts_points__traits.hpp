// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__TRAITS_HPP_
#define APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "apf_interfaces/srv/detail/rrts_points__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace apf_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RRTSPoints_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: obstacle_points
  {
    if (msg.obstacle_points.size() == 0) {
      out << "obstacle_points: []";
    } else {
      out << "obstacle_points: [";
      size_t pending_items = msg.obstacle_points.size();
      for (auto item : msg.obstacle_points) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: obstacle_count
  {
    out << "obstacle_count: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_count, out);
    out << ", ";
  }

  // member: start_point
  {
    if (msg.start_point.size() == 0) {
      out << "start_point: []";
    } else {
      out << "start_point: [";
      size_t pending_items = msg.start_point.size();
      for (auto item : msg.start_point) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: end_point
  {
    if (msg.end_point.size() == 0) {
      out << "end_point: []";
    } else {
      out << "end_point: [";
      size_t pending_items = msg.end_point.size();
      for (auto item : msg.end_point) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RRTSPoints_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: obstacle_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.obstacle_points.size() == 0) {
      out << "obstacle_points: []\n";
    } else {
      out << "obstacle_points:\n";
      for (auto item : msg.obstacle_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: obstacle_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_count: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_count, out);
    out << "\n";
  }

  // member: start_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.start_point.size() == 0) {
      out << "start_point: []\n";
    } else {
      out << "start_point:\n";
      for (auto item : msg.start_point) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: end_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.end_point.size() == 0) {
      out << "end_point: []\n";
    } else {
      out << "end_point:\n";
      for (auto item : msg.end_point) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RRTSPoints_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace apf_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use apf_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const apf_interfaces::srv::RRTSPoints_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  apf_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use apf_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const apf_interfaces::srv::RRTSPoints_Request & msg)
{
  return apf_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<apf_interfaces::srv::RRTSPoints_Request>()
{
  return "apf_interfaces::srv::RRTSPoints_Request";
}

template<>
inline const char * name<apf_interfaces::srv::RRTSPoints_Request>()
{
  return "apf_interfaces/srv/RRTSPoints_Request";
}

template<>
struct has_fixed_size<apf_interfaces::srv::RRTSPoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<apf_interfaces::srv::RRTSPoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<apf_interfaces::srv::RRTSPoints_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace apf_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RRTSPoints_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result_points
  {
    if (msg.result_points.size() == 0) {
      out << "result_points: []";
    } else {
      out << "result_points: [";
      size_t pending_items = msg.result_points.size();
      for (auto item : msg.result_points) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: point_count
  {
    out << "point_count: ";
    rosidl_generator_traits::value_to_yaml(msg.point_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RRTSPoints_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.result_points.size() == 0) {
      out << "result_points: []\n";
    } else {
      out << "result_points:\n";
      for (auto item : msg.result_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: point_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point_count: ";
    rosidl_generator_traits::value_to_yaml(msg.point_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RRTSPoints_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace apf_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use apf_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const apf_interfaces::srv::RRTSPoints_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  apf_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use apf_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const apf_interfaces::srv::RRTSPoints_Response & msg)
{
  return apf_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<apf_interfaces::srv::RRTSPoints_Response>()
{
  return "apf_interfaces::srv::RRTSPoints_Response";
}

template<>
inline const char * name<apf_interfaces::srv::RRTSPoints_Response>()
{
  return "apf_interfaces/srv/RRTSPoints_Response";
}

template<>
struct has_fixed_size<apf_interfaces::srv::RRTSPoints_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<apf_interfaces::srv::RRTSPoints_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<apf_interfaces::srv::RRTSPoints_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<apf_interfaces::srv::RRTSPoints>()
{
  return "apf_interfaces::srv::RRTSPoints";
}

template<>
inline const char * name<apf_interfaces::srv::RRTSPoints>()
{
  return "apf_interfaces/srv/RRTSPoints";
}

template<>
struct has_fixed_size<apf_interfaces::srv::RRTSPoints>
  : std::integral_constant<
    bool,
    has_fixed_size<apf_interfaces::srv::RRTSPoints_Request>::value &&
    has_fixed_size<apf_interfaces::srv::RRTSPoints_Response>::value
  >
{
};

template<>
struct has_bounded_size<apf_interfaces::srv::RRTSPoints>
  : std::integral_constant<
    bool,
    has_bounded_size<apf_interfaces::srv::RRTSPoints_Request>::value &&
    has_bounded_size<apf_interfaces::srv::RRTSPoints_Response>::value
  >
{
};

template<>
struct is_service<apf_interfaces::srv::RRTSPoints>
  : std::true_type
{
};

template<>
struct is_service_request<apf_interfaces::srv::RRTSPoints_Request>
  : std::true_type
{
};

template<>
struct is_service_response<apf_interfaces::srv::RRTSPoints_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__TRAITS_HPP_
