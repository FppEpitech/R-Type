/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** UpdateShaderInfoHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class UpdateShaderInfoHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new UpdateShaderInfoHandler object
         *
         * @param eventType Event type
         */
        UpdateShaderInfoHandler(std::string eventType = "");

        /**
         * @brief Destroy the UpdateShaderInfoHandler object
         *
         */
        ~UpdateShaderInfoHandler() = default;

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

class UpdateShaderInfoHandlerError : public AError {

    public:

        /**
         * @brief Construct a new UpdateShaderInfoHandlerError object
         *
         * @param message Message
         */
        UpdateShaderInfoHandlerError(std::string message) : AError(message) {}
};
