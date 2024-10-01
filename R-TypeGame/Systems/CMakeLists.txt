cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Engine/Client/Lib/Systems/)

include_directories(
        ../../Engine/Shared/Ecs/Include/
        ../../Engine/Shared/Interface/
        ../../Engine/Shared/Component/
)

add_library(system_initPlayer SHARED
    Players/PlayerInitSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ../../Engine/Shared/Component/Position3DComponent.cpp
    ../../Engine/Shared/Component/ObjPathComponent.cpp)
