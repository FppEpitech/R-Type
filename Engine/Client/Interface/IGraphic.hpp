/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../../Shared/enums/KeyMap.hpp"

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
        virtual void Init() = 0;

        /**
         * @brief Update the graphic module.
         */
        virtual void Update() = 0;

        /**
         * @brief Destroy the graphic module.
         */
        virtual void Destroy() = 0;

        /**
         * @brief Get the current key map.
         * @return The current key map.
         */
        virtual KEY_MAP GetKey() = 0;

        /**
         * @brief Draw the current frame.
         */
        virtual void Draw() = 0;

        /**
         * @brief Clear the current frame.
         */
        virtual void Clear() = 0;

        // TEXT

        /**
         * @brief Draw all texts.
         */
        virtual void DrawTexts() = 0;

        /**
         * @brief Check if there are any texts to draw.
         * @return True if there are texts to draw, false otherwise.
         */
        virtual bool HasText() = 0;

        // SOUND

        /**
         * @brief Play all sounds.
         */
        virtual void PlaySounds() = 0;

        /**
         * @brief Check if there are any sounds to play.
         * @return True if there are sounds to play, false otherwise.
         */
        virtual bool HasSound() = 0;

        // MUSIC

        /**
         * @brief Play all music tracks.
         */
        virtual void PlayMusics() = 0;

        /**
         * @brief Check if there are any music tracks to play.
         * @return True if there are music tracks to play, false otherwise.
         */
        virtual bool HasMusic() = 0;

        // 3D ENTITY

        /**
         * @brief Draw all 3D entities.
         */
        virtual void Draw3DEntities() = 0;

        /**
         * @brief Check if there are any 3D entities to draw.
         * @return True if there are 3D entities to draw, false otherwise.
         */
        virtual bool Has3DEntity() = 0;

        // 2D ENTITY

        /**
         * @brief Draw all 2D entities.
         */
        virtual void Draw2DEntities() = 0;

        /**
         * @brief Check if there are any 2D entities to draw.
         * @return True if there are 2D entities to draw, false otherwise.
         */
        virtual bool Has2DEntity() = 0;

        // TEXTURE

        /**
         * @brief Draw all textures.
         */
        virtual void DrawTextures() = 0;

        /**
         * @brief Check if there are any textures to draw.
         * @return True if there are textures to draw, false otherwise.
         */
        virtual bool HasTexture() = 0;

        // SHADER

        /**
         * @brief Draw all shaders.
         */
        virtual void DrawShaders() = 0;

        /**
         * @brief Check if there are any shaders to draw.
         * @return True if there are shaders to draw, false otherwise.
         */
        virtual bool HasShader() = 0;
};
