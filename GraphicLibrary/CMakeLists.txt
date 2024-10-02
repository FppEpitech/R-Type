# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Config/GraphicLibrary/)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Interface/
)

# Add a shared library target 'graphic_raylib'
add_library(graphic_raylib SHARED Src/GraphicLib.cpp)

# Link the 'raylib' library to 'graphic_raylib'
target_link_libraries(graphic_raylib PRIVATE raylib)
