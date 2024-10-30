/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** RegisterHandler.cpp
*/
#include "ABIClient.hpp"
#include "AEvent.hpp"
#include "RegisterHandler.hpp"
#include <iostream>

RegisterHandler::RegisterHandler(std::string eventType)
    : AEventHandler("Register") {}

bool RegisterHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (event->getValues().size() != 3)
            throw RegisterHandlerError("Event values corrupted.");
        if (!networkUnit || networkUnit->getToken() == 0)
            throw RegisterHandlerError("Failed to register, error with the client unit.");
        ABINetwork::sendPacketRegister(networkUnit, std::any_cast<std::string>(event->getValues()[1]), std::any_cast<std::string>(event->getValues()[2]));

        std::string sceneName = std::any_cast<std::string>(event->getValues()[0]);
        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, sceneName);
        sceneManager->changeScene(scenePair);

    } catch (const std::exception &e) {
        throw RegisterHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new RegisterHandler();
    }
}
