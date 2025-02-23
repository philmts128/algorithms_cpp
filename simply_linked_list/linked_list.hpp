/**
 * Implementação de list simplesmente encadeda genérica em C++
 * Autor: Philippe Matias
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "linked_list_node.h"


namespace pm
{
    /*-----------------------------------------------*/
    template <typename T>
    class linked_list
    {
    private:
        /*-----------------------------------------------*/
        int m_size; //tamanho da lista
        linked_list_node<T>* m_head { nullptr }; //nó sentinela

    public:
        /*-----------------------------------------------*/
        linked_list()
        {
            m_size = 0;
            m_head = new linked_list_node<T>();
        }

        /*-----------------------------------------------*/
        linked_list(const linked_list<T>& list)
        {
            m_head = new linked_list_node<T>();
            this->copy_data(list);
        }

        /*-----------------------------------------------*/
        auto operator = (const linked_list<T>& list) -> linked_list<T>&
        {
            if (m_head == nullptr) m_head = new linked_list_node<T>();
            else this->clear();

            this->copy_data(list);
            return *this;
        }

        /*-----------------------------------------------*/
        ~linked_list()
        {
            this->clear();
            delete m_head;
        }

        /*-----------------------------------------------*/
        auto last() -> const T&
        {
            auto cur = m_head;
            while (cur->next != nullptr)
                cur = cur->next;
            return cur->data;
        }

        /*-----------------------------------------------*/
        void push_front(const T& item)
        {
            //novo elemento
            auto new_node = new linked_list_node<T>(item);

            //manipula ponteiros para add. elemento
            auto temp = m_head->next;
            m_head->next = new_node;
            new_node->next = temp;
            m_size += 1;
        }

        /*-----------------------------------------------*/
        void push_back(const T& item)
        {
            //se estiver vzia, add novo elemento com push_front
            if (this->empty()) {
                this->push_front(item);
                return;
            }

            //novo elemento
            auto new_node = new linked_list_node<T>(item);

            auto cur = m_head->next;
            while (cur->next != nullptr)
                cur = cur->next;

            cur->next = new_node;
            m_size += 1;
        }

        /*-----------------------------------------------*/
        void insert(const T& item, int position)
        {
            if (position < 0 || position > (m_size-1)) {
                std::cerr << "posicao invalida!\n";
                return;
            }

            int k = 0; //conta a posição correta

            //acha a posição correta e incrementa o contador
            linked_list_node<T>* current = m_head;
            while (current->next != nullptr && k != position) {
                current = current->next;
                k += 1;
            }

            auto temp = current->next;
            current->next = new linked_list_node<T>(item);
            current->next->next = temp;

            m_size += 1;
        }

        /*-----------------------------------------------*/
        void pop_front()
        {
            if (this->empty())
                return;

            auto temp = m_head->next;
            m_head->next = temp->next;
            delete temp;

            m_size -= 1;
        }

        /*-----------------------------------------------*/
        void pop_back()
        {
            if (this->empty())
                return;

            auto cur = m_head;
            while (cur->next->next != nullptr)
                cur = cur->next;

            delete cur->next;
            cur->next = nullptr;
            m_size -= 1;
        }

        /*-----------------------------------------------*/
        void remove(const T& item)
        {
            auto cur = m_head;

            while (cur->next != nullptr)
            {
                if (cur->next->data == item) {
                    auto temp = cur->next;
                    cur->next = temp->next;
                    delete temp;
                    m_size -= 1;
                    continue;
                }

                cur = cur->next;
            }
        }

        /*-----------------------------------------------*/
        void reverse()
        {
            linked_list_node<T>* prev = nullptr;
            linked_list_node<T>* next = nullptr;
            linked_list_node<T>* curr = m_head->next;

            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            m_head->next = prev;
        }

        /*-----------------------------------------------*/
        void concat(linked_list& list)
        {
            //'navega' até último nó da lista
            auto last = m_head;
            while (last->next != nullptr)
                last = last->next;

            //reliza a junção entre duas listas
            last->next = list.m_head->next;
            list.m_head->next = nullptr;

            //atualiza tamanhos
            m_size += list.m_size;
            list.m_size = 0;
        }

        /*-----------------------------------------------*/
        void swap(linked_list& list)
        {
            //troca tamanhos
           int temp_size = m_size;
           m_size = list.m_size;
           list.m_size = temp_size;

           //troca sentinelas
           auto temp_head = m_head;
           m_head = list.m_head;
           list.m_head = temp_head;
        }

        /*-----------------------------------------------*/
        void clear()
        {
            m_size = 0;
            auto cur = m_head->next;

            while (cur != nullptr) {
                auto temp = cur;
                cur = cur->next;
                delete temp;
            }
        }

        /*-----------------------------------------------*/
        bool operator == (const linked_list<T>& list) const
        {
            if (m_size != list.m_size)
                return false;

            linked_list_node<T>* n1 = m_head->next;
            linked_list_node<T>* n2 = list.m_head->next;

            while (n1 != nullptr) {
                if (n1->data != n2->data)
                    return false;
                n1 = n1->next;
                n2 = n2->next;
            }

            return true;
        }

        /*-----------------------------------------------*/
        bool operator != (const linked_list<T>& list) const {
            return !(*this == list);
        }

        /*-----------------------------------------------*/
        void print()
        {
            auto cur = m_head->next;

            while (cur != nullptr) {
                std::cout << cur->data << " ";
                cur = cur->next;
            }

            std::cout << "\n\n";
        }

        /*-----------------------------------------------*/
        int size() const { return m_size; }
        bool empty() const  { return (m_size == 0); }

    private:
        /*-----------------------------------------------*/
        void copy_data(const linked_list<T>& list)
        {
            auto cur = list.m_head->next;
            auto last = m_head;
            while (cur != nullptr) {
                last->next = new linked_list_node<T>(cur->data);
                cur = cur->next;
                last = last->next;
            }

            m_size = list.m_size;
        }
    };
}

#endif // LINKED_LIST_H
