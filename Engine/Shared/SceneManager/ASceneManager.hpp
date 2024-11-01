/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** ASceneManager.hpp
*/

#pragma once

#include <json/json.h>
#include <unordered_map>

#include "ISystem.hpp"
#include "ISceneManager.hpp"
#include "EventListener.hpp"
#include "PlayerComponent.hpp"
#include "Text/TextComponent.hpp"
#include "Draw/DrawComponent.hpp"
#include "Scale/ScaleComponent.hpp"
#include "KeyMaps/StringKeyMap.hpp"
#include "Colour/ColourComponent.hpp"
#include "Size1D/Size1DComponent.hpp"
#include "ObjPath/ObjPathComponent.hpp"
#include "FontPath/FontPathComponent.hpp"
#include "Editable/EditableComponent.hpp"
#include "EntityId/EntityIdComponent.hpp"
#include "Checkable/CheckableComponent.hpp"
#include "MusicPath/MusicPathComponent.hpp"
#include "SoundPath/SoundPathComponent.hpp"
#include "MusicPitch/MusicPitchComponent.hpp"
#include "Position2D/Position2DComponent.hpp"
#include "Position3D/Position3DComponent.hpp"
#include "SoundPitch/SoundPitchComponent.hpp"
#include "MaterialMap/MaterialMapComponent.hpp"
#include "MusicVolume/MusicVolumeComponent.hpp"
#include "SoundVolume/SoundVolumeComponent.hpp"
#include "TexturePath/TexturePathComponent.hpp"
#include "TextureRect/TextureRectComponent.hpp"
#include "../DefaultEventHandlers/IEventHandler.hpp"
#include "TextPosition2D/TextPosition2DComponent.hpp"
#include "NetworkConnection/NetworkConnectionComponent.hpp"
#include "SpriteSheetAnimation/SpriteSheetAnimationComponent.hpp"

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
            ASceneManager(std::shared_ptr<ECS::Registry> registry, std::shared_ptr<EventListener> eventListener);

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
            bool processUpdate(std::string componentType, ABINetwork::UDPPacket packet);

            /**
             * @brief Change the current scene.
             * @param scene Scene to load.
             */
            void changeScene(std::pair<std::size_t, std::string> scene);

            /**
             * @brief Get the registry.
             * @return ECS::Registry& The registry.
             */
            std::shared_ptr<ECS::Registry> getRegistry();

        protected:

            std::shared_ptr<ECS::Registry>                                                  _registry; // Registries for each scene.
            ECS::Registry                                                                   _defaultRegistry; // Default registry for the scene manager.
            std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>                           _keysSystems; // Keys to load a system for each scene.
            std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>                _keysScenes; // Keys to load a scene for each scene.

            std::unordered_map<std::string, std::function<void(ABINetwork::UDPPacket packet, ECS::Registry& reg)>>   _updateNetworkSystems; // Keys to load a scene for each scene.

            std::size_t                                                                     _nextIndex; // Index of the next empty registry.

            std::shared_ptr<EventListener>                                                  _eventListener; // Event listener for the scene manager.

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
             * @brief Get the event handler lib path.
             * @return std::string Path to the event handler lib.
             */
            virtual std::string _getEventHandlerLibPath() const = 0;

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
             * @brief Load the event handlers of a scene.
             * @param root Json root of the scene.
             * @param index Index of the registry to load the scene.
             */
            void _loadSceneEventHandlers(Json::Value root, std::size_t index);

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
