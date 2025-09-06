/**
* Implementação de ED de pool de objetos alocados no heap
* Autor: Philippe Matias
*/

#pragma once

#include "vector.h"
#include <cstdint>
#include <cassert>
#include <utility>
#include <type_traits>


namespace pm
{
    /*-----------------------------------------------------*/
    template <typename T>
    class object_pool final
    {
        /*-----------------------------------------------------*/
        union block {
            T data;
             block* next { nullptr };
             block()  {}
            ~block()  {}
        };

    private:
        /*-----------------------------------------------------*/
        size_t m_size { 0 };
        block* m_free_list { nullptr };
        pm::vector<void*> m_raw_data;

    public:
        /*-----------------------------------------------------*/
        explicit object_pool(size_t size) : m_size(size)
        {
            assert(size > 0);
            this->add_block();
        }

        /*-----------------------------------------------------*/
        object_pool(const object_pool& other) = delete;
        object_pool& operator = (const object_pool& other) = delete;

        /*-----------------------------------------------------*/
        object_pool(object_pool&& other)
        {
            m_raw_data = std::move(other);
            m_free_list = other.m_free_list;
            m_size = other.m_size;
            other.m_size = 0;
            other.m_free_list = nullptr;
        }

        /*-----------------------------------------------------*/
        ~object_pool()
        {
            for (auto bytes : m_raw_data) {
                ::operator delete[](bytes);
            }
        }

        /*-----------------------------------------------------*/
        template <typename... Args>
        auto allocate(Args&&... args) -> T*
        {
            if (!m_free_list)
                this->add_block();

            block* b = m_free_list;
            m_free_list = m_free_list->next;

            T* p = ::new(static_cast<void*>(std::addressof(b->data)))
                    T(std::forward<Args>(args)...);

            return p;
        }

        /*-----------------------------------------------------*/
        void deallocate(T* ptr)
        {
            if (!ptr) return;

            ptr->~T();
            block* b = reinterpret_cast<block*>(ptr);
            b->next = m_free_list;
            m_free_list = b;
        }

    private:
        /*-----------------------------------------------------*/
        void add_block()
        {
            const size_t bytes = m_size * sizeof(block);

            void* raw = ::operator new[](bytes);
            m_raw_data.append(raw);

            block* base = static_cast<block*>(raw);
            for (size_t i = 0; i < m_size; ++i)
                base[i].next = &base[i + 1];

            base[m_size - 1].next = m_free_list;
            m_free_list = base;
        }
    };
}
