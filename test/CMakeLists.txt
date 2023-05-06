# SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
# SPDX-License-Identifier: GPL-3.0-only

# Dummy libraries to test library inclusion
add_library(lib1 STATIC libinclude/lib1.c)
add_library(lib2 STATIC libinclude/lib2.c)

# Test framework tests
test_program(main stubs.c main.c)
test_program_xf(fail_assert stubs.c fail_assert.c)
test_program_xf(fail_explicit stubs.c fail_explicit.c)
test_program_xf(fail_implicit stubs.c fail_implicit.c)
test_program_xf(fail_implicit_multi stubs.c fail_implicit_multi.c)
test_program_xf(fail_top_level_assert stubs.c fail_top_level_assert.c)
test_program_xf(unexp_pass_assert stubs.c unexp_pass_assert.c)
test_program_xf(unexp_pass_plain stubs.c unexp_pass_plain.c)
test_program(libinclude libinclude/libs.c)
test_program_link_libraries(libinclude lib2 lib1)
