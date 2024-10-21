/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ButtonTexturePathComponent.hpp
*/

#pragma once

#include "../../../Engine/Shared/DefaultComponent/IComponent.hpp"

/**
 * @brief ButtonTexturePathComponent class
 * @details This class will be used to store the texture paths of a button
 *
 */
class ButtonTexturePathComponent : public AComponent {

    public:

        std::string noneTexturePath; /*!< The path to the none texture */
        std::string hoverTexturePath; /*!< The path to the hover texture */
        std::string clickedTexturePath; /*!< The path to the clicked texture */

        /**
         * @brief Construct a new ButtonTexturePathComponent object
         * @details This constructor will be used to create a new ButtonTexturePathComponent object
         *
         * @param normalTexturePath The path to the none texture
         * @param hoverTexturePath The path to the hover texture
         * @param clickedTexturePath The path to the clicked texture
         */
        ButtonTexturePathComponent(const std::string noneTexturePath = "", const std::string hoverTexturePath = "", const std::string clickedTexturePath = "");
};
