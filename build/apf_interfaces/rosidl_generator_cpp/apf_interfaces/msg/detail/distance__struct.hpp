// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_HPP_
#define APF_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'end_point'
// Member 'direction_vector'
// Member 'target_point'
// Member 'end_angle_distance'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__apf_interfaces__msg__Distance __attribute__((deprecated))
#else
# define DEPRECATED__apf_interfaces__msg__Distance __declspec(deprecated)
#endif

namespace apf_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Distance_
{
  using Type = Distance_<ContainerAllocator>;

  explicit Distance_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : end_point(_init),
    direction_vector(_init),
    target_point(_init),
    end_angle_distance(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->end_distance = 0.0;
    }
  }

  explicit Distance_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : end_point(_alloc, _init),
    direction_vector(_alloc, _init),
    target_point(_alloc, _init),
    end_angle_distance(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->end_distance = 0.0;
    }
  }

  // field types and members
  using _end_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _end_point_type end_point;
  using _direction_vector_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _direction_vector_type direction_vector;
  using _target_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _target_point_type target_point;
  using _end_distance_type =
    double;
  _end_distance_type end_distance;
  using _end_angle_distance_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _end_angle_distance_type end_angle_distance;

  // setters for named parameter idiom
  Type & set__end_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->end_point = _arg;
    return *this;
  }
  Type & set__direction_vector(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->direction_vector = _arg;
    return *this;
  }
  Type & set__target_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->target_point = _arg;
    return *this;
  }
  Type & set__end_distance(
    const double & _arg)
  {
    this->end_distance = _arg;
    return *this;
  }
  Type & set__end_angle_distance(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->end_angle_distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    apf_interfaces::msg::Distance_<ContainerAllocator> *;
  using ConstRawPtr =
    const apf_interfaces::msg::Distance_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<apf_interfaces::msg::Distance_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<apf_interfaces::msg::Distance_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::msg::Distance_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::msg::Distance_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::msg::Distance_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::msg::Distance_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<apf_interfaces::msg::Distance_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<apf_interfaces::msg::Distance_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__apf_interfaces__msg__Distance
    std::shared_ptr<apf_interfaces::msg::Distance_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__apf_interfaces__msg__Distance
    std::shared_ptr<apf_interfaces::msg::Distance_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Distance_ & other) const
  {
    if (this->end_point != other.end_point) {
      return false;
    }
    if (this->direction_vector != other.direction_vector) {
      return false;
    }
    if (this->target_point != other.target_point) {
      return false;
    }
    if (this->end_distance != other.end_distance) {
      return false;
    }
    if (this->end_angle_distance != other.end_angle_distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const Distance_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Distance_

// alias to use template instance with default allocator
using Distance =
  apf_interfaces::msg::Distance_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace apf_interfaces

#endif  // APF_INTERFACES__MSG__DETAIL__DISTANCE__STRUCT_HPP_
