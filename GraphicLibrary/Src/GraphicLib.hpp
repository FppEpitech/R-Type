/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#pragma once

#include "../../Engine/Shared/Interface/IGraphic.hpp"
#include "../../build/vcpkg_installed/x64-linux/include/raylib.h"

#include <iostream>

/**
 * @brief Raylib graphical library.
 *  This library will be compile into a .so file
 *  to be use in our gameEngine.
 *
 */
class GraphicLib : public IGraphic {

    public:

        /**
         * @brief Construct a new Graphic Lib object.
         *
         */
        GraphicLib() = default;

        /**
         * @brief Destroy the Graphic Lib object.
         *
         */
        ~GraphicLib();

        /**
         * @brief Init the graphic library/window.
         *
         * @param windowName Name of the window.
         */
        void init(const std::string &windowName);

        /**
         * @brief Check if the window is open.
         *
         * @return true The window is open.
         * @return false The window is closed.
         */
        bool windowIsOpen();

        /**
         * @brief Clear the window.
         *
         */
        void clear();

        /**
         * @brief Get the Key Input object.
         *
         * @return KEY_MAP The key pressed.
         */
        std::size_t getKeyInput();
};
