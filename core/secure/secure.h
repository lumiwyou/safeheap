/**
 * @file secure.h
 * @brief Internal security scheme and sensitivity management
 *
 * Provides functions and definitions for secure schemes and sensitivity classes.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include <stdbool.h>
#include <stdlib.h>

/// @brief The bridging handle between the user-space and the library internals.
typedef void * SecureHandle;

/// @brief A label that determines how sensitive the memory object is to unauthorized information disclosure.
typedef enum {
    CRITICAL,
    INTERNAL,
    PUBLIC,
    _DEFAULT
} Sensitivity;

/// @brief Security sub-scheme for encrypting memory objects.
typedef struct {
    bool enabled;
    int size_incremental_difference;
} EncryptionScheme;

/// @brief Security sub-scheme for fragmenting memory objects.
typedef struct {
    bool enabled;
    int amount;
} FragmentationScheme;

/// @brief Security sub-scheme for generating "noise" during input/output operations.
/// Mitigation against side-channel attacks.
typedef struct {
    bool enabled;
} NoisingScheme;

/// @brief Security sub-scheme for wiping data.
typedef struct {
    bool enabled;
    int rounds;
    char * pattern;
    int length;
} DataWipingScheme;

/// @brief The security scheme for which to use for securing memory objects.
/// Contains sub-schemes such as encryption, fragmentation, noising, data wiping, etc.
typedef struct
{
    Sensitivity sensitivity;
    EncryptionScheme encryption;
    FragmentationScheme fragmentation;
    NoisingScheme noising;
    DataWipingScheme data_wiping;
} SecureObjectScheme;

/// @brief A list of the available schemes to use
extern SecureObjectScheme available_schemes[];

/// @brief Retrieves security scheme by grade attribute
/// @param grade Grade to match against
/// @param size (Optional) Size of the memory object
/// @return Security scheme pointer
SecureObjectScheme * get_scheme_by_grade(Sensitivity grade);