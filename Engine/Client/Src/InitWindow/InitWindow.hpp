/*
** EPITECH PROJECT, 2024
** InitWindow.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <iostream>
#include <memory>
#include <json/json.h>
#include <unordered_map>
#include <fstream>

#include "../GetGraphicalLibrary/IGraphic.hpp"
#include "../../../Error/IError.hpp"


/**
 * @brief System to initialize the window.
 *
 * This system is used to initialize the window of the game.
 * It reads the settings from a JSON file and sets the window accordingly.
 */
class InitWindow {
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
     * @brief Construct a new InitWindow object.
     *
     * @param graphicLib A shared pointer to an IGraphic object.
     * @param settingsPath The path to the settings JSON file. Defaults to "./Config/Settings.json".
     */
    InitWindow(std::shared_ptr<IGraphic> graphicLib, std::string settingsPath = "./Config/Settings.json");

    /**
     * @brief Destroy the InitWindow object.
     */
    ~InitWindow() = default;
};
