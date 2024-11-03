/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** PlayerDeathHandler.hpp
*/

#pragma once

#include "AEventHandler.hpp"
#include "../Error/AError.hpp"

#define END_SCENE "endScene.json"

class PlayerDeathHandler : public AEventHandler {

    public:

        /**
         * @brief Construct a new PlayerDeathHandler object
         *
         * @param eventType Event type
         */
        PlayerDeathHandler(std::string eventType = "");

        /**
         * @brief Destroy the PlayerDeathHandler object
         *
         */
        ~PlayerDeathHandler() = default;

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

class PlayerDeathHandlerError : public AError {

    public:

        /**
         * @brief Construct a new PlayerDeathHandlerError object
         *
         * @param message Message
         */
        PlayerDeathHandlerError(std::string message) : AError(message) {}
};
