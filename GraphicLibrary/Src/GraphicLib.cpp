/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#include "GraphicLib.hpp"

#include <json/json.h>
#include <fstream>

#define SETTINGS_PATH "./Config/Settings.json"

extern "C" IGraphic* loadGraphicInstance() {
    return new GraphicLib();
}

GraphicLib::~GraphicLib()
{
    if (!WindowShouldClose())
        CloseWindow();
}

void GraphicLib::init(const std::string &windowName)
{
    InitWindow(1920, 1080, windowName.c_str());
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

std::size_t GraphicLib::getKeyInput() {
    for (std::size_t i = KEY_NULL; i < KEY_KP_EQUAL; i++) {
        if (IsKeyDown(i))
            return i;
    }
    return KEY_NULL;
}

void GraphicLib::drawOBJ(std::string objPath, float posx, float posy, float posz, float scale)
{
    if (_models.find(objPath) == _models.end())
        _models[objPath] = LoadModel(objPath.c_str());

    Vector3 position = { posx, posy, posz };

    BeginMode3D(_camera);
        DrawModel(_models[objPath], position, scale, WHITE);
    EndMode3D();
}

void GraphicLib::drawTexture(std::string texturePath, float posx, float posy, float scale)
{
    if (_textures.find(texturePath) == _textures.end())
        _textures[texturePath] = LoadTexture(texturePath.c_str());

    Vector2 position = { posx, posy };

    DrawTextureEx(_textures[texturePath], position, 0, scale, WHITE);
}

void GraphicLib::drawTextureRect(std::string texturePath, float posx, float posy, float left, float top, float width, float height, float scale)
{
    if (_textures.find(texturePath) == _textures.end())
        _textures[texturePath] = LoadTexture(texturePath.c_str());

    Rectangle rect = {left, top, width, height};
    Rectangle rectDest = {posx, posy, width * scale, height * scale};
    Vector2 origin = { 0, 0 };

    DrawTexturePro(_textures[texturePath], rect, rectDest, origin, 0, WHITE);
}

void GraphicLib::drawText(std::string text, float posx, float posy, int fontSize, std::string fontPath,
    unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    if (_font.find(fontPath) == _font.end() && fontPath != "")
        _font[fontPath] = LoadFont(fontPath.c_str());

    Color color = {r, g, b, a};

    if (fontPath != "") {
        Vector2 position = { posx, posy };
        DrawTextEx(_font[fontPath], text.c_str(), position, fontSize, 2, color);
    } else
        DrawText(text.c_str(), posx, posy, 24, color);
}

void GraphicLib::initShaderWithMap(std::unordered_map <std::string, std::string> shaders)
{
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
    for (auto shader : _shaders) {
        SetShaderValue(_shaders[shader.first], GetShaderLocation(_shaders[shader.first], "intensity"), &intensity, SHADER_UNIFORM_FLOAT);
    }
}

void GraphicLib::changeShaderIntensity(float intensity)
{
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
    std::ifstream settingsFile(SETTINGS_PATH, std::ifstream::binary);
    settingsFile >> root;
    settingsFile.close();

    if (name == "none") {
        _currentShader = "none";
        root["current"] = "none";
    } else if (_shaders.find(name) != _shaders.end()) {
        _currentShader = name;
        root["current"] = name;
    } else {
        throw WrongCurrentShaderName("Shader not found: " + name);
    }

    std::ofstream settingsFileOut(SETTINGS_PATH, std::ofstream::binary);
    settingsFileOut << root;
    settingsFileOut.close();
}

void GraphicLib::resetShader()
{
    for (auto shader : _shaders)
        UnloadShader(_shaders[shader.first]);
    _shaders.clear();
    _currentShader = "none";
}

void GraphicLib::startDraw()
{
    BeginDrawing();
}

void GraphicLib::endDraw()
{
    EndDrawing();
}

bool GraphicLib::_isShaderReady()
{
    if (_currentShader == "none")
        return false;
    return true;
}

std::pair<int, int> GraphicLib::getWindowSize()
{
    return std::make_pair<int, int>(GetScreenWidth(), GetScreenHeight());
}
