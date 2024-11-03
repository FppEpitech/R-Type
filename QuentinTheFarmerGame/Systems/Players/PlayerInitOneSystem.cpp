/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#include "AEvent.hpp"
#include "LifeParser.hpp"
#include "ScaleParser.hpp"
#include "Speed3DParser.hpp"
#include "ObjPathParser.hpp"
#include "GravityParser.hpp"
#include "HitBoxComponent.hpp"
#include "PlayerComponent.hpp"
#include "CanJumpComponent.hpp"
#include "PlayerInitSystem.hpp"
#include "Position3DParser.hpp"
#include "Draw/DrawComponent.hpp"
#include "Life/LifeComponent.hpp"

#define PATH_JSON "GameData/Entities/PlayerOne.json"

PlayerInitSystem::PlayerInitSystem() :
        ASystem("PlayerInitSystem")
{
}

void PlayerInitSystem::_initPlayer(ECS::Registry& reg, int idxEntity)
{

    reg.register_component<IComponent>("ShootComponent");

    std::shared_ptr<ScaleComponent> scale = parseScale(PATH_JSON);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxEntity, scale, scale->getType());
    }

    std::shared_ptr<Position3DComponent> position3D = parsePosition3D(PATH_JSON);
    if (position3D) {
        reg.register_component<IComponent>(position3D->getType());
        reg.set_component<IComponent>(idxEntity, position3D, position3D->getType());
    }

    std::shared_ptr<ObjPathComponent> objPath = parseObjPath(PATH_JSON);
    if (objPath) {
        reg.register_component<IComponent>(objPath->getType());
        reg.set_component<IComponent>(idxEntity, objPath, objPath->getType());
    }

    std::shared_ptr<LifeComponent> life = parseLife(PATH_JSON);
    if (life) {
        reg.register_component<IComponent>(life->getType());
        reg.set_component<IComponent>(idxEntity, life, life->getType());
    }

    reg.register_component<IComponent>("PlayerComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<PlayerComponent>(), "PlayerComponent");

    std::shared_ptr<Speed3DComponent> speed = parseSpeed3D(PATH_JSON);
    if (speed) {
        reg.register_component<IComponent>(speed->getType());
        reg.set_component<IComponent>(idxEntity, speed, speed->getType());
    }

    std::shared_ptr<GravityComponent> gravity = parseGravity(PATH_JSON);
    if (gravity) {
        reg.register_component<IComponent>(gravity->getType());
        reg.set_component<IComponent>(idxEntity, gravity, gravity->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<DrawComponent>(true), "DrawComponent");

    reg.register_component<IComponent>("HitBoxComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<HitBoxComponent>(), "HitBoxComponent");

    reg.register_component<IComponent>("CanJumpComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<CanJumpComponent>(), "CanJumpComponent");

    std::vector<std::any> playerValues = {};
    playerValues.push_back((float)position3D->x);
    playerValues.push_back((float)position3D->y);
    playerValues.push_back((float)position3D->z);
    playerValues.push_back((float)scale->scale);
    playerValues.push_back((std::string)objPath->path);
    playerValues.push_back((int)idxEntity);
    std::shared_ptr<IEvent> hitBoxEvent = std::make_shared<AEvent>("UpdateHitBox", playerValues);
    reg.addEvent(hitBoxEvent);

    std::vector<std::any> cameraValues = {};
    cameraValues.push_back((float)position3D->x);
    cameraValues.push_back((float)position3D->y);
    cameraValues.push_back((float)position3D->z);
    std::shared_ptr<IEvent> cameraEvent = std::make_shared<AEvent>("UpdateCamera", cameraValues);
    reg.addEvent(cameraEvent);
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new PlayerInitSystem();
}
}
