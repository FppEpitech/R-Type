/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#pragma once

#define DEFAULT_SCENE_PATH "config/scenes/menus/default.json"

#include <unordered_map>

class SceneManager {

    public:

        SceneManager();
        ~SceneManager();

        void processInput(const std::string &input);

    protected:

    private:

        std::unordered_map<std::string, std::string> _sceneKeys; // The second string will be a system
        std::unodered_map<std::string, std::string> _sceneComponents; // The second string will be a component

        _loadSceneKeys(const std::string &path);
        _changeScene(const std::string &sceneName);
};
