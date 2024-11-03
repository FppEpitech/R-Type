/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlaySoundsHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class PlaySoundsHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new PlaySoundsHandler object
         *
         * @param eventType Event type
         */
        PlaySoundsHandler(std::string eventType = "");

        /**
         * @brief Destroy the PlaySoundsHandler object
         *
         */
        ~PlaySoundsHandler() = default;

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

class PlaySoundsHandlerError : public AError {

    public:

        /**
         * @brief Construct a new PlaySoundsHandlerError object
         *
         * @param message Message
         */
        PlaySoundsHandlerError(std::string message) : AError(message) {}
};
