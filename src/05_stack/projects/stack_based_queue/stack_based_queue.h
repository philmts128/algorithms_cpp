/*
* Exercício/projeto do livro do Goodrich.
* A ideia é implementar uma fila com duas pilhas internas.
* Autor: Philippe Matias.
*/

#pragma once

#include "stack.h"


/*-----------------------------------*/
namespace pm
{
    /*-----------------------------------*/
    template <typename T>
    class stack_based_queue final
    {
    private:
        /*-----------------------------------*/
        pm::stack<T> m_left;
        pm::stack<T> m_right;

    public:
        /*-----------------------------------*/
        stack_based_queue() {}

        /*-----------------------------------*/
        void enqueue(const T& data)
        {
            while (! m_right.is_empty()) {
                m_left.push(m_right.top());
                m_right.pop();
            }

            m_right.push(data);

            while (! m_left.is_empty()) {
                m_right.push(m_left.top());
                m_left.pop();
            }
        }

        /*-----------------------------------*/
        void dequeue() {
            m_right.pop();
        }

        /*-----------------------------------*/
        auto front() -> T {
            return m_right.top();
        }

        /*-----------------------------------*/
        auto size() -> size_t {
            return m_right.size();
        }

        /*-----------------------------------*/
        auto is_empty() -> bool {
            return m_right.is_empty();
        }
    };
}
