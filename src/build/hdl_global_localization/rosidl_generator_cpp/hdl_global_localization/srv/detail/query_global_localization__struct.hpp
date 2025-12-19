// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__STRUCT_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'cloud'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Request __attribute__((deprecated))
#else
# define DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Request __declspec(deprecated)
#endif

namespace hdl_global_localization
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct QueryGlobalLocalization_Request_
{
  using Type = QueryGlobalLocalization_Request_<ContainerAllocator>;

  explicit QueryGlobalLocalization_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cloud(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_num_candidates = 0ll;
    }
  }

  explicit QueryGlobalLocalization_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cloud(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_num_candidates = 0ll;
    }
  }

  // field types and members
  using _max_num_candidates_type =
    int64_t;
  _max_num_candidates_type max_num_candidates;
  using _cloud_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _cloud_type cloud;

  // setters for named parameter idiom
  Type & set__max_num_candidates(
    const int64_t & _arg)
  {
    this->max_num_candidates = _arg;
    return *this;
  }
  Type & set__cloud(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->cloud = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Request
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Request
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QueryGlobalLocalization_Request_ & other) const
  {
    if (this->max_num_candidates != other.max_num_candidates) {
      return false;
    }
    if (this->cloud != other.cloud) {
      return false;
    }
    return true;
  }
  bool operator!=(const QueryGlobalLocalization_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QueryGlobalLocalization_Request_

// alias to use template instance with default allocator
using QueryGlobalLocalization_Request =
  hdl_global_localization::srv::QueryGlobalLocalization_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hdl_global_localization


// Include directives for member types
// Member 'header'
// Member 'globalmap_header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Response __attribute__((deprecated))
#else
# define DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Response __declspec(deprecated)
#endif

namespace hdl_global_localization
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct QueryGlobalLocalization_Response_
{
  using Type = QueryGlobalLocalization_Response_<ContainerAllocator>;

  explicit QueryGlobalLocalization_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    globalmap_header(_init)
  {
    (void)_init;
  }

  explicit QueryGlobalLocalization_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    globalmap_header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _globalmap_header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _globalmap_header_type globalmap_header;
  using _inlier_fractions_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _inlier_fractions_type inlier_fractions;
  using _errors_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _errors_type errors;
  using _poses_type =
    std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Pose_<ContainerAllocator>>::other>;
  _poses_type poses;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__globalmap_header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->globalmap_header = _arg;
    return *this;
  }
  Type & set__inlier_fractions(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->inlier_fractions = _arg;
    return *this;
  }
  Type & set__errors(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->errors = _arg;
    return *this;
  }
  Type & set__poses(
    const std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Pose_<ContainerAllocator>>::other> & _arg)
  {
    this->poses = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Response
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hdl_global_localization__srv__QueryGlobalLocalization_Response
    std::shared_ptr<hdl_global_localization::srv::QueryGlobalLocalization_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QueryGlobalLocalization_Response_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->globalmap_header != other.globalmap_header) {
      return false;
    }
    if (this->inlier_fractions != other.inlier_fractions) {
      return false;
    }
    if (this->errors != other.errors) {
      return false;
    }
    if (this->poses != other.poses) {
      return false;
    }
    return true;
  }
  bool operator!=(const QueryGlobalLocalization_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QueryGlobalLocalization_Response_

// alias to use template instance with default allocator
using QueryGlobalLocalization_Response =
  hdl_global_localization::srv::QueryGlobalLocalization_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hdl_global_localization

namespace hdl_global_localization
{

namespace srv
{

struct QueryGlobalLocalization
{
  using Request = hdl_global_localization::srv::QueryGlobalLocalization_Request;
  using Response = hdl_global_localization::srv::QueryGlobalLocalization_Response;
};

}  // namespace srv

}  // namespace hdl_global_localization

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__STRUCT_HPP_
