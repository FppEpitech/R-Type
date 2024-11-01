/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** JoinRoomHandler.cpp
*/

#include "AEvent.hpp"
#include "ABIClient.hpp"
#include "JoinRoomHandler.hpp"
#include <iostream>

JoinRoomHandler::JoinRoomHandler(std::string eventType)
    : AEventHandler("JoinRoom") {}

bool JoinRoomHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (event->getValues().size() != 2)
            throw JoinRoomHandlerError("Event values corrupted.");

        std::string name = std::any_cast<std::string>(event->getValues()[0]);
        std::string password = std::any_cast<std::string>(event->getValues()[1]);

        ABINetwork::sendPacketJoinRoom(networkUnit, name, password);

    } catch (const std::exception &e) {
        throw JoinRoomHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new JoinRoomHandler();
    }
}
