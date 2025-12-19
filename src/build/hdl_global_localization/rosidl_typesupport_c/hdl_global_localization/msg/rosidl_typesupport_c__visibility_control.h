// generated from
// rosidl_typesupport_c/resource/rosidl_typesupport_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__MSG__ROSIDL_TYPESUPPORT_C__VISIBILITY_CONTROL_H_
#define HDL_GLOBAL_LOCALIZATION__MSG__ROSIDL_TYPESUPPORT_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_C_EXPORT_hdl_global_localization __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_C_IMPORT_hdl_global_localization __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_C_EXPORT_hdl_global_localization __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_C_IMPORT_hdl_global_localization __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_C_BUILDING_DLL_hdl_global_localization
    #define ROSIDL_TYPESUPPORT_C_PUBLIC_hdl_global_localization ROSIDL_TYPESUPPORT_C_EXPORT_hdl_global_localization
  #else
    #define ROSIDL_TYPESUPPORT_C_PUBLIC_hdl_global_localization ROSIDL_TYPESUPPORT_C_IMPORT_hdl_global_localization
  #endif
#else
  #define ROSIDL_TYPESUPPORT_C_EXPORT_hdl_global_localization __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_C_IMPORT_hdl_global_localization
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_C_PUBLIC_hdl_global_localization __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_C_PUBLIC_hdl_global_localization
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // HDL_GLOBAL_LOCALIZATION__MSG__ROSIDL_TYPESUPPORT_C__VISIBILITY_CONTROL_H_
