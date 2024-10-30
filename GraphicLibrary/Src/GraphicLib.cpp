/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

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

GraphicLib::~GraphicLib()
{
    if (!WindowShouldClose())
        CloseWindow();
}

void GraphicLib::init(const std::string &windowName)
{
    InitWindow(1920, 1080, windowName.c_str());
    InitAudioDevice();
    SetTargetFPS(140);

    Vector3 position = {0.0f, 0.0f, -10.0f};
    Vector3 target = {0.0f, 0.0f, 0.0f};
    Vector3 up = {0.0f, 1.0f, 0.0f};

    _camera.position = position;                        // Camera position
    _camera.target = target;                            // Camera looking at point
    _camera.up = up;                                    // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                               // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;            // Camera projection type
}

bool GraphicLib::windowIsOpen()
{
    return !WindowShouldClose();
}

void GraphicLib::clear()
{
    ClearBackground(BLACK);
}

std::size_t GraphicLib::getKeyDownInput()
{
    for (std::size_t i = KEY_NULL; i < KEY_KP_EQUAL; i++) {
        if (IsKeyDown(i))
            return i;
    }
    return KEY_NULL;
}

std::size_t GraphicLib::getKeyPressedInput()
{
    for (std::size_t i = KEY_NULL; i < KEY_KP_EQUAL; i++) {
        if (IsKeyPressed(i))
            return i;
    }
    return KEY_NULL;
}

void GraphicLib::drawOBJ(std::string objPath, float posx, float posy, float posz, float scale)
{
    if (!windowIsOpen())
        return;
    if (_models.find(objPath) == _models.end())
        _models[objPath] = LoadModel(objPath.c_str());

    Vector3 position = { posx, posy, posz };

    BeginMode3D(_camera);

    if (_isShaderReady())
        BeginShaderMode(_shaders[_currentShader]);
    DrawModel(_models[objPath], position, scale, WHITE);
    if (_isShaderReady())
        EndShaderMode();

    EndMode3D();
}

void GraphicLib::drawTexture(std::string texturePath, float posx, float posy, float scale)
{
    if (!windowIsOpen())
        return;
    if (_textures.find(texturePath) == _textures.end())
        _textures[texturePath] = LoadTexture(texturePath.c_str());

    std::pair<float, float> positionPair = getSizeWithWindow(posx, posy);
    Vector2 position = {positionPair.first, positionPair.second};

    if (_isShaderReady())
        BeginShaderMode(_shaders[_currentShader]);
    DrawTextureEx(_textures[texturePath], position, 0, getScaleWithWindow(scale), WHITE);
    if (_isShaderReady())
        EndShaderMode();
}

void GraphicLib::drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 255)
{
    if (!windowIsOpen())
        return;
    if (_textures.find(texturePath) == _textures.end())
        _textures[texturePath] = LoadTexture(texturePath.c_str());

    Rectangle rect = {left, top, width, height};

    std::pair<float, float> firstCornerPair = getSizeWithWindow(posx, posy);
    std::pair<float, float> newSizePair = getSizeWithWindow(width * scale, height * scale);

    Vector2 firstCorner = {firstCornerPair.first, firstCornerPair.second};
    Vector2 newSize = {newSizePair.first, newSizePair.second};
    Vector2 secondCorner = {newSize.x, newSize.y};

    Rectangle rectDest = {firstCorner.x, firstCorner.y, secondCorner.x, secondCorner.y};

    Vector2 origin = { 0, 0 };
    Color color = {r, g, b, a};

    if (_isShaderReady())
        BeginShaderMode(_shaders[_currentShader]);
    DrawTexturePro(_textures[texturePath], rect, rectDest, origin, 0, color);
    if (_isShaderReady())
        EndShaderMode();
}

void GraphicLib::drawText(std::string text, float posx, float posy, int fontSize, std::string fontPath,
    unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    if (!windowIsOpen())
        return;
    if (_font.find(fontPath) == _font.end() && fontPath != "")
        _font[fontPath] = LoadFont(fontPath.c_str());

    Color color = {r, g, b, a};

    if (_isShaderReady())
        BeginShaderMode(_shaders[_currentShader]);

    std::pair<float, float> positionPair = getSizeWithWindow(posx, posy);
    Vector2 position = {positionPair.first, positionPair.second};
    fontSize = (int)getScaleWithWindow((float)fontSize);

    if (fontPath != "") {
        DrawTextEx(_font[fontPath], text.c_str(), position, fontSize, 2, color);
    } else
        DrawText(text.c_str(), (int)position.x, (int)position.y, fontSize, color);

    if (_isShaderReady())
        EndShaderMode();
}

void GraphicLib::initShaderWithMap(std::unordered_map <std::string, std::string> shaders)
{
    if (!windowIsOpen())
        return;
    try {
        for (auto shader : shaders) {
            Shader shaderLoaded = LoadShader(0, shader.second.c_str());
            if (shaderLoaded.id == 0)
                throw std::runtime_error("Failed to load shader: " + shader.second);
            _shaders[shader.first] = shaderLoaded;
        }
    } catch (const std::exception &e) {
        throw LoadShaderError(e.what());
    }
}

