cmake_minimum_required(VERSION 3.10)
project(8083_emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0135 NEW)

# Enable testing
include(CTest)

# Use FetchContent to download Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# Ensure the dependency is downloaded and made available
FetchContent_MakeAvailable(googletest)

# Enable Google Test
enable_testing()

# Add the main project library or executable
add_executable(Emulator
    main.cpp 
    src/registers.cpp
    src/memory.cpp
)

# Add the test executable
add_executable(Tests
    tests/registers.cpp
    tests/memory.cpp
    src/registers.cpp
    src/memory.cpp
)
target_link_libraries(Tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Tests)
