/**
 * @file fragmentation.h
 * @brief Internal fragmentation security mechanism
 *
 * Provides functions and definitions for implementing fragmentation of secure memory objects.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include <stdlib.h>
#include "../secure.h"

typedef struct {
    int each_size;
    int remainder_size;
} calculate_fragmentation_result;

void calculate_fragmentation(size_t size, int amount, int size_incremental_difference, calculate_fragmentation_result * result);