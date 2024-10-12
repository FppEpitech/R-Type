# Minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Set the output directory for the library
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Game/Engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Engine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Game/Engine)

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
    ../Components/Editable/
    ../Components/ButtonState/
    ../Components/CallBack/
    ../Components/TextLimit/
    ../Components/Velocity/
    ../Components/Editable/
    ../Components/ButtonTexturePath/
    ../Parser/ScaleParser/
    ../Parser/Position2DParser/
    ../Parser/LifeParser/
    ../Parser/PlayerParser/
    ../Parser/SpeedParser/
    ../Parser/TextureRectParser/
    ../Parser/VelocityParser/
    ../Parser/ShootParser/
    ../Parser/MobParser/
    ../Components/Velocity/
    ../Components/Mob/
    ../Parser/SpriteSheetAnimationParser/
    ../Parser/FontPathParser/
    ../Parser/TextParser/
    ../Parser/ButtonStateParser/
    ../Parser/ColourParser/
    ../Parser/Size1DParser/
    ../Parser/TextPosition2DParser/
    ../Parser/DefaultTextParser/
    ../Parser/TextLimitParser/
    ../Parser/ButtonTexturePathParser/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/
    ${CMAKE_SOURCE_DIR}/Engine/Shared/DLLoader/
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/Errors/
    ../Systems/Background/
    ../Systems/Shoot/
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
    ../Components/Shoot/ShootComponent.cpp
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

add_library(system_moveMobs SHARED MoveSystem/MoveMobs/MoveMobsSystem.cpp)

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
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/DefaultTextComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/NetworkConnectionComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ../Components/ButtonTexturePath/ButtonTexturePathComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/TextPosition2DParser/TextPosition2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/FontPathParser/FontPathParser.cpp
    ../Parser/TextParser/TextParser.cpp
    ../Parser/ButtonStateParser/ButtonStateParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ../Parser/Size1DParser/Size1DParser.cpp
    ../Parser/DefaultTextParser/DefaultTextParser.cpp
    ../Parser/ButtonTexturePathParser/ButtonTexturePathParser.cpp
)
target_link_libraries(system_initConnectButton PRIVATE JsonCpp::JsonCpp)


add_library(system_moveRight SHARED Move/MoveSystemRight/MoveSystemRight.cpp)
add_library(system_moveLeft SHARED Move/MoveSystemLeft/MoveSystemLeft.cpp)
add_library(system_moveUp SHARED Move/MoveSystemUp/MoveSystemUp.cpp)
add_library(system_moveDown SHARED Move/MoveSystemDown/MoveSystemDown.cpp)
add_library(system_moveEntities SHARED Move/MoveEntities/MoveEntitiesSystem.cpp)

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
    Background/UpdatePlanet.cpp
)

add_library(system_initMob SHARED
    Mob/MobInitSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/SpriteSheetAnimationComponent.cpp
    ../Components/Velocity/VelocityComponent.cpp
    ../Components/Mob/MobComponent.cpp
    ../Components/Life/LifeComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/VelocityParser/VelocityParser.cpp
    ../Parser/MobParser/MobParser.cpp
    ../Parser/SpriteSheetAnimationParser/SpriteSheetAnimationParser.cpp
    ../Parser/LifeParser/LifeParser.cpp
)
target_link_libraries(system_initMob PRIVATE JsonCpp::JsonCpp)

add_library(system_shoot_mob SHARED
    ShootMob/ShootSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    ShootMob/ShootInitSystem.cpp
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
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ColourComponent.cpp)
target_link_libraries(system_shoot_mob PRIVATE JsonCpp::JsonCpp)
add_library(system_hitboxPlayer SHARED
    Hitbox/HitboxPlayerSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    Background/UpdatePlanet.cpp
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
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/DefaultTextComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ../Components/Editable/EditableComponent.cpp
    ../Components/TextLimit/TextLimitComponent.cpp
    ../Components/ButtonTexturePath/ButtonTexturePathComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/TextPosition2DParser/TextPosition2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/FontPathParser/FontPathParser.cpp
    ../Parser/TextParser/TextParser.cpp
    ../Parser/ButtonStateParser/ButtonStateParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ../Parser/Size1DParser/Size1DParser.cpp
    ../Parser/DefaultTextParser/DefaultTextParser.cpp
    ../Parser/TextLimitParser/TextLimitParser.cpp
    ../Parser/ButtonTexturePathParser/ButtonTexturePathParser.cpp
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
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/DefaultTextComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ../Components/Editable/EditableComponent.cpp
    ../Components/TextLimit/TextLimitComponent.cpp
    ../Components/ButtonTexturePath/ButtonTexturePathComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
    ../Parser/TextPosition2DParser/TextPosition2DParser.cpp
    ../Parser/ScaleParser/ScaleParser.cpp
    ../Parser/FontPathParser/FontPathParser.cpp
    ../Parser/TextParser/TextParser.cpp
    ../Parser/ButtonStateParser/ButtonStateParser.cpp
    ../Parser/ColourParser/ColourParser.cpp
    ../Parser/Size1DParser/Size1DParser.cpp
    ../Parser/DefaultTextParser/DefaultTextParser.cpp
    ../Parser/TextLimitParser/TextLimitParser.cpp
    ../Parser/ButtonTexturePathParser/ButtonTexturePathParser.cpp
)
target_link_libraries(system_initPortTextButton PRIVATE JsonCpp::JsonCpp)

add_library(system_handleMouse SHARED
    Mouse/MouseSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ../Components/CallBack/CallBackComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)
target_link_libraries(system_handleMouse PRIVATE JsonCpp::JsonCpp)

add_library(system_handleTyping SHARED
    Typing/TypingSystem.cpp
    ../Components/Editable/EditableComponent.cpp
    ../Components/ButtonState/ButtonStateComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/DefaultTextComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.cpp
)
target_link_libraries(system_handleTyping PRIVATE JsonCpp::JsonCpp)

add_library(system_shootDamage SHARED
    Shoot/ShootDamageSystem.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Ecs/Src/Registry.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
    ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
    ../Components/Shoot/ShootComponent.cpp
    ../Components/Life/LifeComponent.cpp
    ../Components/Mob/MobComponent.cpp
    ../Parser/TextureRectParser/TextureRectParser.cpp
    ../Parser/Position2DParser/Position2DParser.cpp
)
target_link_libraries(system_shootDamage PRIVATE JsonCpp::JsonCpp)

add_library(system_initEndLogo SHARED
        Background/EndLogoInitSystem.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/Position2DComponent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/ScaleComponent.cpp
        ${CMAKE_SOURCE_DIR}/Engine/Shared/Component/TextureRectComponent.cpp
        ../Parser/TextureRectParser/TextureRectParser.cpp
        ../Parser/Position2DParser/Position2DParser.cpp
        ../Parser/ScaleParser/ScaleParser.cpp
)
target_link_libraries(system_initEndLogo PRIVATE JsonCpp::JsonCpp)
