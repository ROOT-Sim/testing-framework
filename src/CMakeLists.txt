# SPDX-FileCopyrightText: 2008-2023 HPDCS Group <rootsim@googlegroups.com>
# SPDX-License-Identifier: GPL-3.0-only
add_library(rstest STATIC rng.c test.c thread.c)
target_link_libraries(rstest ${CMAKE_THREAD_LIBS_INIT} ${EXTRA_LIBS})
target_include_directories(rstest PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

install(FILES test.h DESTINATION include)
install(TARGETS rstest LIBRARY DESTINATION lib)
