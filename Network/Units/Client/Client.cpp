/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Client
*/

#include "Client.hpp"

#include <iostream>
#include <iomanip>

namespace ABINetwork
{

Client::Client(std::string ipServer, int tcp_port, int udp_port)
{
    _serverIp = ipServer;
    _tcpPort = tcp_port;
    _udpPort = udp_port;
    _io_context = std::make_shared<asio::io_context>();
    if (!_io_context)
        throw ABIError("Failed to create the client");
    _tcp_socket = std::make_shared<asio::ip::tcp::socket>(*_io_context);
    _udp_socket = std::make_shared<asio::ip::udp::socket>(*_io_context);
    if (!_tcp_socket || !_udp_socket)
        throw ABIError("Failed to create the client");
    _server_endpoint = nullptr;
    _messageId = 0x0000;
    _token = 0;
    if (!_connect())
        throw ABIError("Failed to connect to the server");
}

bool Client::_connect()
{
    try {
        asio::ip::tcp::resolver resolver(*_io_context);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(_serverIp, std::to_string(_tcpPort));
        asio::connect(*_tcp_socket, endpoints);

        asio::error_code ec;
        asio::read(*_tcp_socket, asio::buffer(&_token, sizeof(_token)), ec);
        // asio::read(*_tcp_socket, asio::buffer(&_idxPlayerComponent, sizeof(_idxPlayerComponent)), ec);
        std::cout << "Connected to server with token: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << _token << std::dec << std::endl;
        // std::cout << "Connected to server with index player component: " << _idxPlayerComponent << std::endl;

        _udp_socket->open(asio::ip::udp::v4());
        _server_endpoint = std::make_shared<asio::ip::udp::endpoint>(asio::ip::address::from_string(_serverIp), _udpPort);

        // TODO: When we will be able to send messages

        // this->_messageHandler = std::move(callback);
        // std::vector<uint8_t> initPacket = _createPacket();
        // this->sendMessage(initPacket);
        // _startReceive(reg);

        std::thread io_thread([this]() { _io_context->run(); });
        io_thread.detach();
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error during connection: " << e.what() << std::endl;
        return false;
    }
}

void Client::sendMessage(std::vector<uint8_t> message)
{
    _udp_socket->async_send_to(asio::buffer(message), *_server_endpoint, [](const asio::error_code&, std::size_t) {});
}

int Client::getNumberClient()
{
    throw ABIError("A client unit can't have client connected.");
}

}
