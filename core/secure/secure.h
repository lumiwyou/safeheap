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

typedef void * SecureHandle;

typedef enum {
    CRITICAL,
    INTERNAL,
    PUBLIC
} Sensitivity;

typedef enum {
    TEST
} SchemeIdentifier;

typedef struct {
    bool enabled;
    int size_incremental_difference;
} EncryptionScheme;

typedef struct {
    bool enabled;
    int amount;
} FragmentationScheme;

typedef struct {
    bool enabled;
} NoisingScheme;

typedef struct {
    bool enabled;
    int rounds;
    char * pattern;
    int length;
} DataWipingScheme;

typedef struct
{
    SchemeIdentifier id;
    Sensitivity sensitivity;
    EncryptionScheme encryption;
    FragmentationScheme fragmentation;
    NoisingScheme noising;
    DataWipingScheme data_wiping;
} SecureObjectScheme;

extern SecureObjectScheme available_schemes;

SecureObjectScheme * get_scheme_by_identifier(SchemeIdentifier identifier);
SchemeIdentifier get_scheme_by_grade(Sensitivity grade, size_t size);