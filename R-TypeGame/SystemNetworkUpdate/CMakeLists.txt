# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)

find_package(jsoncpp REQUIRED)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Include/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Interface/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/
    ../Components/Speed/
    ../Components/Life/
    ../Components/Shoot/
    ../Components/Planet/
    ../Components/Editable/
    ../Components/ButtonState/
    ../Components/CallBack/
    ../Components/TextLimit/
    ../Components/Velocity/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
    ../Systems/Background/
    ../Systems/Shoot/
    ../../Engine/Shared/Ecs/Src/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Enum/
)

# Add a shared library target 'system_initPlayer'
add_library(update_position_component SHARED
    UpdatePositionSystem/updatePositionSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Network/Packet/NetworkPacket.cpp
)
