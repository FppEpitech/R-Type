/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** NetworkServer
*/

#include <thread>
#include <random>
#include <vector>
#include <cstdint>
#include <iostream>
#include <asio.hpp>
#include <stdexcept>
#include <unordered_map>

#include "Registry.hpp"
#include "../../../Shared/DefaultComponent/Draw/DrawComponent.hpp"
#include "NetworkPacket.hpp"
#include "Player/PlayerComponent.hpp"

/**
 * @namespace Network
 * @brief Network-related classes and functions
 */
namespace Network {

    /**
     * @brief Server class to Network (Init server, receive data and send data)
     */
    class Server;
};

class Network::Server
{
    using MessageHandler = std::function<void(Network::UDPPacket packet, const asio::ip::udp::endpoint&, std::shared_ptr<ECS::Registry> reg)>;

    public:

        /**
         * @brief Construct a new Server object.
         *
         * @param io_context The IO context to be used for asynchronous operations.
         * @param tcp_port The port number for the TCP acceptor.
         * @param udp_port The port number for the UDP socket.
         */
        Server(int tcp_port, int udp_port);

        /**
         * @brief Starts the server.
         *
         * @param callback Callback function called when the server receive data.
         * @param reg Registery with all system and Component.
         */
        void start(MessageHandler callback, std::shared_ptr<ECS::Registry> reg);

        /**
         * @brief Sends a message to a specific UDP endpoint.
         *
         * @param message The message to be sent.
         * @param endpoint The UDP endpoint to which the message is sent.
         */
        void sendMessage(std::vector<uint8_t>& packet, const asio::ip::udp::endpoint& endpoint);

        /**
         * @brief Create a Packet object.
         *
         * @param messageType Message Type to insert in Packet.
         * @param payload Payload to insert in Packet.
         * @return std::vector<uint8_t> The packet.
         */
        std::vector<uint8_t> createPacket(uint8_t messageType, const std::vector<uint8_t>& payload);

        /**
         * @brief Get the Clients List object.
         *
         * @return std::unordered_map<uint32_t, asio::ip::udp::endpoint> Client List.
         */
        std::unordered_map<uint32_t, asio::ip::udp::endpoint>& getClientsList();

    private:

        /**
         * @brief  Starts accepting new TCP connections.
         *
         * @param reg Registry with all list of component and system.
         */
        void _startAccept(std::shared_ptr<ECS::Registry> reg);

        /**
         * @brief Handles reading from a TCP socket.
         *
         * @param socket A shared pointer to the TCP socket from which data is being read.
         * @param client_id The ID of the client associated with the socket.
         */
        void _startRead(std::shared_ptr<asio::ip::tcp::socket> socket, uint32_t client_token);

        /**
         * @brief Starts receiving UDP messages.
         *
         * @param reg Registry with all list of component and system.
         */
        void _startReceive(std::shared_ptr<ECS::Registry> reg);

        /**
         * @brief Generate a token for the user connection.
         *
         * @return uint32_t Token generate.
         */
        uint32_t _generateToken(void);

        /**
         * @brief Send all client already connected to the new Client.
         *
         */
        void _getAllClientConnected(std::shared_ptr<ECS::Registry> reg, asio::ip::udp::endpoint token);

        std::shared_ptr<asio::io_context>                           _io_context;        // Shared pointer to the io_context object, used to manage asynchronous I/O operations.
        std::shared_ptr<asio::ip::tcp::acceptor>                    _tcp_acceptor;      // Shared pointer to the TCP acceptor object, used to accept incoming TCP connections.
        std::shared_ptr<asio::ip::udp::socket>                      _udp_socket;        // Shared pointer to the UDP socket object, used for sending and receiving UDP datagrams.
        asio::ip::udp::endpoint                                     _remote_endpoint;   // The remote client’s UDP endpoint, representing the client’s IP address and port.
        std::array<char, 1024>                                      _recv_buffer;       // Receive buffer to store data received via UDP.
        std::string                                                 _read_buffer;       // Read buffer to accumulate data received via TCP connection.
        std::unordered_map<uint32_t, asio::ip::udp::endpoint>       _clients;           // Hash table associating a unique identifier to the UDP endpoint of a connected client.
        MessageHandler                                              _messageHandler;    // Message Manager to process messages.
        uint32_t                                                    _messageId;         // Current Message ID (auto-incremente every send of message)
};
