cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Server/lib/systems/)

include_directories(
    ../../Ecs/include/
    ../../include/interfaces/
)

add_library(system_move SHARED MoveSystem.cpp)
