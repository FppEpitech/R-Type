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
    Database db("db.db");
    Users users(db);
    Scores scores(db);
    std::cout << users.registerUser("test", "test") << std::endl;
    std::cout << users.loginUser("test", "test");
    scores.addScore(1, 1);

    for (auto i : scores.getLeaderboard(users))
        std::cout << i.first << " " << i.second << std::endl;
    // try {
    //     GameEngine::Application myApp;
    //     myApp.run();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    return 0;
}
