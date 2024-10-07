/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClicksSystem.cpp
*/

#include <iostream>

#include "KeyMap.hpp"
#include "ClicksSystem.hpp"
#include "ScaleComponent.hpp"
#include "CallBackComponent.hpp"
#include "Position2DComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "TextureRectComponent.hpp"

ClicksSystem::ClicksSystem() : ASystem("ClicksSystem") {}

void ClicksSystem::_handleClicks(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        std::shared_ptr<IGraphic> lib = getGraphicalLibrary();

        if (!lib)
            return;
        std::pair<int, int> mousePos = lib->getMousePosition();

        ECS::SparseArray<IComponent> positions = reg.get_components<IComponent>("Position2DComponent");
        ECS::SparseArray<IComponent> texturesRect = reg.get_components<IComponent>("TextureRectComponent");
        ECS::SparseArray<IComponent> callbacks = reg.get_components<IComponent>("CallBackComponent");
        ECS::SparseArray<IComponent> scales = reg.get_components<IComponent>("ScaleComponent");

        for (ECS::entity_t entity = 0; positions.size() >= entity + 1 && texturesRect.size() >= entity + 1 && callbacks.size() >= entity + 1 && scales.size() >= entity + 1; entity++) {
            std::shared_ptr<Position2DComponent> position = std::dynamic_pointer_cast<Position2DComponent>(positions[entity]);
            std::shared_ptr<TextureRectComponent> textureRect = std::dynamic_pointer_cast<TextureRectComponent>(texturesRect[entity]);
            std::shared_ptr<CallBackComponent> callback = std::dynamic_pointer_cast<CallBackComponent>(callbacks[entity]);
            std::shared_ptr<ScaleComponent> scale = std::dynamic_pointer_cast<ScaleComponent>(scales[entity]);
            if (!position || !textureRect || !callback || !scale)
                continue;
            if (lib->isMouseButtonPressed(IGraphic::MouseButtons::MOUSE_LEFT) && mousePos.first >= position->x && mousePos.first <= position->x + textureRect->width * scale->scale && mousePos.second >= position->y && mousePos.second <= position->y + textureRect->height * scale->scale)
                callback->callback(reg, entity);
        }
    } catch (std::exception e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

extern "C" ISystem *loadSystemInstance()
{
    return new ClicksSystem();
}