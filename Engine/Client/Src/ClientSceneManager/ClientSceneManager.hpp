/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ClientSceneManager
*/

#pragma once

#include "ASceneManager.hpp"

#define FIRST_SCENE "Menus/mainMenu.json"
#define FIRST_GAME_SCENE "firstScene.json"

#define LIB_COMPONENTS_PATH "Engine/"
#define LIB_SYSTEMS_PATH "Engine/"
#define LIB_EVENT_HANDLER_PATH "Engine/"
#define SCENE_PATH "GameData/Scenes/"

/**
 * @brief Namespace for the scene manager.
 * This namespace contains all the classes or enums that are related to the scene management.
 */
namespace SceneManager {

    /**
     * @brief Client ClientSceneManager class.
     * It manages the scenes of the game and the transitions between them.
     */
    class ClientSceneManager : public ASceneManager {

        public:

            /**
             * @brief Construct a new ClientSceneManager object.
             * @param registries Registries for each scene.
             */
            ClientSceneManager(std::shared_ptr<ECS::Registry> registries, std::shared_ptr<EventListener> eventListener);

            /**
             * @brief Destroy the ClientSceneManager object.
             */
            ~ClientSceneManager() = default;

            /**
             * @brief Process input for the scene manager.
             * @param key The key input to process.
             * @param idxPacketEntities The index of the packet entities.
             * @return True if the input was processed successfully, false otherwise.
             */
            bool processInput(KEY_MAP key, int idxPacketEntities) override;

            /**
             * @brief Get the unordered map of sounds.
             */
            std::unordered_map<KEY_MAP, std::string> getSoundMap() override;

            /**
             * @brief Get the ConsumptionCompute object.
             * @return The ConsumptionCompute object.
             */
            ConsumptionCompute GetConsumptionCompute() override;

        private:

            /**
             * @brief Load the sounds for a scene.
             * @param root The JSON value containing the scene data.
             * @param index The index of the registry to load the sounds.
             */
            void _loadSceneSounds(Json::Value root, std::size_t index);

            /**
             * @brief Get the Component Lib Path.
             * @return The path to the component libraries.
             */
            std::string _getComponentLibPath() const override;

            /**
             * @brief Get the System Lib Path.
             * @return The path to the system libraries.
             */
            std::string _getSystemLibPath() const override;

            /**
             * @brief Get the Event Handler Lib Path.
             * @return The path to the event handler libraries.
             */
            std::string _getEventHandlerLibPath() const override;

            /**
             * @brief Get the Scenes Path.
             * @return The path to the scenes.
             */
            std::string _getScenesPath() const override;

            /**
             * @brief Load a scene from a json file.
             * @param path Path to the json file.
             * @param index Index of the registry to load the scene.
             */
            void _loadScene(const std::string &path, std::size_t index) override;

            /**
             * @brief Load the music for a scene.
             * @param root The JSON value containing the scene data.
             * @param index The index of the registry to load the music.
             */
            void _loadSceneMusic(Json::Value root, std::size_t index);
    };
}
