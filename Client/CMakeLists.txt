cmake_minimum_required(VERSION 3.5)

set(EXE r-type_client)

set(EXE_SRC_PATH "src")
set(EXE_INCLUDE_PATH "include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
    ./src/main.cpp
    ./src/Application/Application.cpp
    ./src/SceneManager/SceneManager.cpp
)

include_directories(
    ../Ecs/src/
    ./src/include/
    ./src/Application/
    ./src/SceneManager/
)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

target_link_libraries(
    ${EXE}
    r-type_ecs
)
