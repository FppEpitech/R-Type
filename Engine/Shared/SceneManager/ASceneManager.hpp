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
#include "../../Client/Src/Components/TextComponent/TextComponent.hpp"
#include "../../Client/Src/Components/ScaleComponent/ScaleComponent.hpp"
#include "../../Client/Src/Components/ColourComponent/ColourComponent.hpp"
#include "../../Client/Src/Components/Size1DComponent/Size1DComponent.hpp"
#include "../../Client/Src/Components/ObjPathComponent/ObjPathComponent.hpp"
#include "../../Client/Src/Components/FontPathComponent/FontPathComponent.hpp"
#include "../../Client/Src/Components/MusicPathComponent/MusicPathComponent.hpp"
#include "../../Client/Src/Components/SoundPathComponent/SoundPathComponent.hpp"
#include "../../Client/Src/Components/MusicPitchComponent/MusicPitchComponent.hpp"
#include "Position2DComponent.hpp"
#include "Position3DComponent.hpp"
#include "../../Client/Src/Components/SoundPitchComponent/SoundPitchComponent.hpp"
#include "../../Client/Src/Components/MaterialMapComponent/MaterialMapComponent.hpp"
#include "../../Client/Src/Components/MusicVolumeComponent/MusicVolumeComponent.hpp"
#include "../../Client/Src/Components/SoundVolumeComponent/SoundVolumeComponent.hpp"
#include "../../Client/Src/Components/TexturePathComponent/TexturePathComponent.hpp"

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
            ASceneManager(std::shared_ptr<std::vector<ECS::Registry>> registries);

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

        protected:

            std::shared_ptr<std::vector<ECS::Registry>> _registries; // Registries for each scene.
            std::vector<std::unordered_map<KEY_MAP, std::shared_ptr<ISystem>>> _keysSystems; // Keys to load a system for each scene.
            std::vector<std::unordered_map<KEY_MAP, std::pair<std::size_t, std::string>>> _keysScenes; // Keys to load a scene for each scene.

            std::size_t _nextIndex; // Index of the next empty registry.

            std::vector<std::reference_wrapper<IComponent>> _components {
                _colourComponent,
                _fontPathComponent,
                _materialMapComponent,
                _musicPathComponent,
                _musicPitchComponent,
                _musicVolumeComponent,
                _objPathComponent,
                _position2DComponent,
                _position3DComponent,
                _scaleComponent,
                _size1DComponent,
                _soundPathComponent,
                _soundPitchComponent,
                _soundVolumeComponent,
                _textComponent,
                _texturePathComponent
            }; //< List of graphical components.

            ColourComponent         _colourComponent;       //< Colour component.
            FontPathComponent       _fontPathComponent;     //< Font path component.
            MaterialMapComponent    _materialMapComponent;  //< Material map component.
            MusicPathComponent      _musicPathComponent;    //< Music path component.
            MusicPitchComponent     _musicPitchComponent;   //< Music pitch component.
            MusicVolumeComponent    _musicVolumeComponent;  //< Music volume component.
            ObjPathComponent        _objPathComponent;      //< OBJ path component.
            Position2DComponent     _position2DComponent;   //< Position 2D component.
            Position3DComponent     _position3DComponent;   //< Position 3D component.
            ScaleComponent          _scaleComponent;        //< Scale component.
            Size1DComponent         _size1DComponent;       //< Size 1D component.
            SoundPathComponent      _soundPathComponent;    //< Sound path component.
            SoundPitchComponent     _soundPitchComponent;   //< Sound pitch component.
            SoundVolumeComponent    _soundVolumeComponent;  //< Sound volume component.
            TextComponent           _textComponent;         //< Text component.
            TexturePathComponent    _texturePathComponent;  //< Texture path component.

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
            void _loadScene(const std::string &path, std::size_t index);

            /**
             * @brief Load the next scenes of a already loaded scene.
             * @param path Path to the json file.
             * @param index Index of the registry to load the scene.
             */
            void _loadNextScenes(const std::string &path, std::size_t index);

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
             * @brief Change the current scene.
             * @param scene Scene to load.
             */
            void _changeScene(std::pair<std::size_t, std::string> scene);

            /**
             * @brief Load the graphical components in a register.
             * @param registry Register to fill with components.
             */
            void _loadGraphicComponentsInRegister(ECS::Registry registry);
    };
}
