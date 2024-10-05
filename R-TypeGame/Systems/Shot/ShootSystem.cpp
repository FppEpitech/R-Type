/*
** EPITECH PROJECT, 2024
** ShootSystem
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"
#include "ShotInitSystem.hpp"

ShootSystem::ShootSystem() :
    ASystem("ShootSystem")
{
}

void ShootSystem::_shoot(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::entity_t shoot = reg.spawn_entity();
    ShotInitSystem().getFunction()(reg, shoot);
}

extern "C" ISystem* loadSystemInstance()
{
    return new ShootSystem();
}
