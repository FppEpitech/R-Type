/*
** EPITECH PROJECT, 2024
** PlanetInitSystem
** File description:
** PlanetInitSystem
*/

#include "PlanetInitSystem.hpp"
#include "ScaleComponent.hpp"
#include "TextureRectComponent.hpp"
#include "Position2DComponent.hpp"
#include "TextureRectParser.hpp"
#include "ScaleParser.hpp"
#include "Position2DParser.hpp"
#include "VelocityParser.hpp"
#include "VelocityComponent.hpp"
#include "PlanetComponent.hpp"

#include <fstream>
#include <chrono>
#include <random>

PlanetInitSystem::PlanetInitSystem() :
    ASystem("PlanetInitSystem")
{
}

void PlanetInitSystem::_initPlanet(ECS::Registry& reg, int idxPacketEntities)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count() +
        (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::high_resolution_clock::now().time_since_epoch()).count()
    );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(0, NB_JSON - 1);
    std::uniform_int_distribution<unsigned> distribX(1920, 5000);
    std::uniform_int_distribution<unsigned> distribY(0, 1080);
    std::uniform_real_distribution<float> distribVelocity(0.3, 1.5);

    int randomJson = distrib(gen);

    std::shared_ptr<TextureRectComponent> textureRect = parseTextureRect(_jsonFiles[randomJson]);
    if (textureRect) {
        reg.register_component<IComponent>(textureRect->getType());
        reg.set_component<IComponent>(idxPacketEntities, textureRect, textureRect->getType());
    }

    std::shared_ptr<ScaleComponent> scale = parseScale(_jsonFiles[randomJson]);
    if (scale) {
        reg.register_component<IComponent>(scale->getType());
        reg.set_component<IComponent>(idxPacketEntities, scale, scale->getType());
    }

    std::shared_ptr<Position2DComponent> position2D = parsePosition2D(_jsonFiles[randomJson]);
    if (position2D) {
        reg.register_component<IComponent>(position2D->getType());
        position2D->x = distribX(gen);
        position2D->y = distribY(gen);
        reg.set_component<IComponent>(idxPacketEntities, position2D, position2D->getType());
    }

    std::shared_ptr<VelocityComponent> velocity = parseVelocity(_jsonFiles[randomJson]);
    if (velocity) {
        reg.register_component<IComponent>(velocity->getType());
        float randomVelocity = distribVelocity(gen) * 2;
        velocity->vx = randomVelocity * (-1);
        reg.set_component<IComponent>(idxPacketEntities, velocity, velocity->getType());
    }


    std::shared_ptr<PlanetComponent> planet = std::make_shared<PlanetComponent>();
    if (planet) {
        reg.register_component<IComponent>(planet->getType());
        reg.set_component<IComponent>(idxPacketEntities, planet, planet->getType());
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new PlanetInitSystem();
}
