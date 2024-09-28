cmake_minimum_required(VERSION 3.5)

set(EXE r-type_server)

set(EXE_SRC_PATH "src")
set(EXE_INCLUDE_PATH
    "include"
    "src/GameEngine"
)

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
./${EXE_SRC_PATH}/main.cpp
./${EXE_SRC_PATH}/GameEngine/Application/Application.cpp
./${EXE_SRC_PATH}/GameEngine/SceneManager/SceneManager.cpp
./${EXE_SRC_PATH}/GameEngine/Errors/AError.cpp
)

include_directories(
    ../Ecs/src/
    ../Ecs/include/
    ../include/
    ../include/interfaces/
    ./src/GameEngine/Application/
)

add_subdirectory(src/Network)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(asio CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    r-type_ecs
    r-type_network_server
    JsonCpp::JsonCpp
)
