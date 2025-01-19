/**
 * Implementação de list simplesmente encaded genérica em C++
 * Autor: Philippe Matias
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "linked_list_node.h"


namespace pm
{
    template <typename T>
    class linked_list
    {
    private:
        int m_size; //tamanho da lista
        linked_list_node<T>* m_head { nullptr }; //nó sentinela

    public:
        //contrutor padrão inicia uma lista vazia
        linked_list()
        {
            m_size = 0;
            m_head = new linked_list_node<T>();
        }

        //construtor de cópia
        linked_list(const linked_list<T>& list)
        {
            *this = list;
        }

        //operador de atribuição
        auto operator = (const linked_list<T>& list) -> linked_list<T>&
        {
            //se o sentinela não tiver sido instanciado...
            if (m_head == nullptr) m_head = new linked_list_node<T>();
            else this->clear();

            //se a outra lista estiver vazia, a nossa também ficará
            if (list.empty()) {
                m_size = 0;
                return *this; }

            linked_list_node<T>* cur = list.m_head->next;
            linked_list_node<T>* last = nullptr; //ptr para último elemento

            //adiciona novo elemento apens no fim da nossa lista
            m_head->next = new linked_list_node<T>(cur->data);
            last = m_head->next;
            cur = cur->next;

            while (cur != nullptr) {
                last->next = new linked_list_node<T>(cur->data);
                last = last->next;
                cur = cur->next;
            }

            m_size = list.m_size;
            return *this;
        }

        //destructor
        ~linked_list()
        {
            this->clear();
            delete m_head;
        }

        //obtém o último elemento
        auto last() -> const T&
        {
            auto cur = m_head;
            while (cur->next != nullptr)
                cur = cur->next;
            return cur->data;
        }

        //insere um elemento no início da lista
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

        //insere um elemento na parte final da lista
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

        //remove elemento no inicio da lista
        void pop_front()
        {
            if (this->empty())
                return;

            auto temp = m_head->next;
            m_head->next = temp->next;
            delete temp;

            m_size -= 1;
        }

        //remove eleento no fim da lista
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

        //deleta todos os itens da lista
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

        //imprime todos os elementos da lista
        void print()
        {
            auto cur = m_head->next;

            while (cur != nullptr) {
                std::cout << cur->data << " ";
                cur = cur->next;
            }

            std::cout << "\n\n";
        }

        //tamanho e se está vazia, a lista
        int size() const { return m_size; }
        bool empty() const  { return (m_size == 0); }
    };
}

#endif // LINKED_LIST_H
