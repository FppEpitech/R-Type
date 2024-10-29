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
        if (event->getValues().size() != 3)
            throw ConnectServerHandlerError("Event values corrupted.");

        std::string ipServer = std::any_cast<std::string>(event->getValues()[0]);
        int portTCPServer = std::atoi(std::any_cast<std::string>(event->getValues()[1]).c_str());

        try {
            if (!networkUnit || !ABINetwork::connectToServer(networkUnit, ipServer, portTCPServer))
                return true;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return true;
        }
        std::pair<std::size_t, std::string> scenePair = std::make_pair(0, std::any_cast<std::string>(event->getValues()[2]));
        sceneManager->changeScene(scenePair);


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
