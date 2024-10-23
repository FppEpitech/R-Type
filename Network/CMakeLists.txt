cmake_minimum_required(VERSION 3.10)

set(LIB r-type_abi_network)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Game/Libs/Network/)

set(LIB_SRC_PATH ".")

set(CMAKE_CXX_STANDARD 20)

set(SRC_LIB
    ${LIB_SRC_PATH}/ABI/ABINetwork.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

target_link_libraries(
    ${LIB}
    PRIVATE asio::asio
)
