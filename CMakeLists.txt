cmake_minimum_required(VERSION 3.13)  # CMake version check
project(Eon)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(include/)

# Add main.cpp file of the project root directory as a source file
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h include/*.hpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(Eon ${SOURCE_FILES} ${HEADER_FILES})