cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

include_directories(
    ../../Server/include/
)

add_library(component_position SHARED PositionComponent.cpp)

add_custom_command(TARGET component_position
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rename
        ${CMAKE_CURRENT_BINARY_DIR}/libcomponent_position.so
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Server/lib/components/libcomponent_position.so
)
