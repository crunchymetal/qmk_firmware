// Copyright 2022 Chris Nelson (@crunchymetal)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"
#define ___ KC_NO

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

/* CrunchyPad matrix layout
   *      ,-------------------.
   *      | 01 | 02 | 03 | 04 |
   * ,----|----|----|----|----|
   * | 10 | 11 | 12 | 13 |    |
   * '----|----|----|----| 24 |
   *      | 21 | 22 | 23 |    |
   * ,----|----|----|----|----|
   * | 30 | 31 | 32 | 33 |    |
   * '----|----|----|----| 44 |
   *      | 41 | 42 | 43 |    |
   *      `-------------------'
 */
 #define LAYOUT( \
	     k01, k02, k03, k04, \
	k10, k11, k12, k13,      \
	     k21, k22, k23, k24, \
	k30, k31, k32, k33,      \
	     k41, k42, k43, k44  \
) \
{ \
	{___, k01, k02, k03, k04}, \
	{k10, k11, k12, k13, ___}, \
	{___, k21, k22, k23, k24}, \
	{k30, k31, k32, k33, ___}, \
	{___, k41, k42, k43, k44}  \
}
