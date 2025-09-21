cmake_minimum_required(VERSION 3.16)
project(Assignment05Sorts LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optimize by default for Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# MSVC vs others: set reasonable optimization flags
if(MSVC)
  add_compile_options(/O2 /W4 /permissive-)
else()
  add_compile_options(-O2 -Wall -Wextra -pedantic)
endif()

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Executable
add_executable(sort_bench
  app/main.cpp
  src/sort_algorithms.cpp
)

# On Windows, put the exe under build/app or build/Release for clarity
set_target_properties(sort_bench PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/app"
)
