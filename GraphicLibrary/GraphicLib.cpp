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
    CloseWindow();
}

void GraphicLib::Init(const std::string &windowName)
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
