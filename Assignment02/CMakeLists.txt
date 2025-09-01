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

# --- Test target ---
add_executable(vector_tests ${CMAKE_CURRENT_LIST_DIR}/vector_tests.cpp)

# Make tests see MyVector.hpp (one level up in Assignment02/)
target_include_directories(vector_tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(vector_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(vector_tests)
