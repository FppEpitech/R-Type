
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
    ${EXE_SRC_PATH}/GameEngine/Room/Room.cpp
    ${EXE_SRC_PATH}/GameEngine/ServerSceneManager/ServerSceneManager.cpp
    ../Shared/Consumption/ConsumptionCompute.cpp
    ../Shared/SceneManager/ASceneManager.cpp
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
    ../Shared/DefaultComponents/Music/MusicComponent.cpp
    ../Shared/DefaultComponents/Sound/SoundComponent.cpp
    ../Shared/DefaultComponents/NetworkConnection/NetworkConnectionComponent.cpp
    ../Shared/DefaultComponents/SpriteSheetAnimation/SpriteSheetAnimationComponent.cpp
        ../Shared/DefaultComponents/Player/PlayerComponent.cpp
    ../../Network/Database/Database.cpp
    ../../Network/Database/Models/Scores/Scores.cpp
    ../../Network/Database/Models/Users/Users.cpp
    ../Shared/EventListener/EventListener.cpp
    ../Shared/DefaultComponents/Editable/EditableComponent.cpp
    ../Shared/DefaultComponents/Checkable/CheckableComponent.cpp
)

# Include directories for header files
include_directories(
    ${EXE_SRC_PATH}/GameEngine/Errors
    ${EXE_SRC_PATH}/GameEngine/Application
    ${EXE_SRC_PATH}/GameEngine/Room
    ${EXE_SRC_PATH}/GameEngine/ServerSceneManager
    ../Ecs/Src
    ../Shared/Interface
    ../Shared/SceneManager
    ../Shared/Component
    ../Shared
    ../Shared/Consumption/
    ../Shared/DefaultComponents/
    ../Shared/DefaultSystems/
    ../Shared/DefaultComponents/Entities
        ../Shared/DefaultComponents/Player
    ../../Network/Database
    ../../Network/Errors
    ../../Network/Database/Models/Scores
    ../../Network/Database/Models/Users
    ../Shared/DefaultEventHandlers/
    ../Shared/EventListener/
    ${EXE_INCLUDE_PATH}
    ../../R-TypeGame/Components/

    ${CMAKE_SOURCE_DIR}/Network/Errors
    ${CMAKE_SOURCE_DIR}/Network/ABI
    ${CMAKE_SOURCE_DIR}/Network/Units/Server/
    ${CMAKE_SOURCE_DIR}/Network/Units/
    ${CMAKE_SOURCE_DIR}/Network/Units/ANetworkUnit
    ${CMAKE_SOURCE_DIR}/Network/Messages
    ${CMAKE_SOURCE_DIR}/Network/Messages/UDPPacket
)

# Add the executable target
add_executable(${EXE} ${SRC_EXE})

# Include directories for the executable target
target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

# Find required packages
find_package(asio REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(asio CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
find_package(unofficial-sodium CONFIG REQUIRED)


# Link libraries to the executable target
target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    PRIVATE unofficial::sqlite3::sqlite3
    PRIVATE unofficial-sodium::sodium
    r-type_ecs
    r-type_abi_network
)
