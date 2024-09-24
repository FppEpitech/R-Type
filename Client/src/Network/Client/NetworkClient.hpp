/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** NetworkClient
*/

#include "../Network.hpp"

class Network::Client {

    using MessageHandler = std::function<void(std::string message)>;

    public:
        Client(const std::string& server_ip, int tcp_port, int udp_port);

        void connect(MessageHandler callback);
        void sendMessage(const std::string& message);
        void startReceive();

    private:
        std::string _server_ip;
        int _tcp_port;
        int _udp_port;

        std::shared_ptr<asio::io_context> _io_context;
        std::shared_ptr<asio::ip::tcp::socket> _tcp_socket;
        std::shared_ptr<asio::ip::udp::socket> _udp_socket;
        asio::ip::udp::endpoint _server_endpoint;
        uint32_t _token;

        std::array<char, 1024> _recv_buffer;

        MessageHandler  _messageHandler;    // Message Manager to process messages.
};