/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#include "GraphicLib.hpp"

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
    ClearBackground(WHITE);
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

void GraphicLib::startDraw()
{
    BeginDrawing();
}

void GraphicLib::endDraw()
{
    EndDrawing();
}
