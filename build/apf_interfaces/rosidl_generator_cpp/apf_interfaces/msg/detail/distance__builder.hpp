// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__DISTANCE__BUILDER_HPP_
#define APF_INTERFACES__MSG__DETAIL__DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "apf_interfaces/msg/detail/distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace apf_interfaces
{

namespace msg
{

namespace builder
{

class Init_Distance_link_count
{
public:
  explicit Init_Distance_link_count(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  ::apf_interfaces::msg::Distance link_count(::apf_interfaces::msg::Distance::_link_count_type arg)
  {
    msg_.link_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_obstacle_count
{
public:
  explicit Init_Distance_obstacle_count(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_link_count obstacle_count(::apf_interfaces::msg::Distance::_obstacle_count_type arg)
  {
    msg_.obstacle_count = std::move(arg);
    return Init_Distance_link_count(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_obstacle_direction_vector
{
public:
  explicit Init_Distance_obstacle_direction_vector(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_obstacle_count obstacle_direction_vector(::apf_interfaces::msg::Distance::_obstacle_direction_vector_type arg)
  {
    msg_.obstacle_direction_vector = std::move(arg);
    return Init_Distance_obstacle_count(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_obstacle_distance
{
public:
  explicit Init_Distance_obstacle_distance(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_obstacle_direction_vector obstacle_distance(::apf_interfaces::msg::Distance::_obstacle_distance_type arg)
  {
    msg_.obstacle_distance = std::move(arg);
    return Init_Distance_obstacle_direction_vector(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_end_angle_distance
{
public:
  explicit Init_Distance_end_angle_distance(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_obstacle_distance end_angle_distance(::apf_interfaces::msg::Distance::_end_angle_distance_type arg)
  {
    msg_.end_angle_distance = std::move(arg);
    return Init_Distance_obstacle_distance(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_end_distance
{
public:
  explicit Init_Distance_end_distance(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_end_angle_distance end_distance(::apf_interfaces::msg::Distance::_end_distance_type arg)
  {
    msg_.end_distance = std::move(arg);
    return Init_Distance_end_angle_distance(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_target_point
{
public:
  explicit Init_Distance_target_point(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_end_distance target_point(::apf_interfaces::msg::Distance::_target_point_type arg)
  {
    msg_.target_point = std::move(arg);
    return Init_Distance_end_distance(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_direction_vector
{
public:
  explicit Init_Distance_direction_vector(::apf_interfaces::msg::Distance & msg)
  : msg_(msg)
  {}
  Init_Distance_target_point direction_vector(::apf_interfaces::msg::Distance::_direction_vector_type arg)
  {
    msg_.direction_vector = std::move(arg);
    return Init_Distance_target_point(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

class Init_Distance_end_point
{
public:
  Init_Distance_end_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distance_direction_vector end_point(::apf_interfaces::msg::Distance::_end_point_type arg)
  {
    msg_.end_point = std::move(arg);
    return Init_Distance_direction_vector(msg_);
  }

private:
  ::apf_interfaces::msg::Distance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::apf_interfaces::msg::Distance>()
{
  return apf_interfaces::msg::builder::Init_Distance_end_point();
}

}  // namespace apf_interfaces

#endif  // APF_INTERFACES__MSG__DETAIL__DISTANCE__BUILDER_HPP_
