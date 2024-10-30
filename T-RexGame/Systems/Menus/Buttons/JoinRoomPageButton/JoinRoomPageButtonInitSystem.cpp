/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomPageButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AButtonInitSystem.hpp"
#include "JoinRoomPageButtonInitSystem.hpp"

JoinRoomPageButtonInitSystem::JoinRoomPageButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
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
