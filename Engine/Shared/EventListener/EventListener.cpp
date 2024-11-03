/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** EventListener.cpp
*/

#include <iostream>

#include "EventListener.hpp"

EventListener::EventListener(std::shared_ptr<ECS::Registry> registry,
                             std::shared_ptr <SceneManager::ISceneManager> sceneManager,
                             std::shared_ptr <ABINetwork::INetworkUnit> networkUnit,
                             std::shared_ptr <IGraphic> graphicLib)
{
    _registry = registry;
    _sceneManager = sceneManager;
    _networkUnit = networkUnit;
    _graphicLib = graphicLib;
    if (_registry == nullptr)
        throw EventListenerErrors("Error: registry is null");
    // TODO: Uncomment this when the networkUnit is implemented
    //if (_networkUnit == nullptr)
       // throw EventListenerErrors("Error: networkUnit is null");
}

void EventListener::addHandler(const std::string &eventType, std::shared_ptr <IEventHandler> event)
{
    _eventHandlers[eventType] = event;
}

void EventListener::clearHandlers()
{
    _eventHandlers.clear();
}

void EventListener::removeHandler(const std::string &eventType)
{
    _eventHandlers.erase(eventType);
}

void EventListener::listen()
{
    while (!_registry->getEventQueue().empty()) {
        if (!processEvent(_registry->getEventQueue().front()))
            break;
        _registry->popEvent();
    }
}

void EventListener::setSceneManager(std::shared_ptr <SceneManager::ISceneManager> sceneManager)
{
    _sceneManager = sceneManager;
}

void EventListener::setNetworkUnit(std::shared_ptr <ABINetwork::INetworkUnit> networkUnit)
{
    _networkUnit = networkUnit;
}

bool EventListener::processEvent(std::shared_ptr<IEvent> event)
{
    if (_eventHandlers.find(event->getEventType()) != _eventHandlers.end()) {
        try {
            return _eventHandlers[event->getEventType()]->processEvent(event, _sceneManager, _networkUnit, _graphicLib);
        } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }
    return true;
}
