/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Users
*/

#pragma once

#include "Database.hpp"
#include <sodium.h>

/**
 * @brief Users class
 *
 */
class Users {
    public:
        /**
         * @brief Construct a new Users object
         *
         * @param db
         */
        Users(Database *db);

        /**
         * @brief Destroy the Users object.
         *
         */
        ~Users() = default;

        /**
         * @brief Create the scores table.
         *
         * @return true
         * @return false
         */
        bool createUsersTable();

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
        Users::userSettings getUserSettings(int id);

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
         * @brief User settings struct
         *
         * @param res_width
         * @param res_height
         * @param daltonian_mode
         */
        struct userSettings {
            int res_width;
            int res_height;
            float daltonian_mode;
        };

    private:
        Database *_dbcore; // Database object
        std::shared_ptr<sqlite3> _db; // Database pointer
        std::shared_ptr<int> _rc; // Database return code
};
