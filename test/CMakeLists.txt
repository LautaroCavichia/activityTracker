cmake_minimum_required(VERSION 3.5)
project(activityTracker)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Locate the Google Test libraries
find_package(GTest REQUIRED)

# Add the test executable
set(TEST_SOURCE_FILES ActivityTest.cpp TestMain.cpp
        ../activity.cpp ../TimeUtilities.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})

# Link the Google Test libraries
target_link_libraries(runTests GTest::GTest GTest::Main)
