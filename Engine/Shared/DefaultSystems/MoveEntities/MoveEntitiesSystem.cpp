/*
** EPITECH PROJECT, 2024
** MoveEntitiesSystem
** File description:
** MoveEntitiesSystem
*/

#include "../../../Ecs/Src/Events/AEvent.hpp"
#include "MoveEntitiesSystem.hpp"
#include "Velocity/VelocityComponent.hpp"
#include "../Position2D/Position2DComponent.hpp"

#include <chrono>

MoveEntitiesSystem::MoveEntitiesSystem() :
    ASystem("MoveEntitiesSystem")
{
}

void MoveEntitiesSystem::_moveEntities(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);

    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> velocities = reg.get_components<IComponent>("VelocityComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && velocities.size() >= entity + 1; entity++) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<VelocityComponent> velocity = std::dynamic_pointer_cast<VelocityComponent>(velocities[entity]);
            if (!position || !velocity)
                continue;

            const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
            double timeElapsed = std::chrono::duration<double, std::milli>(now - velocity->frameRate).count() / 1000;

            if (0.005 < timeElapsed) {
                position->x += velocity->vx * timeElapsed;
                position->y += velocity->vy;
                velocity->frameRate = std::chrono::high_resolution_clock::now();

                std::vector<std::any> valuesMoveEntity = {};
                int idxEntity = entity;
                valuesMoveEntity.push_back(idxEntity);
                valuesMoveEntity.push_back(position->x);
                valuesMoveEntity.push_back(position->y);
                std::shared_ptr<IEvent> eventMoveEntity = std::make_shared<AEvent>("MoveEntity", valuesMoveEntity);
                reg.addEvent(eventMoveEntity);
            }
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new MoveEntitiesSystem();
}
}
