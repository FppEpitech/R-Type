/*
** EPITECH PROJECT, 2024
** ShaderPathComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>

#include "IComponent.hpp"

/**
 * @class ShaderPathComponent
 * @brief A component class that holds the path to a shader.
 *
 * This class inherits from AComponent and is used to store the path to a shader.
 */
class ShaderPathComponent : public AComponent {
    public:
        /**
         * @brief The path to the shader.
         */
        std::string shaderPath;

        /**
         * @brief Constructor for ShaderPathComponent.
         *
         * @param shaderPath The path to the shader. Defaults to an empty string.
         */
        ShaderPathComponent(std::string shaderPath = "");
};
