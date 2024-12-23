/*
** EPITECH PROJECT, 2024
** MobSpeTwoInitSystem
** File description:
** MobSpeTwoInitSystem
*/

#include "MobParser.hpp"
#include "LifeParser.hpp"
#include "ScaleParser.hpp"
#include "MobComponent.hpp"
#include "Draw/DrawComponent.hpp"
#include "MobSpeTwoInitSystem.hpp"
#include "LifeComponent.hpp"
#include "Scale/ScaleComponent.hpp"
#include "VelocityParser.hpp"
#include "Position2DParser.hpp"
#include "TextureRectParser.hpp"
#include "Velocity/VelocityComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "SpriteSheetAnimationParser.hpp"
#include "ShootTypeParser.hpp"

#define PATH_JSON "GameData/Entities/Mob-SpeTwo.json"

MobSpeTwoInitSystem::MobSpeTwoInitSystem() :
    ASystem("MobSpeTwoInitSystem")
{
}

void MobSpeTwoInitSystem::_initMob(ECS::Registry& reg, int idxPacketEntities)
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

    std::shared_ptr<ShootTypeComponent> shootType = parseShootType(PATH_JSON);
    if (shootType) {
        reg.register_component<IComponent>(shootType->getType());
        reg.set_component<IComponent>(idxPacketEntities, shootType, shootType->getType());
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

    std::shared_ptr<LifeComponent> life = parseLife(PATH_JSON);
    if (life) {
        reg.register_component<IComponent>(life->getType());
        reg.set_component<IComponent>(idxPacketEntities, life, life->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C"
{
    EXPORT_SYMBOL ISystem *loadSystemInstance()
    {
        return new MobSpeTwoInitSystem();
    }
}
