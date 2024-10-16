/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABINetwork
*/

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

namespace ABINetwork {

    void setMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit, std::shared_ptr<IMessage> message);

    std::shared_ptr<IMessage> getMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit);
}
