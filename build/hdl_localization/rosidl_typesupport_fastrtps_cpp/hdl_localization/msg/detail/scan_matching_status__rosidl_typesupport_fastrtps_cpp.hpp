// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#ifndef HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "hdl_localization/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "hdl_localization/msg/detail/scan_matching_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace hdl_localization
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_localization
cdr_serialize(
  const hdl_localization::msg::ScanMatchingStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_localization
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hdl_localization::msg::ScanMatchingStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_localization
get_serialized_size(
  const hdl_localization::msg::ScanMatchingStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_localization
max_serialized_size_ScanMatchingStatus(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hdl_localization

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_localization
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hdl_localization, msg, ScanMatchingStatus)();

#ifdef __cplusplus
}
#endif

#endif  // HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
