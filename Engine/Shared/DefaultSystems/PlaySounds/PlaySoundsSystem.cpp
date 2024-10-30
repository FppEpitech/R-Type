/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlaySoundsSystem.cpp
*/

#include <iostream>

#include "PlaySoundsSystem.hpp"
#include "ClickableComponent.hpp"
#include "GetGraphicalLibrary.hpp"
#include "AEvent.hpp"

PlaySoundsSystem::PlaySoundsSystem() : ASystem("PlaySoundsSystem") {}

void PlaySoundsSystem::_handlePlaySounds(ECS::Registry &reg, int idxPacketEntities)
{
    try {
        std::vector<std::any> soundsEvent;
        std::shared_ptr<IEvent> event = std::make_shared<AEvent>("PlaySounds", soundsEvent);
        reg.addEvent(event);
    } catch (std::exception e) {
    }
}

extern "C" {
EXPORT_SYMBOL ISystem* loadSystemInstance() {
    return new PlaySoundsSystem();
}
}
