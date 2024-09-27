/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "ITexture.hpp"

/**
 * @class IShader
 * @brief Interface for shader operations.
 *
 * This interface defines a set of methods for loading shaders and setting shader values.
 */
class IShader {
    public:
        /**
         * @brief Virtual destructor for IShader.
         */
        virtual ~IShader() = default;

        /**
         * @brief Load a fragment shader from a file.
         * @param fsFileName The name of the file containing the fragment shader.
         */
        virtual void LoadShaderFs(const char *fsFileName) = 0;

        /**
         * @brief Load a vertex shader from a file.
         * @param vsFileName The name of the file containing the vertex shader.
         */
        virtual void LoadShaderVs(const char *vsFileName) = 0;

        /**
         * @brief Set a shader uniform value.
         * @param uniformLoc The location of the uniform variable.
         * @param value The value to set.
         * @param uniformType The type of the uniform variable.
         */
        virtual void SetShaderValue(int uniformLoc, const void *value, int uniformType) = 0;

        /**
         * @brief Set a shader uniform value to a texture.
         * @param uniformLoc The location of the uniform variable.
         * @param texture The texture to set.
         */
        virtual void SetShaderValueTexture(int uniformLoc, ITexture texture) = 0;
};
