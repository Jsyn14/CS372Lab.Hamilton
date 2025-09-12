cmake_minimum_required(VERSION 3.8)

# Set the project name
project(Assignment04)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include shared headers (e.g., Stack.h, Queue.h)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the class library source files
set(CLASS_LIB_SRC
    src/Stack.cpp
    src/Queue.cpp
)

# Create a static library for Stack and Queue
add_library(classlib STATIC ${CLASS_LIB_SRC})

# Add executables for testing and Josephus problem
add_executable(stacktest tests/stacktest.cpp)
add_executable(queuetest tests/queuetest.cpp)
add_executable(josephus src/josephus.cpp)

# Link the class library to each executable
target_link_libraries(stacktest classlib)
target_link_libraries(queuetest classlib)
target_link_libraries(josephus classlib)