// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice
#include "hdl_global_localization/srv/detail/set_global_map__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hdl_global_localization/srv/detail/set_global_map__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::PointCloud2 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::PointCloud2 &);
size_t get_serialized_size(
  const sensor_msgs::msg::PointCloud2 &,
  size_t current_alignment);
size_t
max_serialized_size_PointCloud2(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs


namespace hdl_global_localization
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
cdr_serialize(
  const hdl_global_localization::srv::SetGlobalMap_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: global_map
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.global_map,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hdl_global_localization::srv::SetGlobalMap_Request & ros_message)
{
  // Member: global_map
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.global_map);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
get_serialized_size(
  const hdl_global_localization::srv::SetGlobalMap_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: global_map

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.global_map, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
max_serialized_size_SetGlobalMap_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: global_map
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_PointCloud2(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _SetGlobalMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hdl_global_localization::srv::SetGlobalMap_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetGlobalMap_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hdl_global_localization::srv::SetGlobalMap_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetGlobalMap_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hdl_global_localization::srv::SetGlobalMap_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetGlobalMap_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SetGlobalMap_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _SetGlobalMap_Request__callbacks = {
  "hdl_global_localization::srv",
  "SetGlobalMap_Request",
  _SetGlobalMap_Request__cdr_serialize,
  _SetGlobalMap_Request__cdr_deserialize,
  _SetGlobalMap_Request__get_serialized_size,
  _SetGlobalMap_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetGlobalMap_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetGlobalMap_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace hdl_global_localization

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hdl_global_localization
const rosidl_message_type_support_t *
get_message_type_support_handle<hdl_global_localization::srv::SetGlobalMap_Request>()
{
  return &hdl_global_localization::srv::typesupport_fastrtps_cpp::_SetGlobalMap_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hdl_global_localization, srv, SetGlobalMap_Request)() {
  return &hdl_global_localization::srv::typesupport_fastrtps_cpp::_SetGlobalMap_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace hdl_global_localization
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
cdr_serialize(
  const hdl_global_localization::srv::SetGlobalMap_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hdl_global_localization::srv::SetGlobalMap_Response & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
get_serialized_size(
  const hdl_global_localization::srv::SetGlobalMap_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hdl_global_localization
max_serialized_size_SetGlobalMap_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _SetGlobalMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hdl_global_localization::srv::SetGlobalMap_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetGlobalMap_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hdl_global_localization::srv::SetGlobalMap_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetGlobalMap_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hdl_global_localization::srv::SetGlobalMap_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetGlobalMap_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SetGlobalMap_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _SetGlobalMap_Response__callbacks = {
  "hdl_global_localization::srv",
  "SetGlobalMap_Response",
  _SetGlobalMap_Response__cdr_serialize,
  _SetGlobalMap_Response__cdr_deserialize,
  _SetGlobalMap_Response__get_serialized_size,
  _SetGlobalMap_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetGlobalMap_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetGlobalMap_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace hdl_global_localization

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hdl_global_localization
const rosidl_message_type_support_t *
get_message_type_support_handle<hdl_global_localization::srv::SetGlobalMap_Response>()
{
  return &hdl_global_localization::srv::typesupport_fastrtps_cpp::_SetGlobalMap_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hdl_global_localization, srv, SetGlobalMap_Response)() {
  return &hdl_global_localization::srv::typesupport_fastrtps_cpp::_SetGlobalMap_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace hdl_global_localization
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SetGlobalMap__callbacks = {
  "hdl_global_localization::srv",
  "SetGlobalMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hdl_global_localization, srv, SetGlobalMap_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hdl_global_localization, srv, SetGlobalMap_Response)(),
};

static rosidl_service_type_support_t _SetGlobalMap__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetGlobalMap__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace hdl_global_localization

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hdl_global_localization
const rosidl_service_type_support_t *
get_service_type_support_handle<hdl_global_localization::srv::SetGlobalMap>()
{
  return &hdl_global_localization::srv::typesupport_fastrtps_cpp::_SetGlobalMap__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hdl_global_localization, srv, SetGlobalMap)() {
  return &hdl_global_localization::srv::typesupport_fastrtps_cpp::_SetGlobalMap__handle;
}

#ifdef __cplusplus
}
#endif
