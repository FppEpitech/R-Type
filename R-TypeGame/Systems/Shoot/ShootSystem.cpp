/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "PlayerComponent.hpp"
#include "Draw/DrawComponent.hpp"
#include "../../../Engine/Ecs/Src/Events/AEvent.hpp"

ShootSystem::ShootSystem() :
    ASystem("ShootSystem")
{
}

void ShootSystem::_shoot(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);

    if (reg.identity == ECS::Registry::Identity::Client)
        return;

    auto now = std::chrono::steady_clock::now();
    auto durationSinceLastShoot = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShootTime).count();
    if (durationSinceLastShoot < 500)
        return;
    lastShootTime = now;

    try {
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");
std::make_shared<ECS::Registry>();
        if (draws.size() <= idxPacketEntities)
            return;
        std::shared_ptr<DrawComponent> drawPlayer = std::dynamic_pointer_cast<DrawComponent>(draws[idxPacketEntities]);
        if (!drawPlayer || !drawPlayer->draw)
            return;

        ECS::entity_t shoot = reg.spawn_entity();
        ShootInitSystem().getFunction()(reg, shoot);

        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");

        if (positions.size() > shoot && positions.size() > idxPacketEntities) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
            std::shared_ptr<Position2DComponent> positionPlayer = std::dynamic_pointer_cast<Position2DComponent>(positions[idxPacketEntities]);

            if (position && positionPlayer) {
                position->x = positionPlayer->x + POS_PLAYER_X;
                position->y = positionPlayer->y + POS_PLAYER_Y;
            }
        }

        std::vector<std::any> shootCreate = {};
        shootCreate.push_back(idxPacketEntities);
        shootCreate.push_back(SHOOT_CREATE);
        int shootIdx = shoot;
        shootCreate.push_back(shootIdx);
        std::shared_ptr<IEvent> eventMoveEntity = std::make_shared<AEvent>("Shoot", shootCreate);
        reg.addEvent(eventMoveEntity);

    } catch (std::exception e){
        std::cerr << "Error in Shoot system: " << e.what() << std::endl;
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new ShootSystem();
    }
}
