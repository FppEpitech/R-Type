cmake_minimum_required(VERSION 3.5)

set(EXE r-type_client)

set(EXE_SRC_PATH "src")
set(EXE_INCLUDE_PATH "include")
set(COMPONENT_PATH "src/Component/")

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
    ./src/main.cpp
    ./src/Application/Application.cpp
    ./src/ClientSceneManager/ClientSceneManager.cpp
    ${COMPONENT_PATH}PathComponent.cpp
    ${COMPONENT_PATH}ScaleComponent.cpp
    ${COMPONENT_PATH}ColourComponent.cpp
    ${COMPONENT_PATH}Position3DComponent.cpp
    ${COMPONENT_PATH}Position2DComponent.cpp
    ${COMPONENT_PATH}Size1DComponent.cpp
    ${COMPONENT_PATH}TextComponent.cpp
)

include_directories(
    ../Ecs/src/
    ../include/
    ../include/interfaces/
    ./src/Application/
    ./src/ClientSceneManager/
    ./src/Component/
    ./src/Errors/
)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(asio CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    JsonCpp::JsonCpp
    raylib
    r-type_ecs
)
