/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Registry
*/

#include "Registry.hpp"

namespace ECS {

entity_t Registry::spawnEntityIdx(std::size_t idx)
{
    entity_t a = idx;
    _entities.push_back(a);
    _next_entity = idx + 1;

    return a;
}

entity_t Registry::spawn_entity() {
    if (!_dead_entities.empty()) {
        entity_t reused_entity = _dead_entities.back();
        _dead_entities.pop_back();
        _entities.push_back(reused_entity);
        return reused_entity;
    }
    entity_t a = _next_entity;
    _entities.push_back(a);
    _next_entity++;

    return a;
}

std::vector<entity_t> Registry::getEntities()
{
    return _entities;
}

entity_t Registry::entity_from_index(std::size_t idx) {
    if (idx < _entities.size())
        return _entities[idx];
    throw std::runtime_error("Entity index out of bounds.");
}

void Registry::kill_entity(entity_t const& entity) {
    for (auto& [typeIdx, remove_func] : _remove_functions)
        remove_func(*this, entity);
    _dead_entities.push_back(entity);
    for (entity_t i = 0; i < _entities.size(); i++) {
        if (_entities[i] == entity) {
            _entities.erase(_entities.begin() + i);
            break;
        }
    }
}

void Registry::run_systems(int idxPacketEntities) {
    for (auto& system : _systems)
        system(*this, idxPacketEntities);
}

void Registry::cloneComponentsArray(ECS::Registry &registry)
{
    setComponentsArrays(registry._components_arrays, registry._remove_functions);
}

void Registry::setComponentsArrays(std::unordered_map <std::string, std::any> componentsArrays, std::unordered_map <std::string, remove_func_t> removeFunctions)
{
    _components_arrays = componentsArrays;
    _remove_functions = removeFunctions;
}

void Registry::clearComponentsArray()
{
    _components_arrays.clear();
    _remove_functions.clear();
}

void Registry::clearSystems()
{
    _systems.clear();
}

void Registry::clearEntities()
{
    _entities.clear();
    _dead_entities.clear();
    _next_entity = 0;
}

void Registry::addEvent(std::shared_ptr<IEvent> event)
{
    if (event)
        _eventQueue.push(event);
}

void Registry::popEvent()
{
    _eventQueue.pop();
}

std::queue<std::shared_ptr<IEvent>> Registry::getEventQueue()
{
    return _eventQueue;
}

} // namespace ECS
