/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AreCheatsOnButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "TextComponent.hpp"
#include "AButtonInitSystem.hpp"
#include "CheckableComponent.hpp"
#include "ButtonTexturePathParser.hpp"
#include "ButtonTexturePathComponent.hpp"
#include "AreCheatsOnButtonInitSystem.hpp"

AreCheatsOnButtonInitSystem::AreCheatsOnButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> checkables = reg.get_components<IComponent>("CheckableComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");

    for (ECS::entity_t entity = 0; checkables.size() >= entity + 1; entity++) {
        std::shared_ptr<CheckableComponent> checkable = std::dynamic_pointer_cast<CheckableComponent>(checkables[entity]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(texts[entity]);
        if (!checkable || !text)
            continue;
        if (text->text == "Cheats") {
            checkable->isChecked = !checkable->isChecked;
        }
    }
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
