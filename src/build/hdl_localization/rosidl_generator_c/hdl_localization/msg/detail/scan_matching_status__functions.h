// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hdl_localization:msg/ScanMatchingStatus.idl
// generated code does not contain a copyright notice

#ifndef HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__FUNCTIONS_H_
#define HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hdl_localization/msg/rosidl_generator_c__visibility_control.h"

#include "hdl_localization/msg/detail/scan_matching_status__struct.h"

/// Initialize msg/ScanMatchingStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hdl_localization__msg__ScanMatchingStatus
 * )) before or use
 * hdl_localization__msg__ScanMatchingStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
bool
hdl_localization__msg__ScanMatchingStatus__init(hdl_localization__msg__ScanMatchingStatus * msg);

/// Finalize msg/ScanMatchingStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
void
hdl_localization__msg__ScanMatchingStatus__fini(hdl_localization__msg__ScanMatchingStatus * msg);

/// Create msg/ScanMatchingStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hdl_localization__msg__ScanMatchingStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
hdl_localization__msg__ScanMatchingStatus *
hdl_localization__msg__ScanMatchingStatus__create();

/// Destroy msg/ScanMatchingStatus message.
/**
 * It calls
 * hdl_localization__msg__ScanMatchingStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
void
hdl_localization__msg__ScanMatchingStatus__destroy(hdl_localization__msg__ScanMatchingStatus * msg);

/// Check for msg/ScanMatchingStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
bool
hdl_localization__msg__ScanMatchingStatus__are_equal(const hdl_localization__msg__ScanMatchingStatus * lhs, const hdl_localization__msg__ScanMatchingStatus * rhs);

/// Copy a msg/ScanMatchingStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
bool
hdl_localization__msg__ScanMatchingStatus__copy(
  const hdl_localization__msg__ScanMatchingStatus * input,
  hdl_localization__msg__ScanMatchingStatus * output);

/// Initialize array of msg/ScanMatchingStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * hdl_localization__msg__ScanMatchingStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
bool
hdl_localization__msg__ScanMatchingStatus__Sequence__init(hdl_localization__msg__ScanMatchingStatus__Sequence * array, size_t size);

/// Finalize array of msg/ScanMatchingStatus messages.
/**
 * It calls
 * hdl_localization__msg__ScanMatchingStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
void
hdl_localization__msg__ScanMatchingStatus__Sequence__fini(hdl_localization__msg__ScanMatchingStatus__Sequence * array);

/// Create array of msg/ScanMatchingStatus messages.
/**
 * It allocates the memory for the array and calls
 * hdl_localization__msg__ScanMatchingStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
hdl_localization__msg__ScanMatchingStatus__Sequence *
hdl_localization__msg__ScanMatchingStatus__Sequence__create(size_t size);

/// Destroy array of msg/ScanMatchingStatus messages.
/**
 * It calls
 * hdl_localization__msg__ScanMatchingStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
void
hdl_localization__msg__ScanMatchingStatus__Sequence__destroy(hdl_localization__msg__ScanMatchingStatus__Sequence * array);

/// Check for msg/ScanMatchingStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
bool
hdl_localization__msg__ScanMatchingStatus__Sequence__are_equal(const hdl_localization__msg__ScanMatchingStatus__Sequence * lhs, const hdl_localization__msg__ScanMatchingStatus__Sequence * rhs);

/// Copy an array of msg/ScanMatchingStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_localization
bool
hdl_localization__msg__ScanMatchingStatus__Sequence__copy(
  const hdl_localization__msg__ScanMatchingStatus__Sequence * input,
  hdl_localization__msg__ScanMatchingStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HDL_LOCALIZATION__MSG__DETAIL__SCAN_MATCHING_STATUS__FUNCTIONS_H_
