/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ISceneManager.hpp
*/

#pragma once

#include "StringKeyMap.hpp"
#include "interfaces/IError.hpp"

/**
 * @brief Namespace for the scene manager.
 * This namespace contains all the classes or enums that are related to the scene management.
 */
namespace SceneManager {

    /**
     * @brief Enum for the register index.
     * This enum is used to deal with all the scenes that should be loaded.
     *
     * @param CURRENT The current scene.
     * @param PREVIOUS The previous scene.
     * @param NEXT The next scene.
     * @note All the scenes between NEXT and the end of the vector are next scenes.
     */
    enum RegisterIndex {
        CURRENT = 0,
        PREVIOUS = 1,
        NEXT = 2
    };

    /**
     * @brief Interface for the scene manager.
     */
    class ISceneManager {

        public:

            /**
             * @brief Destroy the ISceneManager object.
             */
            virtual ~ISceneManager() = default;

            /**
             * @brief Process the input of the scene.
             * @param key Key to process.
             * @return true if the input has been processed, false otherwise.
             */
            virtual bool processInput(KEY_MAP key) = 0;
    };

    /**
     * @brief Class for the scene manager errors.
     *
     */
    class SceneManagerErrors : public AError {

        public:

            /**
             * @brief Construct a new SceneManagerErrors object.
             *
             */
            SceneManagerErrors(const std::string &message) : AError(message) {}
    };

    /**
     * @brief Class for the scene manager json errors.
     *
     */
    class SceneManagerJsonErrors : public SceneManagerErrors {

        public:

            /**
             * @brief Construct a new SceneManagerJsonErrors object.
             *
             */
            SceneManagerJsonErrors(const std::string &message) : SceneManagerErrors(message) {}
    };
}