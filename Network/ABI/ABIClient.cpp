/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** ABIClient
*/

#include "ABINetwork.hpp"
#include "Client.hpp"
#include "Auth/Auth.hpp"
#include "InitMessage/InitMessage.hpp"
#include "KeyPressed/KeyPressed.hpp"
#include "CreateEntity/CreateEntity.hpp"
#include "UpdateComponent/UpdateComponent.hpp"
#include "ChatBox/ChatBox.hpp"
#include "RoomMessage/RoomMessage.hpp"

namespace ABINetwork
{

std::shared_ptr<INetworkUnit> createClient()
{
    return std::make_shared<Client>();
}

bool connectToServer(std::shared_ptr<INetworkUnit> networkUnit, std::string ipServer, int tcp_port)
{
    std::shared_ptr<Client> client = std::dynamic_pointer_cast<Client>(networkUnit);
    if (!client)
        return false;
    return client->connectToServer(ipServer, tcp_port);
}

void sendPacketLogin(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string password)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::LOGIN), message->createLoginPayload(userName, password), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketRegister(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string password)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::REGISTER), message->createRegisterPayload(userName, password), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketLogout(std::shared_ptr<INetworkUnit> networkUnit)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::LOGOUT), message->createLogoutPayload(), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketInit(std::shared_ptr<INetworkUnit> networkUnit)
{
    std::shared_ptr<InitMessage> message = std::make_shared<InitMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::INIT), message->createInitPayload(), networkUnit->getIdMessage(), networkUnit->getToken()));
}


void sendPacketKey(std::shared_ptr<INetworkUnit> networkUnit, int key)
{
    std::shared_ptr<KeyPressedMessage> message = std::make_shared<KeyPressedMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::KEY), message->createKeyPressedPayload(key), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketChatbox(std::shared_ptr<INetworkUnit> networkUnit, std::string userName, std::string chat)
{
    std::shared_ptr<ChatBoxMessage> message = std::make_shared<ChatBoxMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::CHAT_BOX_MESSAGE), message->createChatBoxPayload(userName, chat), networkUnit->getIdMessage(), networkUnit->getToken()));
}

std::pair<std::string, int> getEntityCreationInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<CreateEntityMessage> message = std::make_shared<CreateEntityMessage>();

    if (!message)
        return {"", 0};
    return message->getEntityPayload(packet);
}

std::pair<std::string, std::vector<std::variant<int, float, std::string, bool>>> getUpdateComponentInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<UpdateComponentMessage> message = std::make_shared<UpdateComponentMessage>();

    if (!message)
        return {"", {}};
    return message->getUpdateComponentPayload(packet);
}

void sendPacketGetRooms(std::shared_ptr<INetworkUnit> networkUnit)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::GET_ROOM), message->createGetRoomPayload(), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketCreateRoom(std::shared_ptr<INetworkUnit> networkUnit, std::string roomName, bool privateRoom, std::string roomPassword, bool cheatsRoom, int playerMaxRoom)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::CREATE_ROOM), message->createCreateRoomPayload(roomName, privateRoom, roomPassword, cheatsRoom, playerMaxRoom), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketJoinRoom(std::shared_ptr<INetworkUnit> networkUnit, std::string roomName, std::string password)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::JOIN_ROOM), message->createJoinRoomPayload(roomName, password), networkUnit->getIdMessage(), networkUnit->getToken()));
}

void sendPacketLeaveRoom(std::shared_ptr<INetworkUnit> networkUnit)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message || networkUnit->getToken() == 0)
        return;
    setMessageInQueue(networkUnit, message->_createPacket(uint8_t(IMessage::MessageType::LEAVE_ROOM), message->createLeaveRoomPayload(), networkUnit->getIdMessage(), networkUnit->getToken()));
}

std::tuple<std::string, int, int> getCreatedRoomInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<RoomMessage> message = std::make_shared<RoomMessage>();

    if (!message)
        return {"", 0, 0};
    return message->getCreatedRoomInfoFromPacket(packet);
}

bool getLoginAllowedInfoFromPacket(UDPPacket packet)
{
    std::shared_ptr<AuthMessage> message = std::make_shared<AuthMessage>();

    if (!message)
        return false;
    return message->getLoginAllowedInfoFromPacket(packet);
}

void setClientLogin(std::shared_ptr<INetworkUnit> networkUnit, INetworkUnit::LoginState loginState)
{
    std::shared_ptr<Client> client = std::dynamic_pointer_cast<Client>(networkUnit);
    if (!client)
        return;
    client->setIsLogin(loginState);
}

INetworkUnit::LoginState getClientLogin(std::shared_ptr<INetworkUnit> networkUnit)
{
    std::shared_ptr<Client> client = std::dynamic_pointer_cast<Client>(networkUnit);
    if (!client)
        return INetworkUnit::LoginState::NONE;
    return client->getIsLogin();
}

}
