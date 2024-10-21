/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ANetworkUnit
*/

#include "ANetworkUnit.hpp"

namespace ABINetwork
{

    std::list<std::vector<uint8_t>>& ANetworkUnit::getMessageToSendQueue()
    {
        return this->_queueMessageToSend;
    }

}
