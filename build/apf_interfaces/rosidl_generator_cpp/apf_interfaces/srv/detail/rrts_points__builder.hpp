// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__BUILDER_HPP_
#define APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "apf_interfaces/srv/detail/rrts_points__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace apf_interfaces
{

namespace srv
{

namespace builder
{

class Init_RRTSPoints_Request_end_point
{
public:
  explicit Init_RRTSPoints_Request_end_point(::apf_interfaces::srv::RRTSPoints_Request & msg)
  : msg_(msg)
  {}
  ::apf_interfaces::srv::RRTSPoints_Request end_point(::apf_interfaces::srv::RRTSPoints_Request::_end_point_type arg)
  {
    msg_.end_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::apf_interfaces::srv::RRTSPoints_Request msg_;
};

class Init_RRTSPoints_Request_start_point
{
public:
  explicit Init_RRTSPoints_Request_start_point(::apf_interfaces::srv::RRTSPoints_Request & msg)
  : msg_(msg)
  {}
  Init_RRTSPoints_Request_end_point start_point(::apf_interfaces::srv::RRTSPoints_Request::_start_point_type arg)
  {
    msg_.start_point = std::move(arg);
    return Init_RRTSPoints_Request_end_point(msg_);
  }

private:
  ::apf_interfaces::srv::RRTSPoints_Request msg_;
};

class Init_RRTSPoints_Request_obstacle_count
{
public:
  explicit Init_RRTSPoints_Request_obstacle_count(::apf_interfaces::srv::RRTSPoints_Request & msg)
  : msg_(msg)
  {}
  Init_RRTSPoints_Request_start_point obstacle_count(::apf_interfaces::srv::RRTSPoints_Request::_obstacle_count_type arg)
  {
    msg_.obstacle_count = std::move(arg);
    return Init_RRTSPoints_Request_start_point(msg_);
  }

private:
  ::apf_interfaces::srv::RRTSPoints_Request msg_;
};

class Init_RRTSPoints_Request_obstacle_points
{
public:
  Init_RRTSPoints_Request_obstacle_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RRTSPoints_Request_obstacle_count obstacle_points(::apf_interfaces::srv::RRTSPoints_Request::_obstacle_points_type arg)
  {
    msg_.obstacle_points = std::move(arg);
    return Init_RRTSPoints_Request_obstacle_count(msg_);
  }

private:
  ::apf_interfaces::srv::RRTSPoints_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::apf_interfaces::srv::RRTSPoints_Request>()
{
  return apf_interfaces::srv::builder::Init_RRTSPoints_Request_obstacle_points();
}

}  // namespace apf_interfaces


namespace apf_interfaces
{

namespace srv
{

namespace builder
{

class Init_RRTSPoints_Response_point_count
{
public:
  explicit Init_RRTSPoints_Response_point_count(::apf_interfaces::srv::RRTSPoints_Response & msg)
  : msg_(msg)
  {}
  ::apf_interfaces::srv::RRTSPoints_Response point_count(::apf_interfaces::srv::RRTSPoints_Response::_point_count_type arg)
  {
    msg_.point_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::apf_interfaces::srv::RRTSPoints_Response msg_;
};

class Init_RRTSPoints_Response_result_points
{
public:
  Init_RRTSPoints_Response_result_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RRTSPoints_Response_point_count result_points(::apf_interfaces::srv::RRTSPoints_Response::_result_points_type arg)
  {
    msg_.result_points = std::move(arg);
    return Init_RRTSPoints_Response_point_count(msg_);
  }

private:
  ::apf_interfaces::srv::RRTSPoints_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::apf_interfaces::srv::RRTSPoints_Response>()
{
  return apf_interfaces::srv::builder::Init_RRTSPoints_Response_result_points();
}

}  // namespace apf_interfaces

#endif  // APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__BUILDER_HPP_
