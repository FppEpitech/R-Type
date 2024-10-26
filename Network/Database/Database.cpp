/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Database
*/
#include "Database.hpp"
#include "DbError.hpp"
#include <memory>

Database::Database(std::string path) {
    sqlite3* db_handle = nullptr;

    rc = std::make_shared<int>(sqlite3_open(path.c_str(), &db_handle));
    db = std::shared_ptr<sqlite3>(db_handle, sqlite3_close);
    if (!db || !rc || *rc != SQLITE_OK)
        throw new DbError("Issues opening the sqlite db...");
}

std::shared_ptr<sqlite3_stmt> Database::prepareStmt(std::string query) {
    sqlite3_stmt *stmt;

    *rc = sqlite3_prepare_v2(db.get(), query.c_str(), -1, &stmt, nullptr);
    if (*rc != SQLITE_OK) {
        std::cerr << "PREPARE STMT ERR: " << sqlite3_errmsg(db.get()) << std::endl;
        return nullptr;
    }
    return std::shared_ptr<sqlite3_stmt>(stmt, sqlite3_finalize);
}
