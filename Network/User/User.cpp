/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** User
*/
#include "User.hpp"

User::User(std::string path) {
    _rc = sqlite3_open(path.c_str(), &_db);
    if (_rc != SQLITE_OK) {
        std::cerr << "OPEN DB ERR: " << sqlite3_errmsg(_db) << std::endl;
    }
    this->createTable();
}

User::~User() {
    sqlite3_close(_db);
}

bool User::userIdExists(int id) {
    std::string req("SELECT COUNT(*) FROM users WHERE id = ?;");
    sqlite3_stmt* stmt;
    bool exists = false;

    _rc = sqlite3_prepare_v2(_db, req.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, std::to_string(id).c_str(), -1, SQLITE_STATIC);
    if (_rc != SQLITE_OK)
        std::cerr << "USER ID EXIST ERR: " << sqlite3_errmsg(_db) << std::endl;
    _rc = sqlite3_step(stmt);

    if (_rc == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        exists = (count > 0);
    } else if (_rc != SQLITE_DONE) {
        std::cerr << "USER ID EXIST ERR: " << sqlite3_errmsg(_db) << std::endl;
    }
    sqlite3_finalize(stmt);
    return exists;
}

int User::registerUser(std::string username, std::string password) {
    std::string req("INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "');");
    _rc = sqlite3_exec(_db, req.c_str(), 0, 0, 0);
    if (_rc != SQLITE_OK) {
        std::cerr << "REGISTER USER ERR: " << sqlite3_errmsg(_db) << std::endl;
        return -1;
    }
    return (int)sqlite3_last_insert_rowid(_db);
}

int User::loginUser(std::string username, std::string password) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, username, password FROM users WHERE username = ?";

    _rc = sqlite3_prepare_v2(_db, sql, -1, &stmt, 0);
    if (_rc != SQLITE_OK) {
        std::cerr << "PREP LOGIN USER ERR: " << sqlite3_errmsg(_db) << std::endl;
        return -1;
    }
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    _rc = sqlite3_step(stmt);
    if (_rc == SQLITE_ROW) {
        int userId = sqlite3_column_int(stmt, 0);
        const char *pwd = (const char *)sqlite3_column_text(stmt, 2);

        if (password == std::string(pwd)) {
            sqlite3_finalize(stmt);
            return userId;
        } else {
            std::cerr << "Got the user, but not the right pwd";
            return -1;
        }
    } else if (_rc == SQLITE_DONE) {
        std::cerr << "LOGIN USER ERR: User not found or incorrect password." << std::endl;
    } else {
        std::cerr << "LOGIN USER EXECUTE ERR: " << sqlite3_errmsg(_db) << std::endl;
    }
    sqlite3_finalize(stmt);
    return -1;
}

bool User::createTable() {
    std::string req("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL UNIQUE, password TEXT NOT NULL);");
    _rc = sqlite3_exec(_db, req.c_str(), 0, 0, 0);
    if (_rc != SQLITE_OK) {
        std::cerr << "CREATE TABLE ERR: " << sqlite3_errmsg(_db) << std::endl;
        return false;
    }
    return true;
}

// TODO : throwerr && dbsplit ? & hashgpwd

