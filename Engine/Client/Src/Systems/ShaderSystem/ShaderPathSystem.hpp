/*
** EPITECH PROJECT, 2024
** ShaderPathSystem.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>

#include "IComponent.hpp"

/**
 * @class ShaderPathSystem
 * @brief A component class that holds the path to a shader.
 *
 * This class inherits from AComponent and is used to store the path to a shader.
 */
class ShaderPathSystem : public AComponent {
    public:
        /**
         * @brief The path to the shader.
         */
        std::string shaderPath;

        /**
         * @brief Constructor for ShaderPathSystem.
         *
         * @param shaderPath The path to the shader. Defaults to an empty string.
         */
        ShaderPathSystem(std::string shaderPath = "");
};
