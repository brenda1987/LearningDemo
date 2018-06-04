cmake_minimum_required(VERSION 3.0)
project(LeetCode23)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp)
add_executable(LeetCode23Demo ${SOURCE_FILES})