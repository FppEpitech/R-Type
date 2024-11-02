/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RoomPlayerNumberTextBoxInitSystem.cpp
*/

#include <fstream>
#include <json/json.h>

#include "TextComponent.hpp"
#include "DrawComponent.hpp"
#include "TextLimitParser.hpp"
#include "EditableComponent.hpp"
#include "DefaultTextParser.hpp"
#include "ClickableComponent.hpp"
#include "TextLimitComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "DefaultTextComponent.hpp"
#include "RoomPlayerNumberTextBoxInitSystem.hpp"

RoomPlayerNumberTextBoxInitSystem::RoomPlayerNumberTextBoxInitSystem() :
        ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<ButtonStateComponent> state = std::dynamic_pointer_cast<ButtonStateComponent>(reg.get_components<IComponent>("ButtonStateComponent")[idxPacketEntities]);
    std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(reg.get_components<IComponent>("TextComponent")[idxPacketEntities]);
    std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(reg.get_components<IComponent>("DefaultTextComponent")[idxPacketEntities]);
    if (state && text && defaultText) {
        if (state->state == ButtonStateComponent::ButtonState::CLICKED) {
            if (text->text.empty())
                text->text = defaultText->text;
        }
    }
}

void RoomPlayerNumberTextBoxInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);

    std::shared_ptr<EditableComponent> editable = std::make_shared<EditableComponent>();
    reg.register_component<IComponent>(editable->getType());
    reg.set_component<IComponent>(idxPacketEntities, editable, editable->getType());

    std::shared_ptr<TextLimitComponent> textLimit = parseTextLimit(PATH_JSON);
    if (textLimit) {
        reg.register_component<IComponent>(textLimit->getType());
        reg.set_component<IComponent>(idxPacketEntities, textLimit, textLimit->getType());
    }

    std::shared_ptr<DefaultTextComponent> defaultText = parseDefaultText(PATH_JSON);
    if (defaultText) {
        reg.register_component<IComponent>(defaultText->getType());
        reg.set_component<IComponent>(idxPacketEntities, defaultText, defaultText->getType());
    }

    std::shared_ptr<IComponent> draw = std::make_shared<DrawComponent>();
    reg.set_component(idxPacketEntities, draw, "DrawComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new RoomPlayerNumberTextBoxInitSystem();
    }
}
