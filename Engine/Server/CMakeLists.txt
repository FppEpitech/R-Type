cmake_minimum_required(VERSION 3.5)

set(EXE r-type_server)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Game)

set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH
    "Include"
    "Src/GameEngine"
    "Src/Network"
    "Src/GameEngine/ServerSceneManager"
)

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
    ./${EXE_SRC_PATH}/main.cpp
    ./${EXE_SRC_PATH}/GameEngine/Application/Application.cpp
    ./${EXE_SRC_PATH}/GameEngine/ServerSceneManager/ServerSceneManager.cpp
    ../Shared/SceneManager/ASceneManager.cpp
    ../Shared/Component/FontPathComponent.cpp
    ../Shared/Component/ObjPathComponent.cpp
    ../Shared/Component/TexturePathComponent.cpp
    ../Shared/Component/ScaleComponent.cpp
    ../Shared/Component/ColourComponent.cpp
    ../Shared/Component/Position3DComponent.cpp
    ../Shared/Component/Position2DComponent.cpp
    ../Shared/Component/Size1DComponent.cpp
    ../Shared/Component/TextComponent.cpp
    ../Shared/Component/MaterialMapComponent.cpp
    ../Shared/Component/MusicPathComponent.cpp
    ../Shared/Component/MusicPitchComponent.cpp
    ../Shared/Component/MusicVolumeComponent.cpp
    ../Shared/Component/SoundPathComponent.cpp
    ../Shared/Component/SoundPitchComponent.cpp
    ../Shared/Component/SoundVolumeComponent.cpp
)

include_directories(
        src/Network
        src/GameEngine/Errors
        src/GameEngine/Application
        src/GameEngine/ServerSceneManager
        ../Shared/Ecs/Src
        ../Shared/Interface
        ../Shared/SceneManager
        ../Shared/Network/Packet
        ../Shared/Component
)

add_subdirectory(Src/Network)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(asio REQUIRED)
find_package(jsoncpp REQUIRED)

target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    r-type_ecs
    r-type_network_server
)

add_custom_command(TARGET ${EXE} POST_BUILD
        COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/Game/GameData
        COMMAND cp -r ${CMAKE_SOURCE_DIR}/Engine/Server/Config/* ${CMAKE_SOURCE_DIR}/Game/GameData
        COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/Game/Mods
)
