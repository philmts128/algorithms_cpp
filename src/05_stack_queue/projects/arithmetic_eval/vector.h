/**
 * Implementação de vetor dinâmico
 * Autor: Philippe Matias
 */

#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>

#include "vector_iterator.h"


namespace pm
{
    /*----------------------------------*/
    template <typename T>
    class vector final
    {
    private:
        /*----------------------------------*/
        static constexpr size_t Min_Cap { 128 };
        static constexpr size_t Not_Found { (size_t)(-1) };
        T* m_data { nullptr };
        size_t m_size { 0 };
        size_t m_capacity { Min_Cap };

    public:
        /*----------------------------------*/
        vector() {
            this->reserve(m_capacity);
        }

        /*----------------------------------*/
        vector(size_t size, bool init = true) {
            this->m_size = size;
            this->reserve(calc_capacity(size));

            if (init) {
                for (size_t i = 0; i < m_size; ++i) {
                    m_data[i] = T{};
                }
            }
        }

        /*----------------------------------*/
        template <typename... Args>
        vector(const Args&... args)
        {
            size_t len = sizeof...(args);
            this->m_size = len;
            m_capacity = calc_capacity(len);
            if (m_data) delete[] m_data;
            m_data = new T[m_capacity] { static_cast<T>(args)... };
        }

        /*----------------------------------*/
        vector(const pm::vector<T>& vec) {
            this->copy_data(vec);
        }

        /*----------------------------------*/
        ~vector() { //O(1)
            if (m_data != nullptr) {
                delete[] m_data;
            }
        }

        /*----------------------------------*/
        void append(const T& item) //será O(1) no caso médio amortizado e O(n) no pior caso
        {
            //é muito mais eficiente pois usa menos alocações de memória em tempo de execução.
            if (is_capacity_full()) {
                m_capacity *= 2; //pode melhorar fazendo o crescimento ser exponencial
                this->reserve(m_capacity);
            }

            m_data[m_size++] = item;
        }

        /*----------------------------------*/
        void insert(const T& item, size_t position)
        {
            if (position >= m_size) //size_t é sempre maior ou igual que zero
                return;

            if (this->is_capacity_full()) {
                m_capacity *= 2;
                this->reserve(m_capacity);
            }

            this->right_shift(position);
            m_data[position] = item;
            m_size++;
        }

        /*----------------------------------*/
        void preppend(const T& item)
        {
            if (this->is_empty()) {
                this->append(item);
            } else {
                this->insert(item, 0);
            }
        }

        /*----------------------------------*/
        void remove(const size_t position)
        {
            if (this->is_empty())
                return;
            this->left_shift(position);
            m_size--;

            if (m_size <= m_capacity/4)
                this->shrink();
        }

        /*----------------------------------*/
        void remove_back() { //tempo é O(1) amortizado e O(n) no pior caso
            if (this->is_empty())
                return;
            m_size--;

            if (m_size <= m_capacity/4)
                this->shrink();
        }

        /*----------------------------------*/
        void remove_front() //tempo é sempre O(n) pois elementos serão deslocados
        {
            this->remove(0);
        }

        /*----------------------------------*/
        size_t search(const T& value) //O(n)
        {
            for (size_t i = 0; i < m_size; ++i) {
                if (m_data[i] == value) {
                    return i;
                }
            }
            return Not_Found;
        }

        /*----------------------------------*/
        bool exists(const T& value) const { //O(n)
            return this->search(value) != Not_Found;
        }

        /*----------------------------------*/
        void clear()
        {
            m_capacity = Min_Cap;
            delete[] m_data;
            m_data = new T[Min_Cap];
            m_size = 0;
        }

        /*----------------------------------*/
        auto at(const size_t index) -> const T& { //O(1)
            return m_data[index];
        }

        /*----------------------------------*/
        auto operator = (const pm::vector<T>& vec) -> pm::vector<T>& {
            this->copy_data(vec);
            return *this;
        }

        /*----------------------------------*/
        bool operator == (const pm::vector<T>& vec) const { //O(n)
            if (m_size != vec.m_size)
                return false;

            for (int i = 0; i < m_size; ++i) {
                if (m_data[i] != vec.m_data[i]) {
                    return false;
                }
            }

            return true;
        }

        /*----------------------------------*/
        bool operator != (const pm::vector<T>& vec) const { //O(n)
            return !(*this == vec);
        }

        /*----------------------------------*/
        auto operator [] (const size_t index) -> T& { //O(1)
            return m_data[index];
        }

        /*----------------------------------*/
        T& operator [] (const size_t index) const { //O(1)
            return m_data[index];
        }

        /*----------------------------------*/
        auto operator + (const pm::vector<T>& other) -> const pm::vector<T>
        {
            pm::vector<T> vec(this->m_size + other.m_size, false);

            size_t i = 0;
            for (; i < this->m_size; ++i)
                vec.m_data[i] = this->m_data[i];

            for (size_t j = 0; j < other.m_size; ++j)
                vec.m_data[i+j] = other.m_data[j];

            return vec;
        }

        /*----------------------------------*/
        auto operator += (const pm::vector<T>& other) -> pm::vector<T>&
        {
            size_t i = m_size;

            m_size += other.m_size;
            this->reserve(m_size);

            for (size_t j = 0; j < other.m_size;)
                m_data[i++] = other.m_data[j++];

            return *this;
        }



        /*----------------------------------*/
        size_t size()     const { return  m_size; } //O(1)
        size_t capacity() const { return  m_capacity; } //O(1)
        bool is_empty()   const { return (m_size == 0); } //O(1)
        vector_iterator<T> begin() { return  { m_data }; }
        vector_iterator<T> end()   { return  { &m_data[m_size] }; }


    private:
        /*----------------------------------*/
        void right_shift(size_t start_position = 0) { //O(n-s)
            for (size_t i = m_size; i > start_position; --i) {
                m_data[i] = m_data[i-1];
            }
        }

        /*----------------------------------*/
        void left_shift(size_t start_position = 0) { //O(n-s)
            auto sp = start_position;
            for (; sp < m_size-1; ++sp) {
                m_data[sp] = m_data[sp+1];
            }
        }

        /*----------------------------------*/
        void reserve(size_t capacity) //O(min(capacity, m_size))
        {
            if (m_size == capacity)
                return;

            if (m_data == nullptr) {
                m_data = new T[m_capacity];
                return;
            }

            auto temp = new T[capacity];
            auto lim = (m_size > capacity) ? capacity : m_size;

            for (size_t i = 0; i < lim; ++i)
                temp[i] = m_data[i];

            delete[] m_data;
            m_data = temp;
        }

        /*----------------------------------*/
        size_t calc_capacity(size_t size)
        {
            if (size <= Min_Cap) {
                return Min_Cap;
            } else {
                double exp = log(size)/log(2.0);
                return pow(2.0, ceil(exp)+1);
            }
        }

        /*----------------------------------*/
        void shrink() {
            m_capacity = this->calc_capacity(m_size);
            this->reserve(m_capacity);
        }

        /*----------------------------------*/
        void copy_data(const pm::vector<T>& vec) //O(vec.m_size)
        {
            m_size = vec.m_size;
            m_capacity = this->calc_capacity(m_size);

            if (m_data) delete[] m_data;
            m_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; ++i)
                m_data[i] = vec.m_data[i];
        }

        /*----------------------------------*/ //O(1)
        bool is_capacity_full() const { return (m_capacity == m_size); }
    };
}
