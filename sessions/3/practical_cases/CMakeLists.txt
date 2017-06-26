add_library(sess3_lib STATIC
  types.hpp types.cpp
  logic.hpp logic.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(tests)
add_subdirectory(console)
