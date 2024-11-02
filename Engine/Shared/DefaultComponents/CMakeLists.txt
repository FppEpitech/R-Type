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

include_directories(
        # Component directories
        ./
        ./ButtonState/
        ./ButtonTexturePath/
        ./Checkable/
        ./Clickable/
        ./Colour/
        ./DefaultText/
        ./Draw/
        ./Editable/
        ./FontPath/
        ./Gravity/
        ./MaterialMap/
        ./Music/
        ./NetworkConnection/
        ./ObjPath/
        ./Player/
        ./Position2D/
        ./Position3D/
        ./Scale/
        ./Size1D/
        ./Sound/
        ./Speed/
        ./Speed3D/
        ./SpriteSheetAnimation/
        ./Text/
        ./TextLimit/
        ./TextPosition2D/
        ./TexturePath/
        ./TextureRect/
        ./Velocity/
        ./Velocity3D/
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
)

function(create_default_component_lib component_name)
    set(COMPONENT_SRC "${component_name}/${component_name}Component.cpp")
    set(COMPONENT_HDR "${component_name}/${component_name}Component.hpp")

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
        ButtonState
        ButtonTexturePath
        Checkable
        Clickable
        DefaultText
        Draw
        Editable
        EntityId
        FontPath
        Gravity
        MaterialMap
        Music
        NetworkConnection
        ObjPath
        Player
        Position2D
        Position3D
        Scale
        Size1D
        Sound
        Speed
        Speed3D
        SpriteSheetAnimation
        Text
        TextLimit
        TextPosition2D
        TexturePath
        TextureRect
        Velocity
        Velocity3D
)

foreach(component ${COMPONENTS})
    create_default_component_lib(${component})
endforeach()

target_link_libraries(Player PRIVATE JsonCpp::JsonCpp)

add_library(Colour STATIC
    ../../Error/AError.cpp
    Colour/ColourComponent.cpp
    ../DefaultParser/ColourParser/ColourParser.cpp
)
target_link_libraries(Colour PRIVATE JsonCpp::JsonCpp)
