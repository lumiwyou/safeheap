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
    unsigned char * address;
    size_t length;
} MemoryUnit;

#include "../secure/object/object.h"

void add_memory_unit(SecureHandle secure_handle, unsigned char * address, size_t size);