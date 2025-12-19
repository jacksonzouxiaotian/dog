// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#ifndef HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__TRAITS_HPP_
#define HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__TRAITS_HPP_

#include "hdl_localization/msg/detail/scan_matching_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'relative_pose'
#include "geometry_msgs/msg/detail/transform__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_localization::msg::ScanMatchingStatus>()
{
  return "hdl_localization::msg::ScanMatchingStatus";
}

template<>
inline const char * name<hdl_localization::msg::ScanMatchingStatus>()
{
  return "hdl_localization/msg/ScanMatchingStatus";
}

template<>
struct has_fixed_size<hdl_localization::msg::ScanMatchingStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hdl_localization::msg::ScanMatchingStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hdl_localization::msg::ScanMatchingStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__TRAITS_HPP_
