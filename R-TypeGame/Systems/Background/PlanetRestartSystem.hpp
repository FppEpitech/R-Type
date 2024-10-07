/*
** EPITECH PROJECT, 2024
** PlanetRestartSystem
** File description:
** PlanetRestartSystem
*/

#pragma once

#include <iostream>
#include <chrono>
#include <random>

#include "ISystem.hpp"
#include "VelocityComponent.hpp"
#include "Position2DComponent.hpp"

/**
 * @brief Restart a planet if it leave the screen.
 *
 */
class PlanetRestartSystem : public ASystem {

    public:

        /**
         * @brief Construct a new PlanetRestart System object.
         *
         */
        PlanetRestartSystem();

        /**
         * @brief Destroy the PlanetRestart System object.
         *
         */
        ~PlanetRestartSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _restartPlanet(reg, idxPacketEntities);
            };
        }

    private:

        void _restartPlanet(ECS::Registry& reg, int idxPacketEntities); //< Function to Restart a Planet.
        std::mt19937::result_type _getRandomSeed();
        void _updateNewPositions(std::shared_ptr<VelocityComponent> velocity, std::shared_ptr<Position2DComponent> position);
};
