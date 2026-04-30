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
#include "../core/secure/object/object.h"

SecureHandle sfp_malloc(size_t size, Sensitivity grade);
SecureHandle sfp_calloc(int num, size_t size, Sensitivity grade);
SecureHandle sfp_realloc(SecureHandle secure_handle, size_t size);
void sfp_free(SecureHandle secure_handle);
void sfp_free_x(SecureHandle secure_handle, Sensitivity grade);