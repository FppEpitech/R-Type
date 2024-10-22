/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IpTextBoxInitSystem.cpp
*/

#include <fstream>
#include <json/json.h>

#include "TextComponent.hpp"
#include "DrawComponent.hpp"
#include "TextLimitParser.hpp"
#include "CallBackComponent.hpp"
#include "EditableComponent.hpp"
#include "TextLimitComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "DefaultTextComponent.hpp"
#include "IpTextBoxInitSystem.hpp"

IpTextBoxInitSystem::IpTextBoxInitSystem() :
        ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    std::shared_ptr<ButtonStateComponent> state = std::dynamic_pointer_cast<ButtonStateComponent>(reg.get_components<IComponent>("ButtonStateComponent")[idxPacketEntities]);
    std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(reg.get_components<IComponent>("TextComponent")[idxPacketEntities]);
    std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(reg.get_components<IComponent>("DefaultTextComponent")[idxPacketEntities]);
    if (state && text && defaultText) {
        if (state->state == ButtonStateComponent::ButtonState::CLICKED) {
            state->state = ButtonStateComponent::ButtonState::NONE;
            if (text->text.empty())
                text->text = defaultText->text;
        } else
            state->state = ButtonStateComponent::ButtonState::CLICKED;
    }
}

static void handleOthers(ECS::Registry& reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> states = reg.get_components<IComponent>("ButtonStateComponent");
    ECS::SparseArray<IComponent> callbacks = reg.get_components<IComponent>("CallBackComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");
    for (int i = 0; i < states.size() && i < callbacks.size() && i < texts.size() && i < defaultTexts.size(); i++) {
        std::shared_ptr<ButtonStateComponent> newState = std::dynamic_pointer_cast<ButtonStateComponent>(states[i]);
        std::shared_ptr<CallBackComponent> callback = std::dynamic_pointer_cast<CallBackComponent>(callbacks[i]);
        std::shared_ptr<TextComponent> newText = std::dynamic_pointer_cast<TextComponent>(texts[i]);
        std::shared_ptr<DefaultTextComponent> newDefaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[i]);
        if (!newState || !callback || !newText || !newDefaultText)
            continue;
        if (newState->state == ButtonStateComponent::ButtonState::CLICKED && i != idxPacketEntities) {
            newState->state = ButtonStateComponent::ButtonState::NONE;
            if (newText->text.empty())
                newText->text = newDefaultText->text;
        }
    }
}

void IpTextBoxInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
        handleOthers(reg, idxPacketEntities);
    };

    this->_setButtonProprieties(reg, idxPacketEntities, PATH_JSON, callback);

    std::shared_ptr<EditableComponent> editable = std::make_shared<EditableComponent>();
    reg.register_component<IComponent>(editable->getType());
    reg.set_component<IComponent>(idxPacketEntities, editable, editable->getType());

    std::shared_ptr<TextLimitComponent> textLimit = parseTextLimit(PATH_JSON);
    if (textLimit) {
        reg.register_component<IComponent>(textLimit->getType());
        reg.set_component<IComponent>(idxPacketEntities, textLimit, textLimit->getType());
    }

    reg.register_component<IComponent>("DrawComponent");
    reg.set_component<IComponent>(idxPacketEntities, std::make_shared<DrawComponent>(), "DrawComponent");
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new IpTextBoxInitSystem();
    }
}
