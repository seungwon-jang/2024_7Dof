// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__JACOBIAN__STRUCT_HPP_
#define APF_INTERFACES__MSG__DETAIL__JACOBIAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__apf_interfaces__msg__Jacobian __attribute__((deprecated))
#else
# define DEPRECATED__apf_interfaces__msg__Jacobian __declspec(deprecated)
#endif

namespace apf_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Jacobian_
{
  using Type = Jacobian_<ContainerAllocator>;

  explicit Jacobian_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->col_num = 0l;
      this->col_num5 = 0l;
      this->col_num3 = 0l;
    }
  }

  explicit Jacobian_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->col_num = 0l;
      this->col_num5 = 0l;
      this->col_num3 = 0l;
    }
  }

  // field types and members
  using _flat_jacobian_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _flat_jacobian_type flat_jacobian;
  using _col_num_type =
    int32_t;
  _col_num_type col_num;
  using _flat_jacobian5_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _flat_jacobian5_type flat_jacobian5;
  using _col_num5_type =
    int32_t;
  _col_num5_type col_num5;
  using _flat_jacobian3_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _flat_jacobian3_type flat_jacobian3;
  using _col_num3_type =
    int32_t;
  _col_num3_type col_num3;

  // setters for named parameter idiom
  Type & set__flat_jacobian(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->flat_jacobian = _arg;
    return *this;
  }
  Type & set__col_num(
    const int32_t & _arg)
  {
    this->col_num = _arg;
    return *this;
  }
  Type & set__flat_jacobian5(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->flat_jacobian5 = _arg;
    return *this;
  }
  Type & set__col_num5(
    const int32_t & _arg)
  {
    this->col_num5 = _arg;
    return *this;
  }
  Type & set__flat_jacobian3(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->flat_jacobian3 = _arg;
    return *this;
  }
  Type & set__col_num3(
    const int32_t & _arg)
  {
    this->col_num3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    apf_interfaces::msg::Jacobian_<ContainerAllocator> *;
  using ConstRawPtr =
    const apf_interfaces::msg::Jacobian_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::msg::Jacobian_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      apf_interfaces::msg::Jacobian_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__apf_interfaces__msg__Jacobian
    std::shared_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__apf_interfaces__msg__Jacobian
    std::shared_ptr<apf_interfaces::msg::Jacobian_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jacobian_ & other) const
  {
    if (this->flat_jacobian != other.flat_jacobian) {
      return false;
    }
    if (this->col_num != other.col_num) {
      return false;
    }
    if (this->flat_jacobian5 != other.flat_jacobian5) {
      return false;
    }
    if (this->col_num5 != other.col_num5) {
      return false;
    }
    if (this->flat_jacobian3 != other.flat_jacobian3) {
      return false;
    }
    if (this->col_num3 != other.col_num3) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jacobian_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jacobian_

// alias to use template instance with default allocator
using Jacobian =
  apf_interfaces::msg::Jacobian_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace apf_interfaces

#endif  // APF_INTERFACES__MSG__DETAIL__JACOBIAN__STRUCT_HPP_
