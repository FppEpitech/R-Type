#include "GraphicLib.hpp"

#include <algorithm>
#include <json/json.h>
#include <fstream>

#define SETTINGS_PATH "./Config/Settings.json"

extern "C" {
    EXPORT_SYMBOL IGraphic* loadGraphicInstance() {
        return new GraphicLib();
    }
}

GraphicLib::GraphicLib() : _window(nullptr), _renderer(nullptr) {}

GraphicLib::~GraphicLib()
{
    if (_window) {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }
}

void GraphicLib::init(const std::string &windowName)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        throw std::runtime_error("Failed to initialize SDL: " + std::string(SDL_GetError()));
    }

    _window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!_window) {
        throw std::runtime_error("Failed to create window: " + std::string(SDL_GetError()));
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!_renderer) {
        throw std::runtime_error("Failed to create renderer: " + std::string(SDL_GetError()));
    }

    if (TTF_Init() == -1) {
        throw std::runtime_error("Failed to initialize SDL_ttf: " + std::string(TTF_GetError()));
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        throw std::runtime_error("Failed to initialize SDL_mixer: " + std::string(Mix_GetError()));
    }
}

bool GraphicLib::windowIsOpen()
{
    return _window != nullptr;
}

void GraphicLib::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

std::size_t GraphicLib::getKeyDownInput()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    for (std::size_t i = 0; i < SDL_NUM_SCANCODES; ++i) {
        if (state[i]) {
            return i;
        }
    }
    return SDL_SCANCODE_UNKNOWN;
}

std::size_t GraphicLib::getKeyPressedInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            return event.key.keysym.scancode;
        }
    }
    return SDL_SCANCODE_UNKNOWN;
}

void GraphicLib::drawOBJ(std::string objPath, float posx, float posy, float posz, float scale)
{
    // 3D functionality not supported, return 0
    return;
}

void GraphicLib::drawTexture(std::string texturePath, float posx, float posy, float scale)
{
    if (!windowIsOpen())
        return;
    if (_textures.find(texturePath) == _textures.end()) {
        SDL_Surface* surface = SDL_LoadBMP(texturePath.c_str());
        if (!surface) {
            throw std::runtime_error("Failed to load texture: " + std::string(SDL_GetError()));
        }
        _textures[texturePath] = SDL_CreateTextureFromSurface(_renderer, surface);
        SDL_FreeSurface(surface);
    }

    SDL_Rect dstRect = { static_cast<int>(posx), static_cast<int>(posy), static_cast<int>(scale * DEFAULT_WINDOW_WIDTH), static_cast<int>(scale * DEFAULT_WINDOW_HEIGHT) };
    SDL_RenderCopy(_renderer, _textures[texturePath], NULL, &dstRect);
}

void GraphicLib::drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    if (!windowIsOpen())
        return;
    if (_textures.find(texturePath) == _textures.end()) {
        SDL_Surface* surface = SDL_LoadBMP(texturePath.c_str());
        if (!surface) {
            throw std::runtime_error("Failed to load texture: " + std::string(SDL_GetError()));
        }
        _textures[texturePath] = SDL_CreateTextureFromSurface(_renderer, surface);
        SDL_FreeSurface(surface);
    }

    SDL_Rect srcRect = { static_cast<int>(left), static_cast<int>(top), static_cast<int>(width), static_cast<int>(height) };
    SDL_Rect dstRect = { static_cast<int>(posx), static_cast<int>(posy), static_cast<int>(width * scale), static_cast<int>(height * scale) };
    SDL_SetTextureColorMod(_textures[texturePath], r, g, b);
    SDL_SetTextureAlphaMod(_textures[texturePath], a);
    SDL_RenderCopy(_renderer, _textures[texturePath], &srcRect, &dstRect);
}

void GraphicLib::drawText(std::string text, float posx, float posy, int fontSize, std::string fontPath, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    if (!windowIsOpen())
        return;
    if (_fonts.find(fontPath) == _fonts.end()) {
        _fonts[fontPath] = TTF_OpenFont("./Assets/Fonts/Venite.ttf", fontSize);
        if (!_fonts[fontPath]) {
            throw std::runtime_error("Failed to load font: " + std::string(TTF_GetError()));
        }
    }

    SDL_Color color = { r, g, b, a };
    SDL_Surface* surface = TTF_RenderText_Blended(_fonts[fontPath], text.c_str(), color);
    if (!surface) {
        throw std::runtime_error("Failed to render text: " + std::string(TTF_GetError()));
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect dstRect = { static_cast<int>(posx), static_cast<int>(posy), surface->w, surface->h };
    SDL_RenderCopy(_renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);
}

void GraphicLib::initShaderWithMap(std::unordered_map<std::string, std::string> shaders)
{
    // Shaders not supported in SDL2, do nothing
}

void GraphicLib::initCurrentShader(std::string name)
{
    // Shaders not supported in SDL2, do nothing
}

void GraphicLib::initShaderIntensity(float intensity)
{
    // Shaders not supported in SDL2, do nothing
}

void GraphicLib::changeCurrentShader(std::string name)
{
    // Shaders not supported in SDL2, do nothing
}

void GraphicLib::changeShaderIntensity(float intensity)
{
    // Shaders not supported in SDL2, do nothing
}

void GraphicLib::resetShader()
{
    // Shaders not supported in SDL2, do nothing
}

void GraphicLib::startDraw()
{
    if (!windowIsOpen())
        return;
    SDL_RenderClear(_renderer);
}

void GraphicLib::endDraw()
{
    if (!windowIsOpen())
        return;
    SDL_RenderPresent(_renderer);
}

std::pair<int, int> GraphicLib::getWindowSize()
{
    int w;
    int h;
    SDL_GetWindowSize(_window, &w, &h);
    return std::make_pair(w, h);
}

std::pair<int, int> GraphicLib::getMousePosition()
{
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    return std::make_pair(x, y);
}

bool GraphicLib::isMouseButtonPressed(MouseButtons button)
{
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button);
}

