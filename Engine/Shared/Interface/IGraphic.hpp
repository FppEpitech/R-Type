/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <unordered_map>

/**
 * @class IGraphic
 * @brief Interface for the graphic module.
 *
 * All graphic modules must implement this interface.
 * The graphic module is responsible for rendering the game.
 * It must be able to initialize, update, and destroy itself.
 * The graphic module must be able to render the game.
 */
class IGraphic {
    public:

        /**
         * @brief Enum for the Mouse button inputs.
         *
         */
        enum MouseButtons {
            MOUSE_LEFT = 0,
            MOUSE_RIGHT = 1,
            MOUSE_MIDDLE = 2
        };

        /**
         * @brief Virtual destructor for IGraphic.
         */
        virtual ~IGraphic() = default;

        /**
         * @brief Initialize the graphic module.
         */
        virtual void init(const std::string &windowName) = 0;

        /**
         * @brief check if the window is open/close.
         *
         * @return true Window open.
         * @return false Window closed.
         */
        virtual bool windowIsOpen() = 0;

        /**
         * @brief Clear the window.
         *
         */
        virtual void clear() = 0;

        /**
         * @brief Get the Key Down Input object.
         *
         * @return int The key down.
         */
        virtual std::size_t getKeyDownInput() = 0;

        /**
         * @brief Get the Key Pressed Input object.
         *
         * @return int The key pressed.
         */
        virtual std::size_t getKeyPressedInput() = 0;

        /**
         * @brief Draw an OBJ model on the screen.
         *
         * @param objPath Path to the OBJ Model to draw.
         */

        /**
         * @brief Draw an OBJ model on the screen.
         *
         * @param objPath Path to the OBJ Model to draw.
         * @param posx Position x
         * @param posy Position y
         * @param posz Position z
         * @param scale Scale.
         */
        virtual void drawOBJ(std::string objPath, float posx, float posy, float posz, float scale) = 0;

        /**
         * @brief Draw a texture on the screen.
         *
         * @param texturePath Path to the Texture to draw.*
         * @param posx Position x
         * @param posy Position y
         * @param scale Scale.
         */
        virtual void drawTexture(std::string texturePath, float posx, float posy, float scale) = 0;

        /**
         * @brief Draw a texture rect on the screen.
         *
         * @param texturePath Path to the Texture to draw.*
         * @param posx Position x.
         * @param posy Position y.
         * @param left Left coordinate of the rectangle.
         * @param top Top coordinate of the rectangle.
         * @param width Width of the rectangle.
         * @param height Height of the rectangle.
         * @param scale Scale.
         */
        virtual void drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale) = 0;

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
        virtual void drawText(std::string text, float posx, float posy, int fontSize, std::string fontPath,
            unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0) = 0;

        /**
         * @brief Initialize shaders with a map of shader names and paths.
         *
         * @param shaders A map where the key is the shader name and the value is the shader path.
         */
        virtual void initShaderWithMap(std::unordered_map<std::string, std::string> shaders) = 0;

        /**
         * @brief Initialize the current shader by name.
         *
         * @param name The name of the shader to initialize.
         */
        virtual void initCurrentShader(std::string name) = 0;

        /**
         * @brief Initialize the intensity of the shader.
         *
         * @param intensity The intensity value to set for the shader.
         */
        virtual void initShaderIntensity(float intensity) = 0;

        /**
         * @brief Change the current shader by name.
         *
         * @param name The name of the shader to change to.
         */
        virtual void changeCurrentShader(std::string name) = 0;

        /**
         * @brief Change the intensity of the current shader.
         *
         * @param intensity The new intensity value for the shader.
         */
        virtual void changeShaderIntensity(float intensity) = 0;

        /**
         * @brief Reset the current shader to its default state.
         */
        virtual void resetShader() = 0;

        /**
         * @brief Start to draw on the window.
         * Must be call at the begin of the Game loop.
         *
         */
        virtual void startDraw() = 0;

        /**
         * @brief End to draw on the window.
         * Must be call at the end of the Game loop.
         *
         */
        virtual void endDraw() = 0;

        /**
         * @brief Get the Window Size object.
         *
         * @return std::pair<int, int> Width and Height.
         */
        virtual std::pair<int, int> getWindowSize() = 0;

        /**
         * @brief Get the Mouse Position object.
         *
         * @return std::pair<int, int> Mouse position.
         */
        virtual std::pair<int, int> getMousePosition() = 0;

        /**
         * @brief Checks if the mouse button is pressed.
         *
         * @param button MouseButtons that you want to check.
         * @return true Mouse button is pressed.
         * @return false Mouse button is not pressed.
         */
        virtual bool isMouseButtonPressed(MouseButtons button) = 0;

        /**
         * @brief Checks if the mouse button is down.
         *
         * @param button MouseButtons that you want to check.
         * @return true Mouse button is down.
         * @return false Mouse button is not down.
         */
        virtual bool isMouseButtonDown(MouseButtons button) = 0;
};
