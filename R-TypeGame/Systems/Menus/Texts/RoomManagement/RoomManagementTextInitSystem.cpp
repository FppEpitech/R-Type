/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomManagementTextInitSystem.cpp
*/

#include "DrawComponent.hpp"
#include "RoomManagementTextInitSystem.hpp"

RoomManagementTextInitSystem::RoomManagementTextInitSystem() :
        ASystem("TextInitSystem")
{}

void RoomManagementTextInitSystem::_initText(ECS::Registry &reg, int idxPacketEntities)
{
    _setTextProperties(reg, idxPacketEntities, PATH_JSON);

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new RoomManagementTextInitSystem();
    }
}
