// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__JACOBIAN__BUILDER_HPP_
#define APF_INTERFACES__MSG__DETAIL__JACOBIAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "apf_interfaces/msg/detail/jacobian__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace apf_interfaces
{

namespace msg
{

namespace builder
{

class Init_Jacobian_col_num3
{
public:
  explicit Init_Jacobian_col_num3(::apf_interfaces::msg::Jacobian & msg)
  : msg_(msg)
  {}
  ::apf_interfaces::msg::Jacobian col_num3(::apf_interfaces::msg::Jacobian::_col_num3_type arg)
  {
    msg_.col_num3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::apf_interfaces::msg::Jacobian msg_;
};

class Init_Jacobian_flat_jacobian3
{
public:
  explicit Init_Jacobian_flat_jacobian3(::apf_interfaces::msg::Jacobian & msg)
  : msg_(msg)
  {}
  Init_Jacobian_col_num3 flat_jacobian3(::apf_interfaces::msg::Jacobian::_flat_jacobian3_type arg)
  {
    msg_.flat_jacobian3 = std::move(arg);
    return Init_Jacobian_col_num3(msg_);
  }

private:
  ::apf_interfaces::msg::Jacobian msg_;
};

class Init_Jacobian_col_num5
{
public:
  explicit Init_Jacobian_col_num5(::apf_interfaces::msg::Jacobian & msg)
  : msg_(msg)
  {}
  Init_Jacobian_flat_jacobian3 col_num5(::apf_interfaces::msg::Jacobian::_col_num5_type arg)
  {
    msg_.col_num5 = std::move(arg);
    return Init_Jacobian_flat_jacobian3(msg_);
  }

private:
  ::apf_interfaces::msg::Jacobian msg_;
};

class Init_Jacobian_flat_jacobian5
{
public:
  explicit Init_Jacobian_flat_jacobian5(::apf_interfaces::msg::Jacobian & msg)
  : msg_(msg)
  {}
  Init_Jacobian_col_num5 flat_jacobian5(::apf_interfaces::msg::Jacobian::_flat_jacobian5_type arg)
  {
    msg_.flat_jacobian5 = std::move(arg);
    return Init_Jacobian_col_num5(msg_);
  }

private:
  ::apf_interfaces::msg::Jacobian msg_;
};

class Init_Jacobian_col_num
{
public:
  explicit Init_Jacobian_col_num(::apf_interfaces::msg::Jacobian & msg)
  : msg_(msg)
  {}
  Init_Jacobian_flat_jacobian5 col_num(::apf_interfaces::msg::Jacobian::_col_num_type arg)
  {
    msg_.col_num = std::move(arg);
    return Init_Jacobian_flat_jacobian5(msg_);
  }

private:
  ::apf_interfaces::msg::Jacobian msg_;
};

class Init_Jacobian_flat_jacobian
{
public:
  Init_Jacobian_flat_jacobian()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jacobian_col_num flat_jacobian(::apf_interfaces::msg::Jacobian::_flat_jacobian_type arg)
  {
    msg_.flat_jacobian = std::move(arg);
    return Init_Jacobian_col_num(msg_);
  }

private:
  ::apf_interfaces::msg::Jacobian msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::apf_interfaces::msg::Jacobian>()
{
  return apf_interfaces::msg::builder::Init_Jacobian_flat_jacobian();
}

}  // namespace apf_interfaces

#endif  // APF_INTERFACES__MSG__DETAIL__JACOBIAN__BUILDER_HPP_
