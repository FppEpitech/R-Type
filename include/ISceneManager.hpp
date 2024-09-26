/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ISceneManager
*/

#pragma once

/**
 * @brief Namespace for the scene manager
 * This namespace contains all the classes or enums that are related to the scene management.
 *
 */
namespace SceneManager {

    /**
     * @brief Enum for the register index
     * This enum is used to deal with all the scenes that should be loaded.
     *
     * @param PREVIOUS The previous scene (can be Null if they're no previous scenes (like the first scene))
     * @param CURRENT The current scene (can't be null)
     * @param NEXT The next scene (can be null if they're no next scenes (like the last scene))
     *
     * @note The "Next" enum is used to indicate the first index of the next scenes, but all the next indexes till the end of the array are also considered as next scenes.
     */
    enum RegisterIndex {
        PREVIOUS = 0,
        CURRENT = 1,
        NEXT = 2
    }

    /**
     * @brief Interface for the scene manager
     * This interface is used to define the scene managers.
     *
     * @note We need to discuss about the utility of this interface, but for now, here it is.
     */
    class ISceneManager {
        public:
            virtual ~ISceneManager() = default;
    };
}
