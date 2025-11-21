// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hdl_localization/msg/detail/scan_matching_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hdl_localization
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ScanMatchingStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hdl_localization::msg::ScanMatchingStatus(_init);
}

void ScanMatchingStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hdl_localization::msg::ScanMatchingStatus *>(message_memory);
  typed_message->~ScanMatchingStatus();
}

size_t size_function__ScanMatchingStatus__prediction_labels(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std_msgs::msg::String> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ScanMatchingStatus__prediction_labels(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std_msgs::msg::String> *>(untyped_member);
  return &member[index];
}

void * get_function__ScanMatchingStatus__prediction_labels(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std_msgs::msg::String> *>(untyped_member);
  return &member[index];
}

void resize_function__ScanMatchingStatus__prediction_labels(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std_msgs::msg::String> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ScanMatchingStatus__prediction_errors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Transform> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ScanMatchingStatus__prediction_errors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Transform> *>(untyped_member);
  return &member[index];
}

void * get_function__ScanMatchingStatus__prediction_errors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Transform> *>(untyped_member);
  return &member[index];
}

void resize_function__ScanMatchingStatus__prediction_errors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Transform> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ScanMatchingStatus_message_member_array[7] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "has_converged",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, has_converged),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "matching_error",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, matching_error),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "inlier_fraction",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, inlier_fraction),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "relative_pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Transform>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, relative_pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "prediction_labels",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::String>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, prediction_labels),  // bytes offset in struct
    nullptr,  // default value
    size_function__ScanMatchingStatus__prediction_labels,  // size() function pointer
    get_const_function__ScanMatchingStatus__prediction_labels,  // get_const(index) function pointer
    get_function__ScanMatchingStatus__prediction_labels,  // get(index) function pointer
    resize_function__ScanMatchingStatus__prediction_labels  // resize(index) function pointer
  },
  {
    "prediction_errors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Transform>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization::msg::ScanMatchingStatus, prediction_errors),  // bytes offset in struct
    nullptr,  // default value
    size_function__ScanMatchingStatus__prediction_errors,  // size() function pointer
    get_const_function__ScanMatchingStatus__prediction_errors,  // get_const(index) function pointer
    get_function__ScanMatchingStatus__prediction_errors,  // get(index) function pointer
    resize_function__ScanMatchingStatus__prediction_errors  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ScanMatchingStatus_message_members = {
  "hdl_localization::msg",  // message namespace
  "ScanMatchingStatus",  // message name
  7,  // number of fields
  sizeof(hdl_localization::msg::ScanMatchingStatus),
  ScanMatchingStatus_message_member_array,  // message members
  ScanMatchingStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  ScanMatchingStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ScanMatchingStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ScanMatchingStatus_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hdl_localization


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hdl_localization::msg::ScanMatchingStatus>()
{
  return &::hdl_localization::msg::rosidl_typesupport_introspection_cpp::ScanMatchingStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hdl_localization, msg, ScanMatchingStatus)() {
  return &::hdl_localization::msg::rosidl_typesupport_introspection_cpp::ScanMatchingStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
