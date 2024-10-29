/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AreCheatsOnButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../AButton/AButtonInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Checkable/CheckableComponent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/ButtonTexturePathParser/ButtonTexturePathParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/ButtonTexturePath/ButtonTexturePathComponent.hpp"
#include "AreCheatsOnButtonInitSystem.hpp"

AreCheatsOnButtonInitSystem::AreCheatsOnButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
}

void AreCheatsOnButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);

    std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = parseButtonTexturePath(PATH_JSON);
    if (buttonTexturePath) {
        reg.register_component<IComponent>(buttonTexturePath->getType());
        reg.set_component<IComponent>(idxPacketEntities, buttonTexturePath, buttonTexturePath->getType());
    }

    std::shared_ptr<CheckableComponent> checkable = std::make_shared<CheckableComponent>();
    reg.register_component<IComponent>(checkable->getType());
    reg.set_component<IComponent>(idxPacketEntities, checkable, checkable->getType());
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new AreCheatsOnButtonInitSystem();
    }
}
