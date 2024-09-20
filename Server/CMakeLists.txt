cmake_minimum_required(VERSION 3.5)

set(EXE r-type_server)

set(EXE_SRC_PATH "src")
set(EXE_INCLUDE_PATH "include")

set(SRC_EXE
    ./src/main.cpp

    ./src/GameEngine/DLLoader/DLLoader.cpp
)

include_directories(
    ../Ecs/src/
)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

target_link_libraries(
    ${EXE}
    r-type_ecs
)
