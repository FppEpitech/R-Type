/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateShootHandler.cpp
*/

#include <iostream>

#include "AEvent.hpp"
#include "ABIServer.hpp"
#include "CreateShootHandler.hpp"

CreateShootHandler::CreateShootHandler(std::string eventType)
    : AEventHandler("Shoot") {}

bool CreateShootHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {

        if (event->getValues().size() != 3)
            throw CreateShootHandlerError("Event values corrupted.");

        if (ABINetwork::getTypeOfNetwork(networkUnit) != ABINetwork::INetworkUnit::TypeOfNetwork::TYPE_SERVER)
            return true;

        int indexPlayerEntity = std::any_cast<int>(event->getValues()[0]);
        int action = std::any_cast<int>(event->getValues()[1]);
        int shootIdx = std::any_cast<int>(event->getValues()[2]);

        std::vector<std::pair<int, std::variant<int, float, std::string, bool>>> args;

        args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(indexPlayerEntity)));
        args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(action)));
        args.push_back(std::make_pair(ABINetwork::Type::Int, static_cast<int>(shootIdx)));

        ABINetwork::sendUpdateComponent(networkUnit, "ShootSystem", 3, args);

    } catch (const std::exception &e) {
        throw CreateShootHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new CreateShootHandler();
    }
}
