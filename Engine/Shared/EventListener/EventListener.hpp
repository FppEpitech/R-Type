/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** EventListener.hpp
*/

#pragma once

#include "../../Error/AError.hpp"
#include "../Client/Src/GetGraphicalLibrary/IGraphic.hpp"
#include "Registry.hpp"
#include "../../Network/Units/INetworkUnit.hpp"
#include "ISceneManager.hpp"
#include "IEventHandler.hpp"

class EventListener {

    public:

        /**
         * @brief Construct a new EventListener object
         *
         * @param sceneManager The scene manager
         * @param networkUnit The network unit
         * @param graphicLib The graphic library
         * @note If the instance of the EventListener is in the server side, the graphicLib parameter will be nullptr
         */
        EventListener(std::shared_ptr<ECS::Registry> registry, std::shared_ptr<SceneManager::ISceneManager> sceneManager, std::shared_ptr<ABINetwork::INetworkUnit> networkUnit, std::shared_ptr<IGraphic> graphicLib);

        /**
         * @brief Destroy the EventListener object
         *
         */
        ~EventListener() = default;

        /**
         * @brief Add an event handler to the listener.
         *
         * @param eventType The type of the event
         * @param event The event handler
         */
        void addHandler(const std::string &eventType, std::shared_ptr<IEventHandler> event);

        /**
         * @brief Clear all the handlers of the listener.
         *
         */
        void clearHandlers();

        /**
         * @brief Remove all the handlers of a specific event type.
         *
         * @param eventType The type of the event
         */
        void removeHandler(const std::string &eventType);

        /**
         * @brief Listen to the event queue and process the events.
         *
         */
        void listen();

        /**
         * @brief Set the scene manager.
         *
         * @param sceneManager The scene manager
         */
        void setSceneManager(std::shared_ptr<SceneManager::ISceneManager> sceneManager);

    protected:

        std::shared_ptr<ECS::Registry>                                  _registry; // Registries to get the event queue
        std::shared_ptr<SceneManager::ISceneManager>                    _sceneManager; // The scene manager
        std::shared_ptr<ABINetwork::INetworkUnit>                       _networkUnit; // The network unit
        std::shared_ptr<IGraphic>                                       _graphicLib; // The graphic library

        std::unordered_map<std::string, std::shared_ptr<IEventHandler>> _eventHandlers; // The event handlers


        /**
         * @brief Process an event.
         *
         * @param event The event to process
         */
        void processEvent(std::shared_ptr<IEvent> event);
};

class EventListenerErrors : public AError {
    public:
        EventListenerErrors(const std::string &message) : AError(message) {}
};
