/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ExitButtonInitSystem.cpp
*/

#include <fstream>
#include <iostream>
#include <json/json.h>

#include "AButtonInitSystem.hpp"
#include "GetGraphicalLibrary.hpp"
#include "ExitButtonInitSystem.hpp"

ExitButtonInitSystem::ExitButtonInitSystem() :
    ASystem("ButtonInitSystem") {}

static void handleThis(ECS::Registry& reg, int idxPacketEntities)
{
    try {
        std::shared_ptr<IGraphic> lib = getGraphicalLibrary();

        lib->closeWindow();
    } catch (const std::exception& e) {
    }
}

static void handleOther(ECS::Registry& reg, int idxPacketEntities)
{
}

void ExitButtonInitSystem::_initButton(ECS::Registry& reg, int idxPacketEntities)
{
    std::function<void(ECS::Registry& reg, int idxPacketEntities)> callback = [](ECS::Registry& reg, int idxPacketEntities) {
        handleThis(reg, idxPacketEntities);
        handleOther(reg, idxPacketEntities);
    };

    this->_setButtonProperties(reg, idxPacketEntities, PATH_JSON, callback);
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new ExitButtonInitSystem();
    }
}
