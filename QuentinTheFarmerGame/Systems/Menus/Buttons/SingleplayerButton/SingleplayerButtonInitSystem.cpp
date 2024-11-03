/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SingleplayerButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AEvent.hpp"
#include "AButtonInitSystem.hpp"
#include "GetGraphicalLibrary.hpp"
#include "SingleplayerButtonInitSystem.hpp"

SingleplayerButtonInitSystem::SingleplayerButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::vector<std::any> values = {};

    values.push_back(std::string(FIRST_GAME_SCENE));
    std::shared_ptr<IEvent> eventSinglePlayer = std::make_shared<AEvent>("SinglePlayer", values);
    reg.addEvent(eventSinglePlayer);
}

void SingleplayerButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new SingleplayerButtonInitSystem();
    }
}
