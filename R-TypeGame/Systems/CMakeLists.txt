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

find_package(jsoncpp REQUIRED)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Colour/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/DefaultText/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Draw/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Entities/Player/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/FontPath/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/MaterialMap/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/MusicPath/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/MusicPitch/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/MusicVolume/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/NetworkConnection
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/ObjPath/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Position2D/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Position3D/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Scale/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Size1D/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/SoundPath/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/SoundPitch/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/SoundVolume/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/SpriteSheetAnimation/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Text/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TextPosition2D/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TexturePath/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/TextureRect/
    ../Components/Speed/
    ../Components/Life/
    ../Components/Shoot/
    ../Components/Planet/
    ../Components/Editable/
    ../Components/ButtonState/
    ../Components/Clickable/
    ../Components/TextLimit/
    ../Components/Velocity/
    ../Components/Editable/
    ../Components/ButtonTexturePath/
    ../Components/ShootType/
    ../Parser/ShootTypeParser/
    ../Components/Velocity/
    ../Components/Mob/
    ../Components/
    ../../Engine/Shared/DefaultParser/ScaleParser/
    ../../Engine/Shared/DefaultParser/Position2DParser/
    ../Parser/LifeParser/
    ../../Engine/Shared/DefaultParser/PlayerParser/
    ../Parser/SpeedParser/
    ../../Engine/Shared/DefaultParser/TextureRectParser/
    ../Parser/VelocityParser/
    ../Parser/ShootParser/
    ../Parser/MobParser/
    ../../Engine/Shared/DefaultParser/SpriteSheetAnimationParser/
    ../../Engine/Shared/DefaultParser/FontPathParser/
    ../../Engine/Shared/DefaultParser/TextParser/
    ../Parser/ButtonStateParser/
    ../../Engine/Shared/DefaultParser/ColourParser/
    ../../Engine/Shared/DefaultParser/Size1DParser/
    ../../Engine/Shared/DefaultParser/TextPosition2DParser/
    ../../Engine/Shared/DefaultParser/DefaultTextParser/
    ../Parser/TextLimitParser/
    ../Parser/ButtonTexturePathParser/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
    Background/
    Shoot/
    ../../Engine/Ecs/Src/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Enum/
    Menus/Buttons/AButton/
    ../Error/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/
    AText/
)

# Compile all component in static lib
function(create_component_lib component_name)
    set(COMPONENT_SRC "${CMAKE_SOURCE_DIR}/R-TypeGame/Components/${component_name}/${component_name}Component.cpp")
    set(COMPONENT_HDR "${CMAKE_SOURCE_DIR}/R-TypeGame/Components/${component_name}/${component_name}Component.hpp")

    set(PARSER_SRC "")
    set(PARSER_HDR "")
    if(EXISTS "${CMAKE_SOURCE_DIR}/R-TypeGame/Parser/${component_name}Parser/${component_name}Parser.cpp")
        set(PARSER_SRC "${CMAKE_SOURCE_DIR}/R-TypeGame/Parser/${component_name}Parser/${component_name}Parser.cpp")
        set(PARSER_HDR "${CMAKE_SOURCE_DIR}/R-TypeGame/Parser/${component_name}Parser/${component_name}Parser.hpp")
    endif()

    add_library(${component_name} STATIC ${COMPONENT_SRC} ${COMPONENT_HDR} ${PARSER_SRC} ${PARSER_HDR})

    if(EXISTS "${CMAKE_SOURCE_DIR}/R-TypeGame/Parser/${component_name}Parser/${component_name}Parser.cpp")
        target_link_libraries(${component_name} PRIVATE JsonCpp::JsonCpp)
    endif()

    target_include_directories(${component_name} PUBLIC
        ${CMAKE_SOURCE_DIR}/R-TypeGame/Components/${component_name}
        ${CMAKE_SOURCE_DIR}/R-TypeGame/Parser/${component_name}Parser
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
    )
endfunction()

