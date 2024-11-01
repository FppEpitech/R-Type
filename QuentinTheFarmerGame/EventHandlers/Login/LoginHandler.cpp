/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginHandler.cpp
*/
#include "ABIClient.hpp"
#include "AEvent.hpp"
#include "LoginHandler.hpp"
#include <iostream>

LoginHandler::LoginHandler(std::string eventType)
    : AEventHandler("Login") {}

bool LoginHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (event->getValues().size() != 2)
            throw LoginHandlerError("Event values corrupted.");
        if (!networkUnit || networkUnit->getToken() == 0)
            throw LoginHandlerError("Failed to log, error with the client unit.");

        ABINetwork::sendPacketLogin(networkUnit, std::any_cast<std::string>(event->getValues()[0]), std::any_cast<std::string>(event->getValues()[1]));

    } catch (const std::exception &e) {
        throw LoginHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new LoginHandler();
    }
}
