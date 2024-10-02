cmake_minimum_required(VERSION 3.10)

set(LIB r-type_network_server)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Game/Libs/Network/)

set(LIB_SRC_PATH ".")

set(CMAKE_CXX_STANDARD 20)

set(SRC_LIB
    ${LIB_SRC_PATH}/NetworkServer.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

find_package(asio CONFIG REQUIRED)

target_link_libraries(
    ${LIB}
    PRIVATE asio::asio
    r-type_packet
)

target_include_directories(${LIB} PUBLIC ../../../Shared/Network/Packet)
