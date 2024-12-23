/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** Registry
*/

#pragma once

#include "Events/IEvent.hpp"
#include "SparseArray.hpp"

#include <any>
#include <typeindex>
#include <stdexcept>
#include <functional>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <queue>

/**
 * @brief Entity component system namespace.
 *
 */
namespace ECS {

/**
 * @brief Index type for an Entity in a registry.
 *
 */
using entity_t = std::size_t;


/**
 * @brief Registry class, main class of an ECS.
 * You can add component, entities and systems to a registry.
 *
 */
class Registry {

    public :

        enum class Identity {
            Serveur,
            Client
        };

        /**
         * @brief Register a component in the registry.
         *
         * @tparam Component to register.
         * @return SparseArray<Component>&
         */
        template <class Component>
        SparseArray<Component> &register_component(std::string typeIdx)
        {
            if (_components_arrays.find(typeIdx) == _components_arrays.end()) {
                _components_arrays[typeIdx] = SparseArray<Component>();

                _remove_functions[typeIdx] = [typeIdx](Registry& reg, entity_t const& entity) {
                    reg.remove_component<Component>(entity, typeIdx);
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
        SparseArray<Component> &get_components(std::string typeIdx)
        {
            auto it = _components_arrays.find(typeIdx);
            if (it == _components_arrays.end())
                throw std::runtime_error("Component type not registered.");
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
        SparseArray<Component> const &get_components(std::string typeIdx) const
        {
            auto it = _components_arrays.find(typeIdx);
            if (it == _components_arrays.end())
                throw std::runtime_error("Component type not registered.");
            return std::any_cast<const SparseArray<Component>&>(it->second);
        };

        /**
         * @brief Add an Entity with specifique idx in the register.
         *
         * @param idx Index
         * @return entity_t Index of the entity created.
         */
        entity_t spawnEntityIdx(std::size_t idx);

        /**
         * @brief Add an Entity in the register.
         *
         * @return entity_t Index of the entity created.
         */
        entity_t spawn_entity();

        /**
         * @brief Get Entity vector
         *
         */
        std::vector<entity_t> getEntities();

        /**
         * @brief Get entity from index.
         * This function throw an error if Entity
         * index out of bounds.
         *
         * @param idx Index of the index.
         * @return entity_t Entity get by index.
         */
        entity_t entity_from_index(std::size_t idx);

        /**
         * @brief Kill an entity of the register.
         *  The index is placed in the dead entities list.
         *
         * @param entity Entity to kill.
         */
        void kill_entity(entity_t const& entity);

        /**
         * @brief Set a component to an Entity.
         *
         * @tparam Component type to set.
         * @param entity Entity.
         * @param component Component to set.
         * @param typeIdx Type index of the component.
         * @return SparseArray<Component>::reference_type Reference of the component.
         */
        template <typename Component>
        typename SparseArray<Component>::reference_type set_component(entity_t const& entity, std::shared_ptr<Component> component, std::string typeIdx) {
            auto& components = this->get_components<Component>(typeIdx);
            return components.insert_at(entity, component);
        }

        /**
         * @brief Remove a component from an Entity.
         *
         * @tparam Component type to remove.
         * @param from Entity.
         */
        template <typename Component>
        void remove_component(entity_t const& from, std::string typeIdx)
        {
            auto& components = get_components<Component>(typeIdx);
            components.insert_at(from, nullptr);
        }

        /**
         * @brief Add a system to the registry.
         *
         * @tparam Components Type of components used in the registry.
         * @tparam Function Type of the function system.
         * @param function of the system to add.
         */
        template<typename Function>
        void add_system(Function const& function) {
            _systems.emplace_back(
                [this, function](Registry& reg, int idxPacketEntities) {
                    function(*this, idxPacketEntities);
                }
            );
        }

        /**
         * @brief Run all registry's systems.
         *
         */
        void run_systems(int idxPacketEntities);

        using remove_func_t = std::function<void(Registry&, entity_t const&)>;

        /**
         * @brief Clone the components array of a registry.
         *
         * @param registry Registry to clone.
         */
        void cloneComponentsArray(Registry &registry);

        /**
         * @brief Set the components arrays.
         *
         * @param componentsArrays Components arrays to set.
         * @param removeFunctions Remove functions to set.
         */
        void setComponentsArrays(std::unordered_map<std::string, std::any> componentsArrays, std::unordered_map<std::string, remove_func_t> removeFunctions);

        /**
         * @brief Clear all components arrays.
         *
         */
        void clearComponentsArray();

        /**
         * @brief Clear all systems.
         *
         */
        void clearSystems();

        /**
         * @brief Clear all entities.
         *
         */
        void clearEntities();

        /**
         * @brief Add an event to the event queue.
         *
         * @param event Event to add.
         */
        void addEvent(std::shared_ptr<IEvent> event);

        /**
         * @brief Pop the first event of the event queue.
         *
         */
        void popEvent();

        /**
         * @brief Get the event queue.
         *
         * @return std::queue<IEvent> Event queue.
         */
        std::queue<std::shared_ptr<IEvent>> getEventQueue();


        uint8_t messageType = 0x00;             // Message Type
        std::vector<uint8_t> payload;    // Payload

        std::vector<std::vector<uint8_t>> _queue_payload;   // Payload queue.
        std::vector<uint8_t> _queue_messageType;            // MessageType queue

        std::mutex _myBeautifulMutex;

        Identity identity;              // Identity of who use the Registry.

    private:

        //Arrays
        std::unordered_map<std::string, std::any>                           _components_arrays;         // Array of components.
        std::unordered_map<std::string, remove_func_t>                      _remove_functions;          // Array of functions to remove components.

        // Entities
        std::vector<entity_t>                                               _entities;                  // Array of Entities indexes.
        std::vector<entity_t>                                               _dead_entities;             // Array of dead Entities indexes.
        entity_t                                                            _next_entity = 0;           // Index for the next Entity to create.

        std::vector<std::function<void(Registry&, int)>>                    _systems;                   // Array of systems.

        std::queue<std::shared_ptr<IEvent>>                                                  _eventQueue;                // Event queue.
};

} // namespace ECS
