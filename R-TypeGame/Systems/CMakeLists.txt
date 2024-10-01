cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Engine/Server/Lib/Systems/)

include_directories(
        ../../Engine/Shared/Ecs/Include/
        ../../Engine/Shared/Interface/
        ../Components/Position/
        ../Components/Speed/
        ../../Engine/Shared/Component/Entities/Player/
)

add_library(system_moveRight SHARED MoveSystem/MoveSystemRight/MoveSystemRight.cpp)
