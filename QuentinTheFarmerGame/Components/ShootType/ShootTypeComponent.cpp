/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ShootTypeComponent.cpp
*/

#include "ShootTypeComponent.hpp"

#include <unordered_map>

ShootTypeComponent::ShootTypeComponent(ShootType type) : type(type), AComponent("ShootTypeComponent") {}

ShootTypeComponent::ShootType ShootTypeComponent::getTypeFromString(std::string type)
{
    static const std::unordered_map<std::string, ShootType> shootTypeMap = {
        {"SINGLE", ShootType::SINGLE},
        {"DOUBLE", ShootType::DOUBLE},
        {"TRIPLE", ShootType::TRIPLE},
        {"QUADRUPLE", ShootType::QUADRUPLE},
        {"QUINTUPLE", ShootType::QUINTUPLE},
        {"SEXTUPLE", ShootType::SEXTUPLE}
    };
    auto it = shootTypeMap.find(type);

    if (it == shootTypeMap.end())
        return ShootType::NONE;
    return it->second;
}
