/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomPasswordTextBoxInitSystem.cpp
*/

#include <fstream>
#include <json/json.h>

#include "TextComponent.hpp"
#include "DrawComponent.hpp"
#include "TextLimitParser.hpp"
#include "EditableComponent.hpp"
#include "DefaultTextParser.hpp"
#include "EntityIdComponent.hpp"
#include "ClickableComponent.hpp"
#include "TextLimitComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "DefaultTextComponent.hpp"
#include "JoinRoomPasswordTextBoxInitSystem.hpp"

static void handleThis(ECS::Registry& reg, int idxEntity)
{
    std::shared_ptr<ButtonStateComponent> state = std::dynamic_pointer_cast<ButtonStateComponent>(reg.get_components<IComponent>("ButtonStateComponent")[idxEntity]);
    std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(reg.get_components<IComponent>("TextComponent")[idxEntity]);
    std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(reg.get_components<IComponent>("DefaultTextComponent")[idxEntity]);
    if (state && text && defaultText) {
        if (state->state == ButtonStateComponent::ButtonState::CLICKED) {
            if (text->text.empty())
                text->text = defaultText->text;
        }
    }
}

JoinRoomPasswordTextBoxInitSystem::JoinRoomPasswordTextBoxInitSystem(ECS::Registry &reg, int idxEntity, std::size_t roomId)
{
    std::function<void(ECS::Registry& reg, int idxEntity)> callback = [](ECS::Registry& reg, int idxEntity) {
        handleThis(reg, idxEntity);
    };

    this->_setButtonProperties(reg, idxEntity, CONFIG_PATH, callback);

    std::shared_ptr<EditableComponent> editable = std::make_shared<EditableComponent>();
    reg.register_component<IComponent>(editable->getType());
    reg.set_component<IComponent>(idxEntity, editable, editable->getType());

    std::shared_ptr<TextLimitComponent> textLimit = parseTextLimit(CONFIG_PATH);
    if (textLimit) {
        reg.register_component<IComponent>(textLimit->getType());
        reg.set_component<IComponent>(idxEntity, textLimit, textLimit->getType());
    }

    std::shared_ptr<DefaultTextComponent> defaultText = parseDefaultText(CONFIG_PATH);
    if (defaultText) {
        reg.register_component<IComponent>(defaultText->getType());
        reg.set_component<IComponent>(idxEntity, defaultText, defaultText->getType());
    }

    std::shared_ptr<EntityIdComponent> entityId = std::make_shared<EntityIdComponent>(roomId);
    reg.set_component<IComponent>(idxEntity, entityId, "EntityIdComponent");

    std::shared_ptr<DrawComponent> draw = std::make_shared<DrawComponent>();
    reg.set_component<IComponent>(idxEntity, draw, "DrawComponent");
}
