/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#include "LifeParser.hpp"
#include "ScaleParser.hpp"
#include "Speed3DParser.hpp"
#include "ObjPathParser.hpp"
#include "GravityParser.hpp"
#include "PlayerComponent.hpp"
#include "PlayerInitSystem.hpp"
#include "Position3DParser.hpp"
#include "Draw/DrawComponent.hpp"
#include "Life/LifeComponent.hpp"
#include "Scale/ScaleComponent.hpp"

#define PATH_JSON "GameData/Entities/PlayerOne.json"

PlayerInitSystem::PlayerInitSystem() :
        ASystem("PlayerInitSystem")
{
}

void PlayerInitSystem::_initPlayer(ECS::Registry& reg, int idxPacketEntities)
{

    reg.register_component<IComponent>("ShootComponent");

    std::shared_ptr<ScaleComponent> scale = parseScale(PATH_JSON);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxPacketEntities, scale, scale->getType());
    }

    std::shared_ptr<Position3DComponent> position3D = parsePosition3D(PATH_JSON);
    if (position3D) {
        reg.register_component<IComponent>(position3D->getType());
        reg.set_component<IComponent>(idxPacketEntities, position3D, position3D->getType());
    }

    std::shared_ptr<ObjPathComponent> objPath = parseObjPath(PATH_JSON);
    if (objPath) {
        reg.register_component<IComponent>(objPath->getType());
        reg.set_component<IComponent>(idxPacketEntities, objPath, objPath->getType());
    }

    std::shared_ptr<LifeComponent> life = parseLife(PATH_JSON);
    if (life) {
        reg.register_component<IComponent>(life->getType());
        reg.set_component<IComponent>(idxPacketEntities, life, life->getType());
    }

    reg.register_component<IComponent>("PlayerComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<PlayerComponent>(), "PlayerComponent");

    std::shared_ptr<Speed3DComponent> speed = parseSpeed3D(PATH_JSON);
    if (speed) {
        reg.register_component<IComponent>(speed->getType());
        reg.set_component<IComponent>(idxPacketEntities, speed, speed->getType());
    }

    std::shared_ptr<GravityComponent> gravity = parseGravity(PATH_JSON);
    if (gravity) {
        reg.register_component<IComponent>(gravity->getType());
        reg.set_component<IComponent>(idxPacketEntities, gravity, gravity->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(true), "DrawComponent");
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new PlayerInitSystem();
}
}
