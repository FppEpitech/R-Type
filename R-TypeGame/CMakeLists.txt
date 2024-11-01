# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

set(GAME R-TypeGame)

string(ASCII 27 ESC)
message("${ESC}[1;33mCompile ${GAME}.${ESC}[0m")

# Add the 'Systems' subdirectory to the build
add_subdirectory(Systems)

# Add the 'SystemNetworkUpdate' subdirectory to the build
add_subdirectory(SystemNetworkUpdate)
add_subdirectory(EventHandlers)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/${GAME}/Game)
set(TARGET_DIR ${CMAKE_SOURCE_DIR}/Game)

# Custom target to copy GameData folder to the target directory
add_custom_target(copy_game_data ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_DIR} ${TARGET_DIR}
    COMMENT "Copying directory ${SOURCE_DIR} to ${TARGET_DIR}"
)

# Custom target to clean up copied GameData folder
add_custom_target(clean_game_data
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${TARGET_DIR}
    COMMENT "Cleaning up directory ${TARGET_DIR}"
)

# Make sure clean_game_data runs as part of the default 'clean' operation
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${TARGET_DIR})
