/*
** EPITECH PROJECT, 2024
** PlayerInitSystem
** File description:
** PlayerInitSystem
*/

#include "ISystem.hpp"
#include <iostream>

class PlayerInitSystem : public ASystem {

    public:

        PlayerInitSystem();
        ~PlayerInitSystem() = default;

        std::function<void(ECS::Registry& reg, int idxPacketEntities)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketEntities) {
                _initPlayer(reg, idxPacketEntities);
            };
        }

    private:

        void _initPlayer(ECS::Registry& reg, int idxPacketEntities);
};
