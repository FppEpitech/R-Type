/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginPageButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../../../../Engine/Ecs/Src/Events/AEvent.hpp"
#include "../AButton/AButtonInitSystem.hpp"
#include "../../../../../Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.hpp"
#include "LoginPageButtonInitSystem.hpp"

LoginPageButtonInitSystem::LoginPageButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::vector<std::any> values = {};
    values.push_back(std::string(LOGIN_PAGE));
    std::shared_ptr<IEvent> event = std::make_shared<AEvent>("SwitchScene", values);
    reg.addEvent(event);
}

void LoginPageButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new LoginPageButtonInitSystem();
    }
}
