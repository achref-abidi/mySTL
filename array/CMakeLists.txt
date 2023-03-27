# specify the source files for subproject 1
set(SOURCE_FILES
        main.cpp
        )

# specify the header files for subproject 1
#set(HEADER_FILES
        #subproject1/my_class.h
#        )


# create an executable for subproject 1
add_executable(array ${SOURCE_FILES})
