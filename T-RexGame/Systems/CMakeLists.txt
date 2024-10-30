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
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Editable/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/Checkable/
    ../../Engine/Shared/DefaultParser/ScaleParser/
    ../../Engine/Shared/DefaultParser/Position2DParser/
    ../../Engine/Shared/DefaultParser/PlayerParser/
    ../../Engine/Shared/DefaultParser/TextureRectParser/
    ../../Engine/Shared/DefaultParser/SpriteSheetAnimationParser/
    ../../Engine/Shared/DefaultParser/FontPathParser/
    ../../Engine/Shared/DefaultParser/TextParser/
    ../../Engine/Shared/DefaultParser/ColourParser/
    ../../Engine/Shared/DefaultParser/Size1DParser/
    ../../Engine/Shared/DefaultParser/TextPosition2DParser/
    ../../Engine/Shared/DefaultParser/DefaultTextParser/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Enum/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/
    ../Components/
    ../Components/Clickable/
    ../Components/ButtonState/
    ../Components/TextLimit/
    ../Components/ButtonTexturePath/
    ../Parser/ButtonStateParser/
    ../Parser/TextLimitParser/
    ../Parser/ButtonTexturePathParser/

    Menus/Buttons/AButton/
    Background/
    AText/
)

# Compile all component in static lib
function(create_component_lib component_name)
    set(COMPONENT_SRC "${CMAKE_SOURCE_DIR}/T-RexGame/Components/${component_name}/${component_name}Component.cpp")
    set(COMPONENT_HDR "${CMAKE_SOURCE_DIR}/T-RexGame/Components/${component_name}/${component_name}Component.hpp")

    set(PARSER_SRC "")
    set(PARSER_HDR "")
    if(EXISTS "${CMAKE_SOURCE_DIR}/T-RexGame/Parser/${component_name}Parser/${component_name}Parser.cpp")
        set(PARSER_SRC "${CMAKE_SOURCE_DIR}/T-RexGame/Parser/${component_name}Parser/${component_name}Parser.cpp")
        set(PARSER_HDR "${CMAKE_SOURCE_DIR}/T-RexGame/Parser/${component_name}Parser/${component_name}Parser.hpp")
    endif()

    add_library(${component_name} STATIC ${COMPONENT_SRC} ${COMPONENT_HDR} ${PARSER_SRC} ${PARSER_HDR})

    if(EXISTS "${CMAKE_SOURCE_DIR}/T-RexGame/Parser/${component_name}Parser/${component_name}Parser.cpp")
        target_link_libraries(${component_name} PRIVATE JsonCpp::JsonCpp)
    endif()

    target_include_directories(${component_name} PUBLIC
        ${CMAKE_SOURCE_DIR}/T-RexGame/Components/${component_name}
        ${CMAKE_SOURCE_DIR}/T-RexGame/Parser/${component_name}Parser
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultComponents/
    )
endfunction()

