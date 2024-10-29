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

Client::Client()
{
    _roomPassword = "";
    _loginState = LoginState::NONE;
    _serverIp = "";
    _tcpPort = 0;
    _udpPort = 0;
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
}

bool Client::connectToServer(std::string ipServer, int tcp_port)
{
    try {
        _serverIp = ipServer;
        _tcpPort = tcp_port;
        asio::ip::tcp::resolver resolver(*_io_context);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(_serverIp, std::to_string(_tcpPort));
        asio::connect(*_tcp_socket, endpoints);

        asio::error_code ec;
        asio::read(*_tcp_socket, asio::buffer(&_udpPort, sizeof(_udpPort)), ec);
        asio::read(*_tcp_socket, asio::buffer(&_token, sizeof(_token)), ec);
        // asio::read(*_tcp_socket, asio::buffer(&_idxPlayerComponent, sizeof(_idxPlayerComponent)), ec);
        std::cout << "Connected to server with token: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << _token << std::dec << std::endl;
        // std::cout << "Connected to server with index player component: " << _idxPlayerComponent << std::endl;

        _udp_socket->open(asio::ip::udp::v4());
        _server_endpoint = std::make_shared<asio::ip::udp::endpoint>(asio::ip::address::from_string(_serverIp), _udpPort);

        // TODO: When we will be able to send messages
        _startReceive();

        std::thread io_thread([this]() { _io_context->run(); });
        io_thread.detach();
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error during connection: " << e.what() << std::endl;
        return false;
    }
}

void Client::_addPacketToQueueReceived(UDPPacket packet)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _queueMessage.push_back(packet);
}

void Client::_startReceive()
{
    _udp_socket->async_receive_from(asio::buffer(_recvBuffer), *_server_endpoint,
        [this](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                try {
                    std::string message(_recvBuffer.data(), bytes_recvd);

                    UDPPacket packet(message);

                    _addPacketToQueueReceived(packet);

                } catch (const std::exception& e) {
                    std::cerr << "Exception in message handler: " << e.what() << std::endl;
                }
            }
            asio::post(_udp_socket->get_executor(),
                [this]() {
                    _startReceive();
                });
        });
}

void Client::sendMessage(std::vector<uint8_t> message, uint32_t token)
{
    (void) token;
    try {
        _udp_socket->async_send_to(asio::buffer(message), *_server_endpoint, [](const asio::error_code&, std::size_t) {});
    } catch (const std::exception& e) {
        std::cout << "Error in send Message client: " << e.what() << std::endl;
    }
}

int Client::getNumberClient()
{
    throw ABIError("A client unit can't have client connected.");
}

std::pair<int, int> Client::getPorts()
{
    return {_tcpPort, _udpPort};
}

void Client::setIsLogin(LoginState loginState)
{
    _loginState = loginState;
}

INetworkUnit::LoginState Client::getIsLogin()
{
    return _loginState;
}

void Client::setCurrentRoomPassword(std::string roomPassword)
{
    _roomPassword = roomPassword;
}

std::string Client::getCurrentRoomPassword()
{
    return _roomPassword;
}

}
