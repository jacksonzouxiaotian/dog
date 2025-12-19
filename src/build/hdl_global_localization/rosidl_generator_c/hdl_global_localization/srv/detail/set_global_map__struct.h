// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__STRUCT_H_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'global_map'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

// Struct defined in srv/SetGlobalMap in the package hdl_global_localization.
typedef struct hdl_global_localization__srv__SetGlobalMap_Request
{
  sensor_msgs__msg__PointCloud2 global_map;
} hdl_global_localization__srv__SetGlobalMap_Request;

// Struct for a sequence of hdl_global_localization__srv__SetGlobalMap_Request.
typedef struct hdl_global_localization__srv__SetGlobalMap_Request__Sequence
{
  hdl_global_localization__srv__SetGlobalMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_global_localization__srv__SetGlobalMap_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetGlobalMap in the package hdl_global_localization.
typedef struct hdl_global_localization__srv__SetGlobalMap_Response
{
  uint8_t structure_needs_at_least_one_member;
} hdl_global_localization__srv__SetGlobalMap_Response;

// Struct for a sequence of hdl_global_localization__srv__SetGlobalMap_Response.
typedef struct hdl_global_localization__srv__SetGlobalMap_Response__Sequence
{
  hdl_global_localization__srv__SetGlobalMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_global_localization__srv__SetGlobalMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__STRUCT_H_
