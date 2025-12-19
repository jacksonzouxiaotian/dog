// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__BUILDER_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__BUILDER_HPP_

#include "hdl_global_localization/srv/detail/set_global_map__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hdl_global_localization
{

namespace srv
{

namespace builder
{

class Init_SetGlobalMap_Request_global_map
{
public:
  Init_SetGlobalMap_Request_global_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hdl_global_localization::srv::SetGlobalMap_Request global_map(::hdl_global_localization::srv::SetGlobalMap_Request::_global_map_type arg)
  {
    msg_.global_map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hdl_global_localization::srv::SetGlobalMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::hdl_global_localization::srv::SetGlobalMap_Request>()
{
  return hdl_global_localization::srv::builder::Init_SetGlobalMap_Request_global_map();
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
auto build<::hdl_global_localization::srv::SetGlobalMap_Response>()
{
  return ::hdl_global_localization::srv::SetGlobalMap_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace hdl_global_localization

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__BUILDER_HPP_
