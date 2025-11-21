#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hdl_localization::hdl_localization__rosidl_typesupport_introspection_c" for configuration "RELEASE"
set_property(TARGET hdl_localization::hdl_localization__rosidl_typesupport_introspection_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(hdl_localization::hdl_localization__rosidl_typesupport_introspection_c PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhdl_localization__rosidl_typesupport_introspection_c.so"
  IMPORTED_SONAME_RELEASE "libhdl_localization__rosidl_typesupport_introspection_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS hdl_localization::hdl_localization__rosidl_typesupport_introspection_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_hdl_localization::hdl_localization__rosidl_typesupport_introspection_c "${_IMPORT_PREFIX}/lib/libhdl_localization__rosidl_typesupport_introspection_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
