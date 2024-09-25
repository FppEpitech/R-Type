/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#pragma once

#include "Registry.hpp"

/**
 * @brief SceneManager class
 * It manages the scenes of the game and the transitions between them
 */
class SceneManager {

    public:

        /**
         * @brief Construct a new SceneManager object
         * @param registries Registries for each scene
         *
         */
        SceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries);

        /**
         * @brief Destroy the SceneManager object
         *
         */
        ~SceneManager() = default;

    private:

        std::shared_ptr<std::vector<ECS::Registry>> _registries; // Registries for each scene
};
