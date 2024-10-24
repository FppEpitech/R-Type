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
    std::queue<std::shared_ptr<IEvent>> events = _registry->getEventQueue();
    while (!_registry->getEventQueue().empty()) {
        processEvent(events.front());
        _registry->popEvent();
    }
}

void EventListener::setSceneManager(std::shared_ptr <SceneManager::ISceneManager> sceneManager)
{
    _sceneManager = sceneManager;
}

void EventListener::processEvent(std::shared_ptr<IEvent> event)
{
    if (_eventHandlers.find(event->getEventType()) != _eventHandlers.end())
        _eventHandlers[event->getEventType()]->processEvent(event, _sceneManager, _networkUnit, _graphicLib);
}
