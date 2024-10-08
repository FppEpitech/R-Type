cmake_minimum_required(VERSION 3.5)

# Set compiler flags for coverage
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/tests)

add_executable(server_test
    ./Server/tests.cpp
)

add_executable(client_test
    ./Server/tests.cpp
)

add_executable(ecs_test
    ./Server/tests.cpp
)

# enable testing functionality
enable_testing()

# define tests
add_test(NAME server_test COMMAND server_test)
add_test(NAME client_test COMMAND client_test)
add_test(NAME ecs_test COMMAND ecs_test)
