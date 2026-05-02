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
#include <stdbool.h>

/// @brief Contains the results from `calculate_fragmentation`
typedef struct {
    int each_size;
    int remainder_size;
} calculate_fragmentation_result;

/// @brief Security sub-scheme for fragmenting memory objects.
typedef struct {
    bool enabled;
    int amount;
} FragmentationScheme;

#include "../secure.h"

/// @brief Utility used for calculating the total_size of each fragment and the remainder
/// @param total_size [in] The size of the memory object
/// @param amount [in] The amount of fragments (factor)
/// @param size_incremental_difference [in] Cryptographical padding to the output
/// @param result [out] The structure storing the result information
void calculate_fragmentation(size_t total_size, int amount, int size_incremental_difference, calculate_fragmentation_result * result);