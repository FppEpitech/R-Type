/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SendRoomInfosHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

#define PATH_JSON_INFO_ROOMS "GameData/Scenes/Menus/Buttons/roomInfosTextBoxSystem.json"
#define SEND_ROOMS_INFOS "SendRoomsInfos"
#define BUTTON_OFFSET 100

typedef struct RoomInfos {
    std::string roomName;
    int nbPlayers;
    int maxPlayers;
    std::string scene;
    bool isPrivate;
} RoomInfos;

class SendRoomInfosHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new SendRoomInfosHandler object
         *
         * @param eventType Event type
         */
        SendRoomInfosHandler(std::string eventType = "");

        /**
         * @brief Destroy the SendRoomInfosHandler object
         *
         */
        ~SendRoomInfosHandler() = default;

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

class SendRoomInfosHandlerError : public AError {

    public:

        /**
         * @brief Construct a new SendRoomInfosHandlerError object
         *
         * @param message Message
         */
        SendRoomInfosHandlerError(std::string message) : AError(message) {}
};
