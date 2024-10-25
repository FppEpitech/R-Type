/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** User
*/
#include "Database.hpp"
#include "DbError.hpp"

Database::Database(std::string path) {
    sqlite3* db = nullptr;

    *_rc = sqlite3_open(path.c_str(), &db);
    _db = std::shared_ptr<sqlite3>(db, sqlite3_close);
    if (!_db || *_rc != SQLITE_OK)
        throw new DbError("Issues opening the sqlite db...");
    // this->createTables();
}

sqlite3_stmt *Database::prepareStmt(std::string query) {
    sqlite3_stmt *stmt;

    *_rc = sqlite3_prepare_v2(_db.get(), query.c_str(), -1, &stmt, nullptr);
    if (*_rc != SQLITE_OK) {
        std::cerr << "PREPARE STMT ERR: " << sqlite3_errmsg(_db.get()) << std::endl;
        return nullptr;
    }
    return stmt;
}

// bool Database::createTables() {

// }
//"cln" max all -> push - structmodels / chckSpt - nrm - _priv checkShrd
