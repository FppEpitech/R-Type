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

    _camera.position = (Vector3){ 0.0f, 0.0f, -10.0f };    // Camera position
    _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
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

void GraphicLib::startDraw()
{
    BeginDrawing();
}

void GraphicLib::endDraw()
{
    EndDrawing();
}
