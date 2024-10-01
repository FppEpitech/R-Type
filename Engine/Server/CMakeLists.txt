cmake_minimum_required(VERSION 3.5)

set(EXE r-type_server)

set(EXE_SRC_PATH "Src")
set(EXE_INCLUDE_PATH
    "Include"
    "Src/GameEngine"
    "Src/Network"
    "Src/GameEngine/ServerSceneManager"
)

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
    ./${EXE_SRC_PATH}/main.cpp
    ./${EXE_SRC_PATH}/GameEngine/Application/Application.cpp
    ./${EXE_SRC_PATH}/GameEngine/ServerSceneManager/ServerSceneManager.cpp
    ../Shared/SceneManager/ASceneManager.cpp
)

include_directories(
        src/Network
        src/GameEngine/Errors
        src/GameEngine/Application
        src/GameEngine/ServerSceneManager
        ../Shared/Ecs/Src
        ../Shared/Interface
        ../Shared/SceneManager
        ../Shared/Network/Packet
        ../Shared/Component/Entities/Player/
        ../Shared/Component/
)

add_subdirectory(Src/Network)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(asio REQUIRED)
find_package(jsoncpp REQUIRED)

target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    r-type_ecs
    r-type_network_server
)
