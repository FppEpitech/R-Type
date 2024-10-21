/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** TypingSystem.cpp
*/

#include <iostream>

#include "KeyMaps/KeyMap.hpp"
#include "TypingSystem.hpp"
#include "Text/TextComponent.hpp"
#include "CallBack/CallBackComponent.hpp"
#include "Editable/EditableComponent.hpp"
#include "TextLimit/TextLimitComponent.hpp"
#include "GetGraphicalLibrary/GetGraphicalLibrary.hpp"
#include "ButtonState/ButtonStateComponent.hpp"
#include "DefaultText/DefaultTextComponent.hpp"

TypingSystem::TypingSystem() : ASystem("TypingSystem") {}

void TypingSystem::_handleTyping(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        std::shared_ptr<IGraphic> lib = getGraphicalLibrary();
        if (!lib)
            return;
        std::size_t pressedInput = lib->getKeyPressedInput();

        ECS::SparseArray<IComponent> editables = reg.get_components<IComponent>("EditableComponent");
        ECS::SparseArray<IComponent> buttonStates = reg.get_components<IComponent>("ButtonStateComponent");
        ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
        ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");
        ECS::SparseArray<IComponent> textLimits = reg.get_components<IComponent>("TextLimitComponent");
        ECS::SparseArray<IComponent> callbacks = reg.get_components<IComponent>("CallBackComponent");

        for (ECS::entity_t entity = 0; editables.size() >= entity + 1 && buttonStates.size() >= entity + 1 && texts.size() >= entity + 1 && defaultTexts.size() >= entity + 1 && textLimits.size() >= entity + 1; entity++) {
            std::shared_ptr<EditableComponent> editable = std::dynamic_pointer_cast<EditableComponent>(editables[entity]);
            std::shared_ptr<ButtonStateComponent> buttonState = std::dynamic_pointer_cast<ButtonStateComponent>(buttonStates[entity]);
            std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(texts[entity]);
            std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[entity]);
            std::shared_ptr<TextLimitComponent> textLimit = std::dynamic_pointer_cast<TextLimitComponent>(textLimits[entity]);
            std::shared_ptr<CallBackComponent> callback = std::dynamic_pointer_cast<CallBackComponent>(callbacks[entity]);
            if (!editable || !buttonState || !text || !defaultText || !textLimit || !callback)
                continue;
            if (buttonState->state == ButtonStateComponent::ButtonState::CLICKED) {
                if (defaultText->text == text->text && _isKeyPrintable(pressedInput))
                    text->text = "";
                if (pressedInput == KEY_MAP::KEY_BACKSPACE && text->text.size() > 0)
                    text->text.pop_back();
                else if (pressedInput == KEY_MAP::KEY_ENTER || pressedInput == KEY_MAP::KEY_ESCAPE)
                    callback->callback(reg, entity);
                else if (pressedInput != KEY_MAP::KEY_BACKSPACE && _isKeyPrintable(pressedInput) && text->text.size() < textLimit->limit)
                    text->text += pressedInput;
            }
        }
    } catch (std::exception e) {
    }
}

bool TypingSystem::_isKeyPrintable(size_t input)
{
    return (input >= KEY_MAP::KEY_SPACE && input <= KEY_MAP::KEY_GRAVE) || input == KEY_MAP::KEY_BACKSPACE || (input >= KEY_MAP::KEY_KP_0 && input <= KEY_MAP::KEY_KP_9);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new TypingSystem();
    }
}
