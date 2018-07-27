cmake_minimum_required(VERSION 3.0)
project(LeetCodeRecursive)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/recursive.cpp)
add_executable(LeetCodeGreedy ${SOURCE_FILES})