set(COMPONENTS
        ButtonState
        ButtonTexturePath
        Clickable
        Drawable
        Editable
        Gravity
        Life
        Mob
        ShootType
        Planet
        Shoot
        Speed
        TextLimit
        Velocity
)

foreach(component ${COMPONENTS})
    create_component_lib(${component})
endforeach()

# Compile all default component in static lib
function(create_default_component_lib component_name)
    set(COMPONENT_SRC "${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/${component_name}/${component_name}Component.cpp")
    set(COMPONENT_HDR "${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/${component_name}/${component_name}Component.hpp")

    set(PARSER_SRC "")
    set(PARSER_HDR "")
    if(EXISTS "${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/${component_name}Parser/${component_name}Parser.cpp")
        set(PARSER_SRC "${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/${component_name}Parser/${component_name}Parser.cpp")
        set(PARSER_HDR "${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/${component_name}Parser/${component_name}Parser.hpp")
    endif()

    add_library(${component_name} STATIC ${COMPONENT_SRC} ${COMPONENT_HDR} ${PARSER_SRC} ${PARSER_HDR})

    if(EXISTS "${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/${component_name}Parser/${component_name}Parser.cpp")
        target_link_libraries(${component_name} PRIVATE JsonCpp::JsonCpp)
    endif()

    target_include_directories(${component_name} PUBLIC
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/${component_name}
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/${component_name}Parser
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
    )
endfunction()

set(COMPONENTS
        Colour
        DefaultText
        Draw
        FontPath
        MaterialMap
        MusicPath
        MusicPitch
        MusicVolume
        NetworkConnection
        ObjPath
        Position2D
        Position3D
        Scale
        Size1D
        SoundPath
        SoundPitch
        SoundVolume
        SpriteSheetAnimation
        Text
        TextPosition2D
        TexturePath
        TextureRect
)

foreach(component ${COMPONENTS})
    create_default_component_lib(${component})
endforeach()

add_library(Player STATIC
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Entities/Player/PlayerComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Entities/Player/PlayerComponent.hpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/PlayerParser/PlayerParser.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/PlayerParser/PlayerParser.hpp
)

target_include_directories(Player PUBLIC
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Entities/Player/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultParser/PlayerParser/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
)

target_link_libraries(Player PRIVATE JsonCpp::JsonCpp)

# system_initPlayerOne
add_library(system_initPlayerOne SHARED
        ../Error/AError.cpp
        Players/PlayerInitOneSystem.cpp
)

target_link_libraries(system_initPlayerOne
        Position2D
        Scale
        TextureRect
        SpriteSheetAnimation
        Player
        Draw
        Life
        Speed
        Shoot
        JsonCpp::JsonCpp
)

# system_initPlayerTwo
add_library(system_initPlayerTwo SHARED
        ../Error/AError.cpp
        Players/PlayerInitTwoSystem.cpp
)

target_link_libraries(system_initPlayerTwo
        Position2D
        Scale
        TextureRect
        Player
        Draw
        Life
        Speed
        JsonCpp::JsonCpp
)

# system_initPlayerThree
add_library(system_initPlayerThree SHARED
        Players/PlayerInitThreeSystem.cpp
        ../Error/AError.cpp
)

target_link_libraries(system_initPlayerThree
        Position2D
        Scale
        TextureRect
        Player
        Draw
        Life
        Speed
        JsonCpp::JsonCpp
)

# system_initPlayerFour
add_library(system_initPlayerFour SHARED
        Players/PlayerInitFourSystem.cpp
        ../Error/AError.cpp
)

target_link_libraries(system_initPlayerFour
        Position2D
        Scale
        TextureRect
        Player
        Draw
        Life
        Speed
        JsonCpp::JsonCpp
)

add_library(system_moveMobs SHARED MoveSystem/MoveMobs/MoveMobsSystem.cpp)

# system_initConnectButton
add_library(system_initConnectButton SHARED
        ../Error/AError.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/ConnectButton/ConnectButtonInitSystem.cpp
)

