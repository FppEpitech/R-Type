/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** GetGraphicalLibrary.hpp
*/

#pragma once

#include <memory>

#include "IGraphic.hpp"

#ifdef _WIN32
    #define LIB_SUFFIX ".dll"
#else
    #define LIB_SUFFIX ".so"
#endif

#define PATH_GRAPHIC_LIB "Libs/Graphic/"

/**
 * @brief Get the Graphical Library object.
 *
 * @return std::shared_ptr<IGraphic>
 */
std::shared_ptr<IGraphic> getGraphicalLibrary();
