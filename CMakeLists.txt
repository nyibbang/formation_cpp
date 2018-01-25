cmake_minimum_required(VERSION 3.9)
project(moderncpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

enable_testing()

add_subdirectory(contrib/googletest)

add_executable(moderncpp
  lambdas.cpp
  deduced_return_type.cpp
  relaxed_constexpr.cpp
)
add_test(moderncpp moderncpp)
target_include_directories(moderncpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/contrib/googletest/include
    ${CMAKE_BINARY_DIR}/contrib/googletest/include)
target_link_libraries(moderncpp gmock_main)
