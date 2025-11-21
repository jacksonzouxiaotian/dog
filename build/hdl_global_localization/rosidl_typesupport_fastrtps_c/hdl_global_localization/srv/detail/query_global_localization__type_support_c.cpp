// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
// generated code does not contain a copyright notice
#include "hdl_global_localization/srv/detail/query_global_localization__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hdl_global_localization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hdl_global_localization/srv/detail/query_global_localization__struct.h"
#include "hdl_global_localization/srv/detail/query_global_localization__functions.h"
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

#include "sensor_msgs/msg/detail/point_cloud2__functions.h"  // cloud

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


using _QueryGlobalLocalization_Request__ros_msg_type = hdl_global_localization__srv__QueryGlobalLocalization_Request;

static bool _QueryGlobalLocalization_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _QueryGlobalLocalization_Request__ros_msg_type * ros_message = static_cast<const _QueryGlobalLocalization_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: max_num_candidates
  {
    cdr << ros_message->max_num_candidates;
  }

  // Field name: cloud
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, PointCloud2
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->cloud, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _QueryGlobalLocalization_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _QueryGlobalLocalization_Request__ros_msg_type * ros_message = static_cast<_QueryGlobalLocalization_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: max_num_candidates
  {
    cdr >> ros_message->max_num_candidates;
  }

  // Field name: cloud
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, PointCloud2
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->cloud))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t get_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _QueryGlobalLocalization_Request__ros_msg_type * ros_message = static_cast<const _QueryGlobalLocalization_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name max_num_candidates
  {
    size_t item_size = sizeof(ros_message->max_num_candidates);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cloud

  current_alignment += get_serialized_size_sensor_msgs__msg__PointCloud2(
    &(ros_message->cloud), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _QueryGlobalLocalization_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t max_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: max_num_candidates
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: cloud
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

static size_t _QueryGlobalLocalization_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_QueryGlobalLocalization_Request = {
  "hdl_global_localization::srv",
  "QueryGlobalLocalization_Request",
  _QueryGlobalLocalization_Request__cdr_serialize,
  _QueryGlobalLocalization_Request__cdr_deserialize,
  _QueryGlobalLocalization_Request__get_serialized_size,
  _QueryGlobalLocalization_Request__max_serialized_size
};

static rosidl_message_type_support_t _QueryGlobalLocalization_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_QueryGlobalLocalization_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, QueryGlobalLocalization_Request)() {
  return &_QueryGlobalLocalization_Request__type_support;
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
// #include "hdl_global_localization/srv/detail/query_global_localization__struct.h"
// already included above
// #include "hdl_global_localization/srv/detail/query_global_localization__functions.h"
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

#include "geometry_msgs/msg/detail/pose__functions.h"  // poses
#include "rosidl_runtime_c/primitives_sequence.h"  // errors, inlier_fractions
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // errors, inlier_fractions
#include "std_msgs/msg/detail/header__functions.h"  // globalmap_header, header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_hdl_global_localization
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _QueryGlobalLocalization_Response__ros_msg_type = hdl_global_localization__srv__QueryGlobalLocalization_Response;

static bool _QueryGlobalLocalization_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _QueryGlobalLocalization_Response__ros_msg_type * ros_message = static_cast<const _QueryGlobalLocalization_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: globalmap_header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->globalmap_header, cdr))
    {
      return false;
    }
  }

  // Field name: inlier_fractions
  {
    size_t size = ros_message->inlier_fractions.size;
    auto array_ptr = ros_message->inlier_fractions.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: errors
  {
    size_t size = ros_message->errors.size;
    auto array_ptr = ros_message->errors.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: poses
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    size_t size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _QueryGlobalLocalization_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _QueryGlobalLocalization_Response__ros_msg_type * ros_message = static_cast<_QueryGlobalLocalization_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: globalmap_header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->globalmap_header))
    {
      return false;
    }
  }

  // Field name: inlier_fractions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->inlier_fractions.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->inlier_fractions);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->inlier_fractions, size)) {
      return "failed to create array for field 'inlier_fractions'";
    }
    auto array_ptr = ros_message->inlier_fractions.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: errors
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->errors.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->errors);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->errors, size)) {
      return "failed to create array for field 'errors'";
    }
    auto array_ptr = ros_message->errors.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: poses
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->poses.data) {
      geometry_msgs__msg__Pose__Sequence__fini(&ros_message->poses);
    }
    if (!geometry_msgs__msg__Pose__Sequence__init(&ros_message->poses, size)) {
      return "failed to create array for field 'poses'";
    }
    auto array_ptr = ros_message->poses.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t get_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _QueryGlobalLocalization_Response__ros_msg_type * ros_message = static_cast<const _QueryGlobalLocalization_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name globalmap_header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->globalmap_header), current_alignment);
  // field.name inlier_fractions
  {
    size_t array_size = ros_message->inlier_fractions.size;
    auto array_ptr = ros_message->inlier_fractions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name errors
  {
    size_t array_size = ros_message->errors.size;
    auto array_ptr = ros_message->errors.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name poses
  {
    size_t array_size = ros_message->poses.size;
    auto array_ptr = ros_message->poses.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _QueryGlobalLocalization_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hdl_global_localization
size_t max_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: globalmap_header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: inlier_fractions
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: errors
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: poses
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Pose(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _QueryGlobalLocalization_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hdl_global_localization__srv__QueryGlobalLocalization_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_QueryGlobalLocalization_Response = {
  "hdl_global_localization::srv",
  "QueryGlobalLocalization_Response",
  _QueryGlobalLocalization_Response__cdr_serialize,
  _QueryGlobalLocalization_Response__cdr_deserialize,
  _QueryGlobalLocalization_Response__get_serialized_size,
  _QueryGlobalLocalization_Response__max_serialized_size
};

static rosidl_message_type_support_t _QueryGlobalLocalization_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_QueryGlobalLocalization_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, QueryGlobalLocalization_Response)() {
  return &_QueryGlobalLocalization_Response__type_support;
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
#include "hdl_global_localization/srv/query_global_localization.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t QueryGlobalLocalization__callbacks = {
  "hdl_global_localization::srv",
  "QueryGlobalLocalization",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, QueryGlobalLocalization_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, QueryGlobalLocalization_Response)(),
};

static rosidl_service_type_support_t QueryGlobalLocalization__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &QueryGlobalLocalization__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hdl_global_localization, srv, QueryGlobalLocalization)() {
  return &QueryGlobalLocalization__handle;
}

#if defined(__cplusplus)
}
#endif
