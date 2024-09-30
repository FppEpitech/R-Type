/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** GraphicalLoad
*/

#pragma once

#include <memory>
#include "IGraphic.hpp"
#include "Registry.hpp"

#include "FontComponent.hpp"
#include "Position2DComponent.hpp"
#include "Size1DComponent.hpp"
#include "TextComponent.hpp"

#include <vector>

std::shared_ptr<IGraphic> getGraphicalLibrary();

class loadGraphicalEcs {

    public:

        loadGraphicalEcs() = default;
        ~loadGraphicalEcs() = default;

        void loadInRegister(ECS::Registry registry);

    private:

        std::vector<std::reference_wrapper<IComponent>> _components{
            _fontComponent,
            _position2DComponent,
            _size1DComponent,
            _textComponent
        };

        FontComponent           _fontComponent;
        Position2DComponent     _position2DComponent;
        Size1DComponent         _size1DComponent;
        TextComponent           _textComponent;
};
