/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomListInitSystem.cpp
*/

#include "RoomListInitSystem.hpp"
#include "EntityListComponent.hpp"

RoomListInitSystem::RoomListInitSystem() :
    ASystem("ButtonInitSystem")
{}

void RoomListInitSystem::_initRoomList(ECS::Registry& reg, int idxEntity)
{
    reg.register_component<IComponent>("EntityListComponent");
    reg.set_component<IComponent>(idxEntity, std::make_shared<EntityListComponent>(std::vector<std::size_t>(), "RoomList"), "EntityListComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new RoomListInitSystem();
    }
}
