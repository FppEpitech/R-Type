/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemRight
*/

#include <iostream>

#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../Draw/DrawComponent.hpp"
#include "SpeedComponent.hpp"
#include "../Scale/ScaleComponent.hpp"
#include "../Position2D/Position2DComponent.hpp"
#include "../TextureRect/TextureRectComponent.hpp"

class MoveSystemRight : public ASystem
{
    public:

        /**
         * @brief Construct a new Move System Right object
         *
         */
        MoveSystemRight();

        /**
         * @brief Get the function system.
         *
         * @return std::function<void(ECS::Registry& reg)> the function.
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction();

        /**
         * @brief Function who gonna to update the position at right.
         *
         * @param entityManager Class with all entities and component.
         */
        void updateRightPosition(ECS::Registry& entityManager, int idxPacketEntities);
};
