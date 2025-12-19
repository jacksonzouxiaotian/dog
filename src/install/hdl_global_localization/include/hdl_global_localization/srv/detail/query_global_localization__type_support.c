// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hdl_global_localization/srv/detail/query_global_localization__rosidl_typesupport_introspection_c.h"
#include "hdl_global_localization/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hdl_global_localization/srv/detail/query_global_localization__functions.h"
#include "hdl_global_localization/srv/detail/query_global_localization__struct.h"


// Include directives for member types
// Member `cloud`
#include "sensor_msgs/msg/point_cloud2.h"
// Member `cloud`
#include "sensor_msgs/msg/detail/point_cloud2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hdl_global_localization__srv__QueryGlobalLocalization_Request__init(message_memory);
}

void QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_fini_function(void * message_memory)
{
  hdl_global_localization__srv__QueryGlobalLocalization_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_member_array[2] = {
  {
    "max_num_candidates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Request, max_num_candidates),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cloud",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Request, cloud),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_members = {
  "hdl_global_localization__srv",  // message namespace
  "QueryGlobalLocalization_Request",  // message name
  2,  // number of fields
  sizeof(hdl_global_localization__srv__QueryGlobalLocalization_Request),
  QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_member_array,  // message members
  QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_type_support_handle = {
  0,
  &QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hdl_global_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization_Request)() {
  QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  if (!QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_type_support_handle.typesupport_identifier) {
    QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &QueryGlobalLocalization_Request__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "hdl_global_localization/srv/detail/query_global_localization__rosidl_typesupport_introspection_c.h"
// already included above
// #include "hdl_global_localization/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "hdl_global_localization/srv/detail/query_global_localization__functions.h"
// already included above
// #include "hdl_global_localization/srv/detail/query_global_localization__struct.h"


// Include directives for member types
// Member `header`
// Member `globalmap_header`
#include "std_msgs/msg/header.h"
// Member `header`
// Member `globalmap_header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `inlier_fractions`
// Member `errors`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `poses`
#include "geometry_msgs/msg/pose.h"
// Member `poses`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hdl_global_localization__srv__QueryGlobalLocalization_Response__init(message_memory);
}

void QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_fini_function(void * message_memory)
{
  hdl_global_localization__srv__QueryGlobalLocalization_Response__fini(message_memory);
}

size_t QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__size_function__Pose__poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__get_const_function__Pose__poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__get_function__Pose__poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

bool QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__resize_function__Pose__poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Response, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "globalmap_header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Response, globalmap_header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inlier_fractions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Response, inlier_fractions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "errors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Response, errors),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hdl_global_localization__srv__QueryGlobalLocalization_Response, poses),  // bytes offset in struct
    NULL,  // default value
    QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__size_function__Pose__poses,  // size() function pointer
    QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__get_const_function__Pose__poses,  // get_const(index) function pointer
    QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__get_function__Pose__poses,  // get(index) function pointer
    QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__resize_function__Pose__poses  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_members = {
  "hdl_global_localization__srv",  // message namespace
  "QueryGlobalLocalization_Response",  // message name
  5,  // number of fields
  sizeof(hdl_global_localization__srv__QueryGlobalLocalization_Response),
  QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_member_array,  // message members
  QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_type_support_handle = {
  0,
  &QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hdl_global_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization_Response)() {
  QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_type_support_handle.typesupport_identifier) {
    QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &QueryGlobalLocalization_Response__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "hdl_global_localization/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "hdl_global_localization/srv/detail/query_global_localization__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_members = {
  "hdl_global_localization__srv",  // service namespace
  "QueryGlobalLocalization",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Request_message_type_support_handle,
  NULL  // response message
  // hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_Response_message_type_support_handle
};

static rosidl_service_type_support_t hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_type_support_handle = {
  0,
  &hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hdl_global_localization
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization)() {
  if (!hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_type_support_handle.typesupport_identifier) {
    hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hdl_global_localization, srv, QueryGlobalLocalization_Response)()->data;
  }

  return &hdl_global_localization__srv__detail__query_global_localization__rosidl_typesupport_introspection_c__QueryGlobalLocalization_service_type_support_handle;
}
