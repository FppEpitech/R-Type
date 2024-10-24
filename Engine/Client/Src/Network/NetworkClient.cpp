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
    _messageId = 0x0000;
    _token = 0;
}

void Network::Client::_connectLock(ECS::Registry& reg, uint32_t token, int &idxPlayerComponent)
{
    ECS::SparseArray<IComponent> PlayerComponentArray = reg.get_components<IComponent>("PlayerComponent");
    ECS::SparseArray<IComponent> DrawComponentArray = reg.get_components<IComponent>("DrawComponent");
    for (std::size_t index = 0; index < PlayerComponentArray.size(); index++) {
        PlayerComponent* player = dynamic_cast<PlayerComponent*>(PlayerComponentArray[index].get());
        if (player && player->token == 0) {
            idxPlayerComponent += index;
            player->token = token;

            if (idxPlayerComponent < DrawComponentArray.size()) {
                DrawComponent* draw = dynamic_cast<DrawComponent*>(DrawComponentArray[idxPlayerComponent].get());
                if (draw)
                    draw->draw = true;
            }

            break;
        }
    }
}

void Network::Client::connect(MessageHandler callback, ECS::Registry& reg)
{
    try {
        asio::ip::tcp::resolver resolver(*_io_context);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(_server_ip, std::to_string(_tcp_port));
        asio::connect(*_tcp_socket, endpoints);

        asio::error_code ec;
        asio::read(*_tcp_socket, asio::buffer(&_token, sizeof(_token)), ec);
        asio::read(*_tcp_socket, asio::buffer(&_idxPlayerComponent, sizeof(_idxPlayerComponent)), ec);
        std::cout << "Connected to server with token: " << "0x" << std::hex << std::setw(8) << std::setfill('0') << _token << std::dec << std::endl;
        std::cout << "Connected to server with index player component: " << _idxPlayerComponent << std::endl;

        _idxPlayerServer = _idxPlayerComponent;
        _connectLock(reg, _token, _idxPlayerComponent);

        _udp_socket->open(asio::ip::udp::v4());
        _server_endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_server_ip), _udp_port);

        this->_messageHandler = std::move(callback);
        std::vector<uint8_t> initPacket = _createPacket();
        this->sendMessage(initPacket);
        _startReceive(reg);

        std::thread io_thread([this]() { _io_context->run(); });
        io_thread.detach();
    } catch (const std::exception& e) {
        std::cerr << "Error during connection: " << e.what() << std::endl;
    }
}

void Network::Client::sendMessage(std::vector<uint8_t>& packet)
{
    _udp_socket->async_send_to(asio::buffer(packet), _server_endpoint,
        [](const asio::error_code&, std::size_t) {});
}

void Network::Client::_startReceive(ECS::Registry& reg)
{
    _udp_socket->async_receive_from(asio::buffer(_recv_buffer), _server_endpoint,
        [this, &reg](const asio::error_code& error, std::size_t bytes_recvd) {
            if (!error && bytes_recvd > 0) {
                try {
                    std::string message(_recv_buffer.data(), bytes_recvd);
                    if (this->_messageHandler)
                        this->_messageHandler(message, reg);
                } catch (const std::exception& e) {
                    std::cerr << "Exception in message handler: " << e.what() << std::endl;
                }
            } else if (error) {
                std::cerr << "Error receiving message: " << error.message() << std::endl;
                if (_udp_socket) {
                    asio::error_code ec;
                    _udp_socket->cancel(ec);
                    _udp_socket->close(ec);
                    return;
                }
            }

            asio::post(_udp_socket->get_executor(),
                [this, &reg]() {
                    _startReceive(reg);
                });
        });
}

uint32_t Network::Client::getToken()
{
    return this->_token;
}

bool Network::Client::_SendArrowKey(KEY_MAP key, std::vector<uint8_t> packet)
{
    std::unordered_map<KEY_MAP, uint8_t> arrowKeyMap = {
        {KEY_UP, 0x01},
        {KEY_RIGHT, 0x02},
        {KEY_DOWN, 0x03},
        {KEY_LEFT, 0x04}
    };

    if (arrowKeyMap.find(key) != arrowKeyMap.end()) {
        packet[1] = static_cast<uint8_t>(MessageType::ArrowKey);
        packet[12] = static_cast<uint8_t>(arrowKeyMap[key]);
        sendMessage(packet);
        return true;
    } else {
        return false;
    }
}

