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

#include "Position2DComponent.hpp"
#include "Size1DComponent.hpp"
#include "TextComponent.hpp"

#include <vector>

/**
 * @brief Get the Graphical Library object.
 *
 * @return std::shared_ptr<IGraphic>
 */
std::shared_ptr<IGraphic> getGraphicalLibrary();

/**
 * @brief This class aim to load graphical systems and components in a register.
 *
 */
class loadGraphicalEcs {

    public:

        /**
         * @brief Construct a new load Graphical Ecs object.
         *
         */
        loadGraphicalEcs() = default;

        /**
         * @brief Destroy the load Graphical Ecs object.
         *
         */
        ~loadGraphicalEcs() = default;

        /**
         * @brief Load all graphical systems and components int a register.
         *
         * @param registry Register to fill with systems ad components.
         */
        void loadInRegister(ECS::Registry registry);

    private:

        std::vector<std::reference_wrapper<IComponent>> _components {
            _position2DComponent,
            _size1DComponent,
            _textComponent
        }; //< List of graphical components.

        Position2DComponent     _position2DComponent;   //< Position 2D component.
        Size1DComponent         _size1DComponent;       //< Size 1D component.
        TextComponent           _textComponent;         //< Text component.
};
