/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateRoomHandler.cpp
*/
#include "ABIClient.hpp"
#include "AEvent.hpp"
#include "CreateRoomHandler.hpp"
#include <iostream>

CreateRoomHandler::CreateRoomHandler(std::string eventType)
    : AEventHandler("CreateRoom") {}

bool CreateRoomHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {
        if (event->getValues().size() != 5)
            throw CreateRoomHandlerError("Event values corrupted.");
        if (!networkUnit || networkUnit->getToken() == 0)
            throw CreateRoomHandlerError("Failed to create room, error with the client unit.");

        std::string roomName = std::any_cast<std::string>(event->getValues()[0]);
        std::string roomPassword = std::any_cast<std::string>(event->getValues()[1]);
        int roomMaxPlayer = std::any_cast<int>(event->getValues()[2]);
        bool roomPrivate = std::any_cast<bool>(event->getValues()[3]);
        bool roomCheats = std::any_cast<bool>(event->getValues()[4]);

        if (!roomPrivate)
            roomPassword = "";

        ABINetwork::setCurrentRoomPassword(networkUnit, roomPassword);
        ABINetwork::sendPacketCreateRoom(networkUnit, roomName, roomPrivate, roomPassword, roomCheats, roomMaxPlayer);

    } catch (const std::exception &e) {
        throw CreateRoomHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new CreateRoomHandler();
    }
}
