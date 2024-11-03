/*
** EPITECH PROJECT, 2024
** TreeInitSystem
** File description:
** TreeInitSystem
*/

#include <random>

#include "AEvent.hpp"
#include "ScaleParser.hpp"
#include "ObjPathParser.hpp"
#include "GravityParser.hpp"
#include "HitBoxComponent.hpp"
#include "TreesInitSystem.hpp"
#include "Position3DParser.hpp"
#include "Draw/DrawComponent.hpp"
#include "Scale/ScaleComponent.hpp"

#define PATH_JSON "GameData/Entities/Tree.json"

TreeInitSystem::TreeInitSystem() : ASystem("TreeInitSystem") {}

void TreeInitSystem::_initTree(ECS::Registry& reg, int idxEntity)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count() +
            (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch()).count()
    );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distribY(0, 20);

    float randomY = (float)distribY(gen);

    std::shared_ptr<ScaleComponent> scale = parseScale(PATH_JSON);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxEntity, scale, scale->getType());
    }

    std::shared_ptr<Position3DComponent> position3D = parsePosition3D(PATH_JSON);
    if (position3D) {
        reg.register_component<IComponent>(position3D->getType());
        reg.set_component<IComponent>(idxEntity, position3D, position3D->getType());
        position3D->y += randomY;
    }

    std::shared_ptr<ObjPathComponent> objPath = parseObjPath(PATH_JSON);
    if (objPath) {
        reg.register_component<IComponent>(objPath->getType());
        reg.set_component<IComponent>(idxEntity, objPath, objPath->getType());
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
        return new TreeInitSystem();
    }
}
