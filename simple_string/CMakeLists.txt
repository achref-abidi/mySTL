# Set the build directory
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(SOURCE_FILES
        main.cpp
      Simple_String.h
        )

add_executable(simple_string ${SOURCE_FILES})
