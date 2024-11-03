/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootMobHandler.cpp
*/

#include <iostream>

#include "AEvent.hpp"
#include "ABIServer.hpp"
#include "ShootMobHandler.hpp"

ShootMobHandler::ShootMobHandler(std::string eventType)
    : AEventHandler("ShootMob") {}

bool ShootMobHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {

        if (event->getValues().size() != 2)
            throw ShootMobHandlerError("Event values corrupted.");

        if (ABINetwork::getTypeOfNetwork(networkUnit) != ABINetwork::INetworkUnit::TypeOfNetwork::TYPE_SERVER)
            return true;

        int indexPlayerEntity = std::any_cast<int>(event->getValues()[0]);
        int shootIdx = std::any_cast<int>(event->getValues()[1]);

        std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args;

        args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(indexPlayerEntity)));
        args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(shootIdx)));

        ABINetwork::sendUpdateComponent(networkUnit, "ShootMobSystem", 2, args);

    } catch (const std::exception &e) {
        throw ShootMobHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new ShootMobHandler();
    }
}
