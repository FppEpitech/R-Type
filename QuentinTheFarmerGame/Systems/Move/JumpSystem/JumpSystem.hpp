/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** JumpSystem
*/

#include <iostream>

#include "../../Network/ABI/ABIServer.hpp"
#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../Draw/DrawComponent.hpp"
#include "Speed3D/Speed3DComponent.hpp"
#include "../Position3D/Position3DComponent.hpp"
#include "../Player/PlayerComponent.hpp"

class JumpSystem : public ASystem
{
    public:

        /**
         * @brief Construct a new Move System Up object
         *
         */
        JumpSystem();

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
        void updatePosition(ECS::Registry& entityManager, int idxPacketEntities);
};
