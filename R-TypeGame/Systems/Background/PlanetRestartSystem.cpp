/*
** EPITECH PROJECT, 2024
** PlanetRestartSystem
** File description:
** PlanetRestartSystem
*/

#include "PlanetRestartSystem.hpp"
#include "PlanetComponent.hpp"
#include "GetGraphicalLibrary.hpp"

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

            _updateNewPositions(velocity, position);
        }
    } catch (std::exception e) {
    }
}

void PlanetRestartSystem::_updateNewPositions(std::shared_ptr<VelocityComponent> velocity, std::shared_ptr<Position2DComponent> position)
{
    std::mt19937 gen(_getRandomSeed());
    std::uniform_int_distribution<unsigned> distribX(1920, 5000);
    std::uniform_int_distribution<unsigned> distribY(0, 1080);
    std::uniform_real_distribution<float> distribVelocity(0.3, 1.5);

    position->x = distribX(gen);
    position->y = distribY(gen);
    float randomVelocity = distribVelocity(gen) * 2;
    velocity->vx = randomVelocity * (-1);
}

std::mt19937::result_type PlanetRestartSystem::_getRandomSeed()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count() +
        (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::high_resolution_clock::now().time_since_epoch()).count()
    );
    return seed;
}

extern "C" ISystem* loadSystemInstance()
{
    return new PlanetRestartSystem();
}
