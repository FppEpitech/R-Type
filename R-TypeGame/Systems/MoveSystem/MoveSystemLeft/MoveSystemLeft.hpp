/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemLeft
*/

#include <iostream>

#include "ISystem.hpp"
#include "SpeedComponent.hpp"
#include "Position2DComponent.hpp"

class MoveSystemLeft : public ASystem
{
    public:

        /**
         * @brief Construct a new Move System Left object
         *
         */
        MoveSystemLeft(void);

        /**
         * @brief Get the function system.
         *
         * @return std::function<void(ECS::Registry& reg)> the function.
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction(void);

        /**
         * @brief Function who gonna to update the position at left.
         *
         * @param entityManager Class with all entities and component.
         */
        void updateLeftPosition(ECS::Registry& entityManager, int idxPacketEntities);
};
