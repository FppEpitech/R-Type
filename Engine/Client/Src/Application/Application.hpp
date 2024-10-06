/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** App
*/

#pragma once

#include <iostream>

#include "IGraphic.hpp"
#include "Registry.hpp"
#include "ClientErrors.hpp"
#include "NetworkClient.hpp"
#include "ClientSceneManager.hpp"
#include "GetGraphicalLibrary.hpp"
#include "DrawOBJ/DrawOBJSystem.hpp"
#include "DrawText/DrawTextSystem.hpp"
#include "DrawTexture/DrawTextureSystem.hpp"
#include "DrawTextureRect/DrawTextureRectSystem.hpp"
#include "SpriteSheetAnimation/SpriteSheetAnimationSystem.hpp"

#define WINDOW_TITLE "From noware"

/**
 * @brief Application class
 * It's the main class of the client application
 */
class Application {

    public:

        /**
         * @brief Construct a new Application object
         *
         */
        Application();

        /**
         * @brief Destroy the Application object
         *
         */
        ~Application() = default;

        /**
         * @brief Run the application
         *
         */
        void run();

    private:

        /**
         * @brief Callback function who handle the packet receive.
         *
         * @param packet Packet receive by the server
         */
        void _packetHandler(Network::UDPPacket packet);

        /**
         * @brief Function who handle keyboard signal.
         *
         * @param key Key entered.
         */
        void _keyboardHandler(std::size_t key);

        /**
         * @brief Initialize default graphics systems.
         *
         */
        void _initDefaultGraphicSystems();

        std::shared_ptr<ECS::Registry> _registry;                                        // Registries for each scene.
        std::shared_ptr<Network::Client>            _client;                                            // Network class for client.
        std::vector<std::function<void(ECS::Registry& reg, int idxPacketEntities)>> _defaultSystems;    // Default system.
        std::shared_ptr<SceneManager::ClientSceneManager>       _sceneManager;                          // load and handle scene in the ECS.
};
