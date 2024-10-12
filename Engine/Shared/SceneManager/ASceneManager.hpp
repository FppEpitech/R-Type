/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ASceneManager.hpp
*/

#pragma once

#include <json/json.h>
#include <unordered_map>

#include "ISceneManager.hpp"
#include "../Interface/ISystem.hpp"
#include "../Enum/StringKeyMap.hpp"
#include "TextComponent.hpp"
#include "ScaleComponent.hpp"
#include "ColourComponent.hpp"
#include "Size1DComponent.hpp"
#include "ObjPathComponent.hpp"
#include "FontPathComponent.hpp"
#include "MusicPathComponent.hpp"
#include "SoundPathComponent.hpp"
#include "MusicPitchComponent.hpp"
#include "Position2DComponent.hpp"
#include "Position3DComponent.hpp"
#include "SoundPitchComponent.hpp"
#include "MaterialMapComponent.hpp"
#include "MusicVolumeComponent.hpp"
#include "SoundVolumeComponent.hpp"
#include "TexturePathComponent.hpp"
#include "TextureRectComponent.hpp"
#include "TextPosition2DComponent.hpp"
#include "NetworkConnectionComponent.hpp"
#include "SpriteSheetAnimationComponent.hpp"
#include "PlayerComponent.hpp"
#include "../Network/Packet/NetworkPacket.hpp"

#define CONFIG_SUFFIX ".json"

#ifdef _WIN32
    #define LIB_SUFFIX ".dll"
#else
    #define LIB_SUFFIX ".so"
#endif

/**
 * @brief Namespace for the scene manager.
 * This namespace contains all the classes or enums that are related to the scene management.
 */
namespace SceneManager {

    /**
     * @brief Abstract class for the scene manager.
     */
    class ASceneManager : public ISceneManager {
        public:

            /**
             * @brief Construct a new ASceneManager object.
             * @param registries Registries for each scene.
             */
            ASceneManager(std::shared_ptr<ECS::Registry> registry);

            /**
             * @brief Destroy the ASceneManager object.
             */
            virtual ~ASceneManager() = default;

            /**
             * @brief Process the input of the scene.
             * @param key Key to process.
             * @return true if the input has been processed, false otherwise.
             */
            bool processInput(KEY_MAP key, int idxPacketEntities);

            /**
             * @brief Process the Update network.
             *
             * @param packet Packet receive by the network.
             * @return true if the packet has been processed, false otherwise.
             */
            bool processUpdate(std::string componentType, Network::UDPPacket packet);

            /**
             * @brief Change the current scene.
             * @param scene Scene to load.
             */
            void _changeScene(std::pair<std::size_t, std::string> scene);

        protected:

            std::shared_ptr<ECS::Registry>                                                  _registry; // Registries for each scene.
            ECS::Registry                                                                   _defaultRegistry; // Default registry for the scene manager.
            std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>              _keysSystems; // Keys to load a system for each scene.
            std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>   _keysScenes; // Keys to load a scene for each scene.

            std::unordered_map<std::string, std::function<void(Network::UDPPacket packet, ECS::Registry& reg)>>   _updateNetworkSystems; // Keys to load a scene for each scene.

            std::size_t                                                                     _nextIndex; // Index of the next empty registry.

            /**
             * @brief Get the component lib path.
             * @return std::string Path to the component lib.
             */
            virtual std::string _getComponentLibPath() const = 0;

            /**
             * @brief Get the system lib path.
             * @return std::string Path to the system lib.
             */
            virtual std::string _getSystemLibPath() const = 0;

            /**
             * @brief Get the scenes path.
             * @return std::string Path to the scenes.
             */
            virtual std::string _getScenesPath() const = 0;

            /**
             * @brief Load a scene from a json file.
             * @param path Path to the json file.
             * @param index Index of the registry to load the scene.
             */
            virtual void _loadScene(const std::string &path, std::size_t index) = 0;

            /**
             * @brief Load the entities of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneEntities(Json::Value root, std::size_t index);

            /**
             * @brief Load the systems of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneSystems(Json::Value root, std::size_t index);

            /**
             * @brief Load the keys of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneKeys(Json::Value root, std::size_t index);

            /**
             * @brief Load the keys of a scene containing a json file.
             * @param key Key to load the scene.
             * @param path Path to the json file.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneKeysJson(std::string key, std::string path, std::size_t index);

            /**
             * @brief Load the keys of a scene containing a system.
             * @param key Key to load the scene.
             * @param system System to load.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneKeysSystem(std::string key, std::string system, std::size_t index);

                        /**
             * @brief Load the systems to change component from server.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadNetworkUpdateSystem(Json::Value root, std::size_t index);

            /**
             * @brief Initialise the default components of the scene manager.
             */
            void _initialiseDefaultComponents();
    };
}
