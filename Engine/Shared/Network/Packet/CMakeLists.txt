# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the library name
set(LIB r-type_packet)

# Set the output directory for the library
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Game/Libs/Network/)

# Define include paths
set(LIB_INCLUDE_PATH "Include")

# Define the main source files for the library
set(SRC_LIB
    NetworkPacket.cpp
)

# Add the static library target
add_library(${LIB} STATIC ${SRC_LIB})

# Find required packages
find_package(asio CONFIG REQUIRED)

# Link libraries to the library target
target_link_libraries(
    ${LIB}
    PRIVATE asio::asio
)

# Include directories for the library target
target_include_directories(${LIB} PUBLIC ${LIB_INCLUDE_PATH})
