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


class Scores;

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
         * @brief Create the required tables for the database.
         *
         * @return true
         * @return false
         */
        // bool createTables();

        /**
         * @brief Prepare a statement
         *
         * @param query
         * @return sqlite3_stmt*
         */
        sqlite3_stmt *prepareStmt(std::string query);

        std::shared_ptr<sqlite3>_db = nullptr; // Database.
        std::shared_ptr<int> _rc = std::make_shared<int>(0); // Return code of db.
};
