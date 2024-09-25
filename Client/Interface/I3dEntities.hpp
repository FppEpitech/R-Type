/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <vector>
#include <string>

#include "IColor.hpp"

/**
 * @class I3DEntity
 * @brief Interface for 3D entity operations.
 *
 * This interface defines methods for loading 3D entities, textures, and setting various properties such as position, rotation, scale, and color.
 */
class I3DEntity {
    public:
        /**
         * @enum MATERIAL
         * @brief Enumeration of material types for 3D entities.
         */
        enum MATERIAL {
            MATERIAL_MAP_ALBEDO,       ///< Albedo map
            MATERIAL_MAP_METALNESS,    ///< Metalness map
            MATERIAL_MAP_NORMAL,       ///< Normal map
            MATERIAL_MAP_ROUGHNESS,    ///< Roughness map
            MATERIAL_MAP_OCCLUSION,    ///< Occlusion map
            MATERIAL_MAP_EMISSION,     ///< Emission map
            MATERIAL_MAP_HEIGHT,       ///< Height map
            MATERIAL_MAP_CUBEMAP,      ///< Cubemap
            MATERIAL_MAP_IRRADIANCE,   ///< Irradiance map
            MATERIAL_MAP_PREFILTER,    ///< Prefilter map
            MATERIAL_MAP_BRDF          ///< BRDF map
        };

        /**
         * @brief Virtual destructor for I3DEntity.
         */
        virtual ~I3DEntity() = default;

        /**
         * @brief Load a 3D entity from a file.
         * @param path The path to the file containing the 3D entity.
         * @return The loaded 3D entity.
         */
        virtual I3DEntity Load3DEntity(std::string const &path) = 0;

        /**
         * @brief Load textures for the 3D entity.
         * @param textures A vector of pairs containing texture file paths and their corresponding material types.
         */
        virtual void LoadTexture(std::vector<std::pair<std::string, MATERIAL>>) = 0;

        /**
         * @brief Set the position of the 3D entity.
         * @param x The x-coordinate of the position.
         * @param y The y-coordinate of the position.
         * @param z The z-coordinate of the position.
         */
        virtual void SetPosition(float x, float y, float z) = 0;

        /**
         * @brief Set the rotation of the 3D entity.
         * @param x The rotation angle around the x-axis.
         * @param y The rotation angle around the y-axis.
         * @param z The rotation angle around the z-axis.
         */
        virtual void SetRotation(float x, float y, float z) = 0;

        /**
         * @brief Set the scale of the 3D entity.
         * @param x The scale factor along the x-axis.
         * @param y The scale factor along the y-axis.
         * @param z The scale factor along the z-axis.
         */
        virtual void SetScale(float x, float y, float z) = 0;

        /**
         * @brief Set the color of the 3D entity.
         * @param color The color to set.
         */
        virtual void SetColor(Color color) = 0;
};
