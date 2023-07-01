cmake_minimum_required(VERSION 3.25)
project(activityTracker)

set(CMAKE_CXX_STANDARD 17)

# Adding wxWidgets library
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(activityTracker main.cpp gui.cpp gui.h activity.cpp activity.h activity_log.cpp activity_log.h TimeUtilities.cpp TimeUtilities.h)
target_link_libraries(activityTracker PRIVATE ${wxWidgets_LIBRARIES})

# Add the subdirectory for tests
add_subdirectory(test)


