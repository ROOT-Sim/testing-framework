# ROOT-Sim Testing Framework

_Brought to you by the [High Performance and Dependable Computing Systems (HPDCS)](https://hpdcs.github.io/)
Research Group_

[![Build Status](https://github.com/ROOT-Sim/testing-framework/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/ROOT-Sim/testing-framework/actions/workflows/build_and_test.yml)
----------------------------------------------------------------------------------------

This repository contains the testing framework used by various ROOT-Sim projects.

## Usage

In order to use the testing framework, you can include the following in your `CMakeLists.txt` file:

```cmake
include(FetchContent)
FetchContent_Declare(rstest
        GIT_REPOSITORY https://github.com/ROOT-Sim/testing-framework.git
        GIT_TAG origin/master
        )
FetchContent_MakeAvailable(rstest)
```

Then, you can use the `test_program` function to add tests to your project:

```cmake
test_program(name_of_the_test list.c of.c src.c files.c)
```

If the test is expected to fail, you can use the `test_program_xf` function instead:

```cmake
test_program_xf(name_of_the_test list.c of.c src.c files.c)
```

If the test should use MPI, you can use the `test_program_mpi` function instead:

```cmake
test_program_mpi(name_of_the_test list.c of.c src.c files.c)
```

Please note that in this case, only two MPI ranks are used. There is no possibility to
parameterize the number of nodes at this time.

If the test program should be linked against a specific library, you can use the
`test_program_link_libraries` function to provide a list of library targets to link against:

```cmake
test_program_link_libraries(name_of_the_test liba libb libc)
```

## Test API

The testing framework provides a simple API to write tests. The API is defined in the
`test.h` header file, which is automatically added to the include path when using
`FetchContent`. Refer to the header or to the `core` project for example of how to use.
