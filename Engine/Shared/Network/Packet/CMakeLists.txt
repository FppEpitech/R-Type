cmake_minimum_required(VERSION 3.5)

set(LIB r-type_packet)
set(LIB_INCLUDE_PATH "Include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_LIB
        NetworkPacket.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

find_package(asio CONFIG REQUIRED)
target_link_libraries(
    ${LIB}
    PRIVATE asio::asio
)

target_include_directories(${LIB} PUBLIC ${INCLUDE_EXE})
