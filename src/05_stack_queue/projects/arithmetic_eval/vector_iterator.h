/**
 * Implementação de um iterador simples para a ED pm::vector
 * Autor: Philippe Matias
*/

#pragma once


namespace pm
{
    /*-------------------------------------*/
    template <typename T>
    class vector;

    /*-------------------------------------*/
    template <typename T>
    class vector_iterator final
    {
    private:
        /*-------------------------------------*/
        friend vector<T>;
        T* m_ptr { nullptr };

    public:
        /*-------------------------------------*/
        vector_iterator() {}

        bool operator == (vector_iterator<T> other) {
            return (m_ptr == other.m_ptr);
        }

        bool operator != (vector_iterator<T> other) {
            return !(*this == other);
        }

        auto operator ++ () -> vector_iterator<T>& {
            ++m_ptr;
            return *this;
        }

        auto operator -- () -> vector_iterator<T>& {
            --m_ptr;
            return *this;
        }

        auto operator * () -> T {
            return *m_ptr;
        }

    private:
        /*-------------------------------------*/
        vector_iterator(T* ptr) : m_ptr(ptr) {}
    };
}
