cmake_minimum_required(VERSION 3.5)

set(EXE r-type_client)

set(EXE_SRC_PATH "src")
set(EXE_INCLUDE_PATH "include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_EXE
    ./src/main.cpp
)

include_directories(
    ../Ecs/src/
)

add_executable(${EXE} ${SRC_EXE})

target_include_directories(${EXE} PUBLIC ${EXE_INCLUDE_PATH})

find_package(asio CONFIG REQUIRED)



target_link_libraries(
    ${EXE}
    PRIVATE asio::asio
    r-type_ecs
)
