/*
** EPITECH PROJECT, 2024
** MoveMobsSystem
** File description:
** MoveMobsSystem
*/

#include "MoveMobsSystem.hpp"
#include "VelocityComponent.hpp"
#include "../Position2D/Position2DComponent.hpp"
#include <MobComponent.hpp>


MoveMobsSystem::MoveMobsSystem() :
    ASystem("MoveMobsSystem")
{
}

void MoveMobsSystem::_moveMobs(ECS::Registry& reg, int idxPacketMobs)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> velocities = reg.get_components<IComponent>("VelocityComponent");
        ECS::SparseArray<IComponent> mobs = reg.get_components<IComponent>("MobComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && velocities.size() >= entity + 1; entity++) {
            if (entity >= mobs.size() || entity >= positions.size() || entity >= velocities.size())
                continue;
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<VelocityComponent> velocity = std::dynamic_pointer_cast<VelocityComponent>(velocities[entity]);
            std::shared_ptr<MobComponent> mob = std::dynamic_pointer_cast<MobComponent>(mobs[entity]);

            if (!position || !velocity || !mob)
                continue;
            if (position->x < mob->xStartOscillate && velocity->vx != 0) {
                velocity->vx = 0;
                velocity->vy = mob->oscillateSpeed;
            }
            if (position->y > mob->maxY)
                velocity->vy = -(mob->oscillateSpeed);
            if (position->y < mob->minY)
                velocity->vy = mob->oscillateSpeed;
        }
    } catch (std::exception e) {
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new MoveMobsSystem();
    }
}
