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
        ${CMAKE_SOURCE_DIR}/Engine/Ecs/Src/Events/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/KeyMaps/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultSystems/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/DefaultEventHandlers/PlayMusic/
        ${CMAKE_SOURCE_DIR}/Engine/Shared/
)

add_library(eventHandler_PlayMusic SHARED
        PlayMusic/PlayMusicHandler.cpp
        AEventHandler.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Error/AError.cpp
)

target_link_libraries(eventHandler_PlayMusic PRIVATE asio::asio)