bool Network::Client::_SendAlphaKey(KEY_MAP key, std::vector<uint8_t> packet)
{
    std::unordered_map<KEY_MAP, uint8_t> alphaKeyMap = {
        {KEY_A, 0x01}, {KEY_B, 0x02}, {KEY_C, 0x03}, {KEY_D, 0x04},
        {KEY_E, 0x05}, {KEY_F, 0x06}, {KEY_G, 0x07}, {KEY_H, 0x08},
        {KEY_I, 0x09}, {KEY_J, 0x0A}, {KEY_K, 0x0B}, {KEY_L, 0x0C},
        {KEY_M, 0x0D}, {KEY_N, 0x0E}, {KEY_O, 0x0F}, {KEY_P, 0x10},
        {KEY_Q, 0x11}, {KEY_R, 0x12}, {KEY_S, 0x13}, {KEY_T, 0x14},
        {KEY_U, 0x15}, {KEY_V, 0x16}, {KEY_W, 0x17}, {KEY_X, 0x18},
        {KEY_Y, 0x19}, {KEY_Z, 0x1A}
    };

    if (alphaKeyMap.find(key) != alphaKeyMap.end()) {
        packet[1] = static_cast<uint8_t>(MessageType::AlphaKey);
        packet[12] = static_cast<uint8_t>(alphaKeyMap[key]);
        sendMessage(packet);
        return true;
    } else {
        return false;
    }
}

bool Network::Client::_SendNumberKey(KEY_MAP key, std::vector<uint8_t> packet)
{
    std::unordered_map<KEY_MAP, uint8_t> numberKeyMap = {
        {KEY_KP_1, 0x01}, {KEY_KP_2, 0x02}, {KEY_KP_3, 0x03}, {KEY_KP_4, 0x04},
        {KEY_KP_5, 0x05}, {KEY_KP_6, 0x06}, {KEY_KP_7, 0x07}, {KEY_KP_8, 0x08},
        {KEY_KP_9, 0x09}, {KEY_KP_0, 0x0A}
    };

    if (numberKeyMap.find(key) != numberKeyMap.end()) {
        packet[1] = static_cast<uint8_t>(MessageType::NumberKey);
        packet[12] = static_cast<uint8_t>(numberKeyMap[key]);
        sendMessage(packet);
        return true;
    } else {
        return false;
    }
}

bool Network::Client::_SendSpecialKey(KEY_MAP key, std::vector<uint8_t> packet)
{
    std::unordered_map<KEY_MAP, uint8_t> specialKeyMap = {
        {KEY_SPACE, 0x01}, {KEY_ENTER, 0x02}, {KEY_ESCAPE, 0x03}, {KEY_BACKSPACE, 0x04},
        {KEY_TAB, 0x05}, {KEY_LEFT_SHIFT, 0x06}, {KEY_LEFT_CONTROL, 0x07}, {KEY_LEFT_ALT, 0x08},
        {KEY_CAPS_LOCK, 0x09}, {KEY_F1, 0x0A}, {KEY_F2, 0x0B}, {KEY_F3, 0x0C},
        {KEY_F4, 0x0D}, {KEY_F5, 0x0E}, {KEY_F6, 0x0F}, {KEY_F7, 0x10},
        {KEY_F8, 0x11}, {KEY_F9, 0x12}, {KEY_F10, 0x13}, {KEY_F11, 0x14}
    };

    if (specialKeyMap.find(key) != specialKeyMap.end()) {
        packet[1] = static_cast<uint8_t>(MessageType::SpecialKey);
        packet[12] = static_cast<uint8_t>(specialKeyMap[key]);
        sendMessage(packet);
        return true;
    } else {
        return false;
    }
}

void Network::Client::sendKeyPacket(KEY_MAP key)
{
    std::vector<uint8_t> packet = _createPacket();

    if (_SendArrowKey(key, packet))
        return;
    if (_SendAlphaKey(key, packet))
        return;
    if (_SendNumberKey(key, packet))
        return;
    if (_SendSpecialKey(key, packet))
        return;
    return;
}

std::vector<uint8_t> Network::Client::_createPacket()
{
    std::vector<uint8_t> packet;
    uint32_t payloadLength = 1;

    packet.push_back(VERSION);

    packet.push_back(0x00);

    packet.push_back(static_cast<uint8_t>(_messageId >> 8));
    packet.push_back(static_cast<uint8_t>(_messageId & 0xFF));
    _messageId = (_messageId + 1) % 65536;

    packet.push_back(static_cast<uint8_t>((_token >> 24) & 0xFF));
    packet.push_back(static_cast<uint8_t>((_token >> 16) & 0xFF));
    packet.push_back(static_cast<uint8_t>((_token >> 8) & 0xFF));
    packet.push_back(static_cast<uint8_t>(_token & 0xFF));

    packet.push_back(static_cast<uint8_t>(payloadLength >> 24));
    packet.push_back(static_cast<uint8_t>(payloadLength >> 16));
    packet.push_back(static_cast<uint8_t>(payloadLength >> 8));
    packet.push_back(static_cast<uint8_t>(payloadLength & 0xFF));

    packet.push_back(0x00);

    uint16_t checksum = 0;
    for (const auto& byte : packet) {
        checksum += byte;
    }
    packet.push_back(static_cast<uint8_t>(checksum >> 8));
    packet.push_back(static_cast<uint8_t>(checksum & 0xFF));
    return packet;
}

int Network::Client::getIdxPlayerComponent()
{
    return this->_idxPlayerComponent;
}

int Network::Client::getIdxPlayerServer()
{
    return this->_idxPlayerServer;
}
