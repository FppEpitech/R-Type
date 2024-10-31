/*
** EPITECH PROJECT, 2024
** R-Type game
** File description:
** EntityListComponent
*/

#include "EntityListComponent.hpp"

EntityListComponent::EntityListComponent(std::vector<std::size_t> entities, std::string listType)
    : entities(entities), listType(listType), AComponent("EntityListComponent") {}
