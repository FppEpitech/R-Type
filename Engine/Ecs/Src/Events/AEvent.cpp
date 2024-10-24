/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** AEvent.cpp
*/

#include "AEvent.hpp"

AEvent::AEvent(std::string type, std::vector<std::any> values)
{
    _type = type;
    _values = values;
}

std::string AEvent::getEventType() const
{
    return _type;
}

void AEvent::setEventType(std::string type)
{
    _type = type;
}

std::vector<std::any> AEvent::getValues() const
{
    return _values;
}

void AEvent::setValues(std::vector<std::any> values)
{
    _values = values;
}

void AEvent::addValue(std::any value)
{
    _values.push_back(value);
}
