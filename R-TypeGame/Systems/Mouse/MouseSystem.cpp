/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MouseSystem.cpp
*/

#include <iostream>

#include "MouseSystem.hpp"
#include "ScaleComponent.hpp"
#include "ClickableComponent.hpp"
#include "Position2DComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "TextureRectComponent.hpp"
#include "ButtonTexturePathComponent.hpp"

MouseSystem::MouseSystem() : ASystem("MouseSystem") {}

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

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && clickables.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1; entity++) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
            std::shared_ptr<ClickableComponent> clickable = std::dynamic_pointer_cast<ClickableComponent>(clickables[entity]);
            std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
            if (!position || !textureRect || !clickable || !scale || !buttonTexturePath)
                continue;
            std::pair<float, float> firstCorner = lib->getSizeWithWindow(position->x, position->y);
            std::pair<float, float> secondCorner = lib->getSizeWithWindow(position->x + textureRect->width * scale->scale, position->y + textureRect->height * scale->scale);
            if (mousePos.first >= firstCorner.first && mousePos.first <= secondCorner.first && mousePos.second >= firstCorner.second && mousePos.second <= secondCorner.second) {
                textureRect->path = buttonTexturePath->hoverTexturePath;
                if (lib->isMouseButtonDown(IGraphic::MouseButtons::MOUSE_LEFT))
                    textureRect->path = buttonTexturePath->clickedTexturePath;
                if (lib->isMouseButtonPressed(IGraphic::MouseButtons::MOUSE_LEFT)) {
                    textureRect->path = buttonTexturePath->clickedTexturePath;
                    clickable->callback(reg, entity);
                }
            } else {
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
