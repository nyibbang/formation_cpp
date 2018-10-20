add_library(forma1_sess3_utils STATIC
  strided_iterator.hpp
  types.hpp types.cpp
  ranges.hpp
  logic.hpp logic.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(tests)
add_subdirectory(console)
