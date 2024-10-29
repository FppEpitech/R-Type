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
    try {
        ECS::SparseArray<IComponent> draws = reg.get_components<IComponent>("DrawComponent");

        if (draws.size() <= idxPacketEntities)
            return;
        std::shared_ptr<DrawComponent> drawPlayer = std::dynamic_pointer_cast<DrawComponent>(draws[idxPacketEntities]);
        if (!drawPlayer || !drawPlayer->draw)
            return;

        reg.messageType = 0x02;
        reg.payload.clear();

        std::vector<std::any> valuesMoveEntity = {};
        valuesMoveEntity.push_back(idxPacketEntities);
        std::shared_ptr<IEvent> eventMoveEntity = std::make_shared<AEvent>("Shoot", valuesMoveEntity);
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
