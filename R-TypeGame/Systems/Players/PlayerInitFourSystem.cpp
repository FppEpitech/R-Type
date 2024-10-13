/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#include "SpeedComponent.hpp"
#include "PlayerComponent.hpp"
#include "PlayerInitSystem.hpp"
#include "ScaleComponent.hpp"
#include "DrawComponent.hpp"
#include "TextureRectComponent.hpp"
#include "Position2DComponent.hpp"
#include "../../Components/Life/LifeComponent.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "LifeParser.hpp"
#include "PlayerParser.hpp"
#include "SpeedParser.hpp"

#include <fstream>
#include <json/json.h>

#define PATH_JSON "GameData/Entities/PlayerFour.json"

PlayerInitSystem::PlayerInitSystem() :
    ASystem("PlayerInitSystem")
{
}

void PlayerInitSystem::_initPlayer(ECS::Registry& reg, int idxPacketEntities)
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

    std::shared_ptr<LifeComponent> life = parseLife(PATH_JSON);
    if (life) {
        reg.register_component<IComponent>(life->getType());
        reg.set_component<IComponent>(idxPacketEntities, life, life->getType());
    }

    std::shared_ptr<PlayerComponent> player = parsePlayer(PATH_JSON);
    if (player) {
        reg.register_component<IComponent>(player->getType());
        reg.set_component<IComponent>(idxPacketEntities, player, player->getType());
    }

    std::shared_ptr<SpeedComponent> speed = parseSpeed(PATH_JSON);
    if (speed) {
        reg.register_component<IComponent>(speed->getType());
        reg.set_component<IComponent>(idxPacketEntities, speed, speed->getType());
    }
    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new PlayerInitSystem();
}
}
