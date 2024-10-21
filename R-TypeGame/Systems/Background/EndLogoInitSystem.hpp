/*
** EPITECH PROJECT, 2024
** EndLogoInitSystem
** File description:
** EndLogoInitSystem
*/

#pragma once

#include <iostream>

#include "../../../Engine/Shared/DefaultSystems/ISystem.hpp"

/**
 * @brief Initialize an end logo entity.
 *
 */
class EndLogoInitSystem : public ASystem {

public:

    /**
     * @brief Construct a new end logo Init System object.
     *
     */
    EndLogoInitSystem();

    /**
     * @brief Destroy the end logo Init System object.
     *
     */
    ~EndLogoInitSystem() = default;

    /**
     * @brief Get the Function object.
     *
     * @return std::function<void(ECS::Registry& reg, int idxPacketEntities)>
     */
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
    {
        return [this](ECS::Registry& reg, int idxPacketEntities) {
            _initEndLogo(reg, idxPacketEntities);
        };
    }

private:

    void _initEndLogo(ECS::Registry& reg, int idxPacketEntities); //< Function to init the end logo.
};
