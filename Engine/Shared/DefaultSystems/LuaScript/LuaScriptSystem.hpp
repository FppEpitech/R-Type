/*
** EPITECH PROJECT, 2024
** LuaScriptSystem
** File description:
** LuaScriptSystem
*/

#pragma once

#include <iostream>
#include <sol/sol.hpp>
#include <optional>

#include "../../../../Engine/Shared/DefaultSystems/ISystem.hpp"
/**
 * @brief Run all lua scripts, giving them the ability to modify the game.
 *
 */
class LuaScriptSystem : public ASystem {

    public:

        /**
         * @brief Construct a new LuaScriptSystem System object.
         *
         */
        LuaScriptSystem();

        /**
         * @brief Destroy the LuaScriptSystem System object.
         *
         */
        ~LuaScriptSystem() = default;

        /**
         * @brief Get the Function object.
         *
         * @return std::function<void(ECS::Registry& reg, int idxPacketMobs)>
         */
        std::function<void(ECS::Registry& reg, int idxPacketMobs)> getFunction()
        {
            return [this](ECS::Registry& reg, int idxPacketMobs) {
                _runScripts(reg, idxPacketMobs);
            };
        }
        /**
         * @brief Allows to set an arg for a component, with type x.
         *
         * @tparam T
         * @param reg
         * @param entity
         * @param componentName
         * @param key
         * @param value
         * @return true
         * @return false
         */
        template <typename T>
        bool argSetter(ECS::Registry &reg, int entity, std::string componentName, std::string key, T value);

    /**
     * @brief Allows to get a component's argument value by key, of type T.
     *
     * @tparam T
     * @param reg
     * @param entity
     * @param componentName
     * @param argKey
     * @return T
     */
    template <typename T>
    std::optional<T> argGetter(ECS::Registry &reg, int entity, std::string componentName, std::string argKey);


    /**
     * @brief Allows to register a getter for a type T as str name x.
     *
     * @tparam T
     * @param reg
     * @param type
     * @param lua
     */
    template <typename T>
    void registerGetter(ECS::Registry &reg, std::string type, sol::state &lua);

    /**
     * @brief Registers a setter for T type
     *
     * @tparam T
     * @param reg
     * @param type
     * @param lua
     */
    template <typename T>
    void registerSetter(ECS::Registry &reg, std::string type, sol::state &lua);

    private:
        void _runScripts(ECS::Registry& reg, int idxPacketMobs); //run Lua Scripts.
};
