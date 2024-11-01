// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from apf_interfaces:msg/Distance.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__DISTANCE__FUNCTIONS_H_
#define APF_INTERFACES__MSG__DETAIL__DISTANCE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "apf_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "apf_interfaces/msg/detail/distance__struct.h"

/// Initialize msg/Distance message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * apf_interfaces__msg__Distance
 * )) before or use
 * apf_interfaces__msg__Distance__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Distance__init(apf_interfaces__msg__Distance * msg);

/// Finalize msg/Distance message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Distance__fini(apf_interfaces__msg__Distance * msg);

/// Create msg/Distance message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * apf_interfaces__msg__Distance__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
apf_interfaces__msg__Distance *
apf_interfaces__msg__Distance__create();

/// Destroy msg/Distance message.
/**
 * It calls
 * apf_interfaces__msg__Distance__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Distance__destroy(apf_interfaces__msg__Distance * msg);

/// Check for msg/Distance message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Distance__are_equal(const apf_interfaces__msg__Distance * lhs, const apf_interfaces__msg__Distance * rhs);

/// Copy a msg/Distance message.
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
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Distance__copy(
  const apf_interfaces__msg__Distance * input,
  apf_interfaces__msg__Distance * output);

/// Initialize array of msg/Distance messages.
/**
 * It allocates the memory for the number of elements and calls
 * apf_interfaces__msg__Distance__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Distance__Sequence__init(apf_interfaces__msg__Distance__Sequence * array, size_t size);

/// Finalize array of msg/Distance messages.
/**
 * It calls
 * apf_interfaces__msg__Distance__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Distance__Sequence__fini(apf_interfaces__msg__Distance__Sequence * array);

/// Create array of msg/Distance messages.
/**
 * It allocates the memory for the array and calls
 * apf_interfaces__msg__Distance__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
apf_interfaces__msg__Distance__Sequence *
apf_interfaces__msg__Distance__Sequence__create(size_t size);

/// Destroy array of msg/Distance messages.
/**
 * It calls
 * apf_interfaces__msg__Distance__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Distance__Sequence__destroy(apf_interfaces__msg__Distance__Sequence * array);

/// Check for msg/Distance message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Distance__Sequence__are_equal(const apf_interfaces__msg__Distance__Sequence * lhs, const apf_interfaces__msg__Distance__Sequence * rhs);

/// Copy an array of msg/Distance messages.
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
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Distance__Sequence__copy(
  const apf_interfaces__msg__Distance__Sequence * input,
  apf_interfaces__msg__Distance__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // APF_INTERFACES__MSG__DETAIL__DISTANCE__FUNCTIONS_H_
