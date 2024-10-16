/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIClient
*/

#include "ABINetwork.hpp"

namespace ABINetwork {

    std::shared_ptr<INetworkUnit> createClient(std::string ipServer, std::string portServer);

    void sendPacketRegister(std::shared_ptr<INetworkUnit> networkUnit);

    void sendPacketLogin(std::shared_ptr<INetworkUnit> networkUnit);

    void sendPacketLogout(std::shared_ptr<INetworkUnit> networkUnit);

    void createRoom(std::shared_ptr<INetworkUnit> networkUnit);

    void joinRoom(std::shared_ptr<INetworkUnit> networkUnit);

    void leaveRoom(std::shared_ptr<INetworkUnit> networkUnit);

    void deleteRoom(std::shared_ptr<INetworkUnit> networkUnit);
}
