cmake_minimum_required(VERSION 3.0)
project(Stack)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/stack.cpp ../Queue/src/main.cpp)
add_executable(StackDemo ${SOURCE_FILES})