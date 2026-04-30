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
#include "../secure/secure.h"
#include "../memory/memory.h"

typedef struct {
    SecureHandle secure_handle;
    size_t data_total_size;
    SchemeIdentifier scheme_id;
    MemoryUnit ** memory_units;
    int memory_unit_count;
} SecureObjectContext;

extern SecureObjectContext ** secured_objects_table;
extern int secured_objects_count;

SecureHandle add_secure_object(Sensitivity grade, size_t size);
void remove_secure_object(SecureHandle secure_handle);
void update_secure_object(SecureHandle secure_handle, Sensitivity grade, size_t size);
SecureObjectContext * get_context_by_handle(SecureHandle secure_handle);