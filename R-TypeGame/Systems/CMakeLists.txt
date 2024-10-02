# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Config/Systems/)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Include/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Interface/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
)

# Add a shared library target 'system_initPlayer'
add_library(system_initPlayer SHARED
    Players/PlayerInitSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position3DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ObjPathComponent.cpp
)
