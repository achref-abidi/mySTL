cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME mySTL)

project(${PROJECT_NAME})

# subproject 1
add_subdirectory(array)

add_subdirectory(testcpp)

# subproject 2
#add_subdirectory(subproject2)