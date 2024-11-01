/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ObjParser.hpp
*/

#pragma once

#include <memory>

#include "../../DefaultComponents/ObjPath/ObjPathComponent.hpp"

/**
 * @brief Parse a Obj Json object.
 *
 * @param pathFile Path to the Json file.
 * @return std::shared_ptr<ObjPathComponent>
 */
std::shared_ptr<ObjPathComponent> parseObjPath(std::string pathFile);
