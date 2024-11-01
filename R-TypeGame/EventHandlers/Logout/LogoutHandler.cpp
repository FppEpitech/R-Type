/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LogoutHandler.cpp
*/

#include "ABIClient.hpp"
#include "AEvent.hpp"
#include "LogoutHandler.hpp"
#include <iostream>

LogoutHandler::LogoutHandler(std::string eventType)
    : AEventHandler("Logout") {}

bool LogoutHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        ABINetwork::disconnectToServer(networkUnit);
    } catch (const std::exception &e) {
        throw LogoutHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new LogoutHandler();
    }
}
