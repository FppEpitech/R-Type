/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Users
*/
#include "Users.hpp"
#include "DbError.hpp"

Users::Users(Database *db) : _dbcore(db), _db(db->db), _rc(db->rc) {
    createUsersTable();
    if (sodium_init() < 0)
        throw new DbError("Couldn't load sodium...");
};

bool Users::userIdExists(int id) {
    std::string req("SELECT COUNT(*) FROM users WHERE id = ?;");
    sqlite3_stmt* stmt = _dbcore->prepareStmt(req);
    bool exists = false;

    if (!stmt)
        return false;
    sqlite3_bind_text(stmt, 1, std::to_string(id).c_str(), -1, SQLITE_STATIC);
    *_rc = sqlite3_step(stmt);
    if (*_rc == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        exists = (count > 0);
    } else if (*_rc != SQLITE_DONE) {
        std::cerr << "USER ID EXIST ERR: " << sqlite3_errmsg(_db.get()) << std::endl;
        return false;
    }
    sqlite3_finalize(stmt);
    return exists;
}

int Users::registerUser(std::string username, std::string password) {
    std::string req("INSERT INTO users (username, password) VALUES ('" + username + "', '" + this->hashPassword(password) + "');");
    *_rc = sqlite3_exec(_db.get(), req.c_str(), 0, 0, 0);
    if (*_rc != SQLITE_OK)
        return -1;
    return (int)sqlite3_last_insert_rowid(_db.get());
}

int Users::loginUser(std::string username, std::string password) {
    std::string req("SELECT id, username, password FROM users WHERE username = ?");
    sqlite3_stmt* stmt = _dbcore->prepareStmt(req);

    if (!stmt)
        return -1;
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    *_rc = sqlite3_step(stmt);
    if (*_rc == SQLITE_ROW) {
        int userId = sqlite3_column_int(stmt, 0);
        const char *pwd = (const char *)sqlite3_column_text(stmt, 2);

        if (this->verifyPassword(password, std::string(pwd))) {
            sqlite3_finalize(stmt);
            return userId;
        }
    }
    sqlite3_finalize(stmt);
    return -1;
}


std::string Users::hashPassword(std::string password) {

    char hashed[crypto_pwhash_STRBYTES];
    int res = crypto_pwhash_str(
        hashed,
        password.c_str(),
        password.size(),
        crypto_pwhash_OPSLIMIT_INTERACTIVE,
        crypto_pwhash_MEMLIMIT_INTERACTIVE
    );

    if (res != 0)
        return "";
    return std::string(hashed);
}

bool Users::verifyPassword(std::string password, std::string hash) {
    return crypto_pwhash_str_verify(hash.c_str(), password.c_str(), password.size()) == 0;
}

std::string Users::getUsernameById(int id) {
    std::string req("SELECT username FROM users WHERE id = ?;");
    sqlite3_stmt* stmt = _dbcore->prepareStmt(req);

    sqlite3_bind_int(stmt, 1, id);
    *_rc = sqlite3_step(stmt);
    if (*_rc == SQLITE_ROW) {
        std::string username((const char*)sqlite3_column_text(stmt, 0));
        sqlite3_finalize(stmt);
        return username;
    } else {
        sqlite3_finalize(stmt);
        return std::string("");
    }
}

Users::userSettings Users::getUserSettings(int id) {
    std::string req("SELECT res_width, res_height, daltonian_mode, skin FROM users WHERE id = ?;");
    sqlite3_stmt* stmt = _dbcore->prepareStmt(req);

    if (!stmt)
        return {-1, -1, -1.0};
    sqlite3_bind_int(stmt, 1, id);
    *_rc = sqlite3_step(stmt);
    if (*_rc == SQLITE_ROW) {
        int res_width = sqlite3_column_int(stmt, 0);
        int res_height = sqlite3_column_int(stmt, 1);
        float daltonian_mode = sqlite3_column_double(stmt, 2);
        std::string skin((char *)sqlite3_column_text(stmt, 3));
        sqlite3_finalize(stmt);
        return {res_width, res_height, daltonian_mode, skin};
    }
    sqlite3_finalize(stmt);
    return {-1, -1, -1.0, ""};
}

bool Users::setUserSettings(int id, int res_width, int res_height, float daltonian_mode, std::string skin) {
    std::string req("UPDATE users SET res_width = ?, res_height = ?, daltonian_mode = ?, skin = ? WHERE id = ?;");
    sqlite3_stmt* stmt = _dbcore->prepareStmt(req);

    if (!stmt)
        return false;
    sqlite3_bind_int(stmt, 1, res_width);
    sqlite3_bind_int(stmt, 2, res_height);
    sqlite3_bind_double(stmt, 3, daltonian_mode);
    sqlite3_bind_int(stmt, 4, id);
    sqlite3_bind_text(stmt, 5, skin.c_str(), -1, SQLITE_STATIC);
    *_rc = sqlite3_step(stmt);
    if (*_rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        std::cerr << "SET USER SETTINGS ERR: " << sqlite3_errmsg(_db.get()) << std::endl;
        return false;
    }
    sqlite3_finalize(stmt);
    return true;
}

bool Users::createUsersTable() {
    std::string reqUsers("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL UNIQUE, password TEXT NOT NULL, daltonian_mode FLOAT, res_width INT, res_height INT, skin TEXT NOT NULL);");
    *_rc = sqlite3_exec(_db.get(), reqUsers.c_str(), 0, 0, 0);
    if (*_rc != SQLITE_OK) {
        std::cerr << "CREATE TABLE ERR users: " << sqlite3_errmsg(_db.get()) << std::endl;
        return false;
    }
    return true;
}
