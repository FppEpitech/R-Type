/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** NetworkPacket
*/

#pragma once

#include <thread>
#include <random>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <iostream>
#include <asio.hpp>
#include <stdexcept>
#include <unordered_map>

#define VERSION 0x01

enum class MessageType : uint8_t {
    ArrowKey    = 0x01,  // Arrow
    AlphaKey    = 0x02,  // Alpha (A-Z)
    NumberKey   = 0x03,  // Number (0-9)
    SpecialKey  = 0x04   // Special (Ctrl, Alt, etc.)
};

/**
 * @namespace Network
 * @brief Network-related classes and functions
 */
namespace Network {

    /**
     * @brief UDPPacket class who receive the packet and split it!
     *
     */
    class UDPPacket;
};

class Network::UDPPacket {

    public:

        /**
         * @brief Construct a new UDPPacket object.
         *
         * @param packetData The packet receive on the server.
         */
        UDPPacket(const std::string& packetData);

        /**
         * @brief Get the Version Type object.
         *
         * @return uint8_t The version inserted in the packet.
         */
        uint8_t getVersion(void) const;

        /**
         * @brief Get the Message Type object.
         *
         * @return uint8_t MessageType inserted in the packet.
         */
        uint8_t getMessageType(void) const;

        /**
         * @brief Get the Message ID object.
         *
         * @return uint16_t MessageID inserted in the packet.
         */
        uint16_t getMessageID(void) const;

        /**
         * @brief Get the Token object.
         *
         * @return uint32_t Token inserted in the packet.
         */
        uint32_t getToken(void) const;

        /**
         * @brief Get the Payload Length object.
         *
         * @return uint32_t PayloadLenght inserted in the packet.
         */
        uint32_t getPayloadLength(void) const;

        /**
         * @brief Get the Payload object.
         *
         * @return const std::vector<uint8_t>& Payload inserted in the packet.
         */
        const std::vector<uint8_t>& getPayload(void) const;

        /**
         * @brief Get the Checksum object.
         *
         * @return uint16_t Checksum inserted in the packet.
         */
        uint16_t getChecksum(void) const;

        /**
         * @brief Function to validate if the checksum in the packet is right.
         *
         * @return true If checksum is good.
         * @return false If cheksum isn't good.
         */
        bool validateChecksum(void);

        /**
         * @brief Display all objects of the packet.
         *
         */
        void displayPacket(void);

    private:
        uint8_t                 _version;           // Version of packet.
        uint8_t                 _messageType;       // Type of Message.
        uint16_t                _messageID;         // Id of Message.
        uint32_t                _token;             // Token's User who send the message.
        uint32_t                _payloadLength;     // Payload lenght.
        std::vector<uint8_t>    _payload;           // Payload related to the Message type.
        uint16_t                _checksum;          // Checksum to validate the authenticity of data.
};
