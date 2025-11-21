// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice
#include "hdl_global_localization/srv/detail/set_global_map__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hdl_global_localization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hdl_global_localization/srv/detail/set_global_map__struct.h"
#include "hdl_global_localization/srv/detail/set_global_map__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "sensor_msgs/msg/detail/point_cloud2__functions.h"  // global_map

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
size_t get_serialized_size_sensor_msgs__msg__PointCloud2(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
size_t max_serialized_size_sensor_msgs__msg__PointCloud2(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, PointCloud2)();


using _SetGlobalMap_Request__ros_msg_type = hdl_global_localization__srv__SetGlobalMap_Request;

static bool _SetGlobalMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetGlobalMap_Request__ros_msg_type * ros_message = static_cast<const _SetGlobalMap_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: global_map
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, PointCloud2
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->global_map, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _SetGlobalMap_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetGlobalMap_Request__ros_msg_type * ros_message = static_cast<_SetGlobalMap_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: global_map
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, PointCloud2
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->global_map))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t get_serialized_size_hdl_global_localization__srv__SetGlobalMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetGlobalMap_Request__ros_msg_type * ros_message = static_cast<const _SetGlobalMap_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name global_map

  current_alignment += get_serialized_size_sensor_msgs__msg__PointCloud2(
    &(ros_message->global_map), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _SetGlobalMap_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hdl_global_localization__srv__SetGlobalMap_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t max_serialized_size_hdl_global_localization__srv__SetGlobalMap_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: global_map
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__PointCloud2(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _SetGlobalMap_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hdl_global_localization__srv__SetGlobalMap_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SetGlobalMap_Request = {
  "hdl_global_localization::srv",
  "SetGlobalMap_Request",
  _SetGlobalMap_Request__cdr_serialize,
  _SetGlobalMap_Request__cdr_deserialize,
  _SetGlobalMap_Request__get_serialized_size,
  _SetGlobalMap_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetGlobalMap_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetGlobalMap_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, SetGlobalMap_Request)() {
  return &_SetGlobalMap_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "hdl_global_localization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "hdl_global_localization/srv/detail/set_global_map__struct.h"
// already included above
// #include "hdl_global_localization/srv/detail/set_global_map__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SetGlobalMap_Response__ros_msg_type = hdl_global_localization__srv__SetGlobalMap_Response;

static bool _SetGlobalMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetGlobalMap_Response__ros_msg_type * ros_message = static_cast<const _SetGlobalMap_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _SetGlobalMap_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetGlobalMap_Response__ros_msg_type * ros_message = static_cast<_SetGlobalMap_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t get_serialized_size_hdl_global_localization__srv__SetGlobalMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetGlobalMap_Response__ros_msg_type * ros_message = static_cast<const _SetGlobalMap_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SetGlobalMap_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hdl_global_localization__srv__SetGlobalMap_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t max_serialized_size_hdl_global_localization__srv__SetGlobalMap_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SetGlobalMap_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hdl_global_localization__srv__SetGlobalMap_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SetGlobalMap_Response = {
  "hdl_global_localization::srv",
  "SetGlobalMap_Response",
  _SetGlobalMap_Response__cdr_serialize,
  _SetGlobalMap_Response__cdr_deserialize,
  _SetGlobalMap_Response__get_serialized_size,
  _SetGlobalMap_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetGlobalMap_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetGlobalMap_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, SetGlobalMap_Response)() {
  return &_SetGlobalMap_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "hdl_global_localization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hdl_global_localization/srv/set_global_map.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SetGlobalMap__callbacks = {
  "hdl_global_localization::srv",
  "SetGlobalMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, SetGlobalMap_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, SetGlobalMap_Response)(),
};

static rosidl_service_type_support_t SetGlobalMap__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SetGlobalMap__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, SetGlobalMap)() {
  return &SetGlobalMap__handle;
}

#if defined(__cplusplus)
}
#endif
