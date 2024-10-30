/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GetRoomInfosHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

#define SEND_ROOMS_INFOS "SendRoomsInfos"

class GetRoomInfosHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new GetRoomInfosHandler object
         *
         * @param eventType Event type
         */
        GetRoomInfosHandler(std::string eventType = "");

        /**
         * @brief Destroy the GetRoomInfosHandler object
         *
         */
        ~GetRoomInfosHandler() = default;

        /**
         * @brief Process the event
         *
         * @param event Event to process
         * @param sceneManager Scene manager
         * @param networkUnit Network unit
         * @param graphicLib Graphic library
         * @return true if the event has been processed
         * @return false if the event has not been processed
         */
        bool processEvent(std::shared_ptr<IEvent> event, std::shared_ptr<SceneManager::ISceneManager> sceneManager, std::shared_ptr<ABINetwork::INetworkUnit> networkUnit, std::shared_ptr<IGraphic> graphicLib) override;
};

class GetRoomInfosHandlerError : public AError {

    public:

        /**
         * @brief Construct a new GetRoomInfosHandlerError object
         *
         * @param message Message
         */
        GetRoomInfosHandlerError(std::string message) : AError(message) {}
};