void GraphicLib::initCurrentShader(std::string name)
{
    if (name == "none") {
        _currentShader = "none";
        return;
    }
    if (_shaders.find(name) != _shaders.end()) {
        _currentShader = name;
        return;
    }
    throw WrongCurrentShaderName("Shader not found: " + name);
}

void GraphicLib::initShaderIntensity(float intensity)
{
    if (!windowIsOpen())
        return;
    for (auto shader : _shaders) {
        SetShaderValue(_shaders[shader.first], GetShaderLocation(_shaders[shader.first], "intensity"), &intensity, SHADER_UNIFORM_FLOAT);
    }
}

void GraphicLib::changeShaderIntensity(float intensity)
{
    if (!windowIsOpen())
        return;
    Json::Value root;
    std::ifstream settingsFile(SETTINGS_PATH, std::ifstream::binary);
    settingsFile >> root;
    settingsFile.close();

    for (auto shader : _shaders)
        SetShaderValue(_shaders[shader.first], GetShaderLocation(_shaders[shader.first], "intensity"), &intensity, SHADER_UNIFORM_FLOAT);
    root["color_blindness"]["intensity"] = intensity;
    std::ofstream settingsFileOut(SETTINGS_PATH, std::ofstream::binary);
    settingsFileOut << root;
    settingsFileOut.close();
}

void GraphicLib::changeCurrentShader(std::string name)
{
    Json::Value root;
    Json::StreamWriterBuilder writer;
    std::ifstream settingsFile(SETTINGS_PATH, std::ifstream::binary);
    settingsFile >> root;
    settingsFile.close();

    if (name == "none") {
        _currentShader = "none";
        root["color_blindness"]["current"] = "none";
    } else if (_shaders.find(name) != _shaders.end()) {
        _currentShader = name;
        root["color_blindness"]["current"] = name;
    } else {
        throw WrongCurrentShaderName("Shader not found: " + name);
    }

    std::ofstream settingsFileOut(SETTINGS_PATH, std::ofstream::binary);
    settingsFileOut << Json::writeString(writer, root);
    settingsFileOut.close();
}

void GraphicLib::resetShader()
{
    if (!windowIsOpen())
        return;
    for (auto shader : _shaders)
        UnloadShader(_shaders[shader.first]);
    _shaders.clear();
    _currentShader = "none";
}

void GraphicLib::startDraw()
{
    if (!windowIsOpen())
        return;
    BeginDrawing();
}

void GraphicLib::endDraw()
{
    if (!windowIsOpen())
        return;
    EndDrawing();
}

std::pair<int, int> GraphicLib::getWindowSize()
{
    return std::make_pair<int, int>(GetScreenWidth(), GetScreenHeight());
}

std::pair<int, int> GraphicLib::getMousePosition()
{
    return std::make_pair<int, int>(GetMouseX(), GetMouseY());
}

bool GraphicLib::isMouseButtonPressed(MouseButtons button)
{
    return IsMouseButtonPressed(button);
}

bool GraphicLib::isMouseButtonDown(MouseButtons button)
{
    return IsMouseButtonDown(button);
}

void GraphicLib::setResolutionList(std::vector <std::pair<int, int>> resolutions)
{
    _resolutions = resolutions;
}

void GraphicLib::setResolution(int width, int height) {
    if (std::find(_resolutions.begin(), _resolutions.end(), std::make_pair(width, height)) == _resolutions.end())
        throw ResolutionError("Resolution format not handle: " + std::to_string(width) + "x" + std::to_string(height));
    SetWindowSize(width, height);
}

void GraphicLib::changeResolution(int width, int height) {
    if (std::find(_resolutions.begin(), _resolutions.end(), std::make_pair(width, height)) == _resolutions.end())
        throw ResolutionError("Resolution format not handle: " + std::to_string(width) + "x" + std::to_string(height));
    SetWindowSize(width, height);

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
    ToggleFullscreen();
}

void GraphicLib::changeFullscreen()
{
    ToggleFullscreen();

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
    return std::pair<float, float>{width * GetScreenWidth() / DEFAULT_WINDOW_WIDTH, height * GetScreenHeight() / DEFAULT_WINDOW_HEIGHT};
}

float GraphicLib::getScaleWithWindow(float scale)
{
    float windowScaleX = (float)GetScreenWidth() / DEFAULT_WINDOW_WIDTH;
    float windowScaleY = (float)GetScreenHeight() / DEFAULT_WINDOW_HEIGHT;
    return (windowScaleX < windowScaleY) ? windowScaleX * scale : windowScaleY * scale;
}

bool GraphicLib::closeWindow()
{
    if (windowIsOpen()) {
        CloseAudioDevice();
        CloseWindow();
        return true;
    }
    return false;
}

void GraphicLib::playMusic(std::string path)
{
    if (_music.first == path)
        return;
    _music.first = path;
    StopMusicStream(_music.second);
    if (_music.first == "none")
        return;
    _music.second = LoadMusicStream(path.c_str());
    PlayMusicStream(_music.second);
}

void GraphicLib::updateMusic()
{
    if (_music.first == "none")
        return;
    UpdateMusicStream(_music.second);
}

bool GraphicLib::_isShaderReady()
{
    return _currentShader != "none";
}
