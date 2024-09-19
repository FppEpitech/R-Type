/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** I
*/

#include <thread>
#include <iostream>
#include <asio.hpp>


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


class Network::Server {
    public:

        /**
         * @brief Constructs a new Server object.
         *
         * @param io_context The ASIO I/O context used for asynchronous operations.
         * @param port The port number on which the server listens.
         */
        Server(asio::io_context& io_context, int port);

        /**
         * @brief Sets the message handler callback function.
         *
         * @param callback A callback function that takes a message and a UDP endpoint as parameters.
         */
        void setMessageHandler(MessageHandler callback);

        /**
         * @brief Sends a message to a specific endpoint.
         *
         * @param message The message to be sent.
         * @param endpoint The UDP endpoint to which the message will be sent.
         */
        void send_message(const std::string& message, const asio::ip::udp::endpoint& endpoint);

    private:

        /**
         * @brief Starts receiving data asynchronously.
         */
        void receive();

        asio::ip::udp::socket socket_;
        asio::ip::udp::endpoint remote_endpoint_;
        std::array<char, 1024> recv_buffer_;
        MessageHandler messageHandler_;
};
