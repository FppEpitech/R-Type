/*
** EPITECH PROJECT, 2024
** PlanetRestartSystem
** File description:
** PlanetRestartSystem
*/

#include "AEvent.hpp"
#include "ScaleComponent.hpp"
#include "ObjPathComponent.hpp"
#include "TreeRestartSystem.hpp"
#include "Position3DComponent.hpp"
#include "ColliderDamageComponent.hpp"

PlanetRestartSystem::PlanetRestartSystem() :
    ASystem("TreeRestartSystem") {}

void PlanetRestartSystem::_restartPlanet(ECS::Registry& reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position3DComponent");
        ECS::SparseArray<IComponent> damages = reg.get_components<IComponent>("ColliderDamageComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> objPaths = reg.get_components<IComponent>("ObjPathComponent");

        for (ECS::entity_t entity = 0; entity < positions.size() && entity < damages.size() && entity < scales.size() && entity < objPaths.size(); entity++) {
            std::shared_ptr<Position3DComponent> position = std::dynamic_pointer_cast<Position3DComponent>(positions[entity]);
            std::shared_ptr<ColliderDamageComponent> damage = std::dynamic_pointer_cast<ColliderDamageComponent>(damages[entity]);
            std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            std::shared_ptr<ObjPathComponent> objPath = std::dynamic_pointer_cast<ObjPathComponent>(objPaths[entity]);

            if (!position || !damage || !scale || !objPath)
                continue;
            if (position->z < -10)
                position->z = 50;

            std::vector<std::any> values;
            values.push_back((float)position->x);
            values.push_back((float)position->y);
            values.push_back((float)position->z);
            values.push_back((float)scale->scale);
            values.push_back((std::string)objPath->path);
            values.push_back((int)entity);
            std::shared_ptr<AEvent> event = std::make_shared<AEvent>("UpdateHitBox", values);
            reg.addEvent(event);
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new PlanetRestartSystem();
}
}
