/**
 * @file encryption.h
 * 
 * @brief Memory object encryption system
 * 
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 * 
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

/// @brief Security sub-scheme for encrypting memory objects.
typedef struct {
    bool enabled;
    int size_incremental_difference;
} EncryptionScheme;