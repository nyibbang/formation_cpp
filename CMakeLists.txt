cmake_minimum_required(VERSION 2.8)

project(FormationCpp)

# modules and packages
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
include(EnableCXX11)
enable_testing()

# third parties
set(gtest_force_shared_crt TRUE CACHE BOOL "" FORCE)
add_subdirectory(googletest)
include(ExternalProject)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(sessions/1/practical_cases)
add_subdirectory(sessions/2/practical_cases)
add_subdirectory(sessions/3/practical_cases)
