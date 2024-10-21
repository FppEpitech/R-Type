/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** User
*/
#include <iostream>
#include <sqlite3.h>

class User {
    public:

        User(std::string path);

        ~User();

        bool userIdExists(int id);

        int registerUser(std::string username, std::string password);

        int loginUser(std::string username, std::string password);

        bool createTable();

        std::string createToken(int id);

    private:

        sqlite3 *_db = nullptr;
        int _rc = 0;
};
