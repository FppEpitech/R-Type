/*
** EPITECH PROJECT, 2024
** SpriteSheetAnimationComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once
#include "IComponent.hpp"
#include <ctime>

/**
 * @class SpriteSheetAnimationComponent
 * @brief Component for handling sprite sheet animations in the graphical engine.
 * @inherit AComponent (inherits IComponent)
 *
 * This component is used to store and manage animations within the graphical engine.
 *
 * @var text The text content to be managed by this component.
 */
class SpriteSheetAnimationComponent : public AComponent {
    public:

        std::size_t     nbFrame;            //< Number of sprite sheet frames.
        clock_t         timeElapsed;        //< Time elapsed since last frame changes.
        float           timeFrame;          //< Time for each frame.
        float           vx;                 //< Vector direction x to change Texture Rect left.
        float           vy;                 //< Vector direction y to change Texture Rect top.
        float           startX;             //< Position x of the first frame.
        float           startY;             //< Position y of the first frame.
        std::size_t     currentFrame;       //< Index of the current frame display.
        bool            reverseMod;         //< True if frames should be played in both directions. (For example: left to right and right to left)

        /**
         * @brief Construct a new Animation Component object
         *
         * @param text Initial text content (default is an empty string).
         */
        SpriteSheetAnimationComponent(std::size_t nbFrame = 1, float timeFrame = 0.5, float vx = 0, float vy = 0, float startX = 0, float startY = 0, bool reverseMod = false);
};
