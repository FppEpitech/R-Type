# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the executable name
set(EXE r-type_server)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/)
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/)
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/)

# Define source and include paths
set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH
    "Include"
    "Src/GameEngine"
    "Src/GameEngine/ServerSceneManager"
)

# Define the main source files for the executable
set(SRC_EXE
    ${EXE_SRC_PATH}/main.cpp
    ${EXE_SRC_PATH}/GameEngine/Application/Application.cpp
    ${EXE_SRC_PATH}/GameEngine/ServerSceneManager/ServerSceneManager.cpp
    ../Shared/SceneManager/ASceneManager.cpp
    ../Shared/Component/DrawComponent.cpp
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
    ../Shared/Component/NetworkConnectionComponent.cpp
    ../Shared/Component/SpriteSheetAnimationComponent.cpp
    ../Shared/Component/Entities/Player/PlayerComponent.cpp
)

# Include directories for header files
include_directories(
    ${EXE_SRC_PATH}/GameEngine/Errors
    ${EXE_SRC_PATH}/GameEngine/Application
    ${EXE_SRC_PATH}/GameEngine/ServerSceneManager
    ../Shared/Ecs/Src
    ../Shared/Interface
    ../Shared/SceneManager
    ../Shared/Component
    ../Shared/Component/Entities
    ../Shared/Component/Entities/Player
    ${EXE_INCLUDE_PATH}

    ${CMAKE_SOURCE_DIR}/Network/Errors
    ${CMAKE_SOURCE_DIR}/Network/ABI
    ${CMAKE_SOURCE_DIR}/Network/Units/Server/
    ${CMAKE_SOURCE_DIR}/Network/Units/
    ${CMAKE_SOURCE_DIR}/Network/Units/ANetworkUnit
    ${CMAKE_SOURCE_DIR}/Network/Messages
    ${CMAKE_SOURCE_DIR}/Network/Messages/UDPPacket
)

# Add subdirectory for network sources

# Add the executable target
add_executable(${EXE} ${SRC_EXE})

# Include directories for the executable target
target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

# Find required packages
find_package(asio REQUIRED)
find_package(jsoncpp REQUIRED)

# Link libraries to the executable target
target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    r-type_ecs
    r-type_abi_network
)
