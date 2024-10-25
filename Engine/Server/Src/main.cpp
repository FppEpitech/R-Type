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

int main()
{
    // try {
    //     GameEngine::Application myApp;
    //     myApp.run();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    Database db("db.db");
    Scores scores(&db);
    Users users(&db);

    std::cout << users.registerUser("theophile", "test") << std::endl;

    std::cout << users.loginUser("theophile", "test"  ) << std::endl;


    scores.addScore(1, 100);
    for (auto i : scores.getLeaderboard(users)) {
        std::cout << i.first << " " << i.second << std::endl;
    }


    // db.setUserSettings(1, 1920, 1080, 0.5f);

    // auto settings = db.getUserSettings(1);
    // std::cout << settings.daltonian_mode << std::endl;
    // std::cout << settings.res_height << std::endl;
    // std::cout << settings.res_width << std::endl;

    return 0;
}
