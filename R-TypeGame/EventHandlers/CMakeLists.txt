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

find_package(asio CONFIG REQUIRED)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/KeyMaps/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/
    ${CMAKE_SOURCE_DIR}/Network/Messages/
    ${CMAKE_SOURCE_DIR}/Network/ABI/
    ${CMAKE_SOURCE_DIR}/Network/Units/
    SwitchScene/
    GetRoomInfos/
    SendRoomInfos/
    ../Systems/Menus/Buttons/
    ../Systems/Menus/Buttons/AButton/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/
)

add_library(eventHandler_switchScene SHARED
    SwitchScene/SwitchSceneHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_connectServer SHARED
    ConnectServer/ConnectServerHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_login SHARED
    Login/LoginHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_loginAllowed SHARED
    LoginAllowed/LoginAllowedHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_createShoot SHARED
    CreateShoot/CreateShootHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_shootMob SHARED
    ShootMob/ShootMobHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_register SHARED
    Register/RegisterHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_createRoom SHARED
    CreateRoom/CreateRoomHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_PlaySounds SHARED
        PlaySounds/PlaySoundsHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(eventHandler_PlaySounds PRIVATE asio::asio)

add_library(eventHandler_joinRoom SHARED
    JoinRoom/JoinRoomHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

add_library(eventHandler_logout SHARED
    Logout/LogoutHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_switchScene PRIVATE asio::asio)
target_link_libraries(eventHandler_connectServer PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_login PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_loginAllowed PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_createShoot PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_shootMob PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_register PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_createRoom PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_joinRoom PRIVATE r-type_abi_network asio::asio)
target_link_libraries(eventHandler_logout PRIVATE r-type_abi_network asio::asio)

add_library(eventHandler_getRoomInfos SHARED
    GetRoomInfos/GetRoomInfosHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_getRoomInfos PRIVATE r-type_abi_network asio::asio)

add_library(eventHandler_sendRoomInfos SHARED
        SendRoomInfos/SendRoomInfosHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ../Systems/Menus/Buttons/RoomInfosTextBox/RoomInfoTextBoxInitSystem.cpp
        ../Systems/Menus/Buttons/JoinRoomButton/JoinRoomButtonInitSystem.cpp
        ../Systems/Menus/Buttons/JoinRoomPasswordTextBox/JoinRoomPasswordTextBoxInitSystem.cpp
        ../Systems/Menus/Buttons/AButton/AButtonInitSystem.cpp
)

target_link_libraries(eventHandler_sendRoomInfos PRIVATE
        Position2D
        Text
        EntityList
        ButtonState
        TextPosition2D
        Scale
        Size1D
        Colour
        Draw
        FontPath
        TextureRect
        Clickable
        ButtonTexturePath
        TextLimit
        Editable
        DefaultText
        EntityId
        r-type_abi_network
        asio::asio
)

add_library(eventHandler_singlePlayer SHARED
    SinglePlayer/SinglePlayerHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)
target_link_libraries(eventHandler_singlePlayer PRIVATE
        Player
        Draw
        r-type_abi_network
        asio::asio
)

add_library(eventHandler_playerDeath SHARED
    PlayerDeath/PlayerDeathHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)
target_link_libraries(eventHandler_playerDeath PRIVATE r-type_abi_network asio::asio)
