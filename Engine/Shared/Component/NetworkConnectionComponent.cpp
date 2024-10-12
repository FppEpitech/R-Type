/*
** EPITECH PROJECT, 2024
** NetworkConnectionComponent.cpp
** File description:
** DESCRIPTION
*/

#include "NetworkConnectionComponent.hpp"

NetworkConnectionComponent::NetworkConnectionComponent(bool connect, std::string serverIp, std::string serverPort) :
    AComponent("NetworkConnectionComponent"), connect(connect), serverIp(serverIp), serverPort(serverPort) {}
