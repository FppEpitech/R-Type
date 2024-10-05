/*
** EPITECH PROJECT, 2024
** MoveEntitiesSystem
** File description:
** MoveEntitiesSystem
*/

#include "MoveEntitiesSystem.hpp"
#include "VelocityComponent.hpp"
#include "Position2DComponent.hpp"

MoveEntitiesSystem::MoveEntitiesSystem() :
    ASystem("MoveEntitiesSystem")
{
}

void MoveEntitiesSystem::_moveEntities(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> velocities = reg.get_components<IComponent>("VelocityComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && velocities.size() >= entity + 1; entity++) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<VelocityComponent> velocity = std::dynamic_pointer_cast<VelocityComponent>(velocities[entity]);
            if (!position || !velocity)
                continue;
            position->x += velocity->vx;
            position->y += velocity->vy;
        }
    } catch (std::exception e) {
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new MoveEntitiesSystem();
}
