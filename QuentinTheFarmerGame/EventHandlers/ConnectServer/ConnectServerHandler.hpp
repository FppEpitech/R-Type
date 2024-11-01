/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ConnectServerHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class ConnectServerHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new ConnectServerHandler object
         *
         * @param eventType Event type
         */
        ConnectServerHandler(std::string eventType = "");

        /**
         * @brief Destroy the ConnectServerHandler object
         *
         */
        ~ConnectServerHandler() = default;

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

class ConnectServerHandlerError : public AError {

    public:

        /**
         * @brief Construct a new ConnectServerHandlerError object
         *
         * @param message Message
         */
        ConnectServerHandlerError(std::string message) : AError(message) {}
};
