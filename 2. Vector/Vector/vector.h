/**
 * Implementação de vetor dinâmico
 * Autor: Philippe Matias
 */

#pragma once

#include <cstdint>


namespace pm
{
    /*----------------------------------*/
    template <typename T>
    class vector
    {
    private:
        /*----------------------------------*/
        static constexpr int Min_Cap { 64 };
        T* m_data { nullptr };
        size_t m_size { 0 };
        size_t m_capacity { Min_Cap };

    public:
        /*----------------------------------*/
        vector() {
            this->reserve(m_capacity);
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
        void preppend(const T& item)
        {
            if (is_capacity_full()) {
                m_capacity *= 2;
                this->reserve(m_capacity);
            }

            this->right_shift();
            m_data[0] = item;
            m_size++;
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
        auto operator [] (const size_t index) -> T& { //O(1)
            return m_data[index];
        }

        /*----------------------------------*/
        size_t size() const { return m_size; } //O(1)
        bool is_empty() const { return (m_size == 0); } //O(1)

    private:
        /*----------------------------------*/
        void right_shift(size_t start_position = 0) {
            for (size_t i = m_size; i > start_position; --i) {
                m_data[i] = m_data[i-1];
            }
        }

        /*----------------------------------*/
        void reserve(size_t capacity)
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

        /*----------------------------------*/ //O(1)
        bool is_capacity_full() const { return (m_capacity == m_size); }
    };
}
