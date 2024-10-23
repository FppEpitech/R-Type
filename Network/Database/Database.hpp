/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Db
*/
#include <iostream>
#include <sqlite3.h>
#include <memory>

class Database {
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

    private:

        std::shared_ptr<sqlite3>_db = nullptr; // Database.
        int _rc = 0; // Return code of db.
};
