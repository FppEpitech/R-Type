/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IColor.hpp"
#include "ITexture.hpp"

#include <string>

/**
 * @class I2DEntity
 * @brief Interface for 2D entity operations.
 *
 * This interface defines methods for loading 2D entities, setting various properties such as position, size, color, rotation, scale, rectangle, origin, and texture.
 */
class I2DEntity {
    public:
        /**
         * @brief Virtual destructor for I2DEntity.
         */
        virtual ~I2DEntity() = default;

        /**
         * @brief Load a 2D entity from a file.
         * @param path The path to the file containing the 2D entity.
         */
        virtual void Load2DEntity(std::string const &path) = 0;

        /**
         * @brief Set the position of the 2D entity.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         */
        virtual void SetPosition(float x, float y) = 0;

        /**
         * @brief Set the size of the 2D entity.
         * @param x The width of the entity.
         * @param y The height of the entity.
         */
        virtual void SetSize(float x, float y) = 0;

        /**
         * @brief Set the color of the 2D entity.
         * @param color The color to set.
         */
        virtual void SetColor(Color color) = 0;

        /**
         * @brief Set the rotation of the 2D entity.
         * @param rotation The rotation angle in degrees.
         */
        virtual void SetRotation(float rotation) = 0;

        /**
         * @brief Set the scale of the 2D entity.
         * @param x The scale factor along the x-axis.
         * @param y The scale factor along the y-axis.
         */
        virtual void SetScale(float x, float y) = 0;

        /**
         * @brief Set the rectangle of the 2D entity.
         * @param x The x-coordinate of the rectangle.
         * @param y The y-coordinate of the rectangle.
         * @param w The width of the rectangle.
         * @param h The height of the rectangle.
         */
        virtual void SetRect(float x, float y, float w, float h) = 0;

        /**
         * @brief Set the origin of the 2D entity.
         * @param x The x-coordinate of the origin.
         * @param y The y-coordinate of the origin.
         */
        virtual void SetOrigin(float x, float y) = 0;

        /**
         * @brief Set the texture of the 2D entity.
         * @param texture The texture to set.
         */
        virtual void SetTexture(ITexture texture) = 0;
};
