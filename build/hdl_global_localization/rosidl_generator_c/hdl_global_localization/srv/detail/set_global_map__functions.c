// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hdl_global_localization:srv/SetGlobalMap.idl
// generated code does not contain a copyright notice
#include "hdl_global_localization/srv/detail/set_global_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `global_map`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"

bool
hdl_global_localization__srv__SetGlobalMap_Request__init(hdl_global_localization__srv__SetGlobalMap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // global_map
  if (!sensor_msgs__msg__PointCloud2__init(&msg->global_map)) {
    hdl_global_localization__srv__SetGlobalMap_Request__fini(msg);
    return false;
  }
  return true;
}

void
hdl_global_localization__srv__SetGlobalMap_Request__fini(hdl_global_localization__srv__SetGlobalMap_Request * msg)
{
  if (!msg) {
    return;
  }
  // global_map
  sensor_msgs__msg__PointCloud2__fini(&msg->global_map);
}

bool
hdl_global_localization__srv__SetGlobalMap_Request__are_equal(const hdl_global_localization__srv__SetGlobalMap_Request * lhs, const hdl_global_localization__srv__SetGlobalMap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // global_map
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->global_map), &(rhs->global_map)))
  {
    return false;
  }
  return true;
}

bool
hdl_global_localization__srv__SetGlobalMap_Request__copy(
  const hdl_global_localization__srv__SetGlobalMap_Request * input,
  hdl_global_localization__srv__SetGlobalMap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // global_map
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->global_map), &(output->global_map)))
  {
    return false;
  }
  return true;
}

