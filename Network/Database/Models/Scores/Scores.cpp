/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Scores
*/

#include "Scores.hpp"

Scores::Scores(Database db) : _dbcore(db), _db(db.db), _rc(db.rc) {
    createScoresTable();
};

bool Scores::addScore(int id, int score) {
    std::string req("INSERT INTO scores (id, score) VALUES (?, ?);");
    std::shared_ptr<sqlite3_stmt> stmt = _dbcore.prepareStmt(req);
    if (!stmt)
        return false;
    sqlite3_bind_int(stmt.get(), 1, id);
    sqlite3_bind_int(stmt.get(), 2, score);
    *_rc = sqlite3_step(stmt.get());
    if (*_rc != SQLITE_DONE) {
        std::cerr << "ADD SCORE ERR: " << sqlite3_errmsg(_db.get()) << std::endl;
        return false;
    }
    return true;
}


int Scores::getUserBestScore(int id) {
    std::string req("SELECT MAX(score) FROM scores WHERE id = ?;");
    std::shared_ptr<sqlite3_stmt> stmt = _dbcore.prepareStmt(req);

    if (!stmt)
        return -1;
    sqlite3_bind_int(stmt.get(), 1, id);
    *_rc = sqlite3_step(stmt.get());
    if (*_rc == SQLITE_ROW) {
        int score = sqlite3_column_int(stmt.get(), 0);
        return score;
    }
    return -1;
}

std::vector<std::pair<std::string,int>> Scores::getLeaderboard(Users users) {
    std::string req("SElECT id, MAX(score) FROM scores GROUP BY id ORDER BY MAX(score) DESC LIMIT 10;");

    std::shared_ptr<sqlite3_stmt> stmt = _dbcore.prepareStmt(req);
    if (!stmt)
        return std::vector<std::pair<std::string,int>>();
    std::vector<std::pair<std::string,int>> scores;
    while (sqlite3_step(stmt.get()) == SQLITE_ROW)
        scores.push_back(std::pair(users.getUsernameById(sqlite3_column_int(stmt.get(), 0)), sqlite3_column_int(stmt.get(), 1)));
    return scores;
}

bool Scores::createScoresTable() {
    std::string reqScores("CREATE TABLE IF NOT EXISTS scores (id INTEGER NOT NULL, score INTEGER NOT NULL);");
    *_rc = sqlite3_exec(_db.get(), reqScores.c_str(), 0, 0, 0);
    if (*_rc != SQLITE_OK) {
        std::cerr << "CREATE TABLE ERR score: " << sqlite3_errmsg(_db.get()) << std::endl;
        return false;
    }
    return true;
}
