/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** MoveEntityHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class MoveEntityHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new MoveEntityHandler object
         *
         * @param eventType Event type
         */
        MoveEntityHandler(std::string eventType = "");

        /**
         * @brief Destroy the MoveEntityHandler object
         *
         */
        ~MoveEntityHandler() = default;

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

class MoveEntityHandlerError : public AError {

    public:

        /**
         * @brief Construct a new MoveEntityHandlerError object
         *
         * @param message Message
         */
        MoveEntityHandlerError(std::string message) : AError(message) {}
};
