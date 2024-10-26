/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** main
*/

#include "Application/Application.hpp"
#include "Database.hpp"
#include "Scores.hpp"
#include "Users.hpp"
#include <iostream>

int main()
{
    try {
        GameEngine::Application myApp;
        myApp.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
