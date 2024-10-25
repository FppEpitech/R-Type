/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AEventHandler.hpp
*/

#pragma once

#include "IEventHandler.hpp"

class AEventHandler : public IEventHandler {

    public:

        /**
         * @brief Construct a new AEventHandler object
         *
         * @param eventType Event type
         */
        AEventHandler(std::string eventType = "");

        /**
         * @brief Destroy the AEventHandler object
         *
         */
        ~AEventHandler() = default;

        /**
         * @brief Get the Event Type object
         *
         * @return std::string
         */
        std::string getEventType() override;

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
        virtual bool processEvent(std::shared_ptr<IEvent> event, std::shared_ptr<SceneManager::ISceneManager> sceneManager, std::shared_ptr<ABINetwork::INetworkUnit> networkUnit, std::shared_ptr<IGraphic> graphicLib) override = 0;

    protected:

        std::string _eventType;
};
