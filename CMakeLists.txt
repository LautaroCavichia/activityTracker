cmake_minimum_required(VERSION 3.25)
project(activityTracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(activityTracker main.cpp gui.cpp gui.h activity.cpp activity.h activity_log.cpp activity_log.h TimeUtilities.cpp TimeUtilities.h)
#adding wxWidgets library
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
target_link_libraries(activityTracker ${wxWidgets_LIBRARIES})

