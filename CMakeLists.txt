cmake_minimum_required(VERSION 3.8)

project(FormationCpp)

# modules and packages
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
find_package(Threads)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(gtest_force_shared_crt TRUE CACHE BOOL "" FORCE)
add_subdirectory(contrib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(practical)

option(FORMATIONCPP_COMPILE_GENERIC_TESTS
  "If true, the project will compile the generic tests in the tests subdirectory"
  FALSE
)
if (FORMATIONCPP_COMPILE_GENERIC_TESTS)
  add_subdirectory(tests)
endif()
