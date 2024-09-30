/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

/**
 * @class ITexture
 * @brief Interface for texture operations.
 *
 * This interface defines a set of methods for loading, adding, and manipulating textures.
 */
class ITexture {
public:
    /**
     * @brief Virtual destructor for ITexture.
     */
    virtual ~ITexture() = default;

    /**
     * @brief Load a texture.
     * @return An instance of ITexture.
     */
    virtual ITexture LoadTexture() = 0;

    /**
     * @brief Add a texture.
     */
    virtual void AddTexture() = 0;

    /**
     * @brief Set the position of the texture.
     */
    virtual void SetTexturePosition() = 0;

    /**
     * @brief Set the size of the texture.
     */
    virtual void SetTextureSize() = 0;

    /**
     * @brief Set the color of the texture.
     */
    virtual void SetTextureColor() = 0;

    /**
     * @brief Set the rotation of the texture.
     */
    virtual void SetTextureRotation() = 0;

    /**
     * @brief Set the scale of the texture.
     */
    virtual void SetTextureScale() = 0;

    /**
     * @brief Set the rectangular area of the texture.
     */
    virtual void SetTextureRect() = 0;

    /**
     * @brief Set the origin of the texture.
     */
    virtual void SetTextureOrigin() = 0;
};
