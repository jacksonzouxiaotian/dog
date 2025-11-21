// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#ifndef HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__BUILDER_HPP_
#define HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__BUILDER_HPP_

#include "hdl_localization/msg/detail/scan_matching_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hdl_localization
{

namespace msg
{

namespace builder
{

class Init_ScanMatchingStatus_prediction_errors
{
public:
  explicit Init_ScanMatchingStatus_prediction_errors(::hdl_localization::msg::ScanMatchingStatus & msg)
  : msg_(msg)
  {}
  ::hdl_localization::msg::ScanMatchingStatus prediction_errors(::hdl_localization::msg::ScanMatchingStatus::_prediction_errors_type arg)
  {
    msg_.prediction_errors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

class Init_ScanMatchingStatus_prediction_labels
{
public:
  explicit Init_ScanMatchingStatus_prediction_labels(::hdl_localization::msg::ScanMatchingStatus & msg)
  : msg_(msg)
  {}
  Init_ScanMatchingStatus_prediction_errors prediction_labels(::hdl_localization::msg::ScanMatchingStatus::_prediction_labels_type arg)
  {
    msg_.prediction_labels = std::move(arg);
    return Init_ScanMatchingStatus_prediction_errors(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

class Init_ScanMatchingStatus_relative_pose
{
public:
  explicit Init_ScanMatchingStatus_relative_pose(::hdl_localization::msg::ScanMatchingStatus & msg)
  : msg_(msg)
  {}
  Init_ScanMatchingStatus_prediction_labels relative_pose(::hdl_localization::msg::ScanMatchingStatus::_relative_pose_type arg)
  {
    msg_.relative_pose = std::move(arg);
    return Init_ScanMatchingStatus_prediction_labels(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

class Init_ScanMatchingStatus_inlier_fraction
{
public:
  explicit Init_ScanMatchingStatus_inlier_fraction(::hdl_localization::msg::ScanMatchingStatus & msg)
  : msg_(msg)
  {}
  Init_ScanMatchingStatus_relative_pose inlier_fraction(::hdl_localization::msg::ScanMatchingStatus::_inlier_fraction_type arg)
  {
    msg_.inlier_fraction = std::move(arg);
    return Init_ScanMatchingStatus_relative_pose(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

class Init_ScanMatchingStatus_matching_error
{
public:
  explicit Init_ScanMatchingStatus_matching_error(::hdl_localization::msg::ScanMatchingStatus & msg)
  : msg_(msg)
  {}
  Init_ScanMatchingStatus_inlier_fraction matching_error(::hdl_localization::msg::ScanMatchingStatus::_matching_error_type arg)
  {
    msg_.matching_error = std::move(arg);
    return Init_ScanMatchingStatus_inlier_fraction(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

class Init_ScanMatchingStatus_has_converged
{
public:
  explicit Init_ScanMatchingStatus_has_converged(::hdl_localization::msg::ScanMatchingStatus & msg)
  : msg_(msg)
  {}
  Init_ScanMatchingStatus_matching_error has_converged(::hdl_localization::msg::ScanMatchingStatus::_has_converged_type arg)
  {
    msg_.has_converged = std::move(arg);
    return Init_ScanMatchingStatus_matching_error(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

class Init_ScanMatchingStatus_header
{
public:
  Init_ScanMatchingStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScanMatchingStatus_has_converged header(::hdl_localization::msg::ScanMatchingStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ScanMatchingStatus_has_converged(msg_);
  }

private:
  ::hdl_localization::msg::ScanMatchingStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdl_localization::msg::ScanMatchingStatus>()
{
  return hdl_localization::msg::builder::Init_ScanMatchingStatus_header();
}

}  // namespace hdl_localization

#endif  // HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__BUILDER_HPP_
