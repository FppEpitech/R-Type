/*
** EPITECH PROJECT, 2024
** IGraphic.hpp
** File description:
** DESCRIPTION
*/

#pragma once

/**
 * @class IMusic
 * @brief Interface for music operations.
 *
 * This interface defines a set of methods for loading, controlling, and querying music playback.
 */
class IMusic {
    public:
        /**
         * @brief Virtual destructor for IMusic.
         */
        virtual ~IMusic() = default;

        /**
         * @brief Load music from a file.
         * @param fileName The name of the file to load the music from.
         */
        virtual void LoadMusic(const char *fileName) = 0;

        /**
         * @brief Check if the music is ready to be played.
         * @return True if the music is ready, false otherwise.
         */
        virtual bool IsMusicReady(void) = 0;

        /**
         * @brief Play the music.
         */
        virtual void PlayMusic(void) = 0;

        /**
         * @brief Stop the music.
         */
        virtual void StopMusic(void) = 0;

        /**
         * @brief Unload the music.
         */
        virtual void UnloadMusic(void) = 0;

        /**
         * @brief Set the volume of the music.
         * @param volume The volume level to set (0.0 to 1.0).
         */
        virtual void SetMusicVolume(float volume) = 0;

        /**
         * @brief Get the current volume of the music.
         * @return The current volume level (0.0 to 1.0).
         */
        virtual float GetMusicVolume(void) = 0;

        /**
         * @brief Set the pitch of the music.
         * @param pitch The pitch level to set.
         */
        virtual void SetMusicPitch(float pitch) = 0;

        /**
         * @brief Get the current pitch of the music.
         * @return The current pitch level.
         */
        virtual float GetMusicPitch(void) = 0;

        /**
         * @brief Set whether the music should loop.
         * @param loop True to loop the music, false otherwise.
         */
        virtual void SetMusicLoop(bool loop) = 0;

        /**
         * @brief Get whether the music is set to loop.
         * @return True if the music is set to loop, false otherwise.
         */
        virtual bool GetMusicLoop(void) = 0;
};
