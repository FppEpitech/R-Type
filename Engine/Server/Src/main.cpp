/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** main
*/

#include "Application/Application.hpp"
#include "Database.hpp"
#include "Scores.hpp"

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

    std::cout << db.registerUser("theophile", "test") << std::endl;

    std::cout << db.loginUser("theophile", "test"  ) << std::endl;

    for (auto i : scores.getLeaderboard()) {
        std::cout << i.first << " " << i.second << std::endl;
    }


    // db.setUserSettings(1, 1920, 1080, 0.5f);

    // auto settings = db.getUserSettings(1);
    // std::cout << settings.daltonian_mode << std::endl;
    // std::cout << settings.res_height << std::endl;
    // std::cout << settings.res_width << std::endl;

    return 0;
}
