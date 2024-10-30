/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateRoomButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "DrawComponent.hpp"
#include "AButtonInitSystem.hpp"
#include "CreateRoomButtonInitSystem.hpp"

CreateRoomButtonInitSystem::CreateRoomButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
}

void CreateRoomButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);

    std::shared_ptr<IComponent> draw = std::make_shared<DrawComponent>();
    reg.set_component(idxPacketEntities, draw, "DrawComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new CreateRoomButtonInitSystem();
    }
}
