/*
** EPITECH PROJECT, 2024
** GroundInitSystem
** File description:
** GroundInitSystem
*/

#include "AEvent.hpp"
#include "ScaleParser.hpp"
#include "ObjPathParser.hpp"
#include "HitBoxComponent.hpp"
#include "GroundInitSystem.hpp"
#include "Position3DParser.hpp"
#include "Draw/DrawComponent.hpp"
#include "Scale/ScaleComponent.hpp"

#define PATH_JSON "GameData/Entities/Ground.json"

GroundInitSystem::GroundInitSystem() : ASystem("GroundInitSystem") {}

void GroundInitSystem::_initGround(ECS::Registry& reg, int idxEntity)
{
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

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<DrawComponent>(true), "DrawComponent");

    reg.register_component<IComponent>("HitBoxComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<HitBoxComponent>(), "HitBoxComponent");

    std::vector<std::any> playerValues = {};
    playerValues.push_back((float)position3D->x);
    playerValues.push_back((float)position3D->y);
    playerValues.push_back((float)position3D->z);
    playerValues.push_back((float)scale->scale);
    playerValues.push_back((std::string)objPath->path);
    playerValues.push_back((int)idxEntity);
    std::shared_ptr<IEvent> hitBoxEvent = std::make_shared<AEvent>("UpdateHitBox", playerValues);
    reg.addEvent(hitBoxEvent);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new GroundInitSystem();
    }
}
