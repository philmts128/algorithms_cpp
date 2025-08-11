/**
* Implementação de lista duplamente encadeada circular
* Autor: Philippe Matias
*/


#pragma once

#include <cstdint>
#include <iostream>
#include <utility>

#include "doubly_linked_list_iterator.h"
#include "doubly_linked_list_node.h"


namespace pm
{
    /*-------------------------------------*/
    template <typename T>
    class doubly_linked_list final
    {
    private:
        /*-------------------------------------*/
        doubly_linked_list_node<T>* m_sentinel { nullptr };
        size_t m_size { 0 };

    public:
        /*-------------------------------------*/
        doubly_linked_list() //O(1)
        {
            m_sentinel = new doubly_linked_list_node<T>();
            m_sentinel->next = m_sentinel;
            m_sentinel->prev = m_sentinel;
        }

        /*-------------------------------------*/
        doubly_linked_list(const doubly_linked_list& other) //O(other.m_size)
        {
            m_sentinel = new doubly_linked_list_node<T>();
            m_sentinel->next = m_sentinel;
            m_sentinel->prev = m_sentinel;
            this->copy_data(other);
        }

        /*-------------------------------------*/
        doubly_linked_list(doubly_linked_list&& other) //O(1)
        {
            if (m_sentinel) {
                this->clear();
                delete m_sentinel; }

            m_sentinel = other.m_sentinel;
            m_size = other.m_size;

            other.m_size = 0;
            other.m_sentinel = new doubly_linked_list_node<T>();
            other.m_sentinel->next = m_sentinel;
            other.m_sentinel->prev = m_sentinel;
        }

        /*-------------------------------------*/
        ~doubly_linked_list() //O(m_size) = O(1), supondo que tamanho seja constante
        {
            if (m_sentinel) {
                this->clear();
                delete m_sentinel;
            }
        }

        /*-------------------------------------*/
        void append(const T& item) //O(1)
        {
            auto new_node =
                new doubly_linked_list_node<T>(item);

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
            auto new_node =
                new doubly_linked_list_node<T>(item);

            new_node->prev = m_sentinel;
            new_node->next = m_sentinel->next;
            m_sentinel->next = new_node;

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

            delete last;
            m_size  -= 1;
        }

        /*-------------------------------------*/
        void remove_front() //O(1)
        {
            if (this->is_empty())
                return;

            auto first = m_sentinel->next;
            auto next = first->next;

            delete first;
            m_sentinel->next = next;
            next->prev = m_sentinel;

            m_size  -= 1;
        }

        /*-----------------------------------------------------*/
        size_t size()   const { return m_size; } //O(1)
        bool is_empty() const { return size() == 0; }
        T first()       const { return m_sentinel->prev->data; }
        T last()        const { return m_sentinel->next->data; }

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
                delete it;
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
        auto operator = (const doubly_linked_list<T>& other) -> doubly_linked_list&
        {
            this->copy_data(other);
            *this;
        }

        /*-------------------------------------*/
        bool operator == (const doubly_linked_list<T>& other) const //O(n)
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
        bool operator != (const doubly_linked_list<T>& other) const { //O(n)
            return !(*this == other);
        }

        /*-------------------------------------*/
    private:
        void copy_data(const doubly_linked_list<T>& other) //O(other.m_size)
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
