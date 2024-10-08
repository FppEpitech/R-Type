/*
** EPITECH PROJECT, 2024
** ShootDestroySystem
** File description:
** ShootDestroySystem
*/

#include "ShootDestroySystem.hpp"
#include "Position2DComponent.hpp"
#include "ShootComponent.hpp"
#include "GetGraphicalLibrary.hpp"

ShootDestroySystem::ShootDestroySystem() :
    ASystem("ShootDestroySystem")
{
}

void ShootDestroySystem::_shootDestroy(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
        if (!libGraphic)
            return;

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
                if (position->x >= -100 && position->x <= libGraphic->getWindowSize().first &&
                    position->y >= 0 && position->y <= libGraphic->getWindowSize().second)
                    continue;
                reg.kill_entity(entity);
            }
        }
    } catch (std::exception e){
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new ShootDestroySystem();
}
