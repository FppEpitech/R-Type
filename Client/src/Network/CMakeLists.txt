cmake_minimum_required(VERSION 3.10)

set(LIB r-type_network_client)

set(LIB_SRC_PATH "./")
set(LIB_INCLUDE_PATH "include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_LIB
    ${LIB_SRC_PATH}/NetworkClient.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

find_package(asio CONFIG REQUIRED)
target_link_libraries(
    ${LIB}
    PRIVATE asio::asio
    r-type_packet
)

target_include_directories(${LIB} PUBLIC ${INCLUDE_EXE})
