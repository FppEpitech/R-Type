cmake_minimum_required(VERSION 3.5)

set(EXE r-type_server)

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
        ../Client/Src/Components/FontPathComponent/FontPathComponent.cpp
        ../Client/Src/Components/ObjPathComponent/ObjPathComponent.cpp
        ../Client/Src/Components/TexturePathComponent/TexturePathComponent.cpp
        ../Client/Src/Components/ScaleComponent/ScaleComponent.cpp
        ../Client/Src/Components/ColourComponent/ColourComponent.cpp
    ../Shared/Component/Position3DComponent.cpp
    ../Shared/Component/Position2DComponent.cpp
        ../Client/Src/Components/Size1DComponent/Size1DComponent.cpp
        ../Client/Src/Components/TextComponent/TextComponent.cpp
        ../Client/Src/Components/MaterialMapComponent/MaterialMapComponent.cpp
        ../Client/Src/Components/MusicPathComponent/MusicPathComponent.cpp
        ../Client/Src/Components/MusicPitchComponent/MusicPitchComponent.cpp
        ../Client/Src/Components/MusicVolumeComponent/MusicVolumeComponent.cpp
        ../Client/Src/Components/SoundPathComponent/SoundPathComponent.cpp
        ../Client/Src/Components/SoundPitchComponent/SoundPitchComponent.cpp
        ../Client/Src/Components/SoundVolumeComponent/SoundVolumeComponent.cpp
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
