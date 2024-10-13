/*
** EPITECH PROJECT, 2024
** EndLogoInitSystem
** File description:
** EndLogoInitSystem
*/

#include "ScaleParser.hpp"
#include "DrawComponent.hpp"
#include "ScaleComponent.hpp"
#include "Position2DParser.hpp"
#include "EndLogoInitSystem.hpp"
#include "TextureRectParser.hpp"
#include "Position2DComponent.hpp"
#include "TextureRectComponent.hpp"

#define PATH_JSON "GameData/Entities/EndLogo.json"

EndLogoInitSystem::EndLogoInitSystem() :
        ASystem("EndLogoInitSystem") {}

void EndLogoInitSystem::_initEndLogo(ECS::Registry& reg, int idxPacketEntities)
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

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new EndLogoInitSystem();
    }
}
