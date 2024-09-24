cmake_minimum_required(VERSION 3.10)

set(LIB r-type_network_client)
set(LIB_SRC_PATH "./")
set(CMAKE_CXX_STANDARD 20)

set(SRC_LIB
    ${LIB_SRC_PATH}/Client/NetworkClient.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

find_package(Threads REQUIRED)
target_link_libraries(${LIB} PRIVATE Threads::Threads)
