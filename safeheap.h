/**
 * @file safeheap.h
 * @brief SafeHeap - Secure memory allocation library
 *
 * This is the main include file for the SafeHeap library.
 * Include this header to access all library functionality.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include "core/memory/memory.h"
#include "core/secure/secure.h"
#include "core/secure/fragmentation/fragmentation.h"
#include "core/secure/wiping/wiping.h"
#include "core/secure/object/object.h"

#include "interface/allocate/allocate.h"