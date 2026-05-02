/**
 * @file allocate.h
 * @brief Memory allocation interface for secure object management.
 *
 * Provides functions and definitions for allocating, tracking,
 * and managing secure memory objects within the library.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include "../../core/secure/object/object.h"
#include "../../core/secure/wiping/wiping.h"
#include "../../core/secure/fragmentation/fragmentation.h"

/// @brief Interface function: Allocates a memory object and creates a corresponding `SecureObjectContext`.
/// Equivalent to stdlib `malloc`
/// @param size The size of the memory object
/// @param grade The sensitivity of the memory object
/// @return A handle to the new context for the object
SecureHandle sfp_malloc(size_t size, Sensitivity grade);

/// @brief Interface function: Contiguously allocates a new memory object and creates a corresponding `SecureObjectContext`
/// Equivalent to stdlib `calloc`
/// @param num Number of items in memory object (such as ints or chars)
/// @param size The size of the memory object
/// @param grade The sensitivity of the memory object
/// @return A handle to the new context for the object
SecureHandle sfp_calloc(int num, size_t size, Sensitivity grade);

/// @brief Interface function: Resizes the memory object and updates its `SecureObjectContext`
/// Equivalent to stdlib `realloc`
/// @param secure_handle The handle to the context
/// @param size The new size of the memory object
/// @return New secure handle (resized User Data Buffer)
SecureHandle sfp_realloc(SecureHandle secure_handle, size_t size);

/// @brief Interface function: Frees the memory object and removes its `SecureObjectContext`
/// Equivalent to stdlib `free`
/// @param secure_handle The handle to the context / user data buffer
void sfp_free(SecureHandle secure_handle);