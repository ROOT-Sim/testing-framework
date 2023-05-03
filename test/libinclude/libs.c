/**
 * @file test/libinclude/libs.c
 *
 * @brief Test: A test program to test if the functions can include libraries
 *
 * SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
 * SPDX-License-Identifier: GPL-3.0-only
 */
#include <stdbool.h>

extern bool check_value_from_lib(void);

int main(void)
{
	return check_value_from_lib() != true;
}
