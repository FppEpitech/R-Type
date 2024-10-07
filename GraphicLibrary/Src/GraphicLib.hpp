/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#pragma once

#include "raylib.h"
#include "IError.hpp"
#include "IGraphic.hpp"

#include <vector>
#include <iostream>
#include <unordered_map>

/**
 * @brief Raylib graphical library.
 *  This library will be compile into a .so file
 *  to be use in our gameEngine.
 *
 */
class GraphicLib : public IGraphic {

    public:

        /**
         * @brief Exception class for handling errors related to the current shader name.
         */
        class WrongCurrentShaderName : public AError {
            public:
                /**
                 * @brief Construct a new WrongCurrentShaderName exception.
                 *
                 * @param message The error message.
                 */
                WrongCurrentShaderName(const std::string &message) : AError(message) {}
        };

        /**
         * @brief Exception class for handling errors related to loading shaders.
         */
        class LoadShaderError : public AError {
            public:
                /**
                 * @brief Construct a new LoadShaderError exception.
                 *
                 * @param message The error message.
                 */
                LoadShaderError(const std::string &message) : AError(message) {}
        };

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
         * @brief Get the Key Down Input object.
         *
         * @return KEY_MAP The key down.
         */
        std::size_t getKeyDownInput();

        /**
         * @brief Get the Key Pressed Input object.
         *
         * @return KEY_MAP The key pressed.
         */
        std::size_t getKeyPressedInput();

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
         * @param texturePath Path to the Texture to draw.
         * @param posx Position x
         * @param posy Position y
         * @param scale Scale.
         */
        void drawTexture(std::string texturePath, float posx, float posy, float scale);

        /**
         * @brief Draw a texture rect on the screen.
         *
         * @param texturePath Path to the Texture to draw.
         * @param posx Position x.
         * @param posy Position y.
         * @param left Left coordinate of the rectangle.
         * @param top Top coordinate of the rectangle.
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         * @param scale Scale.
         */
        void drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale);

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
         * @brief Initialize shaders with a map of shader names and paths.
         *
         * @param shaders A map where the key is the shader name and the value is the shader path.
         */
        void initShaderWithMap(std::unordered_map<std::string, std::string> shaders);

        /**
         * @brief Initialize the current shader by name.
         *
         * @param name The name of the shader to initialize.
         */
        void initCurrentShader(std::string name);

        /**
         * @brief Initialize the intensity of the shader.
         *
         * @param intensity The intensity value to set for the shader.
         */
        void initShaderIntensity(float intensity);

        /**
         * @brief Change the current shader by name.
         *
         * @param name The name of the shader to change to.
         */
        void changeCurrentShader(std::string name);

        /**
         * @brief Change the intensity of the current shader.
         *
         * @param intensity The new intensity value for the shader.
         */
        void changeShaderIntensity(float intensity);

        /**
         * @brief Reset the current shader to its default state.
         */
        void resetShader();

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

        /**
         * @brief Get the Window Size object.
         *
         * @return std::pair<int, int> Width and Height.
         */
        std::pair<int, int> getWindowSize();

        /**
         * @brief Get the Mouse Position object.
         *
         * @return std::pair<int, int> Mouse position.
         */
        std::pair<int, int> getMousePosition();

        /**
         * @brief Checks if the mouse button is pressed.
         *
         * @param button The button to check.
         * @return true The button is pressed.
         * @return false The button is not pressed.
         */
        bool isMouseButtonPressed(MouseButtons button);

        /**
         * @brief Checks if the mouse button is down.
         *
         * @param button The button to check.
         * @return true The button is down.
         * @return false The button is not down.
         */
        bool isMouseButtonDown(MouseButtons button);

    private:

        /**
         * @brief Check if the shader is ready.
         *
         * The function will check if the @var _currentShader is none or not.
         * @return true The shader is ready.
         */
        bool _isShaderReady();

        Camera                                      _camera;        //< Player camera.
        std::unordered_map<std::string, Model>      _models;        //< List of Models loaded.
        std::unordered_map<std::string, Texture2D>  _textures;      //< List textures loaded.
        std::unordered_map<std::string, Font>       _font;          //< List of Font loaded.
        std::unordered_map<std::string, Shader>     _shaders;       //< List of Shaders loaded.
        std::string                                 _currentShader; //< Current shader.
};
