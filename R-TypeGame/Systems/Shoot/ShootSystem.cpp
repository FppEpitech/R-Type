/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "ShootInitSystem.hpp"
#include "Position2DComponent.hpp"
#include "PlayerComponent.hpp"

ShootSystem::ShootSystem() :
    ASystem("ShootSystem")
{
}

void ShootSystem::_shoot(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::entity_t shoot = reg.spawn_entity();
    ShootInitSystem().getFunction()(reg, shoot);

    try {
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");

        if (positions.size() > shoot && positions.size() > idxPacketEntities) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[shoot]);
            std::shared_ptr<Position2DComponent> positionPlayer = std::dynamic_pointer_cast<Position2DComponent>(positions[idxPacketEntities]);

            if (position && positionPlayer) {
                position->x = positionPlayer->x + POS_PLAYER_X;
                position->y = positionPlayer->y + POS_PLAYER_Y;
            }
        }
    } catch (std::exception e){
    }
}

extern "C" ISystem* loadSystemInstance()
{
    return new ShootSystem();
}
