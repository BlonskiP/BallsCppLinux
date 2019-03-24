cmake_minimum_required(VERSION 3.13)
project(threadBalls)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(CMAKE_CXX_STANDARD 14)



add_executable(threadBalls main.cpp PrintManager.cpp PrintManager.h Ball.cpp Ball.h Map.cpp Map.h)
target_link_libraries(threadBalls ${CURSES_LIBRARIES})


