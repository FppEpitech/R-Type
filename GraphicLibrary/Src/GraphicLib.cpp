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
}

bool GraphicLib::windowIsOpen()
{
    return !WindowShouldClose();
}

void GraphicLib::clear()
{
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
}

std::size_t GraphicLib::getKeyInput() {
    for (std::size_t i = KEY_NULL; i < KEY_KP_EQUAL; i++) {
        if (IsKeyDown(i))
            return i;
    }
    return KEY_NULL;
}
