/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** ISystemNetworkUpdate
*/

#pragma once

#include <string>
#include <functional>

#include "../../Ecs/Src/Registry.hpp"
#include "../Network/Packet/NetworkPacket.hpp"

/**
 * @brief Macro to define export symbols for different platforms.
 *
 * On Windows, it uses `__declspec(dllexport)` to export symbols.
 * On other platforms, it leaves the symbol definition empty.
 */
#ifdef _WIN32
    #define EXPORT_SYMBOL __declspec(dllexport)
#else
    #define EXPORT_SYMBOL
#endif

/**
 * @brief Interface class for network update systems.
 *
 */
class ISystemNetworkUpdate {

    public:

        /**
         * @brief Destroy the ISystemNetworkUpdate object.
         *
         */
        virtual ~ISystemNetworkUpdate() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(Network::UDPPacket packet, ECS::Registry& reg)>
         */
        virtual std::function<void(Network::UDPPacket packet, ECS::Registry& reg)> getFunction() = 0;
};
