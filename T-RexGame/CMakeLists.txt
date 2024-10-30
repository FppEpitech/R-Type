# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# # Add the 'Systems' subdirectory to the build
add_subdirectory(Systems)

# # Add the 'SystemNetworkUpdate' subdirectory to the build
# add_subdirectory(SystemNetworkUpdate)
add_subdirectory(EventHandlers)

# Variables for source and destination
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/T-RexGame/Game)
set(DESTINATION_DIR ${CMAKE_SOURCE_DIR}/Game)

# Ensure the destination directory exists
file(MAKE_DIRECTORY ${DESTINATION_DIR})

# Custom target to copy the directory (runs each time)
add_custom_target(copy_game ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_DIR} ${DESTINATION_DIR}
    COMMENT "Copying directory ${SOURCE_DIR} to ${DESTINATION_DIR}"
)
