/**
 * @file encryption.h
 * 
 * @brief Memory object encryption system
 * 
 * The library uses Libgcrypt for its encryption features
 * 
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 * 
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include "../secure.h"
#include <gcrypt.h>
#include <stdbool.h>

typedef struct {
    /// @brief Identifier of algorithm in use
    int id;
} EncryptionSchemeAlgorithm;

/// @brief Security sub-scheme for encrypting memory objects.
typedef struct {
    /// @brief Indicates if feature scheme is enabled
    bool enabled;
    EncryptionSchemeAlgorithm * algorithm;
} EncryptionScheme;

extern EncryptionSchemeAlgorithm ** encryption_schemes[];