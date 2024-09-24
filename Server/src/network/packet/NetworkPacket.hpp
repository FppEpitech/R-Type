/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** NetworkPacket
*/

#include <iomanip>

#include "../Network.hpp"

class Network::UDPPacket {

    public:

        UDPPacket(const std::string& packetData);

        uint8_t getVersion(void) const;

        uint8_t getMessageType(void) const;

        uint16_t getMessageID(void) const;

        uint32_t getToken(void) const;

        uint32_t getPayloadLength(void) const;

        const std::vector<uint8_t>& getPayload(void) const;

        uint16_t getChecksum(void) const;

        bool validateChecksum(void);

        void displayPacket(void);

    private:
        uint8_t                 _version;
        uint8_t                 _messageType;
        uint16_t                _messageID;
        uint32_t                _token;
        uint32_t                _payloadLength;
        std::vector<uint8_t>    _payload;
        uint16_t                _checksum;
};

