/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** SceneManager
*/

#pragma once

#define DEFAULT_SCENE_PATH "config/scenes/menus/default.json"

#include <unordered_map>
#include <string>

class SceneManager {

    public:

        SceneManager();
        ~SceneManager();

        void processInput(const std::string &input);

    protected:

    private:

        std::unordered_map<std::string, std::string> _sceneKeys; // The second string will be a system
        std::unordered_map<std::string, std::string> _sceneComponents; // The second string will be a component

        void _loadSceneKeys(const std::string &path);
        void _loadScene(const std::string &path);
        void _loadSceneSystems();
        void _loadSceneComponents();
        void _changeScene(const std::string &sceneName);
};
