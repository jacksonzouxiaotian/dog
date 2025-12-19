// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hdl_global_localization:srv/SetGlobalLocalizationEngine.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__TRAITS_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__TRAITS_HPP_

#include "hdl_global_localization/srv/detail/set_global_localization_engine__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'engine_name'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>()
{
  return "hdl_global_localization::srv::SetGlobalLocalizationEngine_Request";
}

template<>
inline const char * name<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>()
{
  return "hdl_global_localization/srv/SetGlobalLocalizationEngine_Request";
}

template<>
struct has_fixed_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>()
{
  return "hdl_global_localization::srv::SetGlobalLocalizationEngine_Response";
}

template<>
inline const char * name<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>()
{
  return "hdl_global_localization/srv/SetGlobalLocalizationEngine_Response";
}

template<>
struct has_fixed_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hdl_global_localization::srv::SetGlobalLocalizationEngine>()
{
  return "hdl_global_localization::srv::SetGlobalLocalizationEngine";
}

template<>
inline const char * name<hdl_global_localization::srv::SetGlobalLocalizationEngine>()
{
  return "hdl_global_localization/srv/SetGlobalLocalizationEngine";
}

template<>
struct has_fixed_size<hdl_global_localization::srv::SetGlobalLocalizationEngine>
  : std::integral_constant<
    bool,
    has_fixed_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>::value &&
    has_fixed_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>::value
  >
{
};

template<>
struct has_bounded_size<hdl_global_localization::srv::SetGlobalLocalizationEngine>
  : std::integral_constant<
    bool,
    has_bounded_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>::value &&
    has_bounded_size<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>::value
  >
{
};

template<>
struct is_service<hdl_global_localization::srv::SetGlobalLocalizationEngine>
  : std::true_type
{
};

template<>
struct is_service_request<hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__TRAITS_HPP_
