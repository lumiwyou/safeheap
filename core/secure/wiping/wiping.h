/**
 * @file wiping.h
 * @brief Internal data wiping mechanism
 *
 * Provides functions and definitions for data wiping procedure
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/// @brief Security sub-scheme for wiping data.
typedef struct {
    bool enabled;
    int rounds;
    char * pattern;
    int length;
} DataWipingScheme;

#include "../secure.h"

/// @brief Overwrites data using patterns and rounds according to grade
/// @param address address to overwrite
/// @param length length to overwrite
/// @param grade (Optional) sensitivity specifier to overwrite original object sensitivity
void overwrite_data(void * address, size_t length, Sensitivity grade);