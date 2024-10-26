/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Database
*/

#pragma once

#include <iostream>
#include <sqlite3.h>
#include <memory>
#include <vector>



/**
 * @brief Database class.
 *
 */
class Database {


    public:

        /**
         * @brief Construct a new db object.
         *
         * @param path Path to the Database.
         */
        Database(std::string path);

        /**
         * @brief Destroy the Database object.
         *
         */
        ~Database() = default;

        /**
         * @brief Prepare a statement.
         *
         * @param query
         * @return sqlite3_stmt*
         */
        sqlite3_stmt *prepareStmt(std::string query);

        std::shared_ptr<sqlite3> db = nullptr; // Database.
        std::shared_ptr<int> rc = nullptr; // Return code of db.
};
