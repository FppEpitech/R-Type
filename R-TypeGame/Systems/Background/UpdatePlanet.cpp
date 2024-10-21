/*
** EPITECH PROJECT, 2024
** UpdatePlanet
** File description:
** UpdatePlanet
*/

#include <chrono>
#include <random>

#include "UpdatePlanet.hpp"
#include "VelocityComponent.hpp"
#include "../../../Engine/Shared/DefaultComponent/Position2D/Position2DComponent.hpp"

static std::mt19937::result_type getRandomSeed()
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

void updateNewPositions(std::shared_ptr<VelocityComponent> velocity, std::shared_ptr<Position2DComponent> position)
{
    std::mt19937 gen(getRandomSeed());
    std::uniform_int_distribution<unsigned> distribX(1920, 5000);
    std::uniform_int_distribution<unsigned> distribY(0, 1080);
    std::uniform_real_distribution<float> distribVelocity(30, 150);

    position->x = distribX(gen);
    position->y = distribY(gen);
    float randomVelocity = distribVelocity(gen) * 2;
    velocity->vx = randomVelocity * (-1);
}
