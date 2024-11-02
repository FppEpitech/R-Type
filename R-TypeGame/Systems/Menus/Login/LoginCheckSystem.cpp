/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginCheckSystem.cpp
*/

#include "AEvent.hpp"
#include "LoginCheckSystem.hpp"
#include "EntityListComponent.hpp"

LoginCheckSystem::LoginCheckSystem() :
    ASystem("LoginCheckSystem")
{}

void LoginCheckSystem::_loginCheckSystem(ECS::Registry& reg, int idxEntity)
{
    std::vector<std::any> values = {};
    values.push_back(std::string(LOGIN));
    std::shared_ptr<IEvent> loginEvent = std::make_shared<AEvent>("LoginAllowed", values);
    reg.addEvent(loginEvent);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new LoginCheckSystem();
    }
}
