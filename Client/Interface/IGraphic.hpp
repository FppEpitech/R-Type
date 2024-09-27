/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <vector>
#include <memory>

#include "I2dEntities.hpp"
#include "I3dEntities.hpp"
#include "IText.hpp"
#include "IMusic.hpp"
#include "ISound.hpp"
#include "IShader.hpp"
#include "KeyMap.hpp"

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
         * @brief Add a text object to the graphic module.
         *
         * This function adds a text object to the graphic module, which will be managed and rendered by the module.
         *
         * @param text A shared pointer to an IText object that represents the text to be added.
         */
        virtual void AddText(std::shared_ptr<IText> text) = 0;

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
         * @brief Add a sound object to the graphic module.
         *
         * This function adds a sound object to the graphic module, which will be managed and played by the module.
         *
         * @param sound A shared pointer to an ISound object that represents the sound to be added.
         */
        virtual void AddSound(std::shared_ptr<ISound> sound) = 0;

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
         * @brief Add a music object to the graphic module.
         *
         * This function adds a music object to the graphic module, which will be managed and played by the module.
         *
         * @param music A shared pointer to an IMusic object that represents the music to be added.
         */
        virtual void AddMusic(std::shared_ptr<IMusic> music) = 0;

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
         * @brief Add a 3D entity object to the graphic module.
         *
         * This function adds a 3D entity object to the graphic module, which will be managed and rendered by the module.
         *
         * @param entity A shared pointer to an I3DEntity object that represents the 3D entity to be added.
         */
        virtual void Add3DEntity(std::shared_ptr<I3DEntity> entity) = 0;

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
         * @brief Add a 2D entity object to the graphic module.
         *
         * This function adds a 2D entity object to the graphic module, which will be managed and rendered by the module.
         *
         * @param entity A shared pointer to an I2DEntity object that represents the 2D entity to be added.
         */
        virtual void Add2DEntity(std::shared_ptr<I2DEntity> entity) = 0;

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
         * @brief Add a texture object to the graphic module.
         *
         * This function adds a texture object to the graphic module, which will be managed and rendered by the module.
         *
         * @param texture A shared pointer to an ITexture object that represents the texture to be added.
         */
        virtual void AddTexture(std::shared_ptr<ITexture> texture) = 0;

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
         * @brief Add a shader object to the graphic module.
         *
         * This function adds a shader object to the graphic module, which will be managed and rendered by the module.
         *
         * @param shader A shared pointer to an IShader object that represents the shader to be added.
         */
        virtual void AddShader(std::shared_ptr<IShader> shader) = 0;

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
