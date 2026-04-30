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
#include "../secure.h"

void overwrite_data(void * address, size_t length);