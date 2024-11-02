/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomPageButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AEvent.hpp"
#include "AButtonInitSystem.hpp"
#include "JoinRoomPageButtonInitSystem.hpp"

JoinRoomPageButtonInitSystem::JoinRoomPageButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::vector<std::any> values = {};
    values.push_back(std::string(JOIN_ROOM));
    std::shared_ptr<IEvent> switchEvent = std::make_shared<AEvent>(SWITCH_SCENE, values);
    reg.addEvent(switchEvent);
    values.clear();
    std::shared_ptr<IEvent> roomsEvent = std::make_shared<AEvent>(GET_ROOMS_INFOS, values);
    reg.addEvent(roomsEvent);
}

void JoinRoomPageButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new JoinRoomPageButtonInitSystem();
    }
}
