/*
** EPITECH PROJECT, 2024
** R-Type Client
** File description:
** main
*/

#include "Application.hpp"

int main()
{
    try {
        Application app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

