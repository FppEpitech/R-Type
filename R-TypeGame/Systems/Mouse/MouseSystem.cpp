/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MouseSystem.cpp
*/

#include <iostream>

#include "MouseSystem.hpp"
#include "TextComponent.hpp"
#include "ScaleComponent.hpp"
#include "EditableComponent.hpp"
#include "ClickableComponent.hpp"
#include "CheckableComponent.hpp"
#include "Position2DComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "DefaultTextComponent.hpp"
#include "ButtonStateComponent.hpp"
#include "TextureRectComponent.hpp"
#include "ButtonTexturePathComponent.hpp"

MouseSystem::MouseSystem() : ASystem("MouseSystem") {}

static void unselectOthers(ECS::Registry &reg, int idxPacketEntities)
{
    ECS::SparseArray<IComponent> buttonStates = reg.get_components<IComponent>("ButtonStateComponent");
    ECS::SparseArray<IComponent> texts = reg.get_components<IComponent>("TextComponent");
    ECS::SparseArray<IComponent> defaultTexts = reg.get_components<IComponent>("DefaultTextComponent");
    ECS::SparseArray<IComponent> checkables = reg.get_components<IComponent>("CheckableComponent");

    for (int i = 0; i < buttonStates.size(); i++) {
        std::shared_ptr<ButtonStateComponent> buttonState = std::dynamic_pointer_cast<ButtonStateComponent>(buttonStates[i]);
        std::shared_ptr<TextComponent> text = nullptr;
        std::shared_ptr<DefaultTextComponent> defaultText = nullptr;
        std::shared_ptr<CheckableComponent> checkable = nullptr;

        if (checkables.size() >= i + 1) {
            checkable = std::dynamic_pointer_cast<CheckableComponent>(checkables[i]);
            if (checkable)
                break;
        }
        if (texts.size() >= i + 1)
            text = std::dynamic_pointer_cast<TextComponent>(texts[i]);
        if (defaultTexts.size() >= i + 1)
            defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(defaultTexts[i]);

        if (buttonState && i != idxPacketEntities) {
            if (text && defaultText && text->text.empty())
                text->text = defaultText->text;
            buttonState->state = ButtonStateComponent::ButtonState::NONE;
        }
    }
}

void MouseSystem::_handleMouse(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        std::shared_ptr<IGraphic> lib = getGraphicalLibrary();

        if (!lib)
            return;
        std::pair<float, float> mousePos = lib->getMousePosition();
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
        ECS::SparseArray<IComponent> clickables = reg.get_components<IComponent>("ClickableComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> buttonTexturePaths = reg.get_components<IComponent>("ButtonTexturePathComponent");
        ECS::SparseArray<IComponent> buttonStates = reg.get_components<IComponent>("ButtonStateComponent");
        ECS::SparseArray<IComponent> editables = reg.get_components<IComponent>("EditableComponent");
        ECS::SparseArray<IComponent> checkables = reg.get_components<IComponent>("CheckableComponent");
        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && clickables.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1 && buttonStates.size() >= entity + 1; entity++) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
            std::shared_ptr<ClickableComponent> clickable = std::dynamic_pointer_cast<ClickableComponent>(clickables[entity]);
            std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
            std::shared_ptr<ButtonStateComponent> buttonState = std::dynamic_pointer_cast<ButtonStateComponent>(buttonStates[entity]);
            std::shared_ptr<EditableComponent> editable = nullptr;
            std::shared_ptr<CheckableComponent> checkable = nullptr;
            if (!position || !textureRect || !clickable || !scale || !buttonTexturePath || !buttonState)
                continue;

            if (checkables.size() >= entity + 1)
                checkable = std::dynamic_pointer_cast<CheckableComponent>(checkables[entity]);
            if (editables.size() >= entity + 1)
                editable = std::dynamic_pointer_cast<EditableComponent>(editables[entity]);

            std::pair<float, float> firstCorner = lib->getSizeWithWindow(position->x, position->y);
            std::pair<float, float> secondCorner = lib->getSizeWithWindow(position->x + textureRect->width * scale->scale, position->y + textureRect->height * scale->scale);
            if (mousePos.first >= firstCorner.first && mousePos.first <= secondCorner.first && mousePos.second >= firstCorner.second && mousePos.second <= secondCorner.second) {
                if (!((editable || checkable) && buttonState->state == ButtonStateComponent::ButtonState::CLICKED))
                    textureRect->path = buttonTexturePath->hoverTexturePath;
                if (lib->isMouseButtonDown(IGraphic::MouseButtons::MOUSE_LEFT)) {
                    textureRect->path = buttonTexturePath->pressedTexturePath;
                }
                if (lib->isMouseButtonPressed(IGraphic::MouseButtons::MOUSE_LEFT)) {
                    if (editable || checkable) {
                        if (buttonState->state == ButtonStateComponent::ButtonState::CLICKED) {
                            buttonState->state = ButtonStateComponent::ButtonState::NONE;
                            textureRect->path = buttonTexturePath->noneTexturePath;
                        } else if (buttonState->state == ButtonStateComponent::ButtonState::NONE) {
                            buttonState->state = ButtonStateComponent::ButtonState::CLICKED;
                            textureRect->path = buttonTexturePath->clickedTexturePath;
                        }
                    } else {
                        textureRect->path = buttonTexturePath->pressedTexturePath;
                        buttonState->state = ButtonStateComponent::ButtonState::PRESSED;
                    }
                    clickable->callback(reg, entity);
                    unselectOthers(reg, entity);
                }
            } else {
                if ((editable || checkable) && buttonState->state == ButtonStateComponent::ButtonState::CLICKED)
                    continue;
                textureRect->path = buttonTexturePath->noneTexturePath;
            }
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new MouseSystem();
}
}
