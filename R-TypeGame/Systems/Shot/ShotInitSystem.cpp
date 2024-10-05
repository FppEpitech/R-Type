/*
** EPITECH PROJECT, 2024
** ShotInitSystem
** File description:
** ShotInitSystem
*/

#include "SpeedComponent.hpp"
#include "ShotInitSystem.hpp"
#include "ScaleComponent.hpp"
#include "TextureRectComponent.hpp"
#include "Position2DComponent.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "SpeedParser.hpp"

#include <fstream>
#include <json/json.h>

#define PATH_JSON "GameData/Entities/Shot.json"

ShotInitSystem::ShotInitSystem() :
    ASystem("ShotInitSystem")
{
}

void ShotInitSystem::_initShot(ECS::Registry& reg, int idxPacketEntities)
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
}

// extern "C" ISystem* loadSystemInstance()
// {
//     return new ShotInitSystem();
// }
