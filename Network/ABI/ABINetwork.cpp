/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABINetwork
*/

#include "ABINetwork.hpp"

namespace ABINetwork
{

    void setMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit, std::vector<uint8_t> message)
    {
        if (!networkUnit)
            return;
        networkUnit->setMessageToSendQueue(message);
    }

    std::vector<uint8_t> getMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit)
    {
        if (!networkUnit)
            return {};
        return networkUnit->getMessageInQueue();
        // std::list<std::vector<uint8_t>> listMessage = networkUnit->getMessageToSendQueue();

        // if (!listMessage.empty()) {
        //     std::vector<uint8_t> firstMessage = listMessage.front();
        //     listMessage.pop_front();
        //     return firstMessage;
        // }
        // return {};
    }

    void sendMessages(std::shared_ptr<INetworkUnit> networkUnit)
    {
        if (!networkUnit)
            return;
        while (!networkUnit->getMessageToSendQueue().empty()) {
            std::vector<uint8_t> message = getMessageInQueue(networkUnit);
            if (!message.empty())
                networkUnit->sendMessage(message);
        }
    }
}
