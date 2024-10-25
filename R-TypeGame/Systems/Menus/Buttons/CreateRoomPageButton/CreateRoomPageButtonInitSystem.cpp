/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateRoomPageButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AButtonInitSystem.hpp"
#include "CreateRoomPageButtonInitSystem.hpp"

CreateRoomPageButtonInitSystem::CreateRoomPageButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
}

static void handleOther(ECS::Registry& reg, int idxPacketEntities)
{
}

void CreateRoomPageButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
        handleOther(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new CreateRoomPageButtonInitSystem();
    }
}
