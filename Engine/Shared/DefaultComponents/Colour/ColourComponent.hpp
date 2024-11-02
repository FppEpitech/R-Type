/*
** EPITECH PROJECT, 2024
** ColourComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../IComponent.hpp"
#include <iostream>

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


        /**
         * @brief Get the Arg object(mainly for lua api).
         *
         * @return std::any
         */
        std::any getArg(std::string key) override {
            if (key == "r")
                return std::any(int(r));
            if (key == "g")
                return std::any(int(g));
            if (key == "b")
                return std::any(int(b));
            if (key == "a")
                return std::any(int(a));
            return std::any(int(84));
        }

        /**
         * @brief Set the Arg object (mainly for lua api).
         *
         * @return bool
         */
        bool setArg(std::string key, std::any value) override {
            if (key == "r") {
                r = (unsigned char)std::any_cast<int>(value);
                return true;
            }
            if (key == "g") {
                g = (unsigned char)std::any_cast<int>(value);
                return true;
            }
            if (key == "b") {
                b = (unsigned char)std::any_cast<int>(value);
                return true;
            }
            if (key == "a") {
                a = (unsigned char)std::any_cast<int>(value);
                return true;
            }
            return false;
        }
};
