cmake_minimum_required(VERSION 3.5)

set(EXE r-type_client)

set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH "Include")

set(COMPONENT_SRC_FILE ./Src/Components/ShaderComponent/ShaderPathComponent.cpp)

set(COMPONENT_INCLUDE_DIR ./Include/Components/ShaderComponent)

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
        Src/main.cpp
        Src/Application/Application.cpp
        Src/ClientSceneManager/ClientSceneManager.cpp
        Src/GraphicalLibrary/GetGraphicalLibrary.cpp
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
        ${COMPONENT_SRC_FILE}
)

include_directories(
        Src/Network
        Src/Application
        Src/ClientSceneManager
        Src/GraphicalLibrary
        Src/Errors
        ../Shared/GraphicalLoad
        ../Shared/Component
        ../Shared/Ecs/Src
        ../Shared/Interface
        ../Shared/SceneManager
        ../Shared/DLLoader
        ${COMPONENT_INCLUDE_DIR}
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
