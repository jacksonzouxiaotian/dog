// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hdl_global_localization:srv/SetGlobalLocalizationEngine.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__STRUCT_H_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'engine_name'
#include "std_msgs/msg/detail/string__struct.h"

// Struct defined in srv/SetGlobalLocalizationEngine in the package hdl_global_localization.
typedef struct hdl_global_localization__srv__SetGlobalLocalizationEngine_Request
{
  std_msgs__msg__String engine_name;
} hdl_global_localization__srv__SetGlobalLocalizationEngine_Request;

// Struct for a sequence of hdl_global_localization__srv__SetGlobalLocalizationEngine_Request.
typedef struct hdl_global_localization__srv__SetGlobalLocalizationEngine_Request__Sequence
{
  hdl_global_localization__srv__SetGlobalLocalizationEngine_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_global_localization__srv__SetGlobalLocalizationEngine_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetGlobalLocalizationEngine in the package hdl_global_localization.
typedef struct hdl_global_localization__srv__SetGlobalLocalizationEngine_Response
{
  uint8_t structure_needs_at_least_one_member;
} hdl_global_localization__srv__SetGlobalLocalizationEngine_Response;

// Struct for a sequence of hdl_global_localization__srv__SetGlobalLocalizationEngine_Response.
typedef struct hdl_global_localization__srv__SetGlobalLocalizationEngine_Response__Sequence
{
  hdl_global_localization__srv__SetGlobalLocalizationEngine_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hdl_global_localization__srv__SetGlobalLocalizationEngine_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_LOCALIZATION_ENGINE__STRUCT_H_
