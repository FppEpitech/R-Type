cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Engine/Server/Lib/Systems/)

include_directories(
        ../../Engine/Shared/Ecs/Include/
        ../../Engine/Shared/Interface/
        ../../Engine/Shared/Network/Packet/
)

add_library(system_move SHARED MoveSystem.cpp)

find_package(asio REQUIRED)

target_link_libraries(system_move PRIVATE asio::asio)
