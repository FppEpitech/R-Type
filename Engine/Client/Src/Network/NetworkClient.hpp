/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** NetworkClient
*/

#include <array>
#include <thread>
#include <string>
#include <iomanip>
#include <asio.hpp>
#include <iostream>

#include "NetworkPacket.hpp"
#include "PlayerComponent.hpp"
#include "ClientSceneManager.hpp"

# define POSITION_PLAYER_ENTITY_SERVER 8

/**
 * @namespace Network
 * @brief Network-related classes and functions
 */
namespace Network {

    /**
     * @brief Client class to Network (Connection to server, receive data and send data)
     */
    class Client;
};

class Network::Client
{

    using MessageHandler = std::function<void(Network::UDPPacket packet, ECS::Registry& reg)>;

    public:
        /**
         * @brief Construct a new Client object
         *
         * @param server_ip Ip of server.
         * @param tcp_port  TCP port used by the server.
         * @param udp_port  UDP port used by the server.
         */
        Client(const std::string& server_ip, int tcp_port, int udp_port);

        /**
         * @brief Function to connect the client to the server.
         *
         * @param callback Callback function called when the client receive data.
         * @param reg Registry with all component and entity.
         */
        void connect(MessageHandler callback, ECS::Registry& reg);

        /**
         * @brief Send a message to the server.
         *
         * @param packet PAcket to send to the server.
         */
        void sendMessage(std::vector<uint8_t>& packet);

        /**
         * @brief Get the Token object
         *
         * @return uint32_t Token of client.
         */
        uint32_t getToken();

        /**
         * @brief Get the Index of Player Component on Server
         *
         * @return int Index of Player Component on Server.
         */
        int getIdxPlayerComponent();

        /**
         * @brief Get the Index of Player connected on Server
         *
         * @return int Index of Player connected on Server.
         */
        int getIdxPlayerServer();

        /**
         * @brief Function who send the packet to server.
         *
         * @param key Key entered and sended to the server.
         */
        void sendKeyPacket(KEY_MAP key);

    private:

        /**
         * @brief Starts receiving UDP messages.
         *
         * @param reg Registry to pass to callback function.
         */
        void _startReceive(ECS::Registry& reg);

        /**
         * @brief Function to create a packet.
         *
         * @return std::vector<uint8_t> Packet.
         */
        std::vector<uint8_t> _createPacket();

        /**
         * @brief Send a Packet with Arrow in Message type and the Arrow key.
         *
         * @param keyCode The Key code to check if this is an Arrow Key.
         * @param packet The packet to send if this is an Arrow Key.
         */
        bool _SendArrowKey(KEY_MAP key, std::vector<uint8_t> packet);

        /**
         * @brief Send a Packet with Alpha in Message type and the Alpha key.
         *
         * @param keyCode The Key code to check if this is an Alpha Key.
         * @param packet The packet to send if this is an Alpha Key.
         */
        bool _SendAlphaKey(KEY_MAP key, std::vector<uint8_t> packet);

        /**
         * @brief Send a Packet with Number in Message type and the Number key.
         *
         * @param keyCode The Key code to check if this is an Number Key.
         * @param packet The packet to send if this is an Number Key.
         */
        bool _SendNumberKey(KEY_MAP key, std::vector<uint8_t> packet);

        /**
         * @brief Send a Packet with Special in Message type and the Special key.
         *
         * @param keyCode The Key code to check if this is an Special Key.
         * @param packet The packet to send if this is an Special Key.
         */
        bool _SendSpecialKey(KEY_MAP key, std::vector<uint8_t> packet);

        std::string                             _server_ip;         // Server IP
        int                                     _tcp_port;          // TCP port on witch we can connect to the server.
        int                                     _udp_port;          // UDP port on witch we can communicate to the server.

        std::shared_ptr<asio::io_context>       _io_context;        // Shared pointer to the io_context object, used to manage asynchronous I/O operations.
        std::shared_ptr<asio::ip::tcp::socket>  _tcp_socket;        // Shared pointer to the TCP acceptor object, used to accept incoming TCP connections.
        std::shared_ptr<asio::ip::udp::socket>  _udp_socket;        // Shared pointer to the UDP socket object, used for sending and receiving UDP datagrams.
        asio::ip::udp::endpoint                 _server_endpoint;   // Server endpoint (used to communicate with the server).
        uint32_t                                _token;             // Token of client (used to be identify on server)
        int                                     _idxPlayerComponent;// Index of Player Component in server.
        int                                     _idxPlayerServer;   // Index of Player connected in server.

        std::array<char, 1024>                  _recv_buffer;       // Receive buffer to store data received via UDP.

        MessageHandler                          _messageHandler;    // Message Manager to process messages.

        uint32_t                                _messageId;        // Current Message ID (auto-incremente every send of message)
};
