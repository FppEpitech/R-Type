#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../Error/AError.hpp"
#include "IGraphic.hpp"

#include <vector>
#include <iostream>
#include <unordered_map>

#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080

class GraphicLib : public IGraphic {

public:

    class WrongCurrentShaderName : public AError {
    public:
        WrongCurrentShaderName(const std::string &message) : AError(message) {}
    };

    class LoadShaderError : public AError {
    public:
        LoadShaderError(const std::string &message) : AError(message) {}
    };

    class ResolutionError : public AError {
    public:
        ResolutionError(const std::string &message) : AError(message) {}
    };

    GraphicLib();
    ~GraphicLib();

    void init(const std::string &windowName);
    bool windowIsOpen();
    void clear();
    std::size_t getKeyDownInput();
    std::size_t getKeyPressedInput();
    void drawOBJ(std::string objPath, float posx, float posy, float posz, float scale);
    void drawTexture(std::string texturePath, float posx, float posy, float scale);
    void drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void drawText(std::string text, float posx, float posy, int fontSize, std::string fontPath, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void initShaderWithMap(std::unordered_map<std::string, std::string> shaders);
    void initCurrentShader(std::string name);
    void initShaderIntensity(float intensity);
    void changeCurrentShader(std::string name);
    void changeShaderIntensity(float intensity);
    void resetShader();
    void startDraw();
    void endDraw();
    std::pair<int, int> getWindowSize();
    std::pair<int, int> getMousePosition();
    bool isMouseButtonPressed(MouseButtons button);
    bool isMouseButtonDown(MouseButtons button);
    void setResolutionList(std::vector<std::pair<int, int>> resolutions);
    void setResolution(int width, int height);
    void setFullscreen();
    void changeResolution(int width, int height);
    void changeFullscreen();
    std::pair<float, float> getSizeWithWindow(float width, float height);
    float getScaleWithWindow(float scale);
    bool closeWindow();
    void playMusic(std::string path);
    void updateMusic();
    void playSound(std::string path);

private:
    bool _isShaderReady();

    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::unordered_map<std::string, SDL_Texture*> _textures;
    std::unordered_map<std::string, TTF_Font*> _fonts;
    std::unordered_map<std::string, Mix_Chunk*> _sounds;
    std::unordered_map<std::string, Mix_Music*> _music;
    std::vector<std::pair<int, int>> _resolutions;
    std::string _currentShader;
    std::pair<std::string, Mix_Music*> _currentMusic;
};