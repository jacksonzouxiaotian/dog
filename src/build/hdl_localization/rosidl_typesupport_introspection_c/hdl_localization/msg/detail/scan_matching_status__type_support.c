// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hdl_localization/msg/detail/scan_matching_status__rosidl_typesupport_introspection_c.h"
#include "hdl_localization/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hdl_localization/msg/detail/scan_matching_status__functions.h"
#include "hdl_localization/msg/detail/scan_matching_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `relative_pose`
// Member `prediction_errors`
#include "geometry_msgs/msg/transform.h"
// Member `relative_pose`
// Member `prediction_errors`
#include "geometry_msgs/msg/detail/transform__rosidl_typesupport_introspection_c.h"
// Member `prediction_labels`
#include "std_msgs/msg/string.h"
// Member `prediction_labels`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hdl_localization__msg__ScanMatchingStatus__init(message_memory);
}

void ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_fini_function(void * message_memory)
{
  hdl_localization__msg__ScanMatchingStatus__fini(message_memory);
}

size_t ScanMatchingStatus__rosidl_typesupport_introspection_c__size_function__String__prediction_labels(
  const void * untyped_member)
{
  const std_msgs__msg__String__Sequence * member =
    (const std_msgs__msg__String__Sequence *)(untyped_member);
  return member->size;
}

const void * ScanMatchingStatus__rosidl_typesupport_introspection_c__get_const_function__String__prediction_labels(
  const void * untyped_member, size_t index)
{
  const std_msgs__msg__String__Sequence * member =
    (const std_msgs__msg__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ScanMatchingStatus__rosidl_typesupport_introspection_c__get_function__String__prediction_labels(
  void * untyped_member, size_t index)
{
  std_msgs__msg__String__Sequence * member =
    (std_msgs__msg__String__Sequence *)(untyped_member);
  return &member->data[index];
}

bool ScanMatchingStatus__rosidl_typesupport_introspection_c__resize_function__String__prediction_labels(
  void * untyped_member, size_t size)
{
  std_msgs__msg__String__Sequence * member =
    (std_msgs__msg__String__Sequence *)(untyped_member);
  std_msgs__msg__String__Sequence__fini(member);
  return std_msgs__msg__String__Sequence__init(member, size);
}

size_t ScanMatchingStatus__rosidl_typesupport_introspection_c__size_function__Transform__prediction_errors(
  const void * untyped_member)
{
  const geometry_msgs__msg__Transform__Sequence * member =
    (const geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  return member->size;
}

const void * ScanMatchingStatus__rosidl_typesupport_introspection_c__get_const_function__Transform__prediction_errors(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Transform__Sequence * member =
    (const geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ScanMatchingStatus__rosidl_typesupport_introspection_c__get_function__Transform__prediction_errors(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Transform__Sequence * member =
    (geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  return &member->data[index];
}

bool ScanMatchingStatus__rosidl_typesupport_introspection_c__resize_function__Transform__prediction_errors(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Transform__Sequence * member =
    (geometry_msgs__msg__Transform__Sequence *)(untyped_member);
  geometry_msgs__msg__Transform__Sequence__fini(member);
  return geometry_msgs__msg__Transform__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "has_converged",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, has_converged),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "matching_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, matching_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inlier_fraction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, inlier_fraction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "relative_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, relative_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "prediction_labels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, prediction_labels),  // bytes offset in struct
    NULL,  // default value
    ScanMatchingStatus__rosidl_typesupport_introspection_c__size_function__String__prediction_labels,  // size() function pointer
    ScanMatchingStatus__rosidl_typesupport_introspection_c__get_const_function__String__prediction_labels,  // get_const(index) function pointer
    ScanMatchingStatus__rosidl_typesupport_introspection_c__get_function__String__prediction_labels,  // get(index) function pointer
    ScanMatchingStatus__rosidl_typesupport_introspection_c__resize_function__String__prediction_labels  // resize(index) function pointer
  },
  {
    "prediction_errors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_localization__msg__ScanMatchingStatus, prediction_errors),  // bytes offset in struct
    NULL,  // default value
    ScanMatchingStatus__rosidl_typesupport_introspection_c__size_function__Transform__prediction_errors,  // size() function pointer
    ScanMatchingStatus__rosidl_typesupport_introspection_c__get_const_function__Transform__prediction_errors,  // get_const(index) function pointer
    ScanMatchingStatus__rosidl_typesupport_introspection_c__get_function__Transform__prediction_errors,  // get(index) function pointer
    ScanMatchingStatus__rosidl_typesupport_introspection_c__resize_function__Transform__prediction_errors  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_members = {
  "hdl_localization__msg",  // message namespace
  "ScanMatchingStatus",  // message name
  7,  // number of fields
  sizeof(hdl_localization__msg__ScanMatchingStatus),
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_member_array,  // message members
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_type_support_handle = {
  0,
  &ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hdl_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_localization, msg, ScanMatchingStatus)() {
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Transform)();
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Transform)();
  if (!ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_type_support_handle.typesupport_identifier) {
    ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ScanMatchingStatus__rosidl_typesupport_introspection_c__ScanMatchingStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
