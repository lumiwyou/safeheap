/**
 * @file noising.h
 * @brief Anti-side channel analysis system
 *
 * Provides functions and definitions for mitigating side-channel analysis attacks on memory operations.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

/// @brief Security sub-scheme for generating "noise" during input/output operations.
/// Mitigation against side-channel attacks.
typedef struct {
    bool enabled;
} NoisingScheme;