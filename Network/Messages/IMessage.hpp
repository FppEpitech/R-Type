/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** IMessage
*/

#include <vector>
#include <cstdint>

namespace ABINetwork {

class IMessage
{
    public:

        virtual ~IMessage() = default;

        virtual std::vector<uint8_t> getMessagePacket() = 0;
};

}
