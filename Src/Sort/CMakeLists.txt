cmake_minimum_required(VERSION 3.0)
project(Sort)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/sort.cpp)
add_executable(SortDemo ${SOURCE_FILES})