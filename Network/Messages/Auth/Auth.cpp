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
    std::vector<asio::detail::buffered_stream_storage::byte_type> payload;

    uint8_t* userNameBytes = reinterpret_cast<uint8_t*>(&userName);
    payload.insert(payload.end(), userNameBytes, userNameBytes + sizeof(std::string));

    uint8_t* passwordBytes = reinterpret_cast<uint8_t*>(&password);
    payload.insert(payload.end(), passwordBytes, passwordBytes + sizeof(std::string));

    return payload;
}

std::vector<asio::detail::buffered_stream_storage::byte_type> & AuthMessage::createRegisterPayload(std::string userName, std::string password)
{
    return createLoginPayload(userName, password);
}

std::vector<asio::detail::buffered_stream_storage::byte_type> & AuthMessage::createLogoutPayload()
{
    std::vector<asio::detail::buffered_stream_storage::byte_type> payload;

    return payload;
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
