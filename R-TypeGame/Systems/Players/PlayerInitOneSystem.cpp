/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#include "SpeedComponent.hpp"
#include "PlayerComponent.hpp"
#include "Draw/DrawComponent.hpp"
#include "PlayerInitSystem.hpp"
#include "Scale/ScaleComponent.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "SpriteSheetAnimation/SpriteSheetAnimationComponent.hpp"
#include "Life/LifeComponent.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "LifeParser.hpp"
#include "Speed3DParser.hpp"
#include "SpriteSheetAnimationParser.hpp"

#include <fstream>
#include <json/json.h>

#define PATH_JSON "GameData/Entities/PlayerOne.json"

PlayerInitSystem::PlayerInitSystem() :
    ASystem("PlayerInitSystem")
{
}

void PlayerInitSystem::_initPlayer(ECS::Registry& reg, int idxPacketEntities)
{

    reg.register_component<IComponent>("ShootComponent");

    std::shared_ptr<TextureRectComponent> textureRect = parseTextureRect(PATH_JSON);
    if (textureRect) {
        reg.register_component<IComponent>(textureRect->getType());
        reg.set_component<IComponent>(idxPacketEntities, textureRect, textureRect->getType());
    }

    std::shared_ptr<ScaleComponent> scale = parseScale(PATH_JSON);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxPacketEntities, scale, scale->getType());
    }

    std::shared_ptr<Position2DComponent> position2D = parsePosition2D(PATH_JSON);
    if (position2D) {
        reg.register_component<IComponent>(position2D->getType());
        reg.set_component<IComponent>(idxPacketEntities, position2D, position2D->getType());
    }

    std::shared_ptr<LifeComponent> life = parseLife(PATH_JSON);
    if (life) {
        reg.register_component<IComponent>(life->getType());
        reg.set_component<IComponent>(idxPacketEntities, life, life->getType());
    }

    reg.register_component<IComponent>("PlayerComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<PlayerComponent>(), "PlayerComponent");

    std::shared_ptr<SpeedComponent> speed = parseSpeed(PATH_JSON);
    if (speed) {
        reg.register_component<IComponent>(speed->getType());
        reg.set_component<IComponent>(idxPacketEntities, speed, speed->getType());
    }

    std::shared_ptr<SpriteSheetAnimationComponent> animation = parseSpriteSheetAnimation(PATH_JSON);
    if (animation) {
        reg.register_component<IComponent>(animation->getType());
        reg.set_component<IComponent>(idxPacketEntities, animation, animation->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(false), "DrawComponent");
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new PlayerInitSystem();
}
}
