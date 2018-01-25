cmake_minimum_required(VERSION 3.9)
project(moderncpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(GTest REQUIRED)
enable_testing()

add_executable(moderncpp
  generic_lambdas.cpp
  extended_capture_in_lambdas.cpp
)
target_include_directories(moderncpp PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(moderncpp ${GTEST_BOTH_LIBRARIES})
