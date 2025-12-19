// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hdl_global_localization:srv/QueryGlobalLocalization.idl
// generated code does not contain a copyright notice

#ifndef HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__FUNCTIONS_H_
#define HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hdl_global_localization/msg/rosidl_generator_c__visibility_control.h"

#include "hdl_global_localization/srv/detail/query_global_localization__struct.h"

/// Initialize srv/QueryGlobalLocalization message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hdl_global_localization__srv__QueryGlobalLocalization_Request
 * )) before or use
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Request__init(hdl_global_localization__srv__QueryGlobalLocalization_Request * msg);

/// Finalize srv/QueryGlobalLocalization message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Request__fini(hdl_global_localization__srv__QueryGlobalLocalization_Request * msg);

/// Create srv/QueryGlobalLocalization message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
hdl_global_localization__srv__QueryGlobalLocalization_Request *
hdl_global_localization__srv__QueryGlobalLocalization_Request__create();

/// Destroy srv/QueryGlobalLocalization message.
/**
 * It calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Request__destroy(hdl_global_localization__srv__QueryGlobalLocalization_Request * msg);

/// Check for srv/QueryGlobalLocalization message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Request__are_equal(const hdl_global_localization__srv__QueryGlobalLocalization_Request * lhs, const hdl_global_localization__srv__QueryGlobalLocalization_Request * rhs);

/// Copy a srv/QueryGlobalLocalization message.
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
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Request__copy(
  const hdl_global_localization__srv__QueryGlobalLocalization_Request * input,
  hdl_global_localization__srv__QueryGlobalLocalization_Request * output);

/// Initialize array of srv/QueryGlobalLocalization messages.
/**
 * It allocates the memory for the number of elements and calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__init(hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * array, size_t size);

/// Finalize array of srv/QueryGlobalLocalization messages.
/**
 * It calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__fini(hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * array);

/// Create array of srv/QueryGlobalLocalization messages.
/**
 * It allocates the memory for the array and calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence *
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__create(size_t size);

/// Destroy array of srv/QueryGlobalLocalization messages.
/**
 * It calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__destroy(hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * array);

/// Check for srv/QueryGlobalLocalization message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__are_equal(const hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * lhs, const hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * rhs);

/// Copy an array of srv/QueryGlobalLocalization messages.
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
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence__copy(
  const hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * input,
  hdl_global_localization__srv__QueryGlobalLocalization_Request__Sequence * output);

/// Initialize srv/QueryGlobalLocalization message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hdl_global_localization__srv__QueryGlobalLocalization_Response
 * )) before or use
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Response__init(hdl_global_localization__srv__QueryGlobalLocalization_Response * msg);

/// Finalize srv/QueryGlobalLocalization message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Response__fini(hdl_global_localization__srv__QueryGlobalLocalization_Response * msg);

/// Create srv/QueryGlobalLocalization message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
hdl_global_localization__srv__QueryGlobalLocalization_Response *
hdl_global_localization__srv__QueryGlobalLocalization_Response__create();

/// Destroy srv/QueryGlobalLocalization message.
/**
 * It calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Response__destroy(hdl_global_localization__srv__QueryGlobalLocalization_Response * msg);

/// Check for srv/QueryGlobalLocalization message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Response__are_equal(const hdl_global_localization__srv__QueryGlobalLocalization_Response * lhs, const hdl_global_localization__srv__QueryGlobalLocalization_Response * rhs);

/// Copy a srv/QueryGlobalLocalization message.
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
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Response__copy(
  const hdl_global_localization__srv__QueryGlobalLocalization_Response * input,
  hdl_global_localization__srv__QueryGlobalLocalization_Response * output);

/// Initialize array of srv/QueryGlobalLocalization messages.
/**
 * It allocates the memory for the number of elements and calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__init(hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * array, size_t size);

/// Finalize array of srv/QueryGlobalLocalization messages.
/**
 * It calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__fini(hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * array);

/// Create array of srv/QueryGlobalLocalization messages.
/**
 * It allocates the memory for the array and calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence *
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__create(size_t size);

/// Destroy array of srv/QueryGlobalLocalization messages.
/**
 * It calls
 * hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
void
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__destroy(hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * array);

/// Check for srv/QueryGlobalLocalization message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__are_equal(const hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * lhs, const hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * rhs);

/// Copy an array of srv/QueryGlobalLocalization messages.
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
ROSIDL_GENERATOR_C_PUBLIC_hdl_global_localization
bool
hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence__copy(
  const hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * input,
  hdl_global_localization__srv__QueryGlobalLocalization_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HDL_GLOBAL_LOCALIZATION__SRV__DETAIL__QUERY_GLOBAL_LOCALIZATION__FUNCTIONS_H_
