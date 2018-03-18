cmake_minimum_required(VERSION 3.0)
project(TestC)

#set(CMAKE_CXX_STANDARD 11)

include_directories(include)


include_directories(/home/yanhao/project/LearningDemo/Src/LibA/include)
link_directories(/home/yanhao/project/LearningDemo/Src/LibA/lib)

set(EXECUTABLE_OUTPUT_PATH bin)

set(SOURCE_FILES src/main.cpp src/add.cpp)
add_executable(testC ${SOURCE_FILES})
target_link_libraries(testC XAdd)