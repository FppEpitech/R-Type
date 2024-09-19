/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Server
*/

#include "network.hpp"

Network::Server::Server(asio::io_context& io_context, int tcp_port, int udp_port)
    : _io_context(io_context),
      _tcp_acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), tcp_port)),
      _udp_socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), udp_port))
{
    _nextClientId = 1;
}

void Network::Server::start()
{
    _startAccept();
    _startReceive();
}

void Network::Server::_startAccept()
{
    auto socket = std::make_shared<asio::ip::tcp::socket>(_io_context);
    _tcp_acceptor.async_accept(*socket, [this, socket](const asio::error_code& error) {
        if (!error) {
            int client_id = _nextClientId++;
            _clients[client_id] = asio::ip::udp::endpoint();
            std::cout << "Client connected with ID: " << client_id << std::endl;

            _startRead(socket, client_id);

            asio::write(*socket, asio::buffer(std::to_string(client_id)));

            _startAccept();
        }
    });
}

void Network::Server::_startRead(std::shared_ptr<asio::ip::tcp::socket> socket, int client_id)
{
    asio::async_read_until(*socket, asio::dynamic_buffer(_read_buffer), '\n',
        [this, socket, client_id](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                if (error == asio::error::eof || error == asio::error::connection_reset) {
                    std::cout << "Client disconnected with ID: " << client_id << std::endl;
                    _clients.erase(client_id);
                } else {
                    std::cerr << "Error on receive: " << error.message() << std::endl;
                }
            } else {
                _startRead(socket, client_id);
            }
        });
}

void Network::Server::setMessageHandler(MessageHandler callback)
{
    this->_messageHandler = std::move(callback);
}

void Network::Server::_startReceive()
{
    _udp_socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint,
        [this](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                try {
                    std::string message(_recv_buffer.data(), bytes_recvd);
                    int client_id = std::stoi(message.substr(0, message.find(':')));

                    auto it = _clients.find(client_id);

                    if (it != _clients.end()) {
                        if (it->second == asio::ip::udp::endpoint()) {
                            _clients[client_id] = _remote_endpoint;
                        }

                        if (this->_messageHandler) {
                            this->_messageHandler(message, this->_remote_endpoint);
                        }
                    }
                } catch (const std::exception& e) {
                    _startReceive();
                }
            }
            _startReceive();
        });
}

void Network::Server::sendMessage(const std::string& message, const asio::ip::udp::endpoint& endpoint)
{
    _udp_socket.async_send_to(asio::buffer(message), endpoint,
        [](const asio::error_code&, std::size_t) {});
}
