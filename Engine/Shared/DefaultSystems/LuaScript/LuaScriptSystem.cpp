/*
** EPITECH PROJECT, 2024
** LuaScriptSystem
** File description:
** LuaScriptSystem
*/
#include <sol/sol.hpp>
#include "LuaScriptSystem.hpp"
#include <iostream>
#include <filesystem>
#include <IComponent.hpp>

LuaScriptSystem::LuaScriptSystem() : ASystem("LuaScriptSystem") {}

template <typename T>
bool LuaScriptSystem::argSetter(ECS::Registry &reg, int entity, std::string componentName, std::string key, T value) {

    try {
        ECS::SparseArray<IComponent> comp = reg.get_components<IComponent>(componentName);
        if (entity >= comp.size() || !comp[entity])
            return false;
        comp[entity]->setArg(key, value);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

template <typename T>
std::optional<T> LuaScriptSystem::argGetter(ECS::Registry &reg, int entity, std::string componentName, std::string argKey) {
    ECS::SparseArray<IComponent> comp;
    try {
        ECS::SparseArray<IComponent> comp = reg.get_components<IComponent>(componentName);
        if (entity >= comp.size() || !comp[entity])
            return std::nullopt;
         return std::any_cast<T>(comp[entity]->getArg(argKey));
    } catch (std::exception e) {
        return std::nullopt;
    }
    return std::nullopt;
}

template <typename T>
void LuaScriptSystem::registerGetter(ECS::Registry &reg, std::string type, sol::state &lua) {
    lua.set_function("getComponent" + type + "Arg", [&reg, this, &lua](int entity, std::string componentName, std::string arg) -> sol::object {
        std::optional<T> res = argGetter<T>(reg, entity, componentName, arg);
        if (!res.has_value())
            return sol::nil;
        return sol::make_object(lua.lua_state(), res.value());
    });
}

template <typename T>
void LuaScriptSystem::registerSetter(ECS::Registry &reg, std::string type, sol::state &lua) {
    lua.set_function("setComponent" + type + "Arg", [&reg, this](int entity, std::string componentName, std::string key, T value) {
        return argSetter<T>(reg, entity, componentName, key, value);
    });
}

void LuaScriptSystem::_runScripts(ECS::Registry& reg, int idx)
{
    std::lock_guard<std::mutex> lock(reg._myBeautifulMutex);
    try {
        for (auto &f : std::filesystem::directory_iterator("GameData/Scripts/")) {
            std::string path(f.path().string());
            sol::state lua;

            lua.set_function("getComponentsSize", [&reg, this](std::string componentName) {
                try {
                    int size = reg.get_components<IComponent>(componentName).size();
                    return size;
                } catch (std::exception e) {
                    return 0;
                }
            });

            registerGetter<float>(reg, "Float", lua); //getComponentFloatArg
            registerGetter<int>(reg, "Int", lua); //getComponentIntArg
            registerGetter<std::string>(reg, "Str", lua); //getComponentStrArg
            registerGetter<bool>(reg, "Bool", lua); //getComponentBoolArg

            registerSetter<float>(reg, "Float", lua); //setComponentFloatArg
            registerSetter<int>(reg, "Int", lua); ////setComponentIntArg
            registerSetter<std::string>(reg, "Str", lua); //setComponentStrArg
            registerSetter<bool>(reg, "Bool", lua); //setComponentBoolArg

            lua.open_libraries(sol::lib::base);

            lua.script_file(path);
        }

    } catch (std::exception e) {
    }
}

extern "C" {
    EXPORT_SYMBOL ISystem* loadSystemInstance() {
        return new LuaScriptSystem();
    }
}
