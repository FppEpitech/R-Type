/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Db
*/

#pragma once

#include <iostream>
#include <sqlite3.h>
#include <memory>
#include <vector>
// #include "Scores.hpp"
    


class Database {

    struct userSettings {
        int res_width;
        int res_height;
        float daltonian_mode;
    };

    public:

        /**
         * @brief Construct a new db object
         *
         * @param path Path to the Database.
         */
        Database(std::string path);

        /**
         * @brief Destroy the Database object
         *
         */
        ~Database() = default;

        /**
         * @brief Check if a user id exists
         *
         * @param id
         * @return true
         * @return false
         */
        bool userIdExists(int id);

        /**
         * @brief Register a user
         *
         * @param username
         * @param password
         * @return int The id of the user.
         */
        int registerUser(std::string username, std::string password);

        /**
         * @brief Login a user
         *
         * @param username
         * @param password
         * @return int The id of the user.
         */
        int loginUser(std::string username, std::string password);

        /**
         * @brief Create the required tables for the database.
         *
         * @return true
         * @return false
         */
        bool createTables();

        /**
         * @brief Hash a password
         *
         * @param password
         * @return std::string
         */
        std::string hashPassword(std::string password);

        /**
         * @brief Check if a hashed pwd is another clear pwd.
         *
         * @param password
         * @return bool
         */
        bool verifyPassword(std::string password, std::string hash);

        /**
         * @brief Get the user data
         *
         * @param id
         * @return userSettings
         */
        Database::userSettings getUserSettings(int id);

        /**
         * @brief Set the User Settings object
         *
         * @param id
         * @param res_width
         * @param res_height
         * @param daltonian_mode
         */
        bool setUserSettings(int id, int res_width, int res_height, float daltonian_mode);

        /**
         * @brief Get the username by id
         *
         * @param id
         * @return std::string
         */
        std::string getUsernameById(int id);

        /**
         * @brief Prepare a statement
         *
         * @param query
         * @return sqlite3_stmt*
         */
        sqlite3_stmt *prepareStmt(std::string query);

        std::shared_ptr<sqlite3>_db = nullptr; // Database.
        std::shared_ptr<int> _rc = std::make_shared<int>(0); // Return code of db.
        // Scores scores = Scores(this); //The scores model
};
