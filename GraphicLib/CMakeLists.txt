cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Client/lib/graphic/)

include_directories(
    ../include/interfaces/
)

add_library(graphic_raylib SHARED GraphicLib.cpp)

target_link_libraries(graphic_raylib PRIVATE raylib)
