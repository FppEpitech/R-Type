/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** NetworkServer
*/

#include "NetworkServer.hpp"

Network::Server::Server(int tcp_port, int udp_port)
{
    _io_context = std::make_shared<asio::io_context>();
    _tcp_acceptor = std::make_shared<asio::ip::tcp::acceptor>(*_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 4444));
    _udp_socket = std::make_shared<asio::ip::udp::socket>(*_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 4445));
}

void Network::Server::start(MessageHandler callback, ECS::Registry& reg)
{
    std::cout << "Server running on TCP port 4444 and UDP port 4445..." << std::endl;
    this->_messageHandler = std::move(callback);
    _startAccept(reg);
    _startReceive(reg);
    std::thread server_thread([this]() { _io_context->run(); });
    server_thread.detach();
}

uint32_t Network::Server::_generateToken(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> distrib(0, UINT32_MAX);

    return distrib(gen);
}

void Network::Server::_startAccept(ECS::Registry& reg)
{
    auto socket = std::make_shared<asio::ip::tcp::socket>(*_io_context);

    _tcp_acceptor->async_accept(*socket, [this, socket, &reg](const asio::error_code& error) {
        if (!error) {
            try {
                uint32_t token = _generateToken();
                while (_clients.find(token) != _clients.end())
                    token = _generateToken();

                bool tokenAssigned = false;

                ECS::SparseArray<IComponent> PlayerComponentArray = reg.get_components<IComponent>("PlayerComponent");
                for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
                    PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
                    if (player && player->token == 0) {
                        player->token = token;
                        tokenAssigned = true;
                        break;
                    }
                }

                if (tokenAssigned == false) {
                    std::cout << "No more place available" << std::endl;
                    socket->close();
                } else {
                    _clients[token] = asio::ip::udp::endpoint();
                    std::cout << "Client connected with token: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << token << std::dec << std::endl;

                    _startRead(socket, token);
                    asio::write(*socket, asio::buffer(&token, sizeof(token)));
                    _startAccept(reg);
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    });
}

void Network::Server::_startRead(std::shared_ptr<asio::ip::tcp::socket> socket, uint32_t client_token)
{
    asio::async_read_until(*socket, asio::dynamic_buffer(_read_buffer), '\n',
        [this, socket, client_token](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                if (error == asio::error::eof) {
                    std::cout << "Client disconnected (EOF) with ID: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << client_token << std::dec << std::endl;
                } else if (error == asio::error::connection_reset) {
                    std::cout << "Client disconnected (connection reset) with ID: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << client_token << std::dec << std::endl;
                } else {
                    std::cerr << "Error on receive: " << error.message() << std::endl;
                }
                _clients.erase(client_token);
            } else {
                _startRead(socket, client_token);
            }
        });
}

void Network::Server::_startReceive(ECS::Registry& reg)
{
    _udp_socket->async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint,
        [this, &reg](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                try {
                    std::string message(_recv_buffer.data(), bytes_recvd);

                    Network::UDPPacket packet(message);

                    auto it = _clients.find(packet.getToken());
                    if (it != _clients.end()) {
                        if (it->second == asio::ip::udp::endpoint())
                            _clients[packet.getToken()] = _remote_endpoint;
                        if (this->_messageHandler)
                            this->_messageHandler(packet, this->_remote_endpoint, reg);
                    }
                } catch (const std::exception& e) {
                    _startReceive(reg);
                }
            }
            _startReceive(reg);
        });
}

void Network::Server::sendMessage(const std::string& message, const asio::ip::udp::endpoint& endpoint)
{
    _udp_socket->async_send_to(asio::buffer(message), endpoint,
        [](const asio::error_code&, std::size_t) {});
}
