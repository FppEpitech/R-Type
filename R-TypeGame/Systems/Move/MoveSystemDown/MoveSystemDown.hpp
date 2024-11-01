/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** MoveSystemDown
*/

#pragma once

#include <iostream>

#include "../../Network/ABI/ABIServer.hpp"
#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
#include "../Draw/DrawComponent.hpp"
#include "Speed/SpeedComponent.hpp"
#include "../Scale/ScaleComponent.hpp"
#include "../Position2D/Position2DComponent.hpp"
#include "../TextureRect/TextureRectComponent.hpp"

class MoveSystemDown : public ASystem
{
public:

    /**
     * @brief Construct a new Move System Down object
     *
     */
    MoveSystemDown();

    /**
     * @brief Get the function system.
     *
     * @return std::function<void(ECS::Registry& reg)> the function.
     */
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction();

    /**
     * @brief Function who gonna to update the position at down.
     *
     * @param entityManager Class with all entities and component.
     */
    void updateDownPosition(ECS::Registry& entityManager, int idxPacketEntities);
};