target_link_libraries(system_initConnectButton
        Position2D
        Scale
        TextureRect
        Text
        FontPath
        Colour
        Size1D
        TextPosition2D
        DefaultText
        NetworkConnection
        Draw
        ButtonState
        Clickable
        ButtonTexturePath
        JsonCpp::JsonCpp
)

add_library(system_moveRight SHARED Move/MoveSystemRight/MoveSystemRight.cpp)
target_link_libraries(system_moveRight PRIVATE JsonCpp::JsonCpp)
add_library(system_moveLeft SHARED Move/MoveSystemLeft/MoveSystemLeft.cpp)
add_library(system_moveUp SHARED Move/MoveSystemUp/MoveSystemUp.cpp)
add_library(system_moveDown SHARED Move/MoveSystemDown/MoveSystemDown.cpp)
target_link_libraries(system_moveDown PRIVATE JsonCpp::JsonCpp)
add_library(system_moveEntities SHARED Move/MoveEntities/MoveEntitiesSystem.cpp)

add_library(system_shoot SHARED
    ../Error/AError.cpp
    Shoot/ShootSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Shoot/ShootInitSystem.cpp
)

target_link_libraries(system_shoot PRIVATE
        Position2D
        Scale
        TextureRect
        Draw
        Speed
        Velocity
        Shoot
        JsonCpp::JsonCpp
)

add_library(system_shootDestroy SHARED
    ../Error/AError.cpp
    Shoot/ShootDestroySystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)
add_library(system_initBackground SHARED
    ../Error/AError.cpp
    Background/BackgroundInitSystem.cpp
)

target_link_libraries(system_initBackground PRIVATE
    Position2D
    Scale
    TextureRect
    SpriteSheetAnimation
    Draw
    JsonCpp::JsonCpp
)

add_library(system_initPlanet SHARED
    ../Error/AError.cpp
    Background/PlanetInitSystem.cpp
)

target_link_libraries(system_initPlanet PRIVATE
    Planet
    Position2D
    Scale
    TextureRect
    Draw
    Velocity
    JsonCpp::JsonCpp
)

add_library(system_restartPlanet SHARED
    Background/PlanetRestartSystem.cpp
    Background/UpdatePlanet.cpp
)

add_library(system_initMob SHARED
    ../Error/AError.cpp
    Mob/MobInitSystem.cpp
)

target_link_libraries(system_initMob PRIVATE
    Position2D
    Scale
    TextureRect
    SpriteSheetAnimation
    Draw
    Velocity
    ShootType
    Mob
    Life
    JsonCpp::JsonCpp
)

add_library(system_initMobSpeOne SHARED
    ../Error/AError.cpp
    Mob/MobSpeOneInitSystem.cpp
)

target_link_libraries(system_initMobSpeOne PRIVATE
    Position2D
    Scale
    TextureRect
    SpriteSheetAnimation
    Draw
    Velocity
    ShootType
    Mob
    Life
    JsonCpp::JsonCpp
)

add_library(system_initMobSpeTwo SHARED
    ../Error/AError.cpp
    Mob/MobSpeTwoInitSystem.cpp
)

target_link_libraries(system_initMobSpeTwo PRIVATE
    Position2D
    Scale
    TextureRect
    SpriteSheetAnimation
    Draw
    Velocity
    ShootType
    Mob
    Life
    JsonCpp::JsonCpp
)

add_library(system_shoot_mob SHARED
    ../Error/AError.cpp
    ShootMob/ShootSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    ShootMob/ShootInitSystem.cpp
    ShootMob/MobSpeOneShootInitSystem.cpp
    ShootMob/MobSpeTwoShootInitSystem.cpp
)

target_link_libraries(system_shoot_mob PRIVATE
    Position2D
    Scale
    TextureRect
    Draw
    Speed
    Velocity
    Shoot
    SpriteSheetAnimation
    ShootType
    Colour
    JsonCpp::JsonCpp
)

