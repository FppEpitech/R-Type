#pragma once

#include "SparseArray.hpp"

#include <any>
#include <typeindex>
#include <stdexcept>
#include <functional>
#include <unordered_map>

using entity_t = std::size_t;

class Registry {

    public :

        /**
         * @brief Register a component in the registry.
         *
         * @tparam Component to register.
         * @return SparseArray<Component>&
         */
        template <class Component>
        SparseArray<Component> &register_component()
        {
            std::type_index typeIdx(typeid(Component));

            if (_components_arrays.find(typeIdx) == _components_arrays.end()) {
                _components_arrays[typeIdx] = SparseArray<Component>();

                _remove_functions[typeIdx] = [](Registry& register, entity_t const& entity) {
                    register.remove_component<Component>(e);
                };
            }
            return std::any_cast<SparseArray<Component>&>(_components_arrays[typeIdx]);
        };

        /**
         * @brief Get a components by its type.
         * This function throw an error if the component
         * isn't registered.
         *
         * @tparam Component type to get.
         * @return SparseArray<Component>& Component get.
         */
        template <class Component>
        SparseArray<Component> &get_components()
        {
            std::type_index typeIdx(typeid(Component));
            auto it = _components_arrays.find(typeIdx);
            if (it == _components_arrays.end()) {
                throw std::runtime_error("Component type not registered.");
            }
            return std::any_cast<SparseArray<Component>&>(it->second);
        };

        /**
         * @brief Get a components by its type.
         * This function throw an error if the component
         * isn't registered.
         *
         * @tparam Component type to get.
         * @return SparseArray<Component> const& Component get.
         */
        template <class Component>
        SparseArray<Component> const &get_components() const
        {
            std::type_index typeIdx(typeid(Component));
            auto it = _components_arrays.find(typeIdx);
            if (it == _components_arrays.end()) {
                throw std::runtime_error("Component type not registered.");
            }
            return std::any_cast<const SparseArray<Component>&>(it->second);
        };

        /**
         * @brief Add an Entity in the register.
         *
         * @return entity_t Index of the entity created.
         */
        entity_t spawn_entity() {
            if (!_dead_entities.empty()) {
                entity_t reused_entity = _dead_entities.back();
                _dead_entities.pop_back();
                _entities.push_back(reused_entity);
                return reused_entity;
            }
            _entities.push_back(_next_entity);
            return _next_entity++;
        }

        /**
         * @brief Get entity from index.
         * This function throw an error if Entity
         * index out of bounds.
         *
         * @param idx Index of the index.
         * @return entity_t Entity get by index.
         */
        entity_t entity_from_index(std::size_t idx) {
            if (idx < _entities.size()) {
                return _entities[idx];
            }
            throw std::runtime_error("Entity index out of bounds.");
        }

        /**
         * @brief Kill an entity of the register.
         *  The index is placed in the dead entities list.
         *
         * @param entity Enity to kill.
         */
        void kill_entity(entity_t const& entity) {
            for (auto& [typeIdx, remove_func] : _remove_functions) {
                remove_func(*this, entity);
            }
            _dead_entities.push_back(entity);
            for (entity_t i = 0; i < _entities.size(); i++) {
                if (_entities[i] == entity)
                    _entities.erase(_entities.begin() + i);
            }
        }

        /**
         * @brief Add a component to an Entity.
         *
         * @tparam Component type to add.
         * @param entity Entity.
         * @param component Component to add.
         * @return SparseArray<Component>::reference_type Reference of the component.
         */
        template <typename Component>
        typename SparseArray<Component>::reference_type add_component(entity_t const& entity, Component&& component) {
            auto& components = get_components<Component>();
            return components.insert_at(entity, std::forward<Component>(component));
        }

        /**
         * @brief Add a component to an Entity.
         *
         * @tparam Component type to add.
         * @tparam Params type to create the component.
         * @param entity Entity.
         * @param params Params to create the component.
         * @return SparseArray<Component>::reference_type Reference of the component.
         */
        template <typename Component, typename... Params>
        typename SparseArray<Component>::reference_type emplace_component(entity_t const& entity, Params&&... params) {
            auto& components = get_components<Component>();
            return components.emplace_at(entity, std::forward<Params>(params)...);
        }

        /**
         * @brief Remove a component from an Entity.
         *
         * @tparam Component type to remove.
         * @param from Entity.
         */
        template <typename Component>
        void remove_component(entity_t const& from)
        {
            auto& components = get_components<Component>();
            components.erase(from);
        }

        using remove_func_t = std::function<void(Registry&, entity_t const&)>;

    private:

        //Arrays
        std::unordered_map<std::type_index, std::any>           _components_arrays;         // Array of components.
        std::unordered_map<std::type_index, remove_func_t>      _remove_functions;          // Array of functions to remove components.

        // Entities
        std::vector<entity_t>                                   _entities;                  // Array of Entities indexes.
        std::vector<entity_t>                                   _dead_entities;             // Array of dead Entities indexes.
        entity_t                                                _next_entity = 0;           // Index for the next Entity to create.
};
