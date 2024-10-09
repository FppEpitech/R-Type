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
    Shoot/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/
    Shoot/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
    ../Components/Speed/
    ../Components/Velocity/
    ../Components/Shoot/
    ../Parser/TextureRectParser/
    ../Parser/Position2DParser/
    ../Parser/SpeedParser/
    ../Parser/VelocityParser/
    ../Parser/ShootParser/
    ../Parser/ScaleParser/
)

# Add a shared library target 'system_initPlayer'
add_library(update_position_component SHARED
    UpdatePositionSystem/updatePositionSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Network/Packet/NetworkPacket.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Network/Packet/NetworkPacket.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
)
find_package(asio CONFIG REQUIRED)
target_link_libraries(update_position_component PRIVATE asio::asio JsonCpp::JsonCpp)

add_library(update_shoot_system SHARED
    UpdateShootSystem/updateShootSystem.cpp
    ../Systems/Shoot/ShootSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    ../Systems/Shoot/ShootInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
    ../Components/Velocity/VelocityComponent.cpp
    ../Components/Shoot/ShootComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/SpeedParser/SpeedParser.cpp
    ../Parser/VelocityParser/VelocityParser.cpp
    ../Parser/ShootParser/ShootParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Network/Packet/NetworkPacket.cpp
)
find_package(asio CONFIG REQUIRED)
target_link_libraries(update_shoot_system PRIVATE asio::asio JsonCpp::JsonCpp)
