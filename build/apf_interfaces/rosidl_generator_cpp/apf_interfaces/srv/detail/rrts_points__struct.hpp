// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from apf_interfaces:srv/RRTSPoints.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__STRUCT_HPP_
#define APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__apf_interfaces__srv__RRTSPoints_Request __attribute__((deprecated))
#else
# define DEPRECATED__apf_interfaces__srv__RRTSPoints_Request __declspec(deprecated)
#endif

namespace apf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RRTSPoints_Request_
{
  using Type = RRTSPoints_Request_<ContainerAllocator>;

  explicit RRTSPoints_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_count = 0ll;
    }
  }

  explicit RRTSPoints_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_count = 0ll;
    }
  }

  // field types and members
  using _obstacle_points_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _obstacle_points_type obstacle_points;
  using _obstacle_count_type =
    int64_t;
  _obstacle_count_type obstacle_count;
  using _start_point_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _start_point_type start_point;
  using _end_point_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _end_point_type end_point;

  // setters for named parameter idiom
  Type & set__obstacle_points(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->obstacle_points = _arg;
    return *this;
  }
  Type & set__obstacle_count(
    const int64_t & _arg)
  {
    this->obstacle_count = _arg;
    return *this;
  }
  Type & set__start_point(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->start_point = _arg;
    return *this;
  }
  Type & set__end_point(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->end_point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__apf_interfaces__srv__RRTSPoints_Request
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__apf_interfaces__srv__RRTSPoints_Request
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RRTSPoints_Request_ & other) const
  {
    if (this->obstacle_points != other.obstacle_points) {
      return false;
    }
    if (this->obstacle_count != other.obstacle_count) {
      return false;
    }
    if (this->start_point != other.start_point) {
      return false;
    }
    if (this->end_point != other.end_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const RRTSPoints_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RRTSPoints_Request_

// alias to use template instance with default allocator
using RRTSPoints_Request =
  apf_interfaces::srv::RRTSPoints_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace apf_interfaces


#ifndef _WIN32
# define DEPRECATED__apf_interfaces__srv__RRTSPoints_Response __attribute__((deprecated))
#else
# define DEPRECATED__apf_interfaces__srv__RRTSPoints_Response __declspec(deprecated)
#endif

namespace apf_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RRTSPoints_Response_
{
  using Type = RRTSPoints_Response_<ContainerAllocator>;

  explicit RRTSPoints_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->point_count = 0ll;
    }
  }

  explicit RRTSPoints_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->point_count = 0ll;
    }
  }

  // field types and members
  using _result_points_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _result_points_type result_points;
  using _point_count_type =
    int64_t;
  _point_count_type point_count;

  // setters for named parameter idiom
  Type & set__result_points(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->result_points = _arg;
    return *this;
  }
  Type & set__point_count(
    const int64_t & _arg)
  {
    this->point_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__apf_interfaces__srv__RRTSPoints_Response
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__apf_interfaces__srv__RRTSPoints_Response
    std::shared_ptr<apf_interfaces::srv::RRTSPoints_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RRTSPoints_Response_ & other) const
  {
    if (this->result_points != other.result_points) {
      return false;
    }
    if (this->point_count != other.point_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const RRTSPoints_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RRTSPoints_Response_

// alias to use template instance with default allocator
using RRTSPoints_Response =
  apf_interfaces::srv::RRTSPoints_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace apf_interfaces

namespace apf_interfaces
{

namespace srv
{

struct RRTSPoints
{
  using Request = apf_interfaces::srv::RRTSPoints_Request;
  using Response = apf_interfaces::srv::RRTSPoints_Response;
};

}  // namespace srv

}  // namespace apf_interfaces

#endif  // APF_INTERFACES__SRV__DETAIL__RRTS_POINTS__STRUCT_HPP_
