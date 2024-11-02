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

# Find the asio package
find_package(asio CONFIG REQUIRED)

# Include directories for header files
include_directories(
        ${CMAKE_SOURCE_DIR}/Engine/Client/Src/ClientSceneManager/
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/KeyMaps/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/SceneManager/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/EventListener/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/PlayMusic/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/
        ${CMAKE_SOURCE_DIR}/Ecs/Src/Events/
)

add_library(eventHandler_DefaultPlayMusic SHARED
        PlayMusic/PlayMusicHandler.cpp
        AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_DefaultPlayMusic PRIVATE asio::asio)

add_library(eventHandler_DefaultPlaySounds SHARED
        PlaySounds/PlaySoundsHandler.cpp
        AEventHandler.cpp
        ../../Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_DefaultPlaySounds PRIVATE asio::asio)

add_library(eventHandler_UpdateConsumptionHandler SHARED
        UpdateConsumption/UpdateConsumptionHandler.cpp
        AEventHandler.cpp
        ../../Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/Consumption/ConsumptionCompute.cpp
)

target_link_libraries(eventHandler_UpdateConsumptionHandler PRIVATE asio::asio
    DefaultText
    Text
)

add_library(eventHandler_ShaderHandler SHARED
        Shaders/ShadersHandler.cpp
        AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(eventHandler_ShaderHandler PRIVATE asio::asio)

add_library(eventHandler_FullScreenHandler SHARED
        FullScreen/FullScreenHandler.cpp
        AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Registry.cpp
)

target_link_libraries(eventHandler_FullScreenHandler PRIVATE asio::asio)

add_library(eventHandler_UpdateShaderInfoHandler SHARED
        UpdateShaderInfo/UpdateShaderInfoHandler.cpp
        AEventHandler.cpp
        ../../Ecs/Src/Events/AEvent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_UpdateShaderInfoHandler PRIVATE asio::asio
        DefaultText
        Text
)

add_library(eventHandler_moveEntity SHARED
        MoveEntity/MoveEntityHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_moveEntity PRIVATE r-type_abi_network asio::asio)
