cmake_minimum_required(VERSION 3.5)

add_executable(server_test
    ./Server/tests.cpp
)

add_executable(client_test
    ./Server/tests.cpp
)

add_executable(ecs_test
    ./Server/tests.cpp
)

target_link_libraries(server_test PRIVATE criterion)
target_link_libraries(client_test PRIVATE criterion)
target_link_libraries(ecs_test PRIVATE criterion)

# enable testing functionality
enable_testing()

# define tests
add_test(NAME server_test COMMAND server_test)
add_test(NAME client_test COMMAND client_test)
add_test(NAME ecs_test COMMAND ecs_test)