hdl_global_localization__srv__SetGlobalMap_Request *
hdl_global_localization__srv__SetGlobalMap_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdl_global_localization__srv__SetGlobalMap_Request * msg = (hdl_global_localization__srv__SetGlobalMap_Request *)allocator.allocate(sizeof(hdl_global_localization__srv__SetGlobalMap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hdl_global_localization__srv__SetGlobalMap_Request));
  bool success = hdl_global_localization__srv__SetGlobalMap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hdl_global_localization__srv__SetGlobalMap_Request__destroy(hdl_global_localization__srv__SetGlobalMap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hdl_global_localization__srv__SetGlobalMap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hdl_global_localization__srv__SetGlobalMap_Request__Sequence__init(hdl_global_localization__srv__SetGlobalMap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdl_global_localization__srv__SetGlobalMap_Request * data = NULL;

  if (size) {
    data = (hdl_global_localization__srv__SetGlobalMap_Request *)allocator.zero_allocate(size, sizeof(hdl_global_localization__srv__SetGlobalMap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hdl_global_localization__srv__SetGlobalMap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hdl_global_localization__srv__SetGlobalMap_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hdl_global_localization__srv__SetGlobalMap_Request__Sequence__fini(hdl_global_localization__srv__SetGlobalMap_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hdl_global_localization__srv__SetGlobalMap_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hdl_global_localization__srv__SetGlobalMap_Request__Sequence *
hdl_global_localization__srv__SetGlobalMap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdl_global_localization__srv__SetGlobalMap_Request__Sequence * array = (hdl_global_localization__srv__SetGlobalMap_Request__Sequence *)allocator.allocate(sizeof(hdl_global_localization__srv__SetGlobalMap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hdl_global_localization__srv__SetGlobalMap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hdl_global_localization__srv__SetGlobalMap_Request__Sequence__destroy(hdl_global_localization__srv__SetGlobalMap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hdl_global_localization__srv__SetGlobalMap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hdl_global_localization__srv__SetGlobalMap_Request__Sequence__are_equal(const hdl_global_localization__srv__SetGlobalMap_Request__Sequence * lhs, const hdl_global_localization__srv__SetGlobalMap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hdl_global_localization__srv__SetGlobalMap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hdl_global_localization__srv__SetGlobalMap_Request__Sequence__copy(
  const hdl_global_localization__srv__SetGlobalMap_Request__Sequence * input,
  hdl_global_localization__srv__SetGlobalMap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hdl_global_localization__srv__SetGlobalMap_Request);
    hdl_global_localization__srv__SetGlobalMap_Request * data =
      (hdl_global_localization__srv__SetGlobalMap_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hdl_global_localization__srv__SetGlobalMap_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hdl_global_localization__srv__SetGlobalMap_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hdl_global_localization__srv__SetGlobalMap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
hdl_global_localization__srv__SetGlobalMap_Response__init(hdl_global_localization__srv__SetGlobalMap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
hdl_global_localization__srv__SetGlobalMap_Response__fini(hdl_global_localization__srv__SetGlobalMap_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
hdl_global_localization__srv__SetGlobalMap_Response__are_equal(const hdl_global_localization__srv__SetGlobalMap_Response * lhs, const hdl_global_localization__srv__SetGlobalMap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
hdl_global_localization__srv__SetGlobalMap_Response__copy(
  const hdl_global_localization__srv__SetGlobalMap_Response * input,
  hdl_global_localization__srv__SetGlobalMap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

hdl_global_localization__srv__SetGlobalMap_Response *
hdl_global_localization__srv__SetGlobalMap_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdl_global_localization__srv__SetGlobalMap_Response * msg = (hdl_global_localization__srv__SetGlobalMap_Response *)allocator.allocate(sizeof(hdl_global_localization__srv__SetGlobalMap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hdl_global_localization__srv__SetGlobalMap_Response));
  bool success = hdl_global_localization__srv__SetGlobalMap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hdl_global_localization__srv__SetGlobalMap_Response__destroy(hdl_global_localization__srv__SetGlobalMap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hdl_global_localization__srv__SetGlobalMap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hdl_global_localization__srv__SetGlobalMap_Response__Sequence__init(hdl_global_localization__srv__SetGlobalMap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdl_global_localization__srv__SetGlobalMap_Response * data = NULL;

  if (size) {
    data = (hdl_global_localization__srv__SetGlobalMap_Response *)allocator.zero_allocate(size, sizeof(hdl_global_localization__srv__SetGlobalMap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hdl_global_localization__srv__SetGlobalMap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hdl_global_localization__srv__SetGlobalMap_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hdl_global_localization__srv__SetGlobalMap_Response__Sequence__fini(hdl_global_localization__srv__SetGlobalMap_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hdl_global_localization__srv__SetGlobalMap_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hdl_global_localization__srv__SetGlobalMap_Response__Sequence *
hdl_global_localization__srv__SetGlobalMap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hdl_global_localization__srv__SetGlobalMap_Response__Sequence * array = (hdl_global_localization__srv__SetGlobalMap_Response__Sequence *)allocator.allocate(sizeof(hdl_global_localization__srv__SetGlobalMap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hdl_global_localization__srv__SetGlobalMap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hdl_global_localization__srv__SetGlobalMap_Response__Sequence__destroy(hdl_global_localization__srv__SetGlobalMap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hdl_global_localization__srv__SetGlobalMap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hdl_global_localization__srv__SetGlobalMap_Response__Sequence__are_equal(const hdl_global_localization__srv__SetGlobalMap_Response__Sequence * lhs, const hdl_global_localization__srv__SetGlobalMap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hdl_global_localization__srv__SetGlobalMap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hdl_global_localization__srv__SetGlobalMap_Response__Sequence__copy(
  const hdl_global_localization__srv__SetGlobalMap_Response__Sequence * input,
  hdl_global_localization__srv__SetGlobalMap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hdl_global_localization__srv__SetGlobalMap_Response);
    hdl_global_localization__srv__SetGlobalMap_Response * data =
      (hdl_global_localization__srv__SetGlobalMap_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hdl_global_localization__srv__SetGlobalMap_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hdl_global_localization__srv__SetGlobalMap_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hdl_global_localization__srv__SetGlobalMap_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
