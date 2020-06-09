cmake_minimum_required(VERSION 3.16)

# Project C Integration
project(c-integration-modern-cpp)

# Languages
ENABLE_LANGUAGE(CXX)
ENABLE_LANGUAGE(C)

# Languages standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 90)

# Compilers flags:
# - C flags
set(CMAKE_C_FLAGS "-O3 -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -Wextra -fprofile-arcs -ftest-coverage")

# - C++ flags
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra -fprofile-arcs -ftest-coverage")

# Old C libraries
add_library(old_func SHARED old_func/inc/old_func.h old_func/src/old_func.c)
add_library(old_struct SHARED old_struct/inc/old_struct.h old_struct/src/old_struct.c)
add_library(old_pimpl SHARED old_pimpl/inc/old_pimpl.h old_pimpl/src/old_pimpl.c)

# Old C libraries includes for C++ use
include_directories(old_func/inc old_struct/inc old_pimpl/inc)

# Tests
enable_testing()
set(CATCH_INCLUDE_DIR extern/Catch2/single_include)
add_library(Catch2::Catch IMPORTED INTERFACE)
include_directories(${CATCH_INCLUDE_DIR})

add_library(integrations IMPORTED INTERFACE)
add_library(wrapped_integrations IMPORTED INTERFACE)
add_library(smart_pointers_integrations IMPORTED INTERFACE)
include_directories(inc)

# - Integrations
add_executable(integrations_tests tests/integrations_tests.cpp)
target_link_libraries(integrations_tests old_func old_struct old_pimpl)
add_test(integrations_tests integrations_tests)

# - Wrapped integration
add_executable(wrapped_integrations_tests inc/wrapped_integrations.h tests/wrapped_integrations_tests.cpp)
target_link_libraries(wrapped_integrations_tests old_func old_struct old_pimpl)
add_test(wrapped_integrations_tests wrapped_integrations_tests)

# - Smart pointers integration
add_executable(smart_pointers_integrations_tests inc/smart_pointers_integrations.h tests/smart_pointers_integrations_tests.cpp)
target_link_libraries(smart_pointers_integrations_tests old_func old_struct old_pimpl)
add_test(smart_pointers_integrations_tests smart_pointers_integrations_tests)

