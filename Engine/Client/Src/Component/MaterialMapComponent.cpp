/*
** EPITECH PROJECT, 2024
** MaterialMapComponent.cpp
** File description:
** DESCRIPTION
*/

#include "MaterialMapComponent.hpp"

MaterialMapComponent::MaterialMapComponent(std::vector<std::string> paths,
    std::vector<size_t> indexes, std::vector<MaterialType> types) :
    AComponent("MaterialMapComponent"), MaterialPaths(paths), MaterialIndexes(indexes), MaterialTypes(types) {}
