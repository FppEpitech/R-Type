/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#include "GraphicalLoad.hpp"

void LoadGraphicalEcs::loadInRegister(ECS::Registry registry)
{
    for (auto& component : _components)
        registry.register_component<IComponent>(component.get().getType());
}