bool GraphicLib::isMouseButtonDown(MouseButtons button)
{
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button);
}

void GraphicLib::setResolutionList(std::vector<std::pair<int, int>> resolutions)
{
    _resolutions = resolutions;
}

void GraphicLib::setResolution(int width, int height)
{
    if (std::find(_resolutions.begin(), _resolutions.end(), std::make_pair(width, height)) == _resolutions.end())
        throw ResolutionError("Resolution format not handled: " + std::to_string(width) + "x" + std::to_string(height));
    SDL_SetWindowSize(_window, width, height);
}

void GraphicLib::changeResolution(int width, int height)
{
    if (std::find(_resolutions.begin(), _resolutions.end(), std::make_pair(width, height)) == _resolutions.end())
        throw ResolutionError("Resolution format not handled: " + std::to_string(width) + "x" + std::to_string(height));
    SDL_SetWindowSize(_window, width, height);

    Json::Value root;
    Json::StreamWriterBuilder writer;
    std::ifstream settingsFile(SETTINGS_PATH, std::ifstream::binary);

    settingsFile >> root;
    settingsFile.close();
    root["window"]["resolutionIndex"] = std::find(_resolutions.begin(), _resolutions.end(), std::make_pair(width, height)) - _resolutions.begin();
    std::ofstream settingsFileOut(SETTINGS_PATH, std::ofstream::binary);
    settingsFileOut << Json::writeString(writer, root);
    settingsFileOut.close();
}

void GraphicLib::setFullscreen()
{
    SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
}

void GraphicLib::changeFullscreen()
{
    Uint32 fullscreenFlag = SDL_GetWindowFlags(_window) & SDL_WINDOW_FULLSCREEN;
    SDL_SetWindowFullscreen(_window, fullscreenFlag ? 0 : SDL_WINDOW_FULLSCREEN);

    Json::Value root;
    Json::StreamWriterBuilder writer;
    std::ifstream settingsFile(SETTINGS_PATH, std::ifstream::binary);

    settingsFile >> root;
    settingsFile.close();
    root["window"]["fullscreen"] = !root["window"]["fullscreen"].asBool();
    std::ofstream settingsFileOut(SETTINGS_PATH, std::ofstream::binary);
    settingsFileOut << Json::writeString(writer, root);
    settingsFileOut.close();
}

std::pair<float, float> GraphicLib::getSizeWithWindow(float width, float height)
{
    int w;
    int h;
    SDL_GetWindowSize(_window, &w, &h);
    return std::pair<float, float>{width * w / DEFAULT_WINDOW_WIDTH, height * h / DEFAULT_WINDOW_HEIGHT};
}

float GraphicLib::getScaleWithWindow(float scale)
{
    int w;
    int h;
    SDL_GetWindowSize(_window, &w, &h);
    float windowScaleX = static_cast<float>(w) / DEFAULT_WINDOW_WIDTH;
    float windowScaleY = static_cast<float>(h) / DEFAULT_WINDOW_HEIGHT;
    return (windowScaleX < windowScaleY) ? windowScaleX * scale : windowScaleY * scale;
}

bool GraphicLib::closeWindow()
{
    if (windowIsOpen()) {
        Mix_CloseAudio();
        TTF_Quit();
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
        _window = nullptr;
        return true;
    }
    return false;
}

void GraphicLib::playMusic(std::string path)
{
    if (_currentMusic.first == path)
        return;
    _currentMusic.first = path;
    Mix_HaltMusic();
    if (_currentMusic.first == "none")
        return;
    _currentMusic.second = Mix_LoadMUS(path.c_str());
    if (!_currentMusic.second) {
        throw std::runtime_error("Failed to load music: " + std::string(Mix_GetError()));
    }
    Mix_PlayMusic(_currentMusic.second, -1);
}

void GraphicLib::updateMusic()
{
    // SDL_mixer handles music updates internally
}

void GraphicLib::playSound(std::string path)
{
    if (_sounds.find(path) == _sounds.end()) {
        _sounds[path] = Mix_LoadWAV(path.c_str());
        if (!_sounds[path]) {
            throw std::runtime_error("Failed to load sound: " + std::string(Mix_GetError()));
        }
    }
    Mix_PlayChannel(-1, _sounds[path], 0);
}

bool GraphicLib::_isShaderReady()
{
    // Shaders not supported in SDL2, return false
    return false;
}
