/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief Macro to define export symbols for different platforms.
 *
 * On Windows, it uses `__declspec(dllexport)` to export symbols.
 * On other platforms, it leaves the symbol definition empty.
 */
#ifdef _WIN32
    #define EXPORT_SYMBOL __declspec(dllexport)
#else
    #define EXPORT_SYMBOL
#endif

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
         * @return std::size_t The key down.
         */
        virtual std::size_t getKeyDownInput() = 0;

        /**
         * @brief Get the Key Pressed Input object.
         *
         * @return std::size_t The key pressed.
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
         * @param r Color value r.
         * @param g Color value g.
         * @param b Color value b.
         * @param a Color value a.
         */
        virtual void drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale, unsigned char r, unsigned char g, unsigned char b, unsigned char a) = 0;

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
            unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255) = 0;

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

        /**
         * @brief Set the list of available resolutions.
         *
         * @param resolutions A vector of pairs where each pair contains the width and height of a resolution.
         */
        virtual void setResolutionList(std::vector<std::pair<int, int>> resolutions) = 0;

        /**
         * @brief Set the resolution of the window.
         *
         * @param width The width of the window.
         * @param height The height of the window.
         */
        virtual void setResolution(int width, int height) = 0;

        /**
         * @brief Set the window to fullscreen or windowed mode.
         *
         */
        virtual void setFullscreen() = 0;

        /**
         * @brief Change the resolution of the window.
         *
         * @param width The width of the window.
         * @param height The height of the window.
         */
        virtual void changeResolution(int width, int height) = 0;

        /**
         * @brief Toggle the fullscreen mode of the window.
         */
        virtual void changeFullscreen() = 0;

        /**
         * @brief Get the size of an object with the window size.
         *
         * @param width Width of the object.
         * @param height Height of the object.
         * @return new size of the object.
         */
        virtual std::pair<float, float> getSizeWithWindow(float width, float height) = 0;

        /**
         * @brief Get the scale of an object with the window size.
         *
         * @param scale Scale of the object.
         * @return new scale of the object.
         */
        virtual float getScaleWithWindow(float scale) = 0;

        /**
         * @brief Close the window.
         *
         * @return true Window closed.
         * @return false Window open.
         */
        virtual bool closeWindow() = 0;

        /**
         * @brief Play music from the specified file path.
         *
         * @param path Path to the music file to play.
         */
        virtual void playMusic(std::string path) = 0;

        /**
         * @brief Update the music.
        */
        virtual void updateMusic() = 0;

        /**
         * @brief Play a sound
         *
         * @param path Path to the sound file to play.
         */
        virtual void playSound(std::string path) = 0;
};
