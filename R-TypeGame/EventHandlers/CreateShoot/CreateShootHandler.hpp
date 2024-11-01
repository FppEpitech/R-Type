/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** CreateShootHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class CreateShootHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new CreateShootHandler object
         *
         * @param eventType Event type
         */
        CreateShootHandler(std::string eventType = "");

        /**
         * @brief Destroy the CreateShootHandler object
         *
         */
        ~CreateShootHandler() = default;

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

class CreateShootHandlerError : public AError {

    public:

        /**
         * @brief Construct a new CreateShootHandlerError object
         *
         * @param message Message
         */
        CreateShootHandlerError(std::string message) : AError(message) {}
};
