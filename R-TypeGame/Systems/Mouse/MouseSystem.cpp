/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MouseSystem.cpp
*/

#include <iostream>

#include "MouseSystem.hpp"
#include "Scale/ScaleComponent.hpp"
#include "../../Components/CallBack/CallBackComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "../../../Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "../../Components/ButtonTexturePath/ButtonTexturePathComponent.hpp"

MouseSystem::MouseSystem() : ASystem("MouseSystem") {}

void MouseSystem::_handleMouse(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        std::shared_ptr<IGraphic> lib = getGraphicalLibrary();

        if (!lib)
            return;
        std::pair<int, int> mousePos = lib->getMousePosition();
        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
        ECS::SparseArray<IComponent> callbacks = reg.get_components<IComponent>("CallBackComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");
        ECS::SparseArray<IComponent> buttonTexturePaths = reg.get_components<IComponent>("ButtonTexturePathComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && callbacks.size() >= entity + 1 && scales.size() >= entity + 1 && buttonTexturePaths.size() >= entity + 1; entity++) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
            std::shared_ptr<CallBackComponent> callback = std::dynamic_pointer_cast<CallBackComponent>(callbacks[entity]);
            std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            std::shared_ptr<ButtonTexturePathComponent> buttonTexturePath = std::dynamic_pointer_cast<ButtonTexturePathComponent>(buttonTexturePaths[entity]);
            if (!position || !textureRect || !callback || !scale || !buttonTexturePath)
                continue;
            if (mousePos.first >= position->x && mousePos.first <= position->x + textureRect->width * scale->scale && mousePos.second >= position->y && mousePos.second <= position->y + textureRect->height * scale->scale) {
                textureRect->path = buttonTexturePath->hoverTexturePath;
                if (lib->isMouseButtonDown(IGraphic::MouseButtons::MOUSE_LEFT))
                    textureRect->path = buttonTexturePath->clickedTexturePath;
                if (lib->isMouseButtonPressed(IGraphic::MouseButtons::MOUSE_LEFT)) {
                    textureRect->path = buttonTexturePath->clickedTexturePath;
                    callback->callback(reg, entity);
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
