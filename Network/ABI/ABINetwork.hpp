/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABINetwork
*/

#pragma once

#include <list>
#include <thread>
#include <random>
#include <vector>
#include <memory>
#include <cstdint>
#include <iostream>
#include <asio.hpp>
#include <stdexcept>
#include <unordered_map>

#include "IMessage.hpp"
#include "INetworkUnit.hpp"
#include "UDPPacket/UDPPacket.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{
    /**
     * @brief Adds a message to the network unit's message queue.
     *
     * @param networkUnit A shared pointer to the network unit where the message will be queued.
     * @param message A shared pointer to the message to be added to the queue.
     */
    void setMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit, std::vector<uint8_t> message);

    /**
     * @brief Retrieves the next message from the network unit's message queue.
     *
     * @param networkUnit A shared pointer to the network unit from which the message will be retrieved.
     * @return A shared pointer to the next message in the queue, or nullptr if the queue is empty.
     */
    std::vector<uint8_t> getMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit);

}
