/**
 * @file test/libinclude/lib2.c
 *
 * @brief Test: A dummy library to test library inclusion
 *
 * SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
 * SPDX-License-Identifier: GPL-3.0-only
 */
#include <stdbool.h>

extern int get_value_from_lib(void);

bool check_value_from_lib(void)
{
	return get_value_from_lib() == 42;
}
