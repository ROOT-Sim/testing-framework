# SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
# SPDX-License-Identifier: GPL-3.0-only
cmake_minimum_required(VERSION 3.12)
project("ROOT-Sim test framework" LANGUAGES C DESCRIPTION "The testing framework used by ROOT-Sim projects")

set(PROJECT_VERSION 1.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC AND NOT CMAKE_C_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "You are using the MSVC compiler, which does not properly implement C11. Please consider switching to clang.")
endif()
if(NOT MSVC)
    add_compile_options(-Wall -Wextra -pedantic)
endif()

find_package(Threads REQUIRED)

include(CheckLibraryExists)
CHECK_LIBRARY_EXISTS(m exp "" HAVE_LIB_M)
if (HAVE_LIB_M)
    set(EXTRA_LIBS m)
else ()
    set(EXTRA_LIBS "")
endif ()

if (WIN32)
    # Needed for some system calls
    set(EXTRA_LIBS ${EXTRA_LIBS} psapi)
endif ()

add_subdirectory(src)

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

function(test_program_mpi name)
    test_program(${name} ${ARGN})
    set_property(TARGET test_${name} PROPERTY CROSSCOMPILING_EMULATOR "${MPIEXEC_EXECUTABLE};${MPIEXEC_NUMPROC_FLAG};2")
endfunction()

function(test_program_link_libraries name)
    target_link_libraries(test_${name} ${ARGN})
endfunction()

if (NOT IMPORT_AS_LIB)
    # Run the tests
    enable_testing()
    add_subdirectory(test)
endif ()
