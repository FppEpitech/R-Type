cmake_minimum_required(VERSION 3.5)

set(EXE r-type_server)

set(EXE_SRC_PATH "src")
set(EXE_INCLUDE_PATH "include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
    ${EXE_SRC_PATH}/main.cpp
)

include_directories(
    ../Ecs/src/
)

add_subdirectory(src/network)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(Threads REQUIRED)
target_link_libraries(${EXE} r-type_ecs r-type_network_server)
