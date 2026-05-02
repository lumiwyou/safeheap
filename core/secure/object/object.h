/**
 * @file object.h
 * @brief Internal secure object context management
 *
 * Provides functions and definitions for managing secure object contexts.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include "../secure.h"
#include "../../memory/memory.h"

/// @brief The context of a memory object and the security operations surrounding it.
/// Tracks the security schemes to be used, the memory units containing the memory object, and the SecureHandle.
typedef struct {
    /// @brief The handle used for de-referencing the User Data Buffer (UDB) and internal structures
    SecureHandle secure_handle;
    /// @brief The total size of the memory object
    size_t data_total_size;
    /// @brief The security scheme to be employed for securing the memory object
    SecureObjectScheme * scheme;
    /// @brief Contains the actual memory object in either one or more memory `unit(s)`
    MemoryUnit ** memory_units;
    /// @brief The amount of memory units in this context
    int memory_unit_count;
} SecureObjectContext;

/// @brief Central table for tracking all the SecureObjectContext entries
extern SecureObjectContext ** secured_objects_table;
/// @brief Tracks the count of SecureObjectContext entries
extern int secured_objects_count;

/// @brief Adds a new SecureObjectContext
/// @param grade The sensitivity attribute to give
/// @param size The size of memory object to give
/// @return Secure handle to new context
SecureHandle create_secure_object(Sensitivity grade, size_t size);

/// @brief Removes SecureObjectContext by SecureHandle
/// @param secure_handle The secure handle to match against
void delete_secure_object(SecureHandle secure_handle);

/// @brief Updates information in the SecureObjectContext
/// Used in reallocation operations.
/// @param secure_handle The secure handle used for matching
/// @param grade The new sensitivity attribute
/// @param size The new size attribute
void update_secure_object(SecureHandle secure_handle, Sensitivity grade, size_t size);

/// @brief Retrieves a SecureObjectContext by SecureHandle
/// @param secure_handle The secure handle used for matching
/// @return A pointer to the SecureObjectContext
SecureObjectContext * get_secure_object(SecureHandle secure_handle);

/// @brief Finds empty SecureObjectContext spots in the central table (secured_objects_table)
/// @return A pointer to the context
SecureObjectContext ** find_empty_context(void);