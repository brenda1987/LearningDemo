cmake_minimum_required(VERSION 3.0)
project(LibA)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

#set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH lib)

set(SOURCE_FILES src/xadd.cpp)
#add_executable(testC ${SOURCE_FILES})
add_library(XAdd SHARED ${SOURCE_FILES})
#add_library(XAdd STATIC ${SOURCE_FILES})