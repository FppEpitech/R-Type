/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** NetworkClient
*/

#include "NetworkClient.hpp"

Network::Client::Client(const std::string& server_ip, int tcp_port, int udp_port)
{
    _server_ip = server_ip;
    _tcp_port = tcp_port;
    _udp_port = udp_port;
    _io_context = std::make_shared<asio::io_context>();
    _tcp_socket = std::make_shared<asio::ip::tcp::socket>(*_io_context);
    _udp_socket = std::make_shared<asio::ip::udp::socket>(*_io_context);
}

void Network::Client::connect(MessageHandler callback) {
    try {
        asio::ip::tcp::resolver resolver(*_io_context);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(_server_ip, std::to_string(_tcp_port));
        asio::connect(*_tcp_socket, endpoints);

        std::cout << "Debug 1" << std::endl;

        asio::streambuf buf;
        asio::read_until(*_tcp_socket, buf, '\n');
        std::istream is(&buf);
        is >> _token;

        std::cout << "Connected to server with token: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << _token << std::endl;

        _udp_socket->open(asio::ip::udp::v4());
        _server_endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_server_ip), _udp_port);

        this->_messageHandler = std::move(callback);
        startReceive();

        std::thread io_thread([this]() { _io_context->run(); });
        io_thread.detach();
    } catch (const std::exception& e) {
        std::cerr << "Error during connection: " << e.what() << std::endl;
    }
}

void Network::Client::sendMessage(const std::string& message) {
    std::string packet = std::to_string(_token) + message;
    _udp_socket->async_send_to(asio::buffer(packet), _server_endpoint,
        [](const asio::error_code&, std::size_t) {});
}

void Network::Client::startReceive() {
    _udp_socket->async_receive_from(asio::buffer(_recv_buffer), _server_endpoint,
        [this](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                std::string message(_recv_buffer.data(), bytes_recvd);
                if (this->_messageHandler)
                    this->_messageHandler(message);
            }
        });
}
