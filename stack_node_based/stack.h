#ifndef STACK_H
#define STACK_H

#include <exception>
#include "stack_node.h"


namespace pm
{
    /*----------------------*/
    template <typename T>
    class stack
    {
    private:
        /*----------------------*/
        stack_node<T>* m_top { nullptr };
        stack_node<T>* m_first { nullptr };
        int m_size { 0 };

    public:
        /*----------------------*/
        stack() {}
        ~stack() { if (m_top) delete m_top; }

        /*----------------------*/
        void push(const T& data)
        {
            if (this->empty()) {
                m_top = new stack_node<T>(data);
                m_first = m_top;
                m_size++;
                return;
            }

            m_top->next = new stack_node<T>(data);
            m_top = m_top->next;
            m_size++;
        }

        /*----------------------*/
        auto pop() -> const T&
        {
            auto temp = m_top;
            auto data = temp->data;

            stack_node<T>* cur = m_first;
            while (cur->next != nullptr)
                cur = cur->next;

            m_top = cur;
            m_top->next = nullptr;

            delete temp;
            m_size--;

            return data;
        }

        /*----------------------*/
        auto top() -> const T& { return m_top->data; }
        int size() const { return m_size; }
        bool empty() const { return (m_size == 0); }
    };
}


#endif
