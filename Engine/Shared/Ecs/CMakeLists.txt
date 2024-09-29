cmake_minimum_required(VERSION 3.5)

set(LIB r-type_ecs)

set(LIB_SRC_PATH "Src")
set(LIB_INCLUDE_PATH "Include")

set(CMAKE_CXX_STANDARD 20)

set(SRC_LIB
        ${LIB_SRC_PATH}/Registry.cpp
)

add_library(${LIB} STATIC ${SRC_LIB})

target_include_directories(${LIB} PUBLIC ${INCLUDE_EXE})
