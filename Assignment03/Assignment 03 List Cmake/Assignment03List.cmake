cmake_minimum_required(VERSION 3.16)
project(Assignment03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing (CTest + GoogleTest)
include(CTest)
enable_testing()

# --- GoogleTest via FetchContent (same style as lecture) ---
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows/MSVC runtime consistency (matches slide note)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Optional: a simple manual runner (if you want one)
# add_executable(list_demo src/main.cpp)
# target_include_directories(list_demo PRIVATE ${PROJECT_SOURCE_DIR}/include)

# --- Assignment03 tests (List + Bag) ---
add_executable(assignment03_tests tests/Assignment03.cpp)
target_include_directories(assignment03_tests PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  # The following helps some IDEs/IntelliSense find <gtest/gtest.h> immediately:
  ${gtest_SOURCE_DIR}/googletest/include
)
target_link_libraries(assignment03_tests PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(assignment03_tests)

# --- Keep the old vector tests (optional) ---
# If tests/vector_tests.cpp exists and includes "MyVector.hpp" one dir up, this mimics your old setup.
add_executable(vector_tests tests/vector_tests.cpp)
target_include_directories(vector_tests PRIVATE
  ${PROJECT_SOURCE_DIR}         # lets it see headers at repo root
  ${gtest_SOURCE_DIR}/googletest/include
)
target_link_libraries(vector_tests PRIVATE GTest::gtest_main)
gtest_discover_tests(vector_tests)
