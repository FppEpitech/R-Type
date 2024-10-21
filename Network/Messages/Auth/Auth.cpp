/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** AuthMessage
*/

#include "Auth/Auth.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

std::vector<asio::detail::buffered_stream_storage::byte_type> & AuthMessage::createLoginPayload(std::string userName, std::string password)
{
    _payload.clear();

    uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&userName);
    _payload.insert(_payload.end(), userNameBytes, userNameBytes + sizeof(std::string));

    uint8_t* passwordBytes = reinterpret_cast<uint8_t*>(&password);
    _payload.insert(_payload.end(), passwordBytes, passwordBytes + sizeof(std::string));

    return _payload;
}

std::vector<asio::detail::buffered_stream_storage::byte_type> & AuthMessage::createRegisterPayload(std::string userName, std::string password)
{
    return createLoginPayload(userName, password);
}

std::vector<asio::detail::buffered_stream_storage::byte_type> & AuthMessage::createLogoutPayload()
{
    _payload.clear();

    return _payload;
}

std::pair<std::string, std::string> AuthMessage::getLoginInfoFromPacket()
{
    return std::make_pair<std::string, std::string>("", "");
}

std::pair<std::string, std::string> AuthMessage::getRegisterInfoFromPacket()
{
    return std::make_pair<std::string, std::string>("", "");
}

uint32_t AuthMessage::getLogoutInfoFromPacket()
{
    return 0;
}

}