add_library(system_hitboxPlayer SHARED
    Hitbox/HitboxPlayerSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Background/UpdatePlanet.cpp
    ../Error/AError.cpp
)

add_library(system_initIpTextButton SHARED
    ../Error/AError.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Menus/Buttons/AButton/AButtonInitSystem.cpp
    Menus/Buttons/IpTextBox/IpTextBoxInitSystem.cpp
)

target_link_libraries(system_initIpTextButton PRIVATE
    Position2D
    Scale
    TextureRect
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    DefaultText
    Draw
    ButtonState
    Clickable
    Editable
    TextLimit
    ButtonTexturePath
    JsonCpp::JsonCpp
)

add_library(system_initPortTextButton SHARED
    ../Error/AError.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Menus/Buttons/AButton/AButtonInitSystem.cpp
    Menus/Buttons/PortTextBox/PortTextBoxInitSystem.cpp
)

target_link_libraries(system_initPortTextButton PRIVATE
    Position2D
    Scale
    TextureRect
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    DefaultText
    Draw
    ButtonState
    Clickable
    Editable
    TextLimit
    ButtonTexturePath
    JsonCpp::JsonCpp
)

add_library(system_handleMouse SHARED
    ../Error/AError.cpp
    Mouse/MouseSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_handleMouse PRIVATE
    Position2D
    Scale
    TextureRect
    Clickable
    JsonCpp::JsonCpp
)

add_library(system_handleTyping SHARED
    ../Error/AError.cpp
    Typing/TypingSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_handleTyping PRIVATE
    Text
    DefaultText
    Editable
    ButtonState
    JsonCpp::JsonCpp
)

add_library(system_shootDamage SHARED
    ../Error/AError.cpp
    Shoot/ShootDamageSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(system_shootDamage PRIVATE
    Position2D
    Scale
    TextureRect
    Shoot
    Life
    Mob
    JsonCpp::JsonCpp
)

add_library(system_initEndLogo SHARED
    ../Error/AError.cpp
    Background/EndLogoInitSystem.cpp
)

target_link_libraries(system_initEndLogo PRIVATE
    Position2D
    Scale
    TextureRect
    Draw
    JsonCpp::JsonCpp
)

add_library(system_initExitButton SHARED
    ../Error/AError.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Menus/Buttons/AButton/AButtonInitSystem.cpp
    Menus/Buttons/ExitButton/ExitButtonInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_initExitButton PRIVATE
    Position2D
    Scale
    TextureRect
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    ButtonState
    Clickable
    ButtonTexturePath
    JsonCpp::JsonCpp
)

add_library(system_initSingleplayerButton SHARED
    ../Error/AError.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Menus/Buttons/AButton/AButtonInitSystem.cpp
    Menus/Buttons/SingleplayerButton/SingleplayerButtonInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_initSingleplayerButton PRIVATE
    Position2D
    Scale
    TextureRect
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    ButtonState
    Clickable
    ButtonTexturePath
    JsonCpp::JsonCpp
)

add_library(system_initMultiplayerButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/MultiplayerButton/MultiplayerButtonInitSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_initMultiplayerButton PRIVATE
    Position2D
    Scale
    TextureRect
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    ButtonState
    Clickable
    ButtonTexturePath
    JsonCpp::JsonCpp
)

add_library(system_initMapEditorButton SHARED
    ../Error/AError.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    Menus/Buttons/AButton/AButtonInitSystem.cpp
    Menus/Buttons/MapEditorButton/MapEditorButtonInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

target_link_libraries(system_initMapEditorButton PRIVATE
    Position2D
    Scale
    TextureRect
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    ButtonState
    Clickable
    ButtonTexturePath
    JsonCpp::JsonCpp
)

add_library(system_initServerConnectionText SHARED
    ../Error/AError.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
    AText/ATextInitSystem.cpp
    Menus/Texts/ServerConnection/ServerConnectionTextInitSystem.cpp
)

target_link_libraries(system_initServerConnectionText PRIVATE
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    JsonCpp::JsonCpp
)
