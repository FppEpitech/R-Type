cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Engine/Client/Lib/Systems/)

include_directories(
        ../../Engine/Shared/Ecs/Include/
        ../../Engine/Shared/Interface/
        ../Components/Speed/
        ../../Engine/Shared/Component/Entities/Player/
        ../../Engine/Shared/Component/
)

add_library(system_initPlayer SHARED
    Players/PlayerInitSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ../../Engine/Shared/Component/Position3DComponent.cpp
    ../../Engine/Shared/Component/ObjPathComponent.cpp
    ../../Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
    ../Components/Speed/SpeedComponent.cpp)

add_library(system_moveRight SHARED MoveSystem/MoveSystemRight/MoveSystemRight.cpp)
add_library(system_moveLeft SHARED MoveSystem/MoveSystemLeft/MoveSystemLeft.cpp)
add_library(system_moveUp SHARED MoveSystem/MoveSystemUp/MoveSystemUp.cpp)
add_library(system_moveDown SHARED MoveSystem/MoveSystemDown/MoveSystemDown.cpp)
