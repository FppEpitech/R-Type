/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AEventHandler.cpp
*/

#include "AEventHandler.hpp"

AEventHandler::AEventHandler(std::string eventType)
{
    _eventType = eventType;
}

std::string AEventHandler::getEventType()
{
    return _eventType;
}
