/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** SparseArray
*/

#pragma once

#include <optional>
#include <vector>
#include <memory>

/**
 * @brief Container of component.
 *
 * @tparam Component type of the container.
 */
template <typename Component>
class SparseArray {

    public :

        /**
         * @brief Type of a Component in the vector.
         *
         */
        using value_type = std::optional<Component>;

        /**
         * @brief Type for the value reference.
         *
         */
        using reference_type = value_type &;

        /**
         * @brief Type for the const value reference.
         *
         */
        using const_reference_type = value_type const &;

        /**
         * @brief Type for the vector of type component.
         *
         */
        using container_t = std::vector<value_type>;

        /**
         * @brief Type for the size of the vector.
         *
         */
        using size_type = typename container_t::size_type;

        /**
         * @brief Iterator type of the vector.
         *
         */
        using iterator = typename container_t::iterator;

        /**
         * @brief Const iterator type of the vector.
         *
         */
        using const_iterator = typename container_t::const_iterator;

    public :

        /**
         * @brief Construct a new SparseArray object.
         *
         */
        SparseArray (){};

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
         *
         */
        ~SparseArray(){};

        /**
         * @brief Copy assignment operator.
         *
         * @param other SparseArray to copy.
         * @return SparseArray& this
         */
        SparseArray &operator=(SparseArray const &other)
        {
            _data = other.data;
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
         * @brief Get the reference of a value store in the sparseArray.
         *
         * @param idx in the sparseArray.
         * @return reference_type to the value store at the index.
         */
        reference_type operator[](size_t idx)
        {
            return _data[idx];
        };

        /**
         * @brief Get the const reference of a value store in the sparseArray.
         *
         * @param idx in the sparseArray.
         * @return const_reference_type to the value store at the index.
         */
        const_reference_type operator[](size_t idx) const
        {
            return _data[idx];
        };

        /**
         * @brief Returns a read/write iterator that points to the first
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return iterator.
         */
        iterator begin()
        {
            return _data.begin();
        };

        /**
         * @brief Returns a read/write iterator that points to the first
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return const_iterator.
         */
        const_iterator begin() const
        {
            return _data.begin();
        };

        /**
         * @brief Returns a read-only (constant) iterator that points to the
         *  first element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return const_iterator.
         */
        const_iterator cbegin() const
        {
            return _data.cbegin();
        };

        /**
         * @brief Returns a read/write iterator that points one past the last
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return iterator.
         */
        iterator end()
        {
            return _data.end();
        };

        /**
         * @brief Returns a read/write iterator that points one past the last
         *  element in the sparseArray. Iteration is done in ordinary
         *  element order.
         *
         * @return const_iterator.
         */
        const_iterator end() const
        {
            return _data.end();
        };

        /**
         * @brief Returns a read-only (constant) iterator that points one past
         *  the last element in the sparseArray. Iteration is done in
         *  ordinary element order.
         *
         * @return const_iterator.
         */
        const_iterator cend() const
        {
            return _data.cend();
        };

        /**
         * @brief Returns the number of elements in the sparseArray.
         *
         * @return size_type of the sparseArray.
         */
        size_type size() const
        {
            return _data.size();
        };

        /**
         * @brief Inserts given value into sparseArray at the specified position.
         *
         * @param pos Index to insert element.
         * @param component Component to insert.
         * @return reference_type of the new component.
         */
        reference_type insert_at(size_type pos, Component const &component)
        {
            if (pos >= _data.size())
                _data.resize(pos + 1);
            _data[pos] = component;
            return _data[pos];
        }

        /**
         * @brief Inserts given value into sparseArray at the specified position.
         *
         * @param pos Index to insert element.
         * @param component Component to insert.
         * @return reference_type of the new component.
         */
        reference_type insert_at(size_type pos, Component &&component)
        {
            if (pos >= _data.size())
                _data.resize(pos + 1);
            _data[pos] = component;
            return _data[pos];
        };

        /**
         * @brief Inserts an object in sparseArray before specified iterator.
         *
         * @tparam Params for component to create and insert.
         * @param pos Index to insert element.
         * @param params Component to insert.
         * @return reference_type of the new component.
         */
        template <class... Params>
        reference_type emplace_at(size_type pos, Params&&... params)
        {
            if (pos >= _data.size())
                _data.resize(pos + 1);
            _data[pos] = Component(std::forward<Params>(params)...);
            return _data[pos];
        }

        /**
         * @brief Erase a row in the sparseArray.
         *
         * @param pos Index of the element to erase.
         */
        void erase(size_type pos)
        {
            _data.erase(_data.begin() + pos);
        };

        /**
         * @brief Get the index of an object.
         *
         * @param value of the object.
         * @return size_type Index of the object.
         */
        size_type get_index(value_type const &value) const
        {
            for (size_type i = 0; i < _data.size(); ++i) {
                if (_data[i] == value)
                    return i;
            }
            return -1;
        };

    private :

        container_t     _data; // Vector of type std::vector<Component>
};