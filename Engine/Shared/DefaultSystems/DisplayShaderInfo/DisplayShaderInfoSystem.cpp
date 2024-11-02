/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** DisplayShaderInfoSystem.cpp
*/

#include <iostream>
#include <chrono>

#include "DisplayShaderInfoSystem.hpp"
#include "Draw/DrawComponent.hpp"
#include "DefaultText/DefaultTextComponent.hpp"

DisplayShaderInfoSystem::DisplayShaderInfoSystem() : ASystem("DisplayShaderInfoSystem") {}

void DisplayShaderInfoSystem::_handlePlaySounds(ECS::Registry &reg, int idxPacketEntities)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        ECS::SparseArray<IComponent> Draw = reg.get_components<IComponent>("DrawComponent");
        ECS::SparseArray<IComponent> DefaultText = reg.get_components<IComponent>("DefaultTextComponent");

        for (ECS::entity_t entity = 0; entity < Draw.size() && entity < DefaultText.size(); entity++) {
            std::shared_ptr<DefaultTextComponent> defaultText = std::dynamic_pointer_cast<DefaultTextComponent>(DefaultText[entity]);
            std::shared_ptr<DrawComponent> draw = std::dynamic_pointer_cast<DrawComponent>(Draw[entity]);
            if (!defaultText || !draw || defaultText->text != "666")
                continue;
            draw->draw = !draw->draw;
        }
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new DisplayShaderInfoSystem();
}
}
