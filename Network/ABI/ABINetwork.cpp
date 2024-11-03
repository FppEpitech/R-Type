/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABINetwork
*/

#include "ABINetwork.hpp"

namespace ABINetwork
{

    void setMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit, std::vector<uint8_t> message, uint32_t token)
    {
        if (!networkUnit)
            return;
        networkUnit->setMessageToSendQueue(message, token);
    }

    std::pair<std::vector<uint8_t>, uint32_t> getMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit)
    {
        if (!networkUnit)
            return {};
        return networkUnit->getMessageInQueue();
    }

    void sendMessages(std::shared_ptr<INetworkUnit> networkUnit)
    {
        if (!networkUnit)
            return;
        std::lock_guard<std::mutex> lock(networkUnit->getMutex());
        while (!networkUnit->getMessageToSendQueue().empty()) {
            std::pair<std::vector<uint8_t>, uint32_t> message = getMessageInQueue(networkUnit);
            if (!message.first.empty())
                networkUnit->sendMessage(message.first, message.second);
        }
    }

    INetworkUnit::TypeOfNetwork getTypeOfNetwork(std::shared_ptr<INetworkUnit> networkUnit)
    {
        if (!networkUnit)
            return INetworkUnit::TypeOfNetwork::TYPE_UNKNOWN;
        return networkUnit->getTypeOfNetwork();
    }
}
