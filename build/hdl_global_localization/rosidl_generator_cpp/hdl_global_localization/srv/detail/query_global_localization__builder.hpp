// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__BUILDER_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__BUILDER_HPP_

#include "hdl_global_localization/srv/detail/query_global_localization__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hdl_global_localization
{

namespace srv
{

namespace builder
{

class Init_QueryGlobalLocalization_Request_cloud
{
public:
  explicit Init_QueryGlobalLocalization_Request_cloud(::hdl_global_localization::srv::QueryGlobalLocalization_Request & msg)
  : msg_(msg)
  {}
  ::hdl_global_localization::srv::QueryGlobalLocalization_Request cloud(::hdl_global_localization::srv::QueryGlobalLocalization_Request::_cloud_type arg)
  {
    msg_.cloud = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Request msg_;
};

class Init_QueryGlobalLocalization_Request_max_num_candidates
{
public:
  Init_QueryGlobalLocalization_Request_max_num_candidates()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QueryGlobalLocalization_Request_cloud max_num_candidates(::hdl_global_localization::srv::QueryGlobalLocalization_Request::_max_num_candidates_type arg)
  {
    msg_.max_num_candidates = std::move(arg);
    return Init_QueryGlobalLocalization_Request_cloud(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdl_global_localization::srv::QueryGlobalLocalization_Request>()
{
  return hdl_global_localization::srv::builder::Init_QueryGlobalLocalization_Request_max_num_candidates();
}

}  // namespace hdl_global_localization


namespace hdl_global_localization
{

namespace srv
{

namespace builder
{

class Init_QueryGlobalLocalization_Response_poses
{
public:
  explicit Init_QueryGlobalLocalization_Response_poses(::hdl_global_localization::srv::QueryGlobalLocalization_Response & msg)
  : msg_(msg)
  {}
  ::hdl_global_localization::srv::QueryGlobalLocalization_Response poses(::hdl_global_localization::srv::QueryGlobalLocalization_Response::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Response msg_;
};

class Init_QueryGlobalLocalization_Response_errors
{
public:
  explicit Init_QueryGlobalLocalization_Response_errors(::hdl_global_localization::srv::QueryGlobalLocalization_Response & msg)
  : msg_(msg)
  {}
  Init_QueryGlobalLocalization_Response_poses errors(::hdl_global_localization::srv::QueryGlobalLocalization_Response::_errors_type arg)
  {
    msg_.errors = std::move(arg);
    return Init_QueryGlobalLocalization_Response_poses(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Response msg_;
};

class Init_QueryGlobalLocalization_Response_inlier_fractions
{
public:
  explicit Init_QueryGlobalLocalization_Response_inlier_fractions(::hdl_global_localization::srv::QueryGlobalLocalization_Response & msg)
  : msg_(msg)
  {}
  Init_QueryGlobalLocalization_Response_errors inlier_fractions(::hdl_global_localization::srv::QueryGlobalLocalization_Response::_inlier_fractions_type arg)
  {
    msg_.inlier_fractions = std::move(arg);
    return Init_QueryGlobalLocalization_Response_errors(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Response msg_;
};

class Init_QueryGlobalLocalization_Response_globalmap_header
{
public:
  explicit Init_QueryGlobalLocalization_Response_globalmap_header(::hdl_global_localization::srv::QueryGlobalLocalization_Response & msg)
  : msg_(msg)
  {}
  Init_QueryGlobalLocalization_Response_inlier_fractions globalmap_header(::hdl_global_localization::srv::QueryGlobalLocalization_Response::_globalmap_header_type arg)
  {
    msg_.globalmap_header = std::move(arg);
    return Init_QueryGlobalLocalization_Response_inlier_fractions(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Response msg_;
};

class Init_QueryGlobalLocalization_Response_header
{
public:
  Init_QueryGlobalLocalization_Response_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QueryGlobalLocalization_Response_globalmap_header header(::hdl_global_localization::srv::QueryGlobalLocalization_Response::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_QueryGlobalLocalization_Response_globalmap_header(msg_);
  }

private:
  ::hdl_global_localization::srv::QueryGlobalLocalization_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdl_global_localization::srv::QueryGlobalLocalization_Response>()
{
  return hdl_global_localization::srv::builder::Init_QueryGlobalLocalization_Response_header();
}

}  // namespace hdl_global_localization

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__BUILDER_HPP_
