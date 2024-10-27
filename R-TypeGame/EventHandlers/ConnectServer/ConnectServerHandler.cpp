/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ConnectServerHandler.cpp
*/
#include "ABIClient.hpp"
#include "AEvent.hpp"
#include "ConnectServerHandler.hpp"
#include <iostream>

ConnectServerHandler::ConnectServerHandler(std::string eventType)
    : AEventHandler("ConnectServer") {}

bool ConnectServerHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (networkUnit)
            throw ConnectServerHandlerError("Client already connected to a server");
        if (event->getValues().size() != 3)
            throw ConnectServerHandlerError("Event values corrupted.");

        std::string ipServer = std::any_cast<std::string>(event->getValues()[0]);
        int portTCPServer = std::atoi(std::any_cast<std::string>(event->getValues()[1]).c_str());

        networkUnit = ABINetwork::createClient(ipServer, portTCPServer);
        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, std::any_cast<std::string>(event->getValues()[2]));
        sceneManager->changeScene(scenePair);

        if (!networkUnit)
            throw ConnectServerHandlerError("Failed to connect to the server...");

    } catch (const std::exception &e) {
        throw ConnectServerHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new ConnectServerHandler();
    }
}
