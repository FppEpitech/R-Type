/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Server
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

#include "ABIError.hpp"
#include "UDPPacket.hpp"
#include "ANetworkUnit.hpp"

#define SERVER_TCP_PORT 0       // 0 for random port
#define SERVER_UDP_PORT 0       // 0 for random port

/**
 * @namespace ABINetwork
 * @brief Contains functions to manage network communication and operations.
 */
namespace ABINetwork
{

/**
 * @class Server
 * @brief Represents a server in the network.
 *
 * This class inherits from `ANetworkUnit` and represents a server in the network architecture.
 */
class Server : public ANetworkUnit
{

    public:

        /**
         * @brief Construct a new Server object.
         *
         * @param numberPlayer Number of player in a room of server.
         */
        Server(std::size_t numberMaxPlayer);

        /**
         * @brief Destructor.
         *
         * Default destructor for `Server`, which is automatically called when an object
         * of this class is destroyed.
         */
        ~Server() = default;

        /**
         * @brief Starts the server.
         */
        void start(void);

        /**
         * @brief Send all client already connected.
         *
         */
        std::unordered_map<uint32_t, asio::ip::udp::endpoint>& getClientsList();

        /**
         * @brief Send all messages of the queue.
         *
         * @param message Message to send.
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

    private:

        /**
         * @brief Starts accepting new TCP connections.
         *
         */
        void _startAccept(void);

        /**
         * @brief Handles reading from a TCP socket.
         *
         * @param socket A shared pointer to the TCP socket from which data is being read.
         * @param client_id The ID of the client associated with the socket.
         */
        void _startReadDisconnection(std::shared_ptr<asio::ip::tcp::socket> socket, uint32_t client_token);

        /**
         * @brief Starts receiving UDP messages.
         *
         */
        void _startReceive(void);

        /**
         * @brief Generate a token for the user connection.
         *
         * @return uint32_t Token generate.
         */
        uint32_t _generateToken(void);

        std::shared_ptr<asio::io_context>                           _io_context;            // Shared pointer to the io_context object, used to manage asynchronous I/O operations.
        std::shared_ptr<asio::ip::tcp::acceptor>                    _tcp_acceptor;          // Shared pointer to the TCP acceptor object, used to accept incoming TCP connections.
        std::shared_ptr<asio::ip::udp::socket>                      _udp_socket;            // Shared pointer to the UDP socket object, used for sending and receiving UDP datagrams.

        uint32_t                                                    _messageId;             // Current Message ID (auto-incremente every send of message)

        std::size_t                                                 _numberMaxPlayer;       // Number of player in aceptable in a room of server.
        std::size_t                                                 _currentNumberPlayer;   // Current number of player in accepted in a room of server.

        std::unordered_map<uint32_t, asio::ip::udp::endpoint>       _clients;               // Hash table associating a unique identifier to the UDP endpoint of a connected client.

        std::string                                                 _readBufferTCP;        // Read buffer to accumulate data received via TCP connection.
        std::array<char, 1024>                                      _recvBuffer;           // Receive buffer to store data received via UDP.
        asio::ip::udp::endpoint                                     _remoteEndpoint;       // The remote client’s UDP endpoint, representing the client’s IP address and port.

        std::vector<uint32_t>                                       _queueConnection;      // Connection queue

        /**
         * @brief Add a packet received to the queue.
         *
         * @param packet Packet received.
         */
        void _addPacketToQueueReceived(UDPPacket packet);
};

}
