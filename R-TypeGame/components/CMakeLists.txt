cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Server/lib/components/)

include_directories(
    ../../Server/include/
)

add_library(component_position SHARED PositionComponent.cpp)
