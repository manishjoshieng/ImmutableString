cmake_minimum_required(VERSION 3.22.1)

project(ImString)

set(CMAKE_CXX_STANDARD 17)

# Set variables for the directories containing header files and source files
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the source files to the build
add_executable(ImString 
    main.cpp
)




