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

        /**
         * @brief Construct a new Client object.
         *
         */
        Client();

        /**
         * @brief Destructor.
         *
         * Default destructor for `Client`, which is automatically called when an object
         * of this class is destroyed.
         */
        ~Client() = default;

        /**
         * @brief Send all messages of the queue.
         *
         * @param message MEssage to send.
         */
        void sendMessage(std::vector<uint8_t> message) override;

        /**
         * @brief Get the Number Client connected.
         *
         * @return int Number of client connected.
         * @throw Error if getNumberClient of a Client Unit.
         */
        int getNumberClient() override;

        /**
         * @brief Get tcp and udp port of a server.
         * For a client, it return the tcp and udp port
         * of the server to which it is connected.
         *
         * @return std::pair<int, int> Tcp and udp ports.
         */
        std::pair<int, int> getPorts() override;

        /**
         * @brief Function to connect the client to a server.
         *
         * @param ipServer Server's ip to connect to.
         * @param tcp_port Server's tcp port to connect to.
         * @return true Connection succeed.
         * @return false Connection failed.
         */
        bool connectToServer(std::string ipServer, int tcp_port);

        /**
         * @brief Set the Is Login object.
         *
         * @param loginState New value.
         */
        void setIsLogin(LoginState loginState);

        /**
         * @brief Get the Is Login object.
         *
         */
        LoginState getIsLogin();

    private:

        /**
         * @brief Start to receive messages from server.
         *
         */
        void _startReceive();

        /**
         * @brief Add a packet received to the queue.
         *
         * @param packet Packet received.
         */
        void _addPacketToQueueReceived(UDPPacket packet);


        std::string                                 _serverIp;          // Server ip adress.
        int                                         _tcpPort;           // TCP port on witch we can connect to the server.
        int                                         _udpPort;           // UDP port on witch we can communicate to the server.
        LoginState                                  _loginState;        // Check if the client is login.

        std::shared_ptr<asio::io_context>           _io_context;        // Shared pointer to the io_context object, used to manage asynchronous I/O operations.
        std::shared_ptr<asio::ip::tcp::socket>      _tcp_socket;        // Shared pointer to the TCP acceptor object, used to accept incoming TCP connections.
        std::shared_ptr<asio::ip::udp::socket>      _udp_socket;        // Shared pointer to the UDP socket object, used for sending and receiving UDP datagrams.
        std::shared_ptr<asio::ip::udp::endpoint>    _server_endpoint;   // Server endpoint (used to communicate with the server).
        std::array<char, 1024>                      _recvBuffer;        // Receive buffer to store data received via UDP.
};

}
