/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>

/**
 * @class IGraphic
 * @brief Interface for the graphic module.
 *
 * All graphic modules must implement this interface.
 * The graphic module is responsible for rendering the game.
 * It must be able to initialize, update, and destroy itself.
 * The graphic module must be able to render the game.
 */
class IGraphic {
    public:
        /**
         * @brief Virtual destructor for IGraphic.
         */
        virtual ~IGraphic() = default;

        /**
         * @brief Initialize the graphic module.
         */
        virtual void init(const std::string &windowName) = 0;

        /**
         * @brief check if the window is open/close.
         *
         * @return true Window open.
         * @return false Window closed.
         */
        virtual bool windowIsOpen() = 0;

        /**
         * @brief Clear the window.
         *
         */
        virtual void clear() = 0;

        /**
         * @brief Get the Key Input object.
         *
         * @return int The key pressed.
         */
        virtual std::size_t getKeyInput() = 0;

        /**
         * @brief Draw an OBJ model on the screen.
         *
         * @param objPath Path to the OBJ Model to draw.
         */
        virtual void drawOBJ(std::string objPath, float posx, float posy, float posz, float scale) = 0;

        /**
         * @brief Start to draw on the window.
         * Must be call at the begin of the Game loop.
         *
         */
        virtual void startDraw() = 0;

        /**
         * @brief End to draw on the window.
         * Must be call at the end of the Game loop.
         *
         */
        virtual void endDraw() = 0;
};
