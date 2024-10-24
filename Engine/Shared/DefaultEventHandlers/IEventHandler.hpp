/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** IEventHandler.hpp
*/

#pragma once

#include <memory>

#include "../../Ecs/Src/Events/IEvent.hpp"
#include "../SceneManager/ISceneManager.hpp"
#include "../../../Network/Units/INetworkUnit.hpp"
#include "../../../Client/Src/GetGraphicalLibrary/IGraphic.hpp"

/**
 * @brief Interface for the event handler.
 */
class IEventHandler {

    public:

        /**
         * @brief Destroy the IEventHandler object.
         */
        virtual ~IEventHandler() = default;

        /**
         * @brief Get the event type that the handler can process.
         *
         * @return Event type.
         * @note The event type should be the same as the event type that the handler can process.
         */
        virtual std::string getEventType() = 0;

        /**
         * @brief Process the event.
         * @param event Event to process.
         * @param sceneManager Scene manager to use.
         * @param networkUnit Network unit to use.
         * @param graphicalLibrary Graphical library to use.
         * @return true if the event has been processed, false otherwise.
         * @note If the event is processed by the server, the graphicalLibrary will be nullptr.
         */
        virtual bool processEvent(std::shared_ptr<IEvent> event, std::shared_ptr<SceneManager::ISceneManager> sceneManager, std::shared_ptr<ABINetwork::INetworkUnit> networkUnit, std::shared_ptr<IGraphic> graphicalLibrary) = 0;
};
