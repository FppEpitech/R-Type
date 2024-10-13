/*
** EPITECH PROJECT, 2024
** ShootDestroySystem
** File description:
** ShootDestroySystem
*/

#include "ShootDestroySystem.hpp"
#include "Position2DComponent.hpp"
#include "ShootComponent.hpp"

ShootDestroySystem::ShootDestroySystem() :
    ASystem("ShootDestroySystem")
{
}

void ShootDestroySystem::_shootDestroy(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {

        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> shoots = reg.get_components<IComponent>("ShootComponent");

        for (auto entity : reg.getEntities()) {
            if (entity >= shoots.size() || entity >= positions.size())
                continue;
            std::shared_ptr<ShootComponent> shoot = std::dynamic_pointer_cast<ShootComponent>(shoots[entity]);
            if (!shoot)
                continue;
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);

            if (position && shoot->friendlyFire) {
                if (position->x >= -100 && position->x <= 1920 && position->y >= 0 && position->y <= 1080)
                    continue;
                reg.kill_entity(entity);
            }
        }
    } catch (std::exception e){
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new ShootDestroySystem();
    }
}
