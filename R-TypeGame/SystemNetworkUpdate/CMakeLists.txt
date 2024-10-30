# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Engine)

find_package(jsoncpp REQUIRED)
find_package(asio CONFIG REQUIRED)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Include/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Interface/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Player/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Speed/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Editable/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Velocity/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Speed/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Velocity/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/TextureRectParser/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/Position2DParser/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/SpeedParser/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/VelocityParser/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/ScaleParser/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Enum/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/
    ../Components/Life/
    ../Components/Shoot/
    ../Components/Planet/
    ../Components/ButtonState/
    ../Components/Clickable/
    ../Components/TextLimit/
    ../Components/
    ../../../Engine/Client/Src
    ../Systems/Background/
    ../Systems/Shoot/
    ../../Engine/Ecs/Src/
    ../Components/Shoot/
    ../Parser/ShootParser/
    Shoot/
)

# Add a shared library target 'system_initPlayer'
add_library(update_position_component SHARED
    UpdatePositionSystem/updatePositionSystem.cpp
)

target_link_libraries(update_position_component PRIVATE
    asio::asio
    JsonCpp::JsonCpp
    Player
    r-type_abi_network
)

add_library(update_shoot_system SHARED
    UpdateShootSystem/updateShootSystem.cpp
    ../Systems/Shoot/ShootSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    ../Systems/Shoot/ShootInitSystem.cpp
)

target_link_libraries(update_shoot_system PRIVATE
    asio::asio
    JsonCpp::JsonCpp
    Position2D
    Scale
    TextureRect
    Draw
    Speed
    Velocity
    Shoot
    r-type_abi_network
)

add_library(update_playerConnection_system SHARED
    UpdatePlayerConnectionSystem/updatePlayerConnectionSystem.cpp
)

target_link_libraries(update_playerConnection_system PRIVATE
    asio::asio
    JsonCpp::JsonCpp
    Player
    r-type_abi_network
)
