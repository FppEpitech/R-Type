/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** FullScreenSystem.cpp
*/

#include <iostream>

#include "FullScreenSystem.hpp"
#include "Ecs/Src/Events/AEvent.hpp"

FullScreenSystem::FullScreenSystem() : ASystem("FullScreenSystem") {}

void FullScreenSystem::_handleFullScreen(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        std::vector<std::any> FullScreenEvent;
        std::shared_ptr<IEvent> event = std::make_shared<AEvent>("FullScreenHandler", FullScreenEvent);
        reg.addEvent(event);
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new FullScreenSystem();
}
}
