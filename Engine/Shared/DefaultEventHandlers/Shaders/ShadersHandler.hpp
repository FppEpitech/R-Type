/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShadersHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class ShadersHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new ShadersHandler object
         *
         * @param eventType Event type
         */
        ShadersHandler(std::string eventType = "");

        /**
         * @brief Destroy the ShadersHandler object
         *
         */
        ~ShadersHandler() = default;

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

class ShadersHandlerError : public AError {

    public:

        /**
         * @brief Construct a new ShadersHandlerError object
         *
         * @param message Message
         */
        ShadersHandlerError(std::string message) : AError(message) {}
};
