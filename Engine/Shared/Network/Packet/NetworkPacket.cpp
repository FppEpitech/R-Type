/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** NetworkPacket
*/

#include "NetworkPacket.hpp"

Network::UDPPacket::UDPPacket(const std::string& packetData)
{
    if (packetData.size() < 15)
        throw std::invalid_argument("Packet data too short.");

    _version = static_cast<uint8_t>(packetData[0]);
    _messageType = static_cast<uint8_t>(packetData[1]);
    _messageID = static_cast<uint16_t>((static_cast<uint16_t>(packetData[2]) << 8) | static_cast<uint16_t>(packetData[3]));

    _token = (static_cast<uint32_t>(static_cast<uint8_t>(packetData[4])) << 24) |
            (static_cast<uint32_t>(static_cast<uint8_t>(packetData[5])) << 16) |
            (static_cast<uint32_t>(static_cast<uint8_t>(packetData[6])) << 8)  |
            static_cast<uint32_t>(static_cast<uint8_t>(packetData[7]));

    _payloadLength = (static_cast<uint32_t>(packetData[8]) << 24) |
                        (static_cast<uint32_t>(packetData[9]) << 16) |
                        (static_cast<uint32_t>(packetData[10]) << 8) |
                        static_cast<uint32_t>(packetData[11]);

    if (packetData.size() != static_cast<std::size_t>(14) + static_cast<std::size_t>(_payloadLength))
        throw std::invalid_argument("Packet data size does not match the expected length.");
    _payload.assign(packetData.begin() + 12, packetData.begin() + 12 + _payloadLength);

    _checksum = (static_cast<uint16_t>(static_cast<uint8_t>(packetData[12 + _payloadLength]) << 8)) |
                    static_cast<uint16_t>(static_cast<uint8_t>(packetData[13 + _payloadLength]));
}

uint8_t Network::UDPPacket::getVersion() const
{
    return this->_version;
}

uint8_t Network::UDPPacket::getMessageType() const
{
    return this->_messageType;
}

uint16_t Network::UDPPacket::getMessageID() const
{
    return this->_messageID;
}

uint32_t Network::UDPPacket::getToken() const
{
    return this->_token;
}

uint32_t Network::UDPPacket::getPayloadLength() const
{
    return this->_payloadLength;
}

const std::vector<uint8_t>& Network::UDPPacket::getPayload() const
{
    return this->_payload;
}

uint16_t Network::UDPPacket::getChecksum() const
{
    return this->_checksum;
}

bool Network::UDPPacket::validateChecksum()
{
    uint32_t sum = 0;

    sum += _version;
    sum += _messageType;
    sum += (_messageID >> 8) & 0xFF;
    sum += _messageID & 0xFF;
    sum += (_token >> 24) & 0xFF;
    sum += (_token >> 16) & 0xFF;
    sum += (_token >> 8) & 0xFF;
    sum += _token & 0xFF;
    sum += (_payloadLength >> 24) & 0xFF;
    sum += (_payloadLength >> 16) & 0xFF;
    sum += (_payloadLength >> 8) & 0xFF;
    sum += _payloadLength & 0xFF;
    for (uint8_t byte : _payload)
        sum += byte;

    if (static_cast<uint16_t>(sum & 0xFFFF) == _checksum)
        return true;
    else
        return false;
}

void Network::UDPPacket::displayPacket(void)
{
    std::cout << "Version: "<< "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_version) << std::endl;
    std::cout << "Message Type: "<< "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_messageType) << std::endl;
    std::cout << "Message ID: "<< "0x" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(_messageID) << std::endl;
    std::cout << "Token: "<< "0x" << std::hex << std::setw(8) << std::setfill('0') << static_cast<int>(_token) << std::endl;
    std::cout << "Payload Length: "<< "0x" << std::hex << std::setw(8) << std::setfill('0') << static_cast<int>(_payloadLength) << std::endl;
    for (uint8_t bytes : _payload)
        std::cout << "Bytes payload: "<< "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes) << std::endl;
    std::cout << "Checksum: "<< "0x" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(_checksum) << std::dec << std::endl;
}
