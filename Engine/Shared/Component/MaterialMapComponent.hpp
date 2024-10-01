/*
** EPITECH PROJECT, 2024
** MaterialMapComponent.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../Interface/IComponent.hpp"

#include <vector>

/**
 * @class MaterialMapComponent
 * @brief Component for handling different types of material maps within the graphical engine.
 *
 * This component is used to store and manage paths, indexes, and types of material maps.
 */
class MaterialMapComponent : public AComponent {
    public:

        /**
         * @enum MaterialType
         * @brief Enum representing different types of material maps.
         *
         * All those type will be attributed to an 3D object to define its material.
         */
        enum MaterialType {
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

        std::vector<std::string> materialPaths; ///< Paths to the material maps.
        std::vector<size_t> materialIndexes;    ///< Indexes of the material maps.
        std::vector<MaterialType> materialTypes; ///< Types of the material maps.

        /**
         * @brief Construct a new MaterialMapComponent object
         *
         * @param paths Vector of paths to the material maps (default is empty).
         * @param indexes Vector of indexes of the material maps (default is empty).
         * @param types Vector of types of the material maps (default is empty).
         */
        MaterialMapComponent(std::vector<std::string> paths = {}, std::vector<size_t> indexes = {}, std::vector<MaterialType> types = {});
};
