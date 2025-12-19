// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#ifndef HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__STRUCT_H_
#define HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'relative_pose'
// Member 'prediction_errors'
#include "geometry_msgs/msg/detail/transform__struct.h"
// Member 'prediction_labels'
#include "std_msgs/msg/detail/string__struct.h"

// Struct defined in msg/ScanMatchingStatus in the package hdl_localization.
typedef struct hdl_localization__msg__ScanMatchingStatus
{
  std_msgs__msg__Header header;
  bool has_converged;
  float matching_error;
  float inlier_fraction;
  geometry_msgs__msg__Transform relative_pose;
  std_msgs__msg__String__Sequence prediction_labels;
  geometry_msgs__msg__Transform__Sequence prediction_errors;
} hdl_localization__msg__ScanMatchingStatus;

// Struct for a sequence of hdl_localization__msg__ScanMatchingStatus.
typedef struct hdl_localization__msg__ScanMatchingStatus__Sequence
{
  hdl_localization__msg__ScanMatchingStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_localization__msg__ScanMatchingStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__STRUCT_H_
