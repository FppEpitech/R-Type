/*
** EPITECH PROJECT, 2024
** ColourComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"

/**
 * @class ColourComponent
 * @brief Component for handling RGBA color values within the graphical engine.
 *
 * This component is used to store and manage the RGBA color values of entities.
 *
 * @var r The red component of the color.
 * @var g The green component of the color.
 * @var b The blue component of the color.
 * @var a The alpha (transparency) component of the color.
 */
class ColourComponent : public AComponent {

    public:

        unsigned char r; //< The red component of the color.
        unsigned char g; //< The green component of the color.
        unsigned char b; //< The blue component of the color.
        unsigned char a; //< The alpha (transparency) component of the color.

        /**
         * @brief Construct a new ColourComponent object
         *
         * @param r Initial red component of the color.
         * @param g Initial green component of the color.
         * @param b Initial blue component of the color.
         * @param a Initial alpha (transparency) component of the color.
         */
        ColourComponent(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);
};
