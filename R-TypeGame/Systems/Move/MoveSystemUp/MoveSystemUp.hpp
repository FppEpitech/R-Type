/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemUp
*/

#include <iostream>

#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../Draw/DrawComponent.hpp"
#include "SpeedComponent.hpp"
#include "../Position2D/Position2DComponent.hpp"

class MoveSystemUp : public ASystem
{
    public:

        /**
         * @brief Construct a new Move System Up object
         *
         */
        MoveSystemUp();

        /**
         * @brief Get the function system.
         *
         * @return std::function<void(ECS::Registry& reg)> the function.
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction();

        /**
         * @brief Function who gonna to update the position at up.
         *
         * @param entityManager Class with all entities and component.
         */
        void updateUpPosition(ECS::Registry& entityManager, int idxPacketEntities);
};
