/**
* É a lista duplamente encadeada, mas usando pool de memória para melhor performance
* Autor: Philippe Matias
*/


#pragma once

#include <cstdint>
#include <iostream>
#include <utility>

#include "doubly_linked_list_iterator.h"
#include "doubly_linked_list_node.h"
#include "object_pool.h"


namespace pm
{
    /*-------------------------------------*/
    template <typename T>
    class fast_linked_list final
    {
    private:
        /*-------------------------------------*/
        object_pool<doubly_linked_list_node<T>> m_pool { 2048 };
        doubly_linked_list_node<T>* m_sentinel { nullptr };
        size_t m_size { 0 };

    public:
        /*-------------------------------------*/
        fast_linked_list() //O(1)
        {
            m_sentinel = m_pool.allocate();
            m_sentinel->next = m_sentinel;
            m_sentinel->prev = m_sentinel;
        }

        /*-------------------------------------*/
        fast_linked_list(const fast_linked_list& other) //O(other.m_size)
        {
            m_sentinel = m_pool.allocate();
            m_sentinel->next = m_sentinel;
            m_sentinel->prev = m_sentinel;
            this->copy_data(other);
        }

        /*-------------------------------------*/
        fast_linked_list(fast_linked_list&& other) //O(1)
        {
            if (m_sentinel) {
                this->clear();
                m_pool.deallocate(m_sentinel); }

            m_sentinel = other.m_sentinel;
            m_size = other.m_size;

            other.m_size = 0;
            other.m_sentinel = m_pool.allocate();
            other.m_sentinel->next = m_sentinel;
            other.m_sentinel->prev = m_sentinel;
        }

        /*-------------------------------------*/
        ~fast_linked_list() //O(m_size) = O(1), supondo que tamanho seja constante
        {
            if (m_sentinel) {
                this->clear();
                m_pool.deallocate(m_sentinel);
            }
        }

        /*-------------------------------------*/
        void append(const T& item) //O(1)
        {
            auto new_node = m_pool.allocate(item);

            auto last = m_sentinel->prev;
            last->next = new_node;
            new_node->prev = last;
            new_node->next = m_sentinel;
            m_sentinel->prev = new_node;

            m_size += 1;
        }

        /*-------------------------------------*/
        void preppend(const T& item) //O(1)
        {            
            auto new_node = m_pool.allocate(item);

            auto temp = m_sentinel->next;
            m_sentinel->next = new_node;
            new_node->next = temp;
            new_node->prev = m_sentinel;
            temp->prev = new_node;

            m_size += 1;
        }

        /*-------------------------------------*/
        void remove_back() //O(1)
        {
            if (this->is_empty())
                return;

            auto last = m_sentinel->prev;
            auto new_last = last->prev;

            new_last->next = m_sentinel;
            m_sentinel->prev = new_last;

            m_pool.deallocate(last);
            m_size  -= 1;
        }

        /*-------------------------------------*/
        void remove_front() //O(1)
        {
            if (this->is_empty())
                return;

            auto first = m_sentinel->next;
            auto next = first->next;

            m_pool.deallocate(first);
            m_sentinel->next = next;
            next->prev = m_sentinel;

            m_size  -= 1;
        }

        /*-----------------------------------------------------*/
        size_t size()   const { return m_size; } //O(1)
        bool is_empty() const { return size() == 0; }
        T first()       const { return m_sentinel->next->data; }
        T last()        const { return m_sentinel->prev->data; }

        /*-----------------------------------------------------*/
        auto begin() -> doubly_linked_list_iterator<T> { return m_sentinel->next; }
        auto end()   -> doubly_linked_list_iterator<T> { return m_sentinel; }

        /*-------------------------------------*/
        void clear() //O(m_size) = O(1)
        {
            if (this->is_empty())
                return;

            auto it = m_sentinel->next;
            while (it != m_sentinel) {
                auto next = it->next;
                m_pool.deallocate(it);
                it = next; }

            m_sentinel->next = m_sentinel->prev = m_sentinel;
            m_size = 0;
        }

        /*-------------------------------------*/
        void print()
        {
            for (const auto& i : *this)
                std:: cout << i << '\n';
        }

        /*-------------------------------------*/
        auto operator = (const fast_linked_list<T>& other) -> fast_linked_list&
        {
            this->copy_data(other);
            *this;
        }

        /*-------------------------------------*/
        bool operator == (const fast_linked_list<T>& other) const //O(n)
        {
            if (this->size() != other.size())
                return false;

            auto it = m_sentinel->next;
            for (const auto& i : other) {
                if (it->data != i)
                    return false;
                it = it->next; }

            return true;
        }

        /*-------------------------------------*/
        bool operator != (const fast_linked_list<T>& other) const { //O(n)
            return !(*this == other);
        }

        /*-------------------------------------*/
    private:
        void copy_data(const fast_linked_list<T>& other) //O(other.m_size)
        {
            this->clear();
            this->m_size = other.m_size;

            auto it = other.m_sentinel->next;

            for (; it != other.m_sentinel; it = it->next) {
                this->append(it->data);
            }
        }
    };
}
