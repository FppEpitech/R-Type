# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the executable name
set(EXE r-type_client)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game)
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game)
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game)

# Define source and include paths
set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH "Include")

# Define component source files
set(COMPONENT_SRC_FILE
    ../Shared/Component/FontPathComponent.cpp
    ../Shared/Component/ObjPathComponent.cpp
    ../Shared/Component/TexturePathComponent.cpp
    ../Shared/Component/TextureRectComponent.cpp
    ../Shared/Component/ScaleComponent.cpp
    ../Shared/Component/ColourComponent.cpp
    ../Shared/Component/Position3DComponent.cpp
    ../Shared/Component/Position2DComponent.cpp
    ../Shared/Component/TextPosition2DComponent.cpp
    ../Shared/Component/Size1DComponent.cpp
    ../Shared/Component/TextComponent.cpp
    ../Shared/Component/MaterialMapComponent.cpp
    ../Shared/Component/MusicPathComponent.cpp
    ../Shared/Component/MusicPitchComponent.cpp
    ../Shared/Component/MusicVolumeComponent.cpp
    ../Shared/Component/SoundPathComponent.cpp
    ../Shared/Component/SoundPitchComponent.cpp
    ../Shared/Component/SoundVolumeComponent.cpp
    ../Shared/Component/SpriteSheetAnimationComponent.cpp
    ../Shared/Component/Entities/Player/PlayerComponent.cpp
)

# Define system source files
set(SYSTEM_SRC_FILE
    ${EXE_SRC_PATH}/Systems/DrawOBJ/DrawOBJSystem.cpp
    ${EXE_SRC_PATH}/Systems/DrawTexture/DrawTextureSystem.cpp
    ${EXE_SRC_PATH}/Systems/DrawText/DrawTextSystem.cpp
    ${EXE_SRC_PATH}/Systems/DrawTextureRect/DrawTextureRectSystem.cpp
    ${EXE_SRC_PATH}/Systems/SpriteSheetAnimation/SpriteSheetAnimationSystem.cpp
)

# Define the main source files for the executable
set(SRC_EXE
    ${EXE_SRC_PATH}/main.cpp
    ${EXE_SRC_PATH}/Application/Application.cpp
    ${EXE_SRC_PATH}/ClientSceneManager/ClientSceneManager.cpp
    ${EXE_SRC_PATH}/GetGraphicalLibrary/GetGraphicalLibrary.cpp
    ../Shared/SceneManager/ASceneManager.cpp
    ${COMPONENT_SRC_FILE}
    ${SYSTEM_SRC_FILE}
    ${EXE_SRC_PATH}/InitShader/InitShader.cpp
)

# Include directories for header files
include_directories(
    ${EXE_SRC_PATH}/Network
    ${EXE_SRC_PATH}/Application
    ${EXE_SRC_PATH}/ClientSceneManager
    ${EXE_SRC_PATH}/GetGraphicalLibrary
    ${EXE_SRC_PATH}/Errors
    ${EXE_SRC_PATH}/Systems
    ../Shared/GraphicalLoad
    ../Shared/Component
    ../Shared/Component/Entities
    ../Shared/Component/Entities/Player
    ../Shared/Ecs/Src
    ../Shared/Interface
    ../Shared/SceneManager
    ../Shared/DLLoader
    ${EXE_SRC_PATH}/InitShader/
    ${EXE_INCLUDE_PATH}/Components/ShaderComponent
)

# Add subdirectory for network sources
add_subdirectory(${EXE_SRC_PATH}/Network)

# Add the executable target
add_executable(${EXE} ${SRC_EXE})

# Include directories for the executable target
target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

# Find required packages
find_package(asio REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(raylib REQUIRED)

# Link libraries to the executable target
target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    raylib
    r-type_ecs
    r-type_network_client
)
