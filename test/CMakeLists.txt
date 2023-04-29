# SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
# SPDX-License-Identifier: GPL-3.0-only
function(test_program name)
    add_executable(test_${name} ${ARGN})
    target_include_directories(test_${name} PRIVATE ../src)
    target_link_libraries(test_${name} rstest)
    add_test(NAME test_${name} COMMAND test_${name})
    set_tests_properties(test_${name} PROPERTIES TIMEOUT 60)
endfunction()

function(test_program_xf name)
    test_program(${name} ${ARGN})
    set_tests_properties(test_${name} PROPERTIES WILL_FAIL TRUE)
endfunction()

# Test framework tests
test_program(self_main stubs.c main.c)
test_program_xf(self_fail_assert stubs.c fail_assert.c)
test_program_xf(self_fail_explicit stubs.c fail_explicit.c)
test_program_xf(self_fail_implicit stubs.c fail_implicit.c)
test_program_xf(self_fail_implicit_multi stubs.c fail_implicit_multi.c)
test_program_xf(self_fail_top_level_assert stubs.c fail_top_level_assert.c)
test_program_xf(self_unexp_pass_assert stubs.c unexp_pass_assert.c)
test_program_xf(self_unexp_pass_plain stubs.c unexp_pass_plain.c)
