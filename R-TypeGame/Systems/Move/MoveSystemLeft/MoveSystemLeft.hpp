/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemLeft
*/

#pragma once

#include <iostream>

#include "../../Network/ABI/ABIServer.hpp"
#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "Speed/SpeedComponent.hpp"
#include "../Position2D/Position2DComponent.hpp"
#include "../Draw/DrawComponent.hpp"

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
