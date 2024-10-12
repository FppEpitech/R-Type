/*
** EPITECH PROJECT, 2024
** MobInitSystem
** File description:
** MobInitSystem
*/

#include "SpeedComponent.hpp"
#include "MobInitSystem.hpp"
#include "ScaleComponent.hpp"
#include "TextureRectComponent.hpp"
#include "Position2DComponent.hpp"
#include "VelocityComponent.hpp"
#include "MobComponent.hpp"
#include "VelocityParser.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "SpeedParser.hpp"
#include "MobParser.hpp"

#include <fstream>
#include <json/json.h>
#include <SpriteSheetAnimationComponent.hpp>
#include <SpriteSheetAnimationParser.hpp>

#define PATH_JSON "GameData/Entities/Mob.json"

MobInitSystem::MobInitSystem() :
    ASystem("MobInitSystem")
{
}

void MobInitSystem::_initMob(ECS::Registry& reg, int idxPacketEntities)
{
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

    std::shared_ptr<VelocityComponent> velocity = parseVelocity(PATH_JSON);
    if (velocity) {
        reg.register_component<IComponent>(velocity->getType());
        reg.set_component<IComponent>(idxPacketEntities, velocity, velocity->getType());
    }

    std::shared_ptr<MobComponent> mob = parseMob(PATH_JSON);
    if (mob) {
        reg.register_component<IComponent>(mob->getType());
        reg.set_component<IComponent>(idxPacketEntities, mob, mob->getType());
    }

    std::shared_ptr<SpriteSheetAnimationComponent> animation = parseSpriteSheetAnimation(PATH_JSON);
    if (animation) {
        reg.register_component<IComponent>(animation->getType());
        reg.set_component<IComponent>(idxPacketEntities, animation, animation->getType());
    }
}

extern "C"
{   
    EXPORT_SYMBOL ISystem *loadSystemInstance()
    {
        return new MobInitSystem();
    }
}
