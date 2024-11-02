/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SinglePlayerHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class SinglePlayerHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new SinglePlayerHandler object
         *
         * @param eventType Event type
         */
        SinglePlayerHandler(std::string eventType = "");

        /**
         * @brief Destroy the SinglePlayerHandler object
         *
         */
        ~SinglePlayerHandler() = default;

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

class SinglePlayerHandlerError : public AError {

    public:

        /**
         * @brief Construct a new SinglePlayerHandlerError object
         *
         * @param message Message
         */
        SinglePlayerHandlerError(std::string message) : AError(message) {}
};
