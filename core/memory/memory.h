/**
 * @file memory.h
 * @brief Internal memory unit management
 *
 * Provides functions and definitions for managing tracking of memory units
 * in the secure object context.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include <stdlib.h>

typedef struct {
    /// @brief Address of memory object unit
    void * address;
    /// @brief Length of data at `address`
    size_t length;
} MemoryUnit;

#include "../secure/object/object.h"

/// @brief Adds a new memory unit to the SecureObjectContext by SecureHandle and Address
/// @param secure_handle The handle used to find the context
/// @param address The address of the memory unit
/// @param size The size of the memory unit
void add_memory_unit(SecureHandle secure_handle, void * address, size_t size);