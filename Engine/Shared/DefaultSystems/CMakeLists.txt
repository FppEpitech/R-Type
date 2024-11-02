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
        ${CMAKE_SOURCE_DIR}/Network/
        ${CMAKE_SOURCE_DIR}/Network/ABI/
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src
        ../../Error/
)

find_package(jsoncpp REQUIRED)
find_package(asio CONFIG REQUIRED)

add_library(system_moveEntities SHARED
        MoveEntities/MoveEntitiesSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)
target_link_libraries(system_moveEntities
    PRIVATE JsonCpp::JsonCpp
    r-type_abi_network
)

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

add_library(system_handleGravity SHARED
        ../../Error/AError.cpp
        Gravity/GravitySystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(system_handleGravity PRIVATE
        Position3D
        Gravity
)

find_package(sol2 CONFIG REQUIRED)
find_package(Lua CONFIG REQUIRED)
add_library(system_luaScriptSystem SHARED
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        LuaScript/LuaScriptSystem.cpp
)
target_include_directories(system_luaScriptSystem PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(system_luaScriptSystem PRIVATE
    ${LUA_LIBRARIES}
    sol2
)

add_library(system_InitConsumption SHARED
        DisplayConsumption/InitConsumptionSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(system_InitConsumption PRIVATE
        TextPosition2D
        DefaultText
        Text
        Size1D
        Draw
        FontPath
        Colour
        JsonCpp::JsonCpp
)

add_library(system_DisplayConsumption SHARED
        DisplayConsumption/DisplayConsumptionSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(system_DisplayConsumption PRIVATE
        DefaultText
        Draw
        JsonCpp::JsonCpp
)

add_library(system_UpdateConsumption SHARED
        DisplayConsumption/UpdateConsumptionSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
)

target_link_libraries(system_UpdateConsumption PRIVATE
        JsonCpp::JsonCpp
)

add_library(system_Shader SHARED
        Shaders/ShaderSystem.cpp
        ../../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
)

add_library(system_FullScreen SHARED
        FullScreen/FullScreenSystem.cpp
        ../../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
)

add_library(system_InitShaderInfo SHARED
        DisplayShaderInfo/InitShaderInfoSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(system_InitShaderInfo PRIVATE
        TextPosition2D
        DefaultText
        Text
        Size1D
        Draw
        FontPath
        Colour
        JsonCpp::JsonCpp
)

add_library(system_DisplayShaderInfo SHARED
        DisplayShaderInfo/DisplayShaderInfoSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(system_DisplayShaderInfo PRIVATE
        DefaultText
        Draw
        JsonCpp::JsonCpp
)

add_library(system_UpdateShaderInfo SHARED
        DisplayShaderInfo/UpdateShaderInfoSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
)

target_link_libraries(system_UpdateShaderInfo PRIVATE
        JsonCpp::JsonCpp
)
