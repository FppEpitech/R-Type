/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** main
*/

#include <iostream>
#include "asio.hpp"

#include "Application.hpp"

int main()
{
    Application app;
    
    asio::io_context io;
    app.run();
    return 0;
}
