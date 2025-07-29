/**
 * Implementação muito ineficiente de vetor dinâmico para testes e comparações
 * Autor: Philippe Matias
 */

#pragma once

#include <cstdint>


namespace pm
{
    /*----------------------------------*/
    template <typename T>
    class slow_vector
    {
    private:
        /*----------------------------------*/
        T* m_data { nullptr };
        size_t m_size { 0 };

    public:
        /*----------------------------------*/
        slow_vector() {
        }

        /*----------------------------------*/
        ~slow_vector() { //O(1)
            if (m_data != nullptr) {
                delete[] m_data;
            }
        }

        /*----------------------------------*/
        void append(const T& item) //Sempre será O(n) por conta do loop
        {
            //muito ineficiente por causa das constantes alocações dinâmicas de memória
            if (this->is_empty()) {
                m_data = new T[1];
                m_data[0] = item;
                m_size = 1;
                return;
            }

            m_size += 1;
            auto temp = new T[m_size];

            for (size_t i = 0; i < m_size-1; ++i)
                temp[i] = m_data[i];
            temp[m_size-1] = item;
            delete[] m_data;
            m_data = temp;
        }

        /*----------------------------------*/
        void clear()
        {
            if (m_data != nullptr)
                delete[] m_data;

            m_size = 0;
            m_data = nullptr;
        }

        /*----------------------------------*/
        auto operator [] (const size_t index) -> T& { //O(1)
            return m_data[index];
        }

        /*----------------------------------*/
        size_t size() const { return m_size; } //O(1)
        bool is_empty() const { return (m_size == 0); } //O(1)
    };
}
