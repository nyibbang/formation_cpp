cmake_minimum_required(VERSION 2.8)

project(FormationCpp)

# modules and packages
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
include(EnableCXX11)
enable_testing()

# third parties
add_subdirectory(googletest)
include(ExternalProject)
include(External-Boost)

include_directories(${Boost_INCLUDE_DIR})
add_subdirectory(sessions/1/practical_cases)
