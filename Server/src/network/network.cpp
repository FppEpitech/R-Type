/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Server
*/

#include "network.hpp"

Network::Server::Server(asio::io_context& io_context, int port)
    : _socket(io_context, asio::ip::udp::endpoint(asio::ip::address_v4::from_string("127.0.0.1"), port))
{
    receive();
}

void Network::Server::setMessageHandler(MessageHandler callback) {
    this->_messageHandler = std::move(callback);
}

void Network::Server::send_message(const std::string& message, const asio::ip::udp::endpoint& endpoint) {
    _socket.async_send_to(
        asio::buffer(message), endpoint,
        [](const asio::error_code&, std::size_t) {});
}

void Network::Server::receive() {
    _socket.async_receive_from(asio::buffer(_recv_buffer), this->_remote_endpoint,
        [this](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                std::string message(this->_recv_buffer.data(), bytes_recvd);

                if (this->_messageHandler) {
                    this->_messageHandler(message, this->_remote_endpoint);
                }
            }
            receive();
    });
}
