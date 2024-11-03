/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** HitBoxUpdateHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

class HitBoxUpdateHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new HitBoxUpdateHandler object
         *
         * @param eventType Event type
         */
        HitBoxUpdateHandler(std::string eventType = "");

        /**
         * @brief Destroy the HitBoxUpdateHandler object
         *
         */
        ~HitBoxUpdateHandler() = default;

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

class HitBoxUpdateHandlerError : public AError {

    public:

        /**
         * @brief Construct a new HitBoxUpdateHandlerError object
         *
         * @param message Message
         */
        HitBoxUpdateHandlerError(std::string message) : AError(message) {}
};
