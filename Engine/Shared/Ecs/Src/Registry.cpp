/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Registry
*/

#include "Registry.hpp"

namespace ECS {

entity_t Registry::spawn_entity() {
    if (!_dead_entities.empty()) {
        entity_t reused_entity = _dead_entities.back();
        _dead_entities.pop_back();
        _entities.push_back(reused_entity);
        return reused_entity;
    }
    _entities.push_back(_next_entity);
    return _next_entity++;
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
        if (_entities[i] == entity)
            _entities.erase(_entities.begin() + i);
    }
}

void Registry::run_systems(Network::UDPPacket& packet) {
    for (auto& system : _systems)
        system(*this, packet);
}

} // namespace ECS
