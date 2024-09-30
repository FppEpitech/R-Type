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
};
