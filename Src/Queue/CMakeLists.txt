cmake_minimum_required(VERSION 3.0)
project(Queue)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/queue.cpp ../Tree/src/BTree.cpp ../Tree/include/BTree.h ../Tree/src/main.cpp)
add_executable(QueueDemo ${SOURCE_FILES})