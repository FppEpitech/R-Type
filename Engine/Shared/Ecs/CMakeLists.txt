# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the library name
set(LIB r-type_ecs)

# Set the output directory for the library
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Game/Libs/ECS/)

# Define source and include paths
set(LIB_SRC_PATH "Src")
set(LIB_INCLUDE_PATH "Include")

# Define the main source files for the library
set(SRC_LIB
    ${LIB_SRC_PATH}/Registry.cpp
)

# Add the static library target
add_library(${LIB} STATIC ${SRC_LIB})

# Include directories for the library target
target_include_directories(${LIB} PUBLIC ${LIB_INCLUDE_PATH})
