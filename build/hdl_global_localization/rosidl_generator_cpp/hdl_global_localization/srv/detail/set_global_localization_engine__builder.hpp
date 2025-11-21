// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hdl_global_localization:srv/SetGlobalLocalizationEngine.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__BUILDER_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__BUILDER_HPP_

#include "hdl_global_localization/srv/detail/set_global_localization_engine__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hdl_global_localization
{

namespace srv
{

namespace builder
{

class Init_SetGlobalLocalizationEngine_Request_engine_name
{
public:
  Init_SetGlobalLocalizationEngine_Request_engine_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hdl_global_localization::srv::SetGlobalLocalizationEngine_Request engine_name(::hdl_global_localization::srv::SetGlobalLocalizationEngine_Request::_engine_name_type arg)
  {
    msg_.engine_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdl_global_localization::srv::SetGlobalLocalizationEngine_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdl_global_localization::srv::SetGlobalLocalizationEngine_Request>()
{
  return hdl_global_localization::srv::builder::Init_SetGlobalLocalizationEngine_Request_engine_name();
}

}  // namespace hdl_global_localization


namespace hdl_global_localization
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdl_global_localization::srv::SetGlobalLocalizationEngine_Response>()
{
  return ::hdl_global_localization::srv::SetGlobalLocalizationEngine_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace hdl_global_localization

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__BUILDER_HPP_
