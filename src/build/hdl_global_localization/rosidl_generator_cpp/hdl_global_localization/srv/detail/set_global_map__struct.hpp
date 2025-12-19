// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__STRUCT_HPP_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'global_map'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Request __declspec(deprecated)
#endif

namespace hdl_global_localization
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetGlobalMap_Request_
{
  using Type = SetGlobalMap_Request_<ContainerAllocator>;

  explicit SetGlobalMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : global_map(_init)
  {
    (void)_init;
  }

  explicit SetGlobalMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : global_map(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _global_map_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _global_map_type global_map;

  // setters for named parameter idiom
  Type & set__global_map(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->global_map = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Request
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Request
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetGlobalMap_Request_ & other) const
  {
    if (this->global_map != other.global_map) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetGlobalMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetGlobalMap_Request_

// alias to use template instance with default allocator
using SetGlobalMap_Request =
  hdl_global_localization::srv::SetGlobalMap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hdl_global_localization


#ifndef _WIN32
# define DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Response __declspec(deprecated)
#endif

namespace hdl_global_localization
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetGlobalMap_Response_
{
  using Type = SetGlobalMap_Response_<ContainerAllocator>;

  explicit SetGlobalMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SetGlobalMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Response
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hdl_global_localization__srv__SetGlobalMap_Response
    std::shared_ptr<hdl_global_localization::srv::SetGlobalMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetGlobalMap_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetGlobalMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetGlobalMap_Response_

// alias to use template instance with default allocator
using SetGlobalMap_Response =
  hdl_global_localization::srv::SetGlobalMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace hdl_global_localization

namespace hdl_global_localization
{

namespace srv
{

struct SetGlobalMap
{
  using Request = hdl_global_localization::srv::SetGlobalMap_Request;
  using Response = hdl_global_localization::srv::SetGlobalMap_Response;
};

}  // namespace srv

}  // namespace hdl_global_localization

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__SET_GLOBAL_MAP__STRUCT_HPP_
