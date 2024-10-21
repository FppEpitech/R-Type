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

uint32_t ANetworkUnit::getToken()
{
    return _token;
}

uint32_t &ANetworkUnit::getIdMessage()
{
    return _messageId;
}

} // namespace ABINetwork
