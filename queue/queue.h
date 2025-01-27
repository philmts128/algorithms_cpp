#pragma once

#include "queue_node.h"


namespace pm
{
    /*--------------------------------------*/
    template <typename T>
    class queue
    {
    private:
        /*--------------------------------------*/
        pm::queue_node<T>* m_head { nullptr };
        pm::queue_node<T>* m_tail { nullptr};
        int m_size { 0 };

    public:
        /*--------------------------------------*/
        queue()
        {

        }

        /*--------------------------------------*/
        ~queue() { delete m_head; }

        /*--------------------------------------*/
        void enqueue(const T& item)
        {
            auto new_node = new pm::queue_node<T>(item);

            if (this->empty()) {
                m_head = new_node;
                m_tail = m_head;
            } else {
                m_tail->next = new_node;
                m_tail = m_tail->next;
            }

            m_size++;
        }

        /*--------------------------------------*/
        auto dequeue() -> const T&
        {
            if (m_size == 0) {
                return {}
            }

            if (m_size == 1) {
                auto data = m_head->data;
                delete m_head;
                m_head = m_tail = nullptr;
                m_size = 0;
                return data;
            }

            if (m_size > 1) {
                auto temp = m_head;
                auto data = temp->data;
                m_size--;
                return data;
            }
        }

        /*--------------------------------------*/
        int size() const { return m_size; }
        bool empty() const  { return (m_size == 0); }
        auto front() -> const T& { return m_head->data; }
        auto back() -> const T& { return m_tail->data; }
    };
}
