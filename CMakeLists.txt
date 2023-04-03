cmake_minimum_required(VERSION 3.25)
project(activityTracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(activityTracker main.cpp gui.cpp gui.h)
#adding ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(activityTracker ${CURSES_LIBRARIES})