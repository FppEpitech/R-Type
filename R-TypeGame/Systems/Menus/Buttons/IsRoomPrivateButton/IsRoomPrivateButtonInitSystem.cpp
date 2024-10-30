/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IsRoomPrivateButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../../../../../Engine/Shared/DefaultComponents/Text/TextComponent.hpp"
#include "../AButton/AButtonInitSystem.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Editable/EditableComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/Checkable/CheckableComponent.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/DefaultText/DefaultTextComponent.hpp"
#include "../../../../../Engine/Shared/DefaultParser/ButtonTexturePathParser/ButtonTexturePathParser.hpp"
#include "../../../../../Engine/Shared/DefaultComponents/ButtonTexturePath/ButtonTexturePathComponent.hpp"
#include "IsRoomPrivateButtonInitSystem.hpp"

IsRoomPrivateButtonInitSystem::IsRoomPrivateButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> editables = reg.get_components<IComponent>("EditableComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");

    for (ECS::entity_t entity = 0; editables.size() >= entity + 1 && texts.size() >= entity + 1 && defaultTexts.size() >= entity + 1; entity++) {
        std::shared_ptr<EditableComponent> editable = std::dynamic_pointer_cast<EditableComponent>(editables[entity]);
        std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(texts[entity]);
        std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[entity]);
        if (!editable || !text || !defaultText)
            continue;
        if (defaultText->text == "Password") {
            editable->_isEditable = !editable->_isEditable;
            if (!editable->_isEditable)
                text->text = defaultText->text;
        }
    }

    ECS::SparseArray<IComponent> checkables = reg.get_components<IComponent>("CheckableComponent");
    ECS::SparseArray<IComponent> textsCheck = reg.get_components<IComponent>("TextComponent");

    for (ECS::entity_t entity = 0; checkables.size() >= entity + 1; entity++) {
        std::shared_ptr<CheckableComponent> checkable = std::dynamic_pointer_cast<CheckableComponent>(checkables[entity]);
        std::shared_ptr<TextComponent> textCheck = std::dynamic_pointer_cast<TextComponent>(textsCheck[entity]);
        if (!checkable || !textCheck)
            continue;
        if (textCheck->text == "Private")
            checkable->isChecked = !checkable->isChecked;
    }
}

void IsRoomPrivateButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
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
        return new IsRoomPrivateButtonInitSystem();
    }
}
