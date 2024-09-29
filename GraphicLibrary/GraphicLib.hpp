/*
** EPITECH PROJECT, 2024
** GraphicLib
** File description:
** GraphicLib
*/

#pragma once

#include "IGraphic.hpp"
#include "raylib.h"

#include <iostream>

class GraphicLib : public IGraphic {

    public:

        GraphicLib() = default;
        ~GraphicLib();
        void Init(const std::string &windowName);
        bool windowIsOpen();
        void clear();
};
