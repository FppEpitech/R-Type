/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** NetworkClient
*/

#include "../Network.hpp"

class Network::Client
{

    using MessageHandler = std::function<void(std::string message)>;

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
         */
        void connect(MessageHandler callback);

        /**
         * @brief Send a message to the server.
         *
         * @param packet PAcket to send to the server.
         */
        void sendMessage(std::vector<uint8_t>& packet);

    private:

        /**
         * @brief Starts receiving UDP messages.
         *
         */
        void _startReceive();

        std::string                             _server_ip;         // Server IP
        int                                     _tcp_port;          // TCP port on witch we can connect to the server.
        int                                     _udp_port;          // UDP port on witch we can communicate to the server.

        std::shared_ptr<asio::io_context>       _io_context;        // Shared pointer to the io_context object, used to manage asynchronous I/O operations.
        std::shared_ptr<asio::ip::tcp::socket>  _tcp_socket;        // Shared pointer to the TCP acceptor object, used to accept incoming TCP connections.
        std::shared_ptr<asio::ip::udp::socket>  _udp_socket;        // Shared pointer to the UDP socket object, used for sending and receiving UDP datagrams.
        asio::ip::udp::endpoint                 _server_endpoint;   // Server endpoint (used to communicate with the server).
        uint32_t                                _token;             // Token of client (used to be identify on server)

        std::array<char, 1024>                  _recv_buffer;       // Receive buffer to store data received via UDP.

        MessageHandler                          _messageHandler;    // Message Manager to process messages.
};