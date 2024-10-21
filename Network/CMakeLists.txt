cmake_minimum_required(VERSION 3.10)

set(LIB r-type_abi_network)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Game/Libs/Network/)

set(LIB_SRC_PATH ".")

set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${LIB_SRC_PATH}/Messages/
    ${LIB_SRC_PATH}/Units/
    ${LIB_SRC_PATH}/Units/Client/
    ${LIB_SRC_PATH}/Units/ANetworkUnit/
    ${LIB_SRC_PATH}/ABI/
    ${LIB_SRC_PATH}/Errors
)

set(SRC_LIB
    ${LIB_SRC_PATH}/ABI/ABINetwork.cpp
    ${LIB_SRC_PATH}/ABI/ABIServer.cpp
    ${LIB_SRC_PATH}/ABI/ABIClient.cpp

    ${LIB_SRC_PATH}/Units/ANetworkUnit/ANetworkUnit.cpp
    ${LIB_SRC_PATH}/Units/Client/Client.cpp

    ${LIB_SRC_PATH}/Messages/AMessage/AMessage.cpp
    ${LIB_SRC_PATH}/Messages/Auth/Auth.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

find_package(asio CONFIG REQUIRED)

target_link_libraries(
    ${LIB}
    PRIVATE asio::asio
)
