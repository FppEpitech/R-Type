/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Scores
*/
#include "Database.hpp"

class Scores {
    public:

        /**
         * @brief Construct a new Scores object
         *
         * @param db
         */
        Scores(Database db) : _dbcore(db), _db(db._db), _rc(db._rc) {};

        /**
         * @brief Destroy the Scores object.
         *
         */
        ~Scores() = default;

        /**
         * @brief Create the scores table.
         *
         * @return true
         * @return false
         */
        bool createScoresTable();

        /**
         * @brief Add a score to a user.
         *
         * @param id
         * @param score
         * @return true
         * @return false
         */
        bool addScore(int id, int score);

        /**
         * @brief Get the score of a user.
         *
         * @param id
         * @return int
         */
        int getUserBestScore(int id);

        /**
         * @brief Get the leaderboard.
         *
         * @return std::vector<int>
         */
        std::vector<std::pair<std::string,int>> getLeaderboard();

    private:
        Database _dbcore; // Database object
        std::shared_ptr<sqlite3> _db; // Database pointer
        std::shared_ptr<int> _rc; // Database return code
};
