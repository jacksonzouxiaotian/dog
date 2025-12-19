// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__STRUCT_H_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cloud'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

// Struct defined in srv/QueryGlobalLocalization in the package hdl_global_localization.
typedef struct hdl_global_localization__srv__QueryGlobalLocalization_Request
{
  int64_t max_num_candidates;
  sensor_msgs__msg__PointCloud2 cloud;
} hdl_global_localization__srv__QueryGlobalLocalization_Request;

// Struct for a sequence of hdl_global_localization__srv__QueryGlobalLocalization_Request.
typedef struct hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence
{
  hdl_global_localization__srv__QueryGlobalLocalization_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'header'
// Member 'globalmap_header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'inlier_fractions'
// Member 'errors'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in srv/QueryGlobalLocalization in the package hdl_global_localization.
typedef struct hdl_global_localization__srv__QueryGlobalLocalization_Response
{
  std_msgs__msg__Header header;
  std_msgs__msg__Header globalmap_header;
  rosidl_runtime_c__double__Sequence inlier_fractions;
  rosidl_runtime_c__double__Sequence errors;
  geometry_msgs__msg__Pose__Sequence poses;
} hdl_global_localization__srv__QueryGlobalLocalization_Response;

// Struct for a sequence of hdl_global_localization__srv__QueryGlobalLocalization_Response.
typedef struct hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence
{
  hdl_global_localization__srv__QueryGlobalLocalization_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__STRUCT_H_
