cmake_minimum_required(VERSION 3.5)

set(EXE r-type_client)

set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH "Include")

set(COMPONENT_SRC_FILE  ./Src/Components/ShaderComponent/ShaderPathComponent.cpp
                        ./Src/Components/Size1DComponent/Size1DComponent.cpp
                        ./Src/Components/TextComponent/TextComponent.cpp
                        ./Src/Components/MaterialMapComponent/MaterialMapComponent.cpp
                        ./Src/Components/MusicPathComponent/MusicPathComponent.cpp
                        ./Src/Components/MusicPitchComponent/MusicPitchComponent.cpp
                        ./Src/Components/MusicVolumeComponent/MusicVolumeComponent.cpp
                        ./Src/Components/SoundPathComponent/SoundPathComponent.cpp
                        ./Src/Components/SoundPitchComponent/SoundPitchComponent.cpp
                        ./Src/Components/SoundVolumeComponent/SoundVolumeComponent.cpp
                        ./Src/Components/FontPathComponent/FontPathComponent.cpp
                        ./Src/Components/ObjPathComponent/ObjPathComponent.cpp
                        ./Src/Components/TexturePathComponent/TexturePathComponent.cpp
                        ./Src/Components/ScaleComponent/ScaleComponent.cpp
                        ./Src/Components/ColourComponent/ColourComponent.cpp
)

set(COMPONENT_INCLUDE_DIR   ./Src/Components/ShaderComponent
                            ./Src/Components/Size1DComponent/
                            ./Src/Components/TextComponent/
                            ./Src/Components/MaterialMapComponent/
                            ./Src/Components/MusicPathComponent/
                            ./Src/Components/MusicPitchComponent/
                            ./Src/Components/MusicVolumeComponent/
                            ./Src/Components/SoundPathComponent/
                            ./Src/Components/SoundPitchComponent/
                            ./Src/Components/SoundVolumeComponent/
                            ./Src/Components/FontPathComponent/
                            ./Src/Components/ObjPathComponent/
                            ./Src/Components/TexturePathComponent/
                            ./Src/Components/ScaleComponent/
                            ./Src/Components/ColourComponent/
)

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
        Src/main.cpp
        Src/Application/Application.cpp
        Src/ClientSceneManager/ClientSceneManager.cpp
        Src/GraphicalLibrary/GetGraphicalLibrary.cpp
        ../Shared/SceneManager/ASceneManager.cpp
        ../Shared/Component/Position3DComponent.cpp
        ../Shared/Component/Position2DComponent.cpp
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
