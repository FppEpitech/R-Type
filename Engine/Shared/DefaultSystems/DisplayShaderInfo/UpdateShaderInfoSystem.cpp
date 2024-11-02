/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** UpdateShaderInfoSystem.cpp
*/

#include <iostream>

#include "UpdateShaderInfoSystem.hpp"
#include "Ecs/Src/Events/AEvent.hpp"

UpdateShaderInfoSystem::UpdateShaderInfoSystem() : ASystem("UpdateShaderInfoSystem") {}

void UpdateShaderInfoSystem::_handleUpdateShaderInfo(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        std::vector<std::any> UpdateShaderInfoEvent;
        std::shared_ptr<IEvent> event = std::make_shared<AEvent>("DefaultUpdateShaderInfo", UpdateShaderInfoEvent);
        reg.addEvent(event);
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new UpdateShaderInfoSystem();
}
}