set(COMPONENTS
        ButtonState
        ButtonTexturePath
        Clickable
        # Drawable
        # Gravity
        # Life
        # Mob
        # ShootType
        # Planet
        # Shoot
        # Speed
        TextLimit
        # Velocity
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
        Editable
        Checkable
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


######## Menus ##########

add_library(system_initConnectButton SHARED
        ../Error/AError.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/ConnectButton/ConnectButtonInitSystem.cpp
    ../Error/AError.cpp
    Menus/Buttons/AButton/AButtonInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
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
    Editable
    ButtonTexturePath
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
    ButtonTexturePath
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

add_library(system_initRegisterPageButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/RegisterPageButton/RegisterPageButtonInitSystem.cpp
)
target_link_libraries(system_initRegisterPageButton PRIVATE
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

add_library(system_initLoginPageButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/LoginPageButton/LoginPageButtonInitSystem.cpp
)
target_link_libraries(system_initLoginPageButton PRIVATE
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

add_library(system_initAccountManagementText SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        AText/ATextInitSystem.cpp
        Menus/Texts/AccountManagement/AccountManagementTextInitSystem.cpp
)
target_link_libraries(system_initAccountManagementText PRIVATE
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    JsonCpp::JsonCpp
)

add_library(system_initUsernameTextButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/UsernameTextBox/UsernameTextBoxInitSystem.cpp
)

target_link_libraries(system_initUsernameTextButton PRIVATE
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

add_library(system_initPasswordTextButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/PasswordTextBox/PasswordTextBoxInitSystem.cpp
)
target_link_libraries(system_initPasswordTextButton PRIVATE
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

add_library(system_initRegisterText SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        AText/ATextInitSystem.cpp
        Menus/Texts/Register/RegisterTextInitSystem.cpp
)
target_link_libraries(system_initRegisterText PRIVATE
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    JsonCpp::JsonCpp
)

add_library(system_initLoginText SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        AText/ATextInitSystem.cpp
        Menus/Texts/Login/LoginTextInitSystem.cpp
)
target_link_libraries(system_initLoginText PRIVATE
    Text
    FontPath
    Colour
    Size1D
    TextPosition2D
    Draw
    JsonCpp::JsonCpp
)

add_library(system_initRegisterButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/RegisterButton/RegisterButtonInitSystem.cpp
)
target_link_libraries(system_initRegisterButton PRIVATE
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

add_library(system_initLoginButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/LoginButton/LoginButtonInitSystem.cpp
)
target_link_libraries(system_initLoginButton PRIVATE
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

add_library(system_initRoomManagementText SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        AText/ATextInitSystem.cpp
        Menus/Texts/RoomManagement/RoomManagementTextInitSystem.cpp
)
target_link_libraries(system_initRoomManagementText PRIVATE
        Text
        FontPath
        Colour
        Size1D
        TextPosition2D
        Draw
        JsonCpp::JsonCpp
)

add_library(system_initCreateRoomPageButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/CreateRoomPageButton/CreateRoomPageButtonInitSystem.cpp
)
target_link_libraries(system_initCreateRoomPageButton PRIVATE
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

add_library(system_initJoinRoomPageButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/JoinRoomPageButton/JoinRoomPageButtonInitSystem.cpp
)
target_link_libraries(system_initJoinRoomPageButton PRIVATE
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

add_library(system_initRoomCreationText SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        AText/ATextInitSystem.cpp
        Menus/Texts/RoomCreation/RoomCreationTextInitSystem.cpp
)
target_link_libraries(system_initRoomCreationText PRIVATE
        Text
        FontPath
        Colour
        Size1D
        TextPosition2D
        Draw
        JsonCpp::JsonCpp
)

add_library(system_initRoomNameTextBox SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/RoomNameTextBox/RoomNameTextBoxInitSystem.cpp
)
target_link_libraries(system_initRoomNameTextBox PRIVATE
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

add_library(system_initRoomPasswordTextBox SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/RoomPasswordTextBox/RoomPasswordTextBoxInitSystem.cpp
)
target_link_libraries(system_initRoomPasswordTextBox PRIVATE
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

add_library(system_initRoomPlayerNumberTextBox SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/RoomPlayerNumberTextBox/RoomPlayerNumberTextBoxInitSystem.cpp
)
target_link_libraries(system_initRoomPlayerNumberTextBox PRIVATE
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

add_library(system_initCreateRoomButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/CreateRoomButton/CreateRoomButtonInitSystem.cpp
)
target_link_libraries(system_initCreateRoomButton PRIVATE
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

add_library(system_initIsRoomPrivateButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/IsRoomPrivateButton/IsRoomPrivateButtonInitSystem.cpp
)
target_link_libraries(system_initIsRoomPrivateButton PRIVATE
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
        Checkable
        JsonCpp::JsonCpp
)

add_library(system_initAreCheatsOnButton SHARED
        ../Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
        Menus/Buttons/AButton/AButtonInitSystem.cpp
        Menus/Buttons/AreCheatsOnButton/AreCheatsOnButtonInitSystem.cpp
)
target_link_libraries(system_initAreCheatsOnButton PRIVATE
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
        Checkable
        JsonCpp::JsonCpp
)
#########################








add_library(system_initBackground SHARED
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
