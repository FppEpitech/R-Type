/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MapEditorButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "../AButton/AButtonInitSystem.hpp"
#include "../../../../../Engine/Client/Src/GetGraphicalLibrary/GetGraphicalLibrary.hpp"
#include "MapEditorButtonInitSystem.hpp"

MapEditorButtonInitSystem::MapEditorButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    try {
    } catch (const std::exception& e) {
    }
}

void MapEditorButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new MapEditorButtonInitSystem();
    }
}
