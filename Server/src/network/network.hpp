/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** I
*/

#include <thread>
#include <iostream>
#include <asio.hpp>
#include <unordered_map>

/**
 * @namespace Network
 * @brief Network-related classes and functions
 */
namespace Network {

    /**
     * @brief Server class to Network (Init server, receive data and send data)
     */
    class Server;

    using MessageHandler = std::function<void(const std::string&, const asio::ip::udp::endpoint&)>;
};

class Network::Server
{
    public:

        /**
         * @brief Construct a new Server object
         *
         * @param io_context The IO context to be used for asynchronous operations.
         * @param tcp_port The port number for the TCP acceptor.
         * @param udp_port The port number for the UDP socket.
         */
        Server(asio::io_context& io_context, int tcp_port, int udp_port);

        /**
         * @brief Starts the server.
         */
        void start(void);

        /**
         * @brief Sends a message to a specific UDP endpoint.
         *
         * @param message The message to be sent.
         * @param endpoint The UDP endpoint to which the message is sent.
         */
        void sendMessage(const std::string& message, const asio::ip::udp::endpoint& endpoint);

        /**
         * @brief Sets the message handler callback function.
         *
         * @param callback A callback function that takes a message and a UDP endpoint as parameters.
         */
        void setMessageHandler(MessageHandler callback);

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
        void _startRead(std::shared_ptr<asio::ip::tcp::socket> socket, int client_id);

        /**
         * @brief Starts receiving UDP messages.
         */
        void _startReceive(void);

        asio::io_context&                                   _io_context;
        asio::ip::tcp::acceptor                             _tcp_acceptor;
        asio::ip::udp::socket                               _udp_socket;
        asio::ip::udp::endpoint                             _remote_endpoint;
        std::array<char, 1024>                              _recv_buffer;
        std::string                                         _read_buffer;
        std::unordered_map<int, asio::ip::udp::endpoint>    _clients;
        MessageHandler                                      _messageHandler;
        int                                                 _nextClientId;
};

