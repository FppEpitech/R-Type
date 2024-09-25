/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#pragma once

#include "Registry.hpp"

/**
 * @brief Application class
 * It's the main class of the client application
 */
class Application {

    public:

        /**
         * @brief Construct a new Application object
         *
         */
        Application();

        /**
         * @brief Destroy the Application object
         *
         */
        ~Application() = default;

        /**
         * @brief Run the application
         *
         */
        void Run();

    private:

        // TODO: Network class

        std::vector<ECS::Registry> _registries; // Registries for each scene
};
