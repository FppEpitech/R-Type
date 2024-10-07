# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)

find_package(jsoncpp REQUIRED)

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Include/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Interface/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/
    ../Components/Speed/
    ../Components/Life/
    ../Components/Shoot/
    ../Components/Planet/
    ../Systems/Shoot/
    ../Components/ButtonState/
    ../Components/CallBack/
    ../Parser/ScaleParser/
    ../Parser/Position2DParser/
    ../Parser/LifeParser/
    ../Parser/PlayerParser/
    ../Parser/SpeedParser/
    ../Parser/TextureRectParser/
    ../Parser/VelocityParser/
    ../Parser/ShootParser/
    ../Components/Velocity/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
    ../Parser/SpriteSheetAnimationParser/
    ../Parser/FontPathParser/
    ../Parser/TextParser/
    ../Parser/ButtonStateParser/
    ../Parser/ColourParser/
    ../Parser/Size1DParser/
    ../Parser/TextPosition2DParser/
    ../../Engine/Shared/Ecs/Src/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Enum/
)

# Add a shared library target 'system_initPlayer'
add_library(system_initPlayerOne SHARED
    Players/PlayerInitOneSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/SpriteSheetAnimationComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/LifeParser/LifeParser.cpp
    ../Parser/PlayerParser/PlayerParser.cpp
    ../Parser/SpeedParser/SpeedParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/SpriteSheetAnimationParser/SpriteSheetAnimationParser.cpp
)
target_link_libraries(system_initPlayerOne PRIVATE JsonCpp::JsonCpp)

add_library(system_initPlayerTwo SHARED
    Players/PlayerInitTwoSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/LifeParser/LifeParser.cpp
    ../Parser/PlayerParser/PlayerParser.cpp
    ../Parser/SpeedParser/SpeedParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
)
target_link_libraries(system_initPlayerTwo PRIVATE JsonCpp::JsonCpp)

add_library(system_initPlayerThree SHARED
    Players/PlayerInitThreeSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/LifeParser/LifeParser.cpp
    ../Parser/PlayerParser/PlayerParser.cpp
    ../Parser/SpeedParser/SpeedParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
)
target_link_libraries(system_initPlayerThree PRIVATE JsonCpp::JsonCpp)

add_library(system_initPlayerFour SHARED
    Players/PlayerInitFourSystem.cpp
    ../Components/Life/LifeComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Entities/Player/PlayerComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/LifeParser/LifeParser.cpp
    ../Parser/PlayerParser/PlayerParser.cpp
    ../Parser/SpeedParser/SpeedParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
)
target_link_libraries(system_initPlayerFour PRIVATE JsonCpp::JsonCpp)

add_library(system_initConnectButton SHARED
        Menus/Buttons/ConnectButtonInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/FontPathComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ColourComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Size1DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextPosition2DComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/TextPosition2DParser/TextPosition2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/FontPathParser/FontPathParser.cpp
    ../Parser/TextParser/TextParser.cpp
    ../Parser/ButtonStateParser/ButtonStateParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ../Parser/Size1DParser/Size1DParser.cpp
)
target_link_libraries(system_initConnectButton PRIVATE JsonCpp::JsonCpp)


add_library(system_moveRight SHARED MoveSystem/MoveSystemRight/MoveSystemRight.cpp)
add_library(system_moveLeft SHARED MoveSystem/MoveSystemLeft/MoveSystemLeft.cpp)
add_library(system_moveUp SHARED MoveSystem/MoveSystemUp/MoveSystemUp.cpp)
add_library(system_moveDown SHARED MoveSystem/MoveSystemDown/MoveSystemDown.cpp)
add_library(system_moveEntities SHARED MoveSystem/MoveEntities/MoveEntitiesSystem.cpp)

add_library(system_shoot SHARED
    Shoot/ShootSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    Shoot/ShootInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ../Components/Speed/SpeedComponent.cpp
    ../Components/Velocity/VelocityComponent.cpp
    ../Components/Shoot/ShootComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/SpeedParser/SpeedParser.cpp
    ../Parser/VelocityParser/VelocityParser.cpp
    ../Parser/ShootParser/ShootParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp)
target_link_libraries(system_shoot PRIVATE JsonCpp::JsonCpp)

add_library(system_shootDestroy SHARED
    Shoot/ShootDestroySystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
)

add_library(system_initBackground SHARED
    Background/BackgroundInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/SpriteSheetAnimationComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/SpriteSheetAnimationParser/SpriteSheetAnimationParser.cpp
)
target_link_libraries(system_initBackground PRIVATE JsonCpp::JsonCpp)

add_library(system_initPlanet SHARED
    Background/PlanetInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ../Components/Velocity/VelocityComponent.cpp
    ../Components/Planet/PlanetComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/VelocityParser/VelocityParser.cpp
)
target_link_libraries(system_initPlanet PRIVATE JsonCpp::JsonCpp)

add_library(system_restartPlanet SHARED
    Background/PlanetRestartSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)

add_library(system_initIpTextButton SHARED
        Menus/Buttons/IpTextBoxInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/FontPathComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ColourComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Size1DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextPosition2DComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/TextPosition2DParser/TextPosition2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/FontPathParser/FontPathParser.cpp
    ../Parser/TextParser/TextParser.cpp
    ../Parser/ButtonStateParser/ButtonStateParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ../Parser/Size1DParser/Size1DParser.cpp
)
target_link_libraries(system_initIpTextButton PRIVATE JsonCpp::JsonCpp)

add_library(system_initPortTextButton SHARED
    Menus/Buttons/PortTextBoxInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/FontPathComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ColourComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Size1DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextPosition2DComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/TextPosition2DParser/TextPosition2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/FontPathParser/FontPathParser.cpp
    ../Parser/TextParser/TextParser.cpp
    ../Parser/ButtonStateParser/ButtonStateParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ../Parser/Size1DParser/Size1DParser.cpp
)
target_link_libraries(system_initPortTextButton PRIVATE JsonCpp::JsonCpp)

add_library(system_handleClick SHARED
    ClicksSystems/ClicksSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)
target_link_libraries(system_handleClick PRIVATE JsonCpp::JsonCpp)
