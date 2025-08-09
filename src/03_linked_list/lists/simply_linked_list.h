/**
 * Implementação de lista simplesmente encadeada em C++11
 * Autor: Philippe Matias
 */

#pragma once

#include <cstdint>
#include <iostream> //for debugging purposes
#include "simply_linked_list_iterator.h"


namespace pm
{
    template <typename T>
    struct simply_linked_list_node
    {
        T data;
        simply_linked_list_node* next { nullptr };
        simply_linked_list_node() {}
        simply_linked_list_node(const T& data) : data(data) {}
    };
}


namespace pm
{
    /*-----------------------------------------------------*/
    template <typename T>
    class simply_linked_list final
    {
    private:
        /*-----------------------------------------------------*/
        simply_linked_list_node<T>* m_first { nullptr }; //head
        simply_linked_list_node<T>* m_last  { nullptr }; //tail
        size_t m_size { 0 };

    public:
        /*-----------------------------------------------------*/
        simply_linked_list()
        {
        }

        /*-----------------------------------------------------*/
        simply_linked_list(const simply_linked_list<T>& other) {
            this->copy_data(other);
        }


        /*-----------------------------------------------------*/
        template <typename... Args>
        simply_linked_list(Args... args)
        {
            for (auto& i : { std::forward<Args>(args)... })
                this->append(i);
        }


        /*-----------------------------------------------------*/
        simply_linked_list(simply_linked_list<T>&& other)
        {
            this->clear();

            m_first = other.m_first;
            m_last = other.m_last;
            m_size = other.m_size;

            other.m_first = other.m_last = nullptr;
            other.m_size = 0;
        }

        /*-----------------------------------------------------*/
        ~simply_linked_list() {
            this->clear();
        }


        /*-----------------------------------------------------*/
        void append(const T& data)
        {
            auto new_node = new simply_linked_list_node<T>(data);

            if (m_first == nullptr) {
                m_first = m_last = new_node;
                m_size = 1;
                return;
            }

            m_last->next = new_node;
            m_last = new_node;
            m_size += 1;
        }


        /*-----------------------------------------------------*/
        void preppend(const T& data)
        {
            auto new_node = new simply_linked_list_node<T>(data);

            if (m_first == nullptr) {
                m_first = m_last = new_node;
                m_size = 1;
                return;
            }

            new_node->next = m_first;
            m_first = new_node;
            m_size += 1;
        }


        /*-----------------------------------------------------*/
        void remove_front() //verificar o last!
        {
            if (this->is_empty())
                return;

            auto temp = m_first;
            m_first = m_first->next;
            delete temp;
            m_size -= 1;
            if (this->is_empty()) m_last = nullptr;
        }


        /*-----------------------------------------------------*/
        void remove_back()
        {
            if (this->is_empty())
                return;

            if (this->size() == 1) {
                delete m_first;
                m_first = m_last = nullptr;
                m_size = 0;
                return;
            }

            auto it = m_first;
            while (it->next != m_last)
                it = it->next;

            m_last = it;
            delete it->next;
            m_last->next = nullptr;
            m_size -= 1;
        }


        /*-----------------------------------------------------*/
        auto begin() -> simply_linked_list_iterator<T> {
            return { m_first };
        }


        /*-----------------------------------------------------*/
        auto end() -> simply_linked_list_iterator<T> {
            return { nullptr };
        }

        /*-----------------------------------------------------*/
        void clear()
        {
            if (m_first == nullptr || m_last == nullptr)
                return;

            auto it = m_first;
            while (it != nullptr) {
                auto next = it->next;
                delete it;
                it = next;
            }

            m_size = 0;
            m_first = m_last = nullptr;
        }


        /*-----------------------------------------------------*/
        bool operator == (const simply_linked_list<T>& other) const
        {
            if (this->size() != other.size())
                return false;

            auto this_it = m_first;
            auto other_it = other.m_first;

            while (this_it != m_last) {
                if (this_it->data != other_it->data)
                    return false;
                this_it  = this_it->next;
                other_it = other_it->next;
            }

            return true;
        }


        /*-----------------------------------------------------*/
        bool operator != (const simply_linked_list<T>& other) const {
            return !(*this == other);
        }


        /*-----------------------------------------------------*/
        auto operator = (const simply_linked_list<T>& other) -> simply_linked_list<T>&
        {
            this->copy_data(other);
            return *this;
        }


        /*-----------------------------------------------------*/
        size_t size()    const { return m_size; }
        bool is_empty()  const { return size() == 0; }
        T first() const  { return m_first->data; }
        T last()  const  { return m_last->data; }


        /*-----------------------------------------------------*/
        void print(bool reverse = false)
        {
            if (reverse) {
                reverse_print(m_first);
                return;
            }

            auto first = m_first;

            while (first != nullptr) {
                std::cout << first->data << '\n';
                first = first->next;
            }
        }


        /*-----------------------------------------------------*/
        auto reverse_print(simply_linked_list_node<T>* node) -> simply_linked_list_node<T>*
        {
            if (node == nullptr) {
                return node;
            } else {
                auto n = reverse_print(node->next);
                std::cout << node->data << '\n';
                return n;
            }
        }


    private:
        /*-----------------------------------------------------*/
        void copy_data(const simply_linked_list<T>& other)
        {
            this->clear();

            auto it = other.m_first;
            while (it != nullptr) {
                this->append(it->data);
                it = it->next;
            }
        }
    };
}
