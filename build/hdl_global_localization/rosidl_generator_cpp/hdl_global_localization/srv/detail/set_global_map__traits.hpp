// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__TRAITS_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__TRAITS_HPP_

#include "hdl_global_localization/srv/detail/set_global_map__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'global_map'
#include "sensor_msgs/msg/detail/point_cloud2__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_global_localization::srv::SetGlobalMap_Request>()
{
  return "hdl_global_localization::srv::SetGlobalMap_Request";
}

template<>
inline const char * name<hdl_global_localization::srv::SetGlobalMap_Request>()
{
  return "hdl_global_localization/srv/SetGlobalMap_Request";
}

template<>
struct has_fixed_size<hdl_global_localization::srv::SetGlobalMap_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct has_bounded_size<hdl_global_localization::srv::SetGlobalMap_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::PointCloud2>::value> {};

template<>
struct is_message<hdl_global_localization::srv::SetGlobalMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_global_localization::srv::SetGlobalMap_Response>()
{
  return "hdl_global_localization::srv::SetGlobalMap_Response";
}

template<>
inline const char * name<hdl_global_localization::srv::SetGlobalMap_Response>()
{
  return "hdl_global_localization/srv/SetGlobalMap_Response";
}

template<>
struct has_fixed_size<hdl_global_localization::srv::SetGlobalMap_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hdl_global_localization::srv::SetGlobalMap_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hdl_global_localization::srv::SetGlobalMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_global_localization::srv::SetGlobalMap>()
{
  return "hdl_global_localization::srv::SetGlobalMap";
}

template<>
inline const char * name<hdl_global_localization::srv::SetGlobalMap>()
{
  return "hdl_global_localization/srv/SetGlobalMap";
}

template<>
struct has_fixed_size<hdl_global_localization::srv::SetGlobalMap>
  : std::integral_constant<
    bool,
    has_fixed_size<hdl_global_localization::srv::SetGlobalMap_Request>::value &&
    has_fixed_size<hdl_global_localization::srv::SetGlobalMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<hdl_global_localization::srv::SetGlobalMap>
  : std::integral_constant<
    bool,
    has_bounded_size<hdl_global_localization::srv::SetGlobalMap_Request>::value &&
    has_bounded_size<hdl_global_localization::srv::SetGlobalMap_Response>::value
  >
{
};

template<>
struct is_service<hdl_global_localization::srv::SetGlobalMap>
  : std::true_type
{
};

template<>
struct is_service_request<hdl_global_localization::srv::SetGlobalMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hdl_global_localization::srv::SetGlobalMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__TRAITS_HPP_
