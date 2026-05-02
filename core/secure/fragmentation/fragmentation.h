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

/// @brief Contains the results from `calculate_fragmentation`
typedef struct {
    int each_size;
    int remainder_size;
} calculate_fragmentation_result;

/// @brief Utility used for calculating the size of each fragment and the remainder
/// @param size [in] The size of the memory object
/// @param amount [in] The amount of fragments (factor)
/// @param size_incremental_difference [in] Cryptographical padding to the output
/// @param result [out] The structure storing the result information
void calculate_fragmentation(size_t size, int amount, int size_incremental_difference, calculate_fragmentation_result * result);