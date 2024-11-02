/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShaderSystem.cpp
*/

#include <iostream>

#include "ShaderSystem.hpp"
#include "Ecs/Src/Events/AEvent.hpp"

ShaderSystem::ShaderSystem() : ASystem("ShaderSystem") {}

void ShaderSystem::_handleShader(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        std::vector<std::any> ShaderEvent;
        std::shared_ptr<IEvent> event = std::make_shared<AEvent>("ShadersHandler", ShaderEvent);
        reg.addEvent(event);
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new ShaderSystem();
}
}
