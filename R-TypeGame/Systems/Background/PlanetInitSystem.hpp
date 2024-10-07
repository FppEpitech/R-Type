/*
** EPITECH PROJECT, 2024
** PlanetInitSystem
** File description:
** PlanetInitSystem
*/

#pragma once

#include <iostream>
#include <unordered_map>

#include "ISystem.hpp"

#define PATH_JSON_PLANET "GameData/Entities/Planet.json"
#define PATH_JSON_PLANET_SMALL "GameData/Entities/Planet-small.json"
#define PATH_JSON_ASTEROID_1 "GameData/Entities/Asteroid-1.json"
#define PATH_JSON_ASTEROID_2 "GameData/Entities/Asteroid-2.json"
#define NB_JSON 4

/**
 * @brief Initialize a planet entity.
 *
 */
class PlanetInitSystem : public ASystem {

    public:

        /**
         * @brief Construct a new planet Init System object.
         *
         */
        PlanetInitSystem();

        /**
         * @brief Destroy the planet Init System object.
         *
         */
        ~PlanetInitSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initPlanet(reg, idxPacketEntities);
            };
        }

    private:

        void _initPlanet(ECS::Registry& reg, int idxPacketEntities); //< Function to init the Planet.

        std::unordered_map<int, std::string> _jsonFiles = {
            {0, PATH_JSON_PLANET},
            {1, PATH_JSON_PLANET_SMALL},
            {2, PATH_JSON_ASTEROID_1},
            {3, PATH_JSON_ASTEROID_2},
        };
};
