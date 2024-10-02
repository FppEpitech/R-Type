/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#pragma once

#include "IGraphic.hpp"
#include "raylib.h"

#include <unordered_map>
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
         * @return false The window is closed.                                     /
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

        /**
         * @brief Draw an OBJ model on the screen.
         *
         * @param objPath Path to the OBJ Model to draw.
         * @param posx Position x
         * @param posy Position y
         * @param posz Position z
         * @param scale Scale.
         */
        void drawOBJ(std::string objPath, float posx, float posy, float posz, float scale);

        /**
         * @brief Draw a texture on the screen.
         *
         * @param texturePath Path to the Texture to draw.*
         * @param posx Position x
         * @param posy Position y
         * @param scale Scale.
         */
        void drawTexture(std::string texturePath, float posx, float posy, float scale);

        /**
         * @brief Draw a text on the screen.
         *
         * @param text Text to draw.
         * @param posx Position x.
         * @param posy Position y.
         * @param fontSize Font size.
         * @param fontPath Font path.
         * @param r Color value r.
         * @param g Color value g.
         * @param b Color value b.
         * @param a Color value a.
         */
        void drawText(std::string text, float posx, float posy, int fontSize, std::string fontPath,
            unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0);

        /**
         * @brief Start to draw on the window.
         * Must be call at the begin of the Game loop.
         *
         */
        void startDraw();

        /**
         * @brief End to draw on the window.
         * Must be call at the end of the Game loop.
         *
         */
        void endDraw();

    private:

        Camera                                      _camera;        //< Player camera.
        std::unordered_map<std::string, Model>      _models;        //< List of Models loaded.
        std::unordered_map<std::string, Texture2D>  _textures;      //< List textures loaded.
        std::unordered_map<std::string, Font>       _font;          //< List of Font loaded.
};
