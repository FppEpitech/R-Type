/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Server
*/

#include "Server.hpp"

namespace ABINetwork
{

Server::Server(std::size_t numberMaxPlayer)
{
    _io_context = std::make_shared<asio::io_context>();
    if (!_io_context)
        throw ABIError("Failed to create the server");
    _tcp_acceptor = std::make_shared<asio::ip::tcp::acceptor>(*_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), SERVER_TCP_PORT));
    _udp_socket = std::make_shared<asio::ip::udp::socket>(*_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), SERVER_UDP_PORT));
    if (!_tcp_acceptor || !_udp_socket)
        throw ABIError("Failed to create the server");
    _messageId = 0x0000;
    _numberMaxPlayer = numberMaxPlayer;
    _currentNumberPlayer = 0;
    start();
}

void Server::start()
{
    std::cout << "Server running on TCP port " << _tcp_acceptor->local_endpoint().port() << " and UDP port " << _udp_socket->local_endpoint().port() << "..." << std::endl;

    _startAccept();
    _startReceive();
    std::thread server_thread([this]() { _io_context->run(); });
    server_thread.detach();
}

void Server::_startAccept()
{
    auto socket = std::make_shared<asio::ip::tcp::socket>(*_io_context);

    _tcp_acceptor->async_accept(*socket, [this, socket](const asio::error_code& error) {
        if (!error) {
            try {
                uint32_t token = _generateToken();
                while (_clients.find(token) != _clients.end())
                    token = _generateToken();

                if (_numberMaxPlayer > _currentNumberPlayer) {
                    _currentNumberPlayer++;
                    _clients[token] = asio::ip::udp::endpoint();

                    std::cout << "Client connected with token: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << token << std::dec <<
                    "| endpoint: " << _clients[token] << std::endl;

                    _queueConnection.push_back(std::make_pair(token, false));

                    int udpPort = _udp_socket->local_endpoint().port();
                    asio::write(*socket, asio::buffer(&udpPort, sizeof(udpPort)));
                    asio::write(*socket, asio::buffer(&token, sizeof(token)));
                    _startReadDisconnection(socket, token);
                    _startAccept();
                } else {
                    std::cout << "No more place available" << std::endl;
                    socket->close();
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    });
}

void Server::_startReadDisconnection(std::shared_ptr<asio::ip::tcp::socket> socket, uint32_t client_token)
{
    asio::async_read_until(*socket, asio::dynamic_buffer(_readBufferTCP), '\n',
        [this, socket, client_token](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                if (error == asio::error::eof) {
                    std::cout << "Client disconnected (EOF) with ID: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << client_token << std::dec << std::endl;
                    _currentNumberPlayer--;
                } else if (error == asio::error::connection_reset) {
                    std::cout << "Client disconnected (connection reset) with ID: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << client_token << std::dec << std::endl;
                    _currentNumberPlayer--;
                } else {
                    std::cerr << "Error on receive: " << error.message() << std::endl;
                }
                _clients.erase(client_token);
            } else {
                _startReadDisconnection(socket, client_token);
            }
        });
}

void Server::_addPacketToQueueReceived(UDPPacket packet)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _queueMessage.push_back(packet);
}

void Server::_startReceive()
{
    _udp_socket->async_receive_from(asio::buffer(_readBufferTCP), _remoteEndpoint,
        [this](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                try {
                    std::string message(_readBufferTCP.data(), bytes_recvd);

                    UDPPacket packet(message);

                    auto it = _clients.find(packet.getToken());
                    if (it != _clients.end()) {
                        if (it->second == asio::ip::udp::endpoint()) {
                            _clients[packet.getToken()] = _remoteEndpoint;
                        }
                        _addPacketToQueueReceived(packet);
                    }
                } catch (const std::exception& e) {
                    _startReceive();
                }
            }
            _startReceive();
        }
    );
}

uint32_t Server::_generateToken(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> distrib(0, UINT32_MAX);

    return distrib(gen);
}

std::unordered_map<uint32_t, asio::ip::udp::endpoint>& Server::getClientsList()
{
    return _clients;
}

void Server::sendMessage(std::vector<uint8_t> message)
{
    for (auto clientEndpoint : _clients)
        _udp_socket->send_to(asio::buffer(message), clientEndpoint.second);
}

int Server::getNumberClient()
{
    return _currentNumberPlayer;
}

std::pair<int, int> Server::getPorts()
{
    return {_tcp_acceptor->local_endpoint().port(), _udp_socket->local_endpoint().port()};
}

std::vector<std::pair<uint32_t, bool>>& Server::getqueueConnection()
{
    return _queueConnection;
}

}
