cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME mySTL)

project(${PROJECT_NAME})

# subproject 1
add_subdirectory(array)
add_subdirectory(vector)
add_subdirectory(simple_string)