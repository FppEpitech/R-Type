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

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

include_directories(
        # Component directories
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/ButtonState/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/ButtonTexturePath/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Checkable/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Clickable/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Colour/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/DefaultText/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Draw/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Editable/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/FontPath/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Gravity/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/MaterialMap/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Music/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/NetworkConnection/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/ObjPath/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Player/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Position2D/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Position3D/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Scale/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Size1D/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Sound/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Speed/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/SpriteSheetAnimation/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Text/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TextLimit/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TextPosition2D/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TexturePath/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TextureRect/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Velocity/
        # Default systems directories
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems
        # Parser directories
        ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
        ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
        ${CMAKE_SOURCE_DIR}/Engine/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/Enum/
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/
        AText/
        # Network directories
        ${CMAKE_SOURCE_DIR}/Network/ABI/
)

find_package(jsoncpp REQUIRED)
find_package(asio CONFIG REQUIRED)

add_library(system_moveRight SHARED Move/MoveSystemRight/MoveSystemRight.cpp)
target_link_libraries(system_moveRight PRIVATE JsonCpp::JsonCpp)
add_library(system_moveLeft SHARED Move/MoveSystemLeft/MoveSystemLeft.cpp)
target_link_libraries(system_moveLeft PRIVATE asio::asio)
add_library(system_moveUp SHARED Move/MoveSystemUp/MoveSystemUp.cpp)
target_link_libraries(system_moveUp PRIVATE asio::asio)
add_library(system_moveDown SHARED Move/MoveSystemDown/MoveSystemDown.cpp)
target_link_libraries(system_moveDown PRIVATE JsonCpp::JsonCpp)
add_library(system_moveEntities SHARED Move/MoveEntities/MoveEntitiesSystem.cpp)

add_library(system_handleMouse SHARED
        ../../Error/AError.cpp
        Mouse/MouseSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_handleMouse PRIVATE
        Position2D
        Scale
        TextureRect
        Clickable
        Editable
        ButtonTexturePath
        JsonCpp::JsonCpp
)

add_library(system_handleTyping SHARED
        ../../Error/AError.cpp
        Typing/TypingSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_handleTyping PRIVATE
        Text
        DefaultText
        Editable
        ButtonState
        ButtonTexturePath
        JsonCpp::JsonCpp
)
