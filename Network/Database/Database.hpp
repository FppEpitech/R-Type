/*
** EPITECH PROJECT, 2024
** R-Type Network
** File description:
** Db
*/
#include <iostream>
#include <sqlite3.h>
#include <memory>
#include <vector>

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

        /**
         * @brief Hash a password
         *
         * @param password
         * @return std::string
         */
        std::string hashPassword(std::string password);

        /**
         * @brief Check if a hashed pwd is another clear pwd.
         *
         * @param password
         * @return bool
         */
        bool verifyPassword(std::string password, std::string hash);

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
         * @brief Get the leaderboard
         *
         * @return std::vector<int>
         */
        std::vector<int> getLeaderboard();

        /**
         * @brief Get the user data
         *
         * @param id
         */
        void getUserData(int id); // TO DEFINE -----------------------

        /**
         * @brief Set the user data
         *
         * @param width_res
         * @param height_res
         * @param daltonian_mode
         * @return true
         * @return false
         */
        bool setUserData(int width_res, int height_res, float daltonian_mode);

        /**
         * @brief Set the User Settings object
         *
         * @param id
         * @param res_width
         * @param res_height
         * @param daltonian_mode
         */
        void setUserSettings(int id, int res_width, int res_height, float daltonian_mode);

    private:

        std::shared_ptr<sqlite3>_db = nullptr; // Database.
        int _rc = 0; // Return code of db.
};
