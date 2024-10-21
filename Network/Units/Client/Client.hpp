/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Client
*/

#pragma once

#include <string>
#include <cstdint>
#include <asio.hpp>

#include "ABIError.hpp"
#include "ANetworkUnit.hpp"

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

/**
 * @class Client
 * @brief Represents a client in the network.
 *
 * This class inherits from `ANetworkUnit` and represents a client in the network architecture.
 */
class Client : public ANetworkUnit
{

    public:

        Client(std::string ipServer, int tcp_port, int udp_port);

        /**
         * @brief Destructor.
         *
         * Default destructor for `Client`, which is automatically called when an object
         * of this class is destroyed.
         */
        ~Client() = default;


    private:

        std::string                                 _serverIp;          // Server ip adress.
        int                                         _tcpPort;           // TCP port on witch we can connect to the server.
        int                                         _udpPort;           // UDP port on witch we can communicate to the server.

        std::shared_ptr<asio::io_context>           _io_context;        // Shared pointer to the io_context object, used to manage asynchronous I/O operations.
        std::shared_ptr<asio::ip::tcp::socket>      _tcp_socket;        // Shared pointer to the TCP acceptor object, used to accept incoming TCP connections.
        std::shared_ptr<asio::ip::udp::socket>      _udp_socket;        // Shared pointer to the UDP socket object, used for sending and receiving UDP datagrams.
        std::shared_ptr<asio::ip::udp::endpoint>    _server_endpoint;   // Server endpoint (used to communicate with the server).

        /**
         * @brief Function to connect the client to the server.
         *
         * @return true Connection worked.
         * @return false Connection failed.
         */
        bool _connect();
};

}
