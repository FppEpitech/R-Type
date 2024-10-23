/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ANetworkUnit
*/

#include "ANetworkUnit.hpp"

namespace ABINetwork
{

    ANetworkUnit::ANetworkUnit()
    {
        _token = 0;
        _messageId = 0;
    }

    std::list<std::vector<uint8_t>>& ANetworkUnit::getMessageToSendQueue()
    {
        return this->_queueMessageToSend;
    }

    void ANetworkUnit::setMessageToSendQueue(std::vector<uint8_t> message)
    {
        _queueMessageToSend.push_back(message);
    }

    std::vector<uint8_t> ANetworkUnit::getMessageInQueue()
    {
        if (!_queueMessageToSend.empty()) {
            std::vector<uint8_t> firstMessage = _queueMessageToSend.front();
            _queueMessageToSend.pop_front();
            return firstMessage;
        }
        return {};
    }

    uint32_t ANetworkUnit::getToken()
    {
        return _token;
    }

    uint32_t &ANetworkUnit::getIdMessage()
    {
        return _messageId;
    }

} // namespace ABINetwork
