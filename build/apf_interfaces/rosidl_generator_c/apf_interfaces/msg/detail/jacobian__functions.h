// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from apf_interfaces:msg/Jacobian.idl
// generated code does not contain a copyright notice

#ifndef APF_INTERFACES__MSG__DETAIL__JACOBIAN__FUNCTIONS_H_
#define APF_INTERFACES__MSG__DETAIL__JACOBIAN__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "apf_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "apf_interfaces/msg/detail/jacobian__struct.h"

/// Initialize msg/Jacobian message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * apf_interfaces__msg__Jacobian
 * )) before or use
 * apf_interfaces__msg__Jacobian__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Jacobian__init(apf_interfaces__msg__Jacobian * msg);

/// Finalize msg/Jacobian message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Jacobian__fini(apf_interfaces__msg__Jacobian * msg);

/// Create msg/Jacobian message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * apf_interfaces__msg__Jacobian__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
apf_interfaces__msg__Jacobian *
apf_interfaces__msg__Jacobian__create();

/// Destroy msg/Jacobian message.
/**
 * It calls
 * apf_interfaces__msg__Jacobian__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Jacobian__destroy(apf_interfaces__msg__Jacobian * msg);

/// Check for msg/Jacobian message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Jacobian__are_equal(const apf_interfaces__msg__Jacobian * lhs, const apf_interfaces__msg__Jacobian * rhs);

/// Copy a msg/Jacobian message.
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
apf_interfaces__msg__Jacobian__copy(
  const apf_interfaces__msg__Jacobian * input,
  apf_interfaces__msg__Jacobian * output);

/// Initialize array of msg/Jacobian messages.
/**
 * It allocates the memory for the number of elements and calls
 * apf_interfaces__msg__Jacobian__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Jacobian__Sequence__init(apf_interfaces__msg__Jacobian__Sequence * array, size_t size);

/// Finalize array of msg/Jacobian messages.
/**
 * It calls
 * apf_interfaces__msg__Jacobian__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Jacobian__Sequence__fini(apf_interfaces__msg__Jacobian__Sequence * array);

/// Create array of msg/Jacobian messages.
/**
 * It allocates the memory for the array and calls
 * apf_interfaces__msg__Jacobian__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
apf_interfaces__msg__Jacobian__Sequence *
apf_interfaces__msg__Jacobian__Sequence__create(size_t size);

/// Destroy array of msg/Jacobian messages.
/**
 * It calls
 * apf_interfaces__msg__Jacobian__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
void
apf_interfaces__msg__Jacobian__Sequence__destroy(apf_interfaces__msg__Jacobian__Sequence * array);

/// Check for msg/Jacobian message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_apf_interfaces
bool
apf_interfaces__msg__Jacobian__Sequence__are_equal(const apf_interfaces__msg__Jacobian__Sequence * lhs, const apf_interfaces__msg__Jacobian__Sequence * rhs);

/// Copy an array of msg/Jacobian messages.
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
apf_interfaces__msg__Jacobian__Sequence__copy(
  const apf_interfaces__msg__Jacobian__Sequence * input,
  apf_interfaces__msg__Jacobian__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // APF_INTERFACES__MSG__DETAIL__JACOBIAN__FUNCTIONS_H_
