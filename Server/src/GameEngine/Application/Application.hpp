/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Application
*/

#pragma once

#include "Registry.hpp"

namespace GameEngine {

class Application {

    public:

        Application();
        ~Application() = default;
        void run();

    private:

        //Network
        ECS::Registry   _registry;
};

} // namespace GameEngine
