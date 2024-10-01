cmake_minimum_required(VERSION 3.5)

set(EXE r-type_client)

set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH "Include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
        Src/main.cpp
        Src/Application/Application.cpp
        Src/ClientSceneManager/ClientSceneManager.cpp
        Src/GraphicalLibrary/GetGraphicalLibrary.cpp
        ../Shared/SceneManager/ASceneManager.cpp
        ../Shared/GraphicalLoad/GraphicalLoad.cpp
        ./Src/Component/FontPathComponent.cpp
        ./Src/Component/ObjPathComponent.cpp
        ./Src/Component/TexturePathComponent.cpp
        ./Src/Component/ScaleComponent.cpp
        ./Src/Component/ColourComponent.cpp
        ./Src/Component/Position3DComponent.cpp
        ./Src/Component/Position2DComponent.cpp
        ./Src/Component/Size1DComponent.cpp
        ./Src/Component/TextComponent.cpp
        ./Src/Component/MaterialMapComponent.cpp
        ./Src/Component/MusicPathComponent.cpp
        ./Src/Component/MusicPitchComponent.cpp
        ./Src/Component/MusicVolumeComponent.cpp
        ./Src/Component/SoundPathComponent.cpp
        ./Src/Component/SoundPitchComponent.cpp
        ./Src/Component/SoundVolumeComponent.cpp
)

include_directories(
        Src/Network
        Src/Application
        Src/ClientSceneManager
        Src/GraphicalLibrary
        Src/Errors
        ../Shared/GraphicalLoad
        Src/Component
        ../Shared/Ecs/Src
        ../Shared/Interface
        ../Shared/SceneManager
        ../Shared/DLLoader
)

add_subdirectory(Src/Network)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(asio REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(raylib REQUIRED)

target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    raylib
    r-type_ecs
    r-type_network_client
)
