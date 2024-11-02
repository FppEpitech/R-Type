/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GravitySystem.cpp
*/

#include <iostream>

#include "GravitySystem.hpp"
#include "GravityComponent.hpp"
#include "Position3DComponent.hpp"

GravitySystem::GravitySystem() : ASystem("GravitySystem") {}

void GravitySystem::_handleGravity(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> positions3D = reg.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> gravities = reg.get_components<IComponent>("GravityComponent");

        for (ECS::entity_t entity = 0; entity < positions3D.size() && entity < gravities.size(); entity++) {
            std::shared_ptr<Position3DComponent> position3D = std::dynamic_pointer_cast<Position3DComponent>(positions3D[entity]);
            std::shared_ptr<GravityComponent> gravity = std::dynamic_pointer_cast<GravityComponent>(gravities[entity]);

            if (!position3D || !gravity)
                continue;

            position3D->x -= gravity->gravityX;
            position3D->y -= gravity->gravityY;
            position3D->z -= gravity->gravityZ;
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new GravitySystem();
}
}
