# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Include/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Interface/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/
    ../Components/Speed/
)

# Add a shared library target 'system_initPlayer'
add_library(system_initPlayer SHARED
    Players/PlayerInitSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position3DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ObjPathComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
)

add_library(system_moveRight SHARED MoveSystem/MoveSystemRight/MoveSystemRight.cpp)
add_library(system_moveLeft SHARED MoveSystem/MoveSystemLeft/MoveSystemLeft.cpp)
add_library(system_moveUp SHARED MoveSystem/MoveSystemUp/MoveSystemUp.cpp)
add_library(system_moveDown SHARED MoveSystem/MoveSystemDown/MoveSystemDown.cpp)
