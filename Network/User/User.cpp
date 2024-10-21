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
}

User::~User() {
    sqlite3_close(_db);
}

bool User::userIdExists(int id) {
    std::string req("SELECT COUNT(*) FROM users WHERE id = " + std::to_string(id) + ";");
    sqlite3_stmt* stmt;
    bool exists = false;

    _rc = sqlite3_prepare_v2(_db, req.c_str(), -1, &stmt, nullptr);
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

std::string User::registerUser(std::string username, std::string password) {
    std::string req("INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "');");
    _rc = sqlite3_exec(_db, req.c_str(), 0, 0, 0);
    if (_rc != SQLITE_OK) {
        std::cerr << "REGISTER USER ERR: " << sqlite3_errmsg(_db) << std::endl;
        return "";
    }
    return "fkdqmfjkdlqmfjdklqfjldmf";
}

std::string User::loginUser(std::string username, std::string password) {
    std::string req("SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "';");
    _rc = sqlite3_exec(_db, req.c_str(), 0, 0, 0);
    if (_rc != SQLITE_OK) {
        std::cerr << "LOGIN USER ERR : " << sqlite3_errmsg(_db) << std::endl;
        return "";
    }
    return "fkdqmfjkdlqmfjdklqfjldmf";
}

bool User::createTable() {
    std::string req("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL, password TEXT NOT NULL);");
    _rc = sqlite3_exec(_db, req.c_str(), 0, 0, 0);
    if (_rc != SQLITE_OK) {
        std::cerr << "CREATE TABLE ERR: " << sqlite3_errmsg(_db) << std::endl;
        return false;
    }
    return true;
}

int main() {
    User userSystem("users.db");
    userSystem.registerUser("theophile", "test");
    userSystem.loginUser("fjdkqm","jfdqlm");
    userSystem.userIdExists(433);
}


//token / db not from this / token management / splitregister token etc- comments
