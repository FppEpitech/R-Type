/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Server
*/

#include "network.hpp"

Network::Server::Server(asio::io_context& io_context, int port)
    : socket_(io_context, asio::ip::udp::endpoint(asio::ip::address_v4::from_string("127.0.0.1"), port))
{
    receive();
}

void Network::Server::setMessageHandler(MessageHandler callback) {
    messageHandler_ = std::move(callback);
}

void Network::Server::send_message(const std::string& message, const asio::ip::udp::endpoint& endpoint) {
    socket_.async_send_to(
        asio::buffer(message), endpoint,
        [](const asio::error_code&, std::size_t) {});
}

void Network::Server::receive() {
    socket_.async_receive_from(asio::buffer(recv_buffer_), remote_endpoint_,
        [this](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                std::string message(recv_buffer_.data(), bytes_recvd);

                if (messageHandler_) {
                    messageHandler_(message, remote_endpoint_);
                }
            }
            receive();
    });
}
