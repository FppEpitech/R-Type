/*
** EPITECH PROJECT, 2024
** ShootInitSystem
** File description:
** ShootInitSystem
*/

#include "SpeedComponent.hpp"
#include "ShootInitSystem.hpp"
#include "Draw/DrawComponent.hpp"
#include "Scale/ScaleComponent.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "Velocity/VelocityComponent.hpp"
#include "ShootComponent.hpp"
#include "VelocityParser.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "Speed3DParser.hpp"
#include "ShootParser.hpp"

#include <fstream>
#include <json/json.h>

#define PATH_JSON "GameData/Entities/Shoot.json"

ShootInitSystem::ShootInitSystem() :
    ASystem("ShootInitSystem")
{
}

void ShootInitSystem::_initShoot(ECS::Registry& reg, int idxPacketEntities)
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

    std::shared_ptr<SpeedComponent> speed = parseSpeed(PATH_JSON);
    if (speed) {
        reg.register_component<IComponent>(speed->getType());
        reg.set_component<IComponent>(idxPacketEntities, speed, speed->getType());
    }

    std::shared_ptr<VelocityComponent> velocity = parseVelocity(PATH_JSON);
    if (velocity) {
        reg.register_component<IComponent>(velocity->getType());
        reg.set_component<IComponent>(idxPacketEntities, velocity, velocity->getType());
    }

    std::shared_ptr<ShootComponent> shoot = parseShoot(PATH_JSON);
    if (shoot) {
        reg.register_component<IComponent>(shoot->getType());
        reg.set_component<IComponent>(idxPacketEntities, shoot, shoot->getType());
    }
    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}
