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
        std::list<std::vector<uint8_t>> listMessage = networkUnit->getMessageToSendQueue();

        listMessage.push_back(message);
    }

    std::vector<uint8_t> getMessageInQueue(std::shared_ptr<INetworkUnit> networkUnit)
    {
        std::list<std::vector<uint8_t>> listMessage = networkUnit->getMessageToSendQueue();

        if (!listMessage.empty()) {
            std::vector<uint8_t> firstMessage = listMessage.front();
            listMessage.pop_front();
            return firstMessage;
        }

        return {};
    }

}
