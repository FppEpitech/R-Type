/*
** EPITECH PROJECT, 2024
** PlanetRestartSystem
** File description:
** PlanetRestartSystem
*/

#include "PlanetRestartSystem.hpp"
#include "PlanetComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "UpdatePlanet.hpp"

PlanetRestartSystem::PlanetRestartSystem() :
    ASystem("PlanetRestartSystem")
{
}

void PlanetRestartSystem::_restartPlanet(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        std::shared_ptr<IGraphic> libGraphic = getGraphicalLibrary();
        if (!libGraphic)
            return;

        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> velocities = reg.get_components<IComponent>("VelocityComponent");
        ECS::SparseArray<IComponent> planets = reg.get_components<IComponent>("PlanetComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 &&
        velocities.size() >= entity + 1 &&planets.size() >= entity + 1; entity++) {

            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<VelocityComponent> velocity = std::dynamic_pointer_cast<VelocityComponent>(velocities[entity]);
            std::shared_ptr<PlanetComponent> planet = std::dynamic_pointer_cast<PlanetComponent>(planets[entity]);
            if (!position || !velocity || !planet)
                continue;
            if (position->x >= -500)
                    continue;

            updateNewPositions(velocity, position);
        }
    } catch (std::exception e) {
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new PlanetRestartSystem();
}
