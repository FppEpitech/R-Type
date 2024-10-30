/*
** EPITECH PROJECT, 2024
** CactusInitSystem
** File description:
** CactusInitSystem
*/

#include "CactusInitSystem.hpp"
#include "Scale/ScaleComponent.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "Draw/DrawComponent.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "VelocityComponent.hpp"
#include "VelocityParser.hpp"


#include <fstream>
#include <json/json.h>

#define PATH_JSON "GameData/Entities/Cactus.json"

CactusInitSystem::CactusInitSystem() :
    ASystem("CactusInitSystem")
{
}

void CactusInitSystem::_initCactus(ECS::Registry& reg, int idxPacketEntities)
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

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new CactusInitSystem();
}
}
