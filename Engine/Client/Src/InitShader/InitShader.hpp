/*
** EPITECH PROJECT, 2024
** InitShader.hpp
** File description:
** DESCRIPTION
*/

#pragma once


#include <iostream>
#include <memory>

#include "IGraphic.hpp"
#include "IError.hpp"

/**
 * @brief System to draw a Shader.
 *
 * The Shader is a program that runs on the GPU.
 * It link with a .fs file.
 * In our game one example of shader is the system to adapt color for the colorblind.
 */
class InitShader {

public:

    /**
     * @brief Exception class for JSON-related errors.
     *
     * This class inherits from the AError class and is used to handle errors
     * related to JSON operations within the InitShader system.
     */
    class JsonError : public AError {
        public:
            /**
             * @brief Construct a new JsonError object.
             *
             * @param message The error message to be associated with this exception.
             */
            JsonError(const std::string &message) : AError(message) {}
    };

    /**
     * @brief Construct a new Draw Shader System object.
     *
     */
    InitShader(std::shared_ptr<IGraphic> graphicLib, std::string settingsPath = "./Config/Settings.json");

    /**
     * @brief Destroy the Draw Shader System object.
     *
     */
    ~InitShader() = default;
};
