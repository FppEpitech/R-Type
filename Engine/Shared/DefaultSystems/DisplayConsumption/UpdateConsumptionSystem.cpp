/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** UpdateConsumptionSystem.cpp
*/

#include <iostream>

#include "UpdateConsumptionSystem.hpp"
#include "Ecs/Src/Events/AEvent.hpp"

UpdateConsumptionSystem::UpdateConsumptionSystem() : ASystem("UpdateConsumptionSystem") {}

void UpdateConsumptionSystem::_handleUpdateConsumption(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        std::vector<std::any> UpdateConsumptionEvent;
        std::shared_ptr<IEvent> event = std::make_shared<AEvent>("DefaultUpdateConsumption", UpdateConsumptionEvent);
        reg.addEvent(event);
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new UpdateConsumptionSystem();
}
}
