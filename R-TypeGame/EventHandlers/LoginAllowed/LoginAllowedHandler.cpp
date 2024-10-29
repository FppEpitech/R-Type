/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** LoginAllowedHandler.cpp
*/
#include "ABIClient.hpp"
#include "AEvent.hpp"
#include "LoginAllowedHandler.hpp"
#include <iostream>

LoginAllowedHandler::LoginAllowedHandler(std::string eventType)
    : AEventHandler("LoginAllowed") {}

bool LoginAllowedHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {

        if (event->getValues().size() != 1)
            throw LoginAllowedHandlerError("Event values corrupted.");
        if (!networkUnit || networkUnit->getToken() == 0)
            throw LoginAllowedHandlerError("Failed to log, error with the client unit.");

        if (ABINetwork::getClientLogin(networkUnit) == ABINetwork::INetworkUnit::LoginState::NONE)
            return false;
        if (ABINetwork::getClientLogin(networkUnit) == ABINetwork::INetworkUnit::LoginState::JUST_FAILED) {
            ABINetwork::setClientLogin(networkUnit, ABINetwork::INetworkUnit::LoginState::NONE);
            return true;
        }

        std::string sceneName = std::any_cast<std::string>(event->getValues()[0]);
        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, sceneName);
        sceneManager->changeScene(scenePair);

        ABINetwork::sendPacketCreateRoom(networkUnit, "name", false, "", false, 4);

    } catch (const std::exception &e) {
        throw LoginAllowedHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new LoginAllowedHandler();
    }
}
