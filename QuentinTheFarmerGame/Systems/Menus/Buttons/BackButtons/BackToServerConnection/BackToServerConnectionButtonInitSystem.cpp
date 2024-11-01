/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** BackToServerConnectionButtonInitSystem.cpp
*/

#include <fstream>
#include <json/json.h>

#include "AEvent.hpp"
#include "AButtonInitSystem.hpp"
#include "BackToServerConnectionButtonInitSystem.hpp"

BackToServerConnectionButtonInitSystem::BackToServerConnectionButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::vector<std::any> values = {};
    std::shared_ptr<IEvent> eventLogout = std::make_shared<AEvent>("Logout", values);
    reg.addEvent(eventLogout);

    values.push_back(std::string(BACK_TO_SERVER_CONNECTION));
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("SwitchScene", values);
    reg.addEvent(event);
}

void BackToServerConnectionButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new BackToServerConnectionButtonInitSystem();
    }
}
