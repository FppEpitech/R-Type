/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

/**
 * @class ISound
 * @brief Interface for sound operations.
 *
 * This interface defines a set of methods for loading, updating, and controlling sound playback.
 */
class ISound {
    public:
        /**
         * @brief Virtual destructor for ISound.
         */
        virtual ~ISound() = default;

        /**
         * @brief Load a sound from a file.
         * @param fileName The name of the file to load the sound from.
         */
        virtual void LoadSound(const char *fileName) = 0;

        /**
         * @brief Check if the sound is ready to be played.
         * @return True if the sound is ready, false otherwise.
         */
        virtual bool IsSoundReady() = 0;

        /**
         * @brief Update the sound with new data.
         * @param data The new sound data.
         * @param sampleCount The number of samples in the data.
         */
        virtual void UpdateSound(const void *data, int sampleCount) = 0;

        /**
         * @brief Unload the sound.
         */
        virtual void UnloadSound() = 0;

        /**
         * @brief Play the sound.
         */
        virtual void PlaySound() = 0;

        /**
         * @brief Stop the sound.
         */
        virtual void StopSound() = 0;

        /**
         * @brief Set the volume of the sound.
         * @param volume The volume level to set (0.0 to 1.0).
         */
        virtual void SetSoundVolume(float volume) = 0;

        /**
         * @brief Get the current volume of the sound.
         * @return The current volume level (0.0 to 1.0).
         */
        virtual float GetSoundVolume() = 0;

        /**
         * @brief Set the pitch of the sound.
         * @param pitch The pitch level to set.
         */
        virtual void SetSoundPitch(float pitch) = 0;

        /**
         * @brief Get the current pitch of the sound.
         * @return The current pitch level.
         */
        virtual float GetSoundPitch() = 0;

        /**
         * @brief Set whether the sound should loop.
         * @param loop True to loop the sound, false otherwise.
         */
        virtual void SetSoundLoop(bool loop) = 0;

        /**
         * @brief Get whether the sound is set to loop.
         * @return True if the sound is set to loop, false otherwise.
         */
        virtual bool GetSoundLoop() = 0;
};
