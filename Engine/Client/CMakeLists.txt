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
    ../Shared/DefaultComponents/Draw/DrawComponent.cpp
    ../Shared/DefaultComponents/FontPath/FontPathComponent.cpp
    ../Shared/DefaultComponents/ObjPath/ObjPathComponent.cpp
    ../Shared/DefaultComponents/TexturePath/TexturePathComponent.cpp
    ../Shared/DefaultComponents/TextureRect/TextureRectComponent.cpp
    ../Shared/DefaultComponents/Scale/ScaleComponent.cpp
    ../Shared/DefaultComponents/Colour/ColourComponent.cpp
    ../Shared/DefaultComponents/Position3D/Position3DComponent.cpp
    ../Shared/DefaultComponents/Position2D/Position2DComponent.cpp
    ../Shared/DefaultComponents/TextPosition2D/TextPosition2DComponent.cpp
    ../Shared/DefaultComponents/Size1D/Size1DComponent.cpp
    ../Shared/DefaultComponents/Text/TextComponent.cpp
    ../Shared/DefaultComponents/MaterialMap/MaterialMapComponent.cpp
    ../Shared/DefaultComponents/MusicPath/MusicPathComponent.cpp
    ../Shared/DefaultComponents/MusicPitch/MusicPitchComponent.cpp
    ../Shared/DefaultComponents/MusicVolume/MusicVolumeComponent.cpp
    ../Shared/DefaultComponents/SoundPath/SoundPathComponent.cpp
    ../Shared/DefaultComponents/SoundPitch/SoundPitchComponent.cpp
    ../Shared/DefaultComponents/SoundVolume/SoundVolumeComponent.cpp
    ../Shared/DefaultComponents/NetworkConnection/NetworkConnectionComponent.cpp
    ../Shared/DefaultComponents/SpriteSheetAnimation/SpriteSheetAnimationComponent.cpp
    ../Shared/DefaultComponents/Entities/Player/PlayerComponent.cpp
        ../Shared/DefaultComponents/Editable/EditableComponent.cpp
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
    ${EXE_SRC_PATH}/InitWindow/InitWindow.cpp
    ../Error/AError.cpp
    ../Shared/Consumption/ConsumptionCompute.cpp
    ../Shared/EventListener/EventListener.cpp
)

# Include directories for header files
include_directories(
    # ${EXE_SRC_PATH}/Network
    ${EXE_SRC_PATH}/Application
    ${EXE_SRC_PATH}/ClientSceneManager
    ${EXE_SRC_PATH}/GetGraphicalLibrary
    ${EXE_SRC_PATH}/Errors
    ${EXE_SRC_PATH}/Systems
    ../Shared/GraphicalLoad
    ../Shared/Component
    ../Shared/DefaultComponents/Entities
    ../Shared/DefaultComponents/Entities/Player
    ../Ecs/Src
    ../Shared/Interface
    ../Shared
    ../Shared/DefaultComponents/
    ../Shared/DefaultSystems/
    ../Shared/SceneManager
    ../Shared/DLLoader
    ../Shared/Consumption/
    ${EXE_SRC_PATH}/InitShader/
    ${EXE_SRC_PATH}/InitWindow/
    ${EXE_INCLUDE_PATH}/Components/ShaderComponent
    ../Shared/EventListener/
    ../Shared/DefaultEventHandlers/
    ../../R-TypeGame/Components/

    ${CMAKE_SOURCE_DIR}/Network/Errors
    ${CMAKE_SOURCE_DIR}/Network/ABI
    ${CMAKE_SOURCE_DIR}/Network/Units/Client/
    ${CMAKE_SOURCE_DIR}/Network/Units/
    ${CMAKE_SOURCE_DIR}/Network/Units/ANetworkUnit
    ${CMAKE_SOURCE_DIR}/Network/Messages
)

# Add subdirectory for network sources
# add_subdirectory(${EXE_SRC_PATH}/Network)

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
    # r-type_network_client
    r-type_abi_network
)
