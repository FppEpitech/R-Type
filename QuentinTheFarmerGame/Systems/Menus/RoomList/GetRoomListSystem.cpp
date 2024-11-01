/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GetRoomListSystem.cpp
*/

#include "AEvent.hpp"
#include "GetRoomListSystem.hpp"
#include "EntityListComponent.hpp"

GetRoomListSystem::GetRoomListSystem() :
    ASystem("GetRoomListSystem")
{}

void GetRoomListSystem::_getRoomListSystem(ECS::Registry& reg, int idxEntity)
{
    std::vector<std::any> values = {};
    std::shared_ptr<IEvent> SendRoomsInfos = std::make_shared<AEvent>(SEND_ROOMS_INFOS, values);
    reg.addEvent(SendRoomsInfos);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new GetRoomListSystem();
    }
}
