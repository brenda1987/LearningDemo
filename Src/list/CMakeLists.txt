cmake_minimum_required(VERSION 3.0)
project(list)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/list.cpp ../Stack/src/main.cpp ../Stack/src/stack.cpp ../Stack/include/stack.h)
add_executable(ListDemo ${SOURCE_FILES})