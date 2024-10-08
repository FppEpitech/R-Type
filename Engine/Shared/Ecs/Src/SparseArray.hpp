/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** SparseArray
*/

#pragma once

#include <vector>
#include <memory>

/**
 * @brief Entity component system namespace.
 *
 */
namespace ECS {

/**
 * @brief Container of components.
 *
 * @tparam Component Type of the component to store.
 */
template <typename Component>
class SparseArray {

    public:
        /**
         * @brief Type of a Component in the vector.
         */
        using value_type = std::shared_ptr<Component>;

        /**
         * @brief Type for the value reference.
         */
        using reference_type = value_type&;

        /**
         * @brief Type for the const value reference.
         */
        using const_reference_type = const value_type&;

        /**
         * @brief Type for the vector of components.
         */
        using container_t = std::vector<value_type>;

        /**
         * @brief Type for the size of the vector.
         */
        using size_type = typename container_t::size_type;

        /**
         * @brief Iterator type for the vector.
         */
        using iterator = typename container_t::iterator;

        /**
         * @brief Const iterator type for the vector.
         */
        using const_iterator = typename container_t::const_iterator;

    public:
        /**
         * @brief Construct a new SparseArray object.
         */
        SparseArray() = default;

        /**
         * @brief Construct a new SparseArray object.
         * It's a copy constructor.
         *
         * @param other SparseArray to copy.
         */
        SparseArray (SparseArray const &other)
        {
            _data = other._data;
        };

        /**
         * @brief Construct a new SparseArray object.
         * It's a move constructor.
         *
         * @param other SparseArray to move.
         */
        SparseArray (SparseArray &&other) noexcept
        {
            _data = other._data;
        };

        /**
         * @brief Destroy the SparseArray object.
         */
        ~SparseArray() = default;

        /**
         * @brief Copy assignment operator.
         *
         * @param other SparseArray to copy.
         * @return SparseArray& this
         */
        SparseArray &operator=(SparseArray const &other)
        {
            _data = other._data;
            return *this;
        };

        /**
         * @brief Move assignment operator.
         *
         * @param other SparseArray to move.
         * @return SparseArray& this
         */
        SparseArray & operator=( SparseArray &&other) noexcept
        {
            _data = other._data;
            return *this;
        };

        /**
         * @brief Get the reference of a value stored in the SparseArray.
         *
         * @param idx Index in the SparseArray.
         * @return reference_type Reference to the value stored at the index.
         */
        reference_type operator[](size_type idx) {
            return _data[idx];
        }

        /**
         * @brief Get the const reference of a value stored in the SparseArray.
         *
         * @param idx Index in the SparseArray.
         * @return const_reference_type Const reference to the value stored at the index.
         */
        const_reference_type operator[](size_type idx) const {
            return _data[idx];
        }

        /**
         * @brief Returns a read/write iterator that points to the first
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return iterator.
         */
        iterator begin() {
            return _data.begin();
        }

        /**
         * @brief Returns a read/write iterator that points to the first
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return const_iterator.
         */
        const_iterator begin() const {
            return _data.begin();
        }

        /**
         * @brief Returns a read-only (constant) iterator that points to the
         *  first element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return const_iterator.
         */
        const_iterator cbegin() const {
            return _data.cbegin();
        }

        /**
         * @brief Returns a read/write iterator that points one past the last
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return iterator.
         */
        iterator end() {
            return _data.end();
        }

        /**
         * @brief Returns a read/write iterator that points one past the last
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return const_iterator.
         */
        const_iterator end() const {
            return _data.end();
        }

        /**
         * @brief Returns a read-only (constant) iterator that points one past
         *  the last element in the sparseArray. Iteration is done in
         *  ordinary element order.
         *
         * @return const_iterator.
         */
        const_iterator cend() const {
            return _data.cend();
        }

        /**
         * @brief Returns the number of elements in the sparseArray.
         *
         * @return size_type of the sparseArray.
         */
        size_type size() const {
            return _data.size();
        }

        /**
         * @brief Inserts a shared_ptr to the component at the specified index.
         *
         * @param pos Index to insert element.
         * @param component Shared pointer to the component to insert.
         * @return reference_type Reference to the new component.
         */
        reference_type insert_at(size_type pos, value_type component) {
            if (pos >= _data.size())
                _data.resize(pos + 1);
            _data[pos] = std::move(component);
            return _data[pos];
        }

        /**
         * @brief Emplaces a new component at the specified index.
         *
         * @param pos Index to insert element.
         * @tparam Params Parameters to pass to the component's constructor.
         * @return reference_type Reference to the new component.
         */
        template <class... Params>
        reference_type emplace_at(size_type pos, Params&&... params) {
            if (pos >= _data.size())
                _data.resize(pos + 1);
            _data[pos] = std::make_shared<Component>(std::forward<Params>(params)...);
            return _data[pos];
        }

        /**
         * @brief Erases the element at the specified index.
         */
        void erase(size_type pos) {
            if (pos < _data.size())
                _data.erase(_data.begin() + pos);
        }

        /**
         * @brief Finds the index of the given component.
         *
         * @param value The shared pointer to search for.
         * @return size_type Index of the component, or -1 if not found.
         */
        size_type get_index(const value_type& value) const {
            for (size_type i = 0; i < _data.size(); ++i) {
                if (_data[i] == value)
                    return i;
            }
            return static_cast<size_type>(-1);
        }

    private:
        container_t _data;  // Vector of shared pointers to components.
};

} // namespace ECS
