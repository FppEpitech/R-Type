/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** main
*/

#include "Application/Application.hpp"
#include "Database.hpp"

int main()
{
    // try {
    //     GameEngine::Application myApp;
    //     myApp.run();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    Database db("db.db");


    std::cout << db.registerUser("theophile", "test") << std::endl;

    std::cout << db.loginUser("theophile", "test"  ) << std::endl;

    return 0;
}
