cmake_minimum_required(VERSION 3.0)
project(Tree)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/BTree.cpp src/leetCodeBTree.cpp)
add_executable(BTreeDemo ${SOURCE_FILES})