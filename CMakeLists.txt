# SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
# SPDX-License-Identifier: GPL-3.0-only
cmake_minimum_required(VERSION 3.12)
project("ROOT-Sim test framework" LANGUAGES C DESCRIPTION "The testing framework used by ROOT-Sim projects")

set(PROJECT_VERSION 1.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (MSVC)
    message(FATAL_ERROR "You are using the MSVC compiler, which does not properly implement C11. Please consider switching to clang.")
endif ()

find_package(Threads REQUIRED)
add_compile_options(-Wall -Wextra -pedantic)

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

# Run the tests
enable_testing()
add_subdirectory(test)
