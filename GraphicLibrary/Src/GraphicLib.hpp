/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#pragma once

#include "raylib.h"
#include "../Error/AError.hpp"
#include "IGraphic.hpp"

#include <vector>
#include <iostream>
#include <unordered_map>

#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080

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
         * @brief Exception class set a wrong resolution.
        */
        class ResolutionError : public AError {
        public:
            /**
             * @brief Construct a new ResolutionError exception.
             *
             * @param message The error message.
            */
            ResolutionError(const std::string &message) : AError(message) {}
        };

        /**
         * @brief Exception class for handling errors related to the model.
        */
        class ModelError : public AError {
        public:
            /**
             * @brief Construct a new ModelError exception.
             *
             * @param message The error message.
            */
            ModelError(const std::string &message) : AError(message) {}
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
         * @param r Color value r.
         * @param g Color value g.
         * @param b Color value b.
         * @param a Color value a.
        */
        void drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

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
        unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 255);

        /**
         * @brief Draw HitBoxes on the screen.
         *
         * @param hitBoxes A vector of HitBox objects.
         * @param r Color value r.
         * @param g Color value g.
         * @param b Color value b.
         * @param a Color value a.
         */
        void drawHitBoxes(std::vector<HitBox> hitBoxes, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);

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
         * @brief Switch to the next shader in the list.
         */
        void nextCurrentShader();

        /**
         * @brief Switch to the previous shader in the list.
         */
        void previousCurrentShader();

        /**
         * @brief Get the name of the current shader.
         *
         * @return std::string The name of the current shader.
         */
        std::string getCurrentShader();

        /**
         * @brief Get the intensity of the current shader.
         *
         * @return float The intensity of the current shader.
         */
        float getCurrentShaderIntensity();

        /**
         * @brief Increase the intensity of the current shader.
         */
        void nextShaderIntensity();

        /**
         * @brief Decrease the intensity of the current shader.
         */
        void previousShaderIntensity();

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

        /**
         * @brief Set the list of available resolutions.
         *
         * @param resolutions A vector of pairs where each pair contains the width and height of a resolution.
        */
        void setResolutionList(std::vector<std::pair<int, int>> resolutions);

        /**
         * @brief Set the resolution of the window.
         *
         * @param width The width of the window.
         * @param height The height of the window.
        */
        void setResolution(int width, int height);

        /**
         * @brief Set the window to fullscreen or windowed mode.
         *
        */
        void setFullscreen();

        /**
         * @brief Change the resolution of the window.
         *
         * @param width The width of the window.
         * @param height The height of the window.
        */
        void changeResolution(int width, int height);

        /**
         * @brief Toggle the fullscreen mode of the window.
        */
        void changeFullscreen();

        /**
         * @brief Returns the size of an object with the window size.
         *
         * @param width The width of the object.
         * @param height The height of the object.
         * @return std::pair<float, float> The size of the object.
        */
        std::pair<float, float> getSizeWithWindow(float width, float height);

        /**
         * @brief Returns the scale of an object with the window size.
         *
         * @param scale The scale of the object.
         * @return float The new scale of the object.
        */
        float getScaleWithWindow(float scale);

        /**
         * @brief Close the window.
         *
         * @return true The window is closed.
         * @return false The window is not closed.
        */
        bool closeWindow();

        /**
         * @brief Play music with a given scale.
         *
         * @param path The path to the music file.
        */
        void playMusic(std::string path);

        /**
         * @brief Update the music.
        */
        void updateMusic();

        /**
         * @brief Play a sound
         *
         * @param path Path to the sound file to play.
         */
        void playSound(std::string path);

        /**
         * @brief Set the camera settings.
         *
         * @param posX Position x.
         * @param posY Position y.
         * @param posZ Position z.
         * @param targetX Target x.
         * @param targetY Target y.
         * @param targetZ Target z.
         * @param upX Up x.
         * @param upY Up y.
         * @param upZ Up z.
         * @param fovY Field of view y.
         */
        void setCameraSettings(float posX, float posY, float posZ, float targetX, float targetY, float targetZ, float upX, float upY, float upZ, float fovY);

        /**
         * @brief Set the camera position.
         *
         * @param posX Position x.
         * @param posY Position y.
         * @param posZ Position z.
         */
        void setCameraPosition(float posX, float posY, float posZ);

        /**
         * @brief Set the camera target
         *
         * @param targetX Target x.
         * @param targetY Target y.
         * @param targetZ Target z.
         */
        void setCameraTarget(float targetX, float targetY, float targetZ);

        /**
         * @brief Set the camera up.
         *
         * @param upX Up x.
         * @param upY Up y.
         * @param upZ Up z.
         */
        void setCameraUp(float upX, float upY, float upZ);

        /**
         * @brief Set the camera field of view.
         *
         * @param fovY Field of view y.
         */
        void setCameraFovY(float fovY);

        /**
         * @brief Get the camera position.
         *
         * @param objPath Path to the OBJ Model to get the HitBoxes from.
         * @param posX Position x of the model.
         * @param posY Position y of the model.
         * @param posZ Position z of the model.
         * @param scale Scale of the model.
         * @return std::vector<HitBox> A vector of HitBox objects.
         */
        std::vector<HitBox> getHitBoxesFromModel(std::string modelPath, float posX, float posY, float posZ, float scale);

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
        std::unordered_map<std::string, Sound>      _sounds;       //< List of Shaders loaded.
        std::vector<std::pair<int, int>>            _resolutions;   //< List of resolutions.
        std::string                                 _currentShader; //< Current shader.
        std::pair<std::string, Music>               _music;         //< Music.
};
