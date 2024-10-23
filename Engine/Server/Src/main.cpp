/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** main
*/

#include "Application/Application.hpp"
#include "User.hpp"

int main()
{
    // try {
    //     GameEngine::Application myApp;
    //     myApp.run();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    User user("users.db");

    std::cout << user.registerUser("theophile", "test") << std::endl;

    std::cout << user.loginUser("theophile", "test") << std::endl;

    return 0;
}
