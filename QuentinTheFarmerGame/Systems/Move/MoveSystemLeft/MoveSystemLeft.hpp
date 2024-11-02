/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemLeft
*/

#include <iostream>

#include "../../Network/ABI/ABIServer.hpp"
#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "Speed3D/Speed3DComponent.hpp"
#include "../Position3D/Position3DComponent.hpp"
#include "../Draw/DrawComponent.hpp"
#include "../Player/PlayerComponent.hpp"

class MoveSystemLeft : public ASystem
{
    public:

        /**
         * @brief Construct a new Move System Left object
         *
         */
        MoveSystemLeft();

        /**
         * @brief Get the function system.
         *
         * @return std::function<void(ECS::Registry& reg)> the function.
         */
        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction();

        /**
         * @brief Function who gonna to update the position at left.
         *
         * @param entityManager Class with all entities and component.
         */
        void updateLeftPosition(ECS::Registry& entityManager, int idxPacketEntities);
};
