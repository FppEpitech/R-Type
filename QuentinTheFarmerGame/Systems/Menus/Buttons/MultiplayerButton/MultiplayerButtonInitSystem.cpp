/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MultiplayerButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AEvent.hpp"
#include "AButtonInitSystem.hpp"
#include "GetGraphicalLibrary.hpp"
#include "MultiplayerButtonInitSystem.hpp"

MultiplayerButtonInitSystem::MultiplayerButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::vector<std::any> values = {};
    values.push_back(std::string(CONNECT_TO_SERVER));
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("SwitchScene", values);
    reg.addEvent(event);
}

void MultiplayerButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new MultiplayerButtonInitSystem();
    }
}
