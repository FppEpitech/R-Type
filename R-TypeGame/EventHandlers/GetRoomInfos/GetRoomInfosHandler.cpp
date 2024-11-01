/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GetRoomInfosHandler.cpp
*/

#include "AEvent.hpp"
#include "ABIClient.hpp"
#include "GetRoomInfosHandler.hpp"
#include <iostream>

GetRoomInfosHandler::GetRoomInfosHandler(std::string eventType)
    : AEventHandler("GetRoomsInfos") {}

bool GetRoomInfosHandler::processEvent(std::shared_ptr<IEvent> event,
                                      std::shared_ptr<SceneManager::ISceneManager> sceneManager,
                                      std::shared_ptr<ABINetwork::INetworkUnit> networkUnit,
                                      std::shared_ptr<IGraphic> graphicLib)
{
    try {

        ABINetwork::sendPacketGetRooms(networkUnit);
        ABINetwork::setGetRoomState(networkUnit, ABINetwork::INetworkUnit::GetRoomState::SENT);

    } catch (const std::exception &e) {
        throw GetRoomInfosHandlerError("Error while processing the event: " + std::string(e.what()));
    }
    return true;
}

extern "C" {
    EXPORT_SYMBOL IEventHandler *loadEventHandlerInstance() {
        return new GetRoomInfosHandler();
    }
}